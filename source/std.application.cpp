//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.application.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Application * g_pApplication = nullptr;
//-----------------------------------------------------------------------------------------------//
Application::Application( int & nargc, char ** lppargv ):QApplication(nargc, lppargv) 
{
   g_pApplication = this;
   m_FrameWindow = nullptr;
   m_Terminated = false;
   m_Locale = std::shared_ptr<QLocale>(new QLocale
   {
      QLocale::Portuguese, QLocale::Brazil
   });
   /**/
   connect(this, &QGuiApplication::lastWindowClosed,[=]()
   { 
      run_and_wait([&]
      { 
         OnLastWindowClosed(this);  
      });
   });
   connect(this, &QGuiApplication::focusWindowChanged,[=](QWindow * pWnd)
   { 
      run_and_wait([&]
      {
         OnFocusWindowChanged(pWnd, this);
      });
   });

   QLocale::setDefault(m_Locale.operator*());
}
//-----------------------------------------------------------------------------------------------//
Application::~Application()
{
   disconnect();
   cancel();
}
//-----------------------------------------------------------------------------------------------//
void __fastcall Application::Terminate()
{
   if ( m_FrameWindow )
   {
      if ( m_FrameWindow->close() )
      {
         cancel();
         Terminated = true;
      }
   }
}
//-----------------------------------------------------------------------------------------------//
int __fastcall Application::Execute()
{
   if ( m_FrameWindow )
   {
      m_FrameWindow->Show();
   }
   return exec();
}
//-----------------------------------------------------------------------------------------------//
Application  * __fastcall Application::GetMainApp()
{
   return g_pApplication;
}
//-----------------------------------------------------------------------------------------------//
MainWindow  * __fastcall Application::GetMainWindow()
{
   return g_pApplication->m_FrameWindow;
}
//-----------------------------------------------------------------------------------------------//