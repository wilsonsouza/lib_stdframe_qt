//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defs.hpp>
#include <std.menu.hpp>
#include <std.mainwindow.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK Application: 
      public QApplication, public task_group
   {
      Q_OBJECT
   public:
      Application ( int & nArgc, char ** paArgv );
#if(_DISABLED)
      Application ( int & nargc, char ** lppargv, bool bguienabled );
      Application ( int & nargc, char ** lppargv, qApplication::Type type );
      Application ( display * lpdisplay, qt::handle hvisual = 0, qt::handle hcolormap = 0 );
      Application ( display * lpdisplay, int & nargc, char ** lppargv, qt::handle hvisual = 0, qt::handle hcolormap = 0 );
      Application ( qApplication::qs60mainApplicationfactory factory, int & nargc, char ** lppargv );
#endif
      virtual  ~Application();

      //overwrite
      virtual void __fastcall Terminate();
      virtual int  __fastcall Execute();
      virtual void __fastcall ProcessEvents(QEventLoop::ProcessEventsFlags Flags = QEventLoop::AllEvents);

      //static
      static Application * __fastcall GetMainApp();
      static MainWindow  * __fastcall GetMainWindow();

      DECLARE_OPERATOR(Application);
      virtual void OnLastWindowClosed(Application * Sender){}
      virtual void OnFocusWindowChanged(QWindow * pWnd, Application * Sender){}

      set_property(bool, Terminated);
      set_property(std::MainWindow *, FrameWindow);
      set_property(std::ustring, AppName);
      set_property(std::ustring, Title);
      set_property(std::ustring, Version);
      set_property(std::ustring, Credit);
      set_property(std::ustring, Owner);
      set_property(std::ustring, Copyright);
      set_property(std::shared_ptr<QLocale>, Locale);
   };
   //-----------------------------------------------------------------------------------------------//
   __inline void __fastcall Application::ProcessEvents(QEventLoop::ProcessEventsFlags flags)
   {
      QCoreApplication::processEvents(flags);
   }
   //-----------------------------------------------------------------------------------------------//
};