//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.mdiframewindow.hpp>
#include <std.mdiframewindowarea.hpp>
#include <std.menubar.hpp>
#include <std.mdichildwindow.hpp>
#include <std.imdichildwindowimpl.hpp>
#include <std.widgetimpl.hpp>
#include <std.timer.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MDIChildWindow::MDIChildWindow(QWidget * pOwner, std::ustring const & szName, Qt::WindowFlags wfflags):
IMDIChildWindowImpl(pOwner, szName, wfflags)
{
   SetIconsList( shared_ptr<IconsImplEx<>>( new IconsImplEx<>() ) );
   setWindowIcon( IconsList->GetCommon()->MYDOCUMENTS );
   /**/
   m_VerticalBox = new WidgetImpl<>();
   m_HorizontalBox = new WidgetImpl<QHBoxLayout>();
   m_FormBox = new WidgetImpl<QFormLayout>();
   m_GridBox = new WidgetImpl<QGridLayout>();
   /**/
   setAttribute(Qt::WA_DeleteOnClose);
   /**/
   SetMode( unsigned int( Window::Mode::NORMAL ) );
   SetTerminated( false );
   SetFrameWindow( reinterpret_cast< MDIFrameWindow * >( pOwner ) );
   /**/
   if(pOwner && FrameWindow)
   {
      if ( FrameWindow->Desktop )
      {
         FrameWindow->Desktop->addSubWindow( this );
      }
   }
   /**/
   Timer = shared_ptr<std::Timer>{new std::Timer( this )};
   Timer->setInterval( 0x64 );
   /**/
   connect(Timer.get(), &std::Timer::timeout, [=] ()
   {
      OnNotify( this, WM_TIMER, nullptr );
   } );
   /**/
}
//-----------------------------------------------------------------------------------------------//
MDIChildWindow::~MDIChildWindow()
{
   disconnect();
   cancel();
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MDIChildWindow::Update()
{
   Show(m_Mode);
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MDIChildWindow::Close()
{
   /* emit close window */
   if ( close() )
   {
      cancel();
      Terminated = true;
   }
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MDIChildWindow::Show(unsigned int uMode)
{
   //emit signal of show command
   run_and_wait( [&]
   {
      if ( !OnShow( this, uMode ) )
         return;
   } );
   /* when call functions of display mode it´s lock system*/
   if (m_Mode != uMode)
      m_Mode = uMode;

   if (uMode == Window::Mode::HIDE)
      hide();

   if (uMode == Window::Mode::MAXIMIZED)
      showMaximized();

   if (uMode == Window::Mode::MINIMIZED)
      showMinimized();

   if (uMode == Window::Mode::NORMAL)
      show();
}
//-----------------------------------------------------------------------------------------------//
bool MDIChildWindow::event(QEvent * e)
{
   QEvent::Type uId = e->type();
   /**/
   if(uId == QEvent::Polish)
   {
      run_and_wait([&]
      {
         if ( OnCreate( this ) )
         {
            e->accept();
            //TimerEventHandle->start();
         }
      });
      return e->isAccepted();
   }
   else if (QEvent::WindowActivate == uId)
   {
      run_and_wait([&]
      {
         if ( OnActivate( this ) )
         {
            e->accept();
            m_Timer->start();
         }
         else
         {
            e->ignore();
         }
      });
      return e->isAccepted();
   }
   else if (QEvent::WindowDeactivate == uId)
   {
      run_and_wait([&]
      {
         if ( OnDeactivate( this ) )
         {
            e->accept();
            m_Timer->stop();
         }
         else
         {
            e->ignore();
         }
      });
      return e->isAccepted();
   }
   return QMdiSubWindow::event(e);
}
//-----------------------------------------------------------------------------------------------//
void MDIChildWindow::closeEvent(QCloseEvent * e)
{
   run_and_wait([&]
   {
      if ( !OnClose( this ) )
      {
         e->ignore();
      }
      else
      {
         e->accept();
         m_Timer->stop();
      }
   });
}
//-----------------------------------------------------------------------------------------------//
void MDIChildWindow::timerEvent(QTimerEvent * e)
{
}
//-----------------------------------------------------------------------------------------------//
void MDIChildWindow::contextMenuEvent(QContextMenuEvent * e)
{
   run_and_wait([&]
   { 
      if ( OnContextMenuRequested( e->pos(), this ) )
      {
         e->accept();
      }
      else
      {
         e->ignore();
      }
   });
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MDIChildWindow::SetWidget(QWidget * pOwner)
{
   setWidget(pOwner);
   Show();
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnCreate(MDIChildWindow * pWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnClose(MDIChildWindow * pWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnActivate(MDIChildWindow * pChildWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnDeactivate(MDIChildWindow * pChildWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnShow(MDIChildWindow * pChildWnd, 
   unsigned int const & uMode)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnContextMenuRequested(QPoint const & p, MDIChildWindow * pChildWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnWindowStateChanged(MDIChildWindow * pChildWnd, 
   Qt::WindowStates wsOld, Qt::WindowStates wsNew)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindow::OnNotify(MDIChildWindow * pWnd, long lMsg, void const * pMsg)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
std::shared_ptr<sql::Query> & MDIChildWindow::GetSQLHandle() const
{
   return m_FrameWindow->GetSingleQueryLanguageHandle();
}
//-----------------------------------------------------------------------------------------------//
