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
#include <std.mdichildwindow.hpp>
#include <std.application.hpp>
#include <std.toolbar.hpp>
#include <std.timer.hpp>
#include <std.popup.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MDIFrameWindow::MDIFrameWindow(QWidget * pOwner, 
   std::Application * pApplication, std::ustring const strName, Qt::WindowFlags wfflags):
MainWindow(pOwner, strName, wfflags)
{
   SetApplicationHandle(pApplication);
   SetDesktop(new MDIFrameWindowArea(this));
   SetName(strName);
   setCentralWidget(GetDesktop());
   SetTimer( std::shared_ptr<std::Timer>( new std::Timer( this, GetClassName() ) ) );
   GetTimer()->setInterval(0x400);
   /**/
   QMdiArea::ViewMode vMode = QMdiArea::ViewMode( Settings->value( RegKey::VIEWMODE, Desktop->viewMode() ).toInt() );
   {
      Desktop->setViewMode( vMode );
   }
}
//-----------------------------------------------------------------------------------------------//
MDIFrameWindow::~MDIFrameWindow()
{
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::ActivateNextChildWindow()
{
   Desktop->activateNextSubWindow();
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::ActivatePreviousChildWindow()
{
   Desktop->activatePreviousSubWindow();
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::Cascade()
{
   Desktop->cascadeSubWindows();
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::CloseActiveChildWindow()
{
   Desktop->closeActiveSubWindow();
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::CloseAllChildWindows()
{
   Desktop->closeAllSubWindows();
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::SetActiveMDIChildWindow(MDIChildWindow * pChildWnd)
{
   Desktop->setActiveSubWindow(dynamic_cast<QMdiSubWindow *>(pChildWnd));
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::Tile()
{
   Desktop->tileSubWindows();
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::IsMDIChildWindowExists(std::ustring const & strName)
{
   MDIChildWindow * pWnd = Desktop->operator [](strName);
   return (pWnd != nullptr);
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::OnProcessInternalMDIChildWindowCommands( MainWindow * pWnd, std::ustring const & strName )
{
   if ( strName.contains( Captions::Window::CASCADE ) )
   {
      this->Cascade();
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::TILE ) )
   {
      this->Tile();
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::CLOSE ) )
   {
      MDIChildWindow * pChildWnd = Desktop->GetActiveMDIChildWindow();

      if ( pChildWnd != nullptr )
      {
         pChildWnd->close();
         bool bEnabled = Desktop->GetListMDIChildWindow().count() != 0;
         EnableMenuItem( Captions::File::CLOSE, bEnabled );
      }
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::CLOSEALL ) )
   {
      shared_ptr<QMutex> pMutex { new QMutex() };
      shared_ptr<QMutexLocker> pLocker { new QMutexLocker( pMutex.get() ) };
      /**/
      CloseAllChildWindows();
      //refresh Menu items
      EnableMDIActions( nullptr );
      /**/
      bool bEnabled = Desktop->GetListMDIChildWindow().count() != 0;
      EnableMenuItem( Captions::File::CLOSE, bEnabled );
      /**/
      pLocker.reset();
      pMutex.reset();
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::DOCUMENT ) )
   {
      bool bDoc = Desktop->documentMode();
      MenuItemData * pDoc = shared_ptr<Popup>( *this )->operator[]( strName );
      /**/
      Desktop->setDocumentMode( !bDoc );
      //repaint all windows
      UpdateAllMDIChildWindows();

      if ( pDoc != nullptr )
      {
         if ( pDoc->GetActionItem() != nullptr )
         {
            pDoc->GetActionItem()->setChecked( !bDoc );
         }
      }
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::HIDE ) )
   {
      MDIChildWindow * pChildWnd = Desktop->GetActiveMDIChildWindow();

      if ( pChildWnd != nullptr )
      {
         pChildWnd->Show( Window::Mode::HIDE );
      }
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::SHOW ) ||
      strName.contains( Captions::Window::MAXIMIZE ) ||
      strName.contains( Captions::Window::REFRESH ) )
   {
      MDIChildWindow * pChildWnd = Desktop->GetActiveMDIChildWindow();

      if ( pChildWnd != nullptr )
      {
         pChildWnd->Show();
      }
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::MINIMIZE ) )
   {
      MDIChildWindow * pChildWnd = Desktop->GetActiveMDIChildWindow();

      if ( pChildWnd != nullptr )
      {
         pChildWnd->Show( Window::Mode::MINIMIZED );
      }
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::NEXT ) )
   {
      this->ActivateNextChildWindow();
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::PREVIOUS ) )
   {
      this->ActivatePreviousChildWindow();
      return;
   }
   /**/
   if ( strName.contains( Captions::Window::TABBED ) )
   {
      QMdiArea::ViewMode vmViewMode = Desktop->viewMode();
      MenuItemData * pTabDocViewMode = shared_ptr<Popup>( *this )->operator[]( strName );

      if ( vmViewMode == QMdiArea::TabbedView )
      {
         Desktop->setViewMode( QMdiArea::SubWindowView );
      }
      else
      {
         Desktop->setViewMode( QMdiArea::TabbedView );
      }
      /**/
      Desktop->setTabsClosable( vmViewMode == QMdiArea::TabbedView );
      /**/
      if ( pTabDocViewMode != nullptr )
      {
         QAction * p = pTabDocViewMode->ActionItem;
         /**/
         if ( p != nullptr )
         {
            p->setChecked( Desktop->viewMode() == QMdiArea::TabbedView );
         }
      }
      /**/
      UpdateAllMDIChildWindows();
      GetSettings()->setValue( RegKey::VIEWMODE, Desktop->viewMode() );
      return;
   }
   /**/
   if ( strName.contains( Captions::Style::PART ) )
   {
      this->SetChangeStyle( strName );
   }
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnCommand(bool const & bChecked, Action * pAc)
{
   if (Desktop != nullptr)
   {
      if (!Desktop->GetListMDIChildWindow().empty())
      {
         OnProcessInternalMDIChildWindowCommands(this, pAc->objectName());
      }
      else if(pAc->text().contains(Captions::Style::PART))
      {
         SetChangeStyle(pAc->objectName());
         return true;
      }
   }
   /**/
   return MainWindow::OnCommand(bChecked, pAc);
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnCreate(QWidget * pWnd)
{
   QStatusBar * pBar = statusBar();
   bool bStausBarIsVisible = Settings->value(RegKey::STATUSBAR, true).toBool();
   bool bToolBarIsVisible  = Settings->value(RegKey::TOOLBAR, true).toBool();
   /**/
   pBar->setVisible(bStausBarIsVisible);
   /**/
   if (GetToolBarHandle() != nullptr)
   {
      GetToolBarHandle()->setVisible(bToolBarIsVisible);
   }
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnClose(QWidget * pWnd)
{
   return MainWindow::OnClose(pWnd);
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnActivate(QWidget * pWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnDeactivate(QWidget * pWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnShowWindow(QWidget * pWnd, unsigned int const & uMode)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnUpdateUI(QWidget * pWnd, 
   MenuItemData * pUI, bool const & bEnabled)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnNotify(QObject * pWnd, unsigned long ulMsg, void const * pData)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIFrameWindow::OnTimer(QWidget * pWnd, std::Timer * pTimer)
{
   /* call via pplx */
   run_and_wait( [&]
   {
      EnableMDIActions( nullptr );
      OnNotify( this, WM_TIMER, Timer.get() );
   } );
   return true;
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::UpdateAllMDIChildWindows()
{
   QList<QMdiSubWindow *> q = Desktop->GetListMDIChildWindow();
   /**/
   std::for_each( q.begin(), q.end(), [&] ( QMdiSubWindow * p )
   {
      p->update();
   } );
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MDIFrameWindow::EnableMDIActions(std::MenuItems const * pItems)
{
   std::shared_ptr<QMutexLocker> pLocker(new QMutexLocker(&QMutex()));
   std::MenuItems * p = GetPopup()->FindPopup(std::Captions::Window::NAME);
   {
      /**/
      if ( p == nullptr )
      {
         return;
      }
      /**/
      if ( p->empty() )
      {
         return;
      }
   }
   /**/
   std::for_each( p->begin(), p->end(), [&] ( MenuItemData * d )
   {
      if ( !d->IsSeparator() )
      {
         int offset = Desktop->GetListMDIChildWindow().size();

         if ( offset == 0 && d->IsAction() )
            d->GetActionItem()->setEnabled( false );
         /**/
         if ( offset == 1 && d->IsAction() )
         {
            if ( d->GetCaption() != Captions::Window::NAME &&
               d->GetCaption() != Captions::Window::CLOSEALL &&
               d->GetCaption() != Captions::Window::NEXT &&
               d->GetCaption() != Captions::Window::PREVIOUS &&
               d->GetCaption() != Captions::Window::TILE )
            {
               d->GetActionItem()->setEnabled( true );
            }
            else
            {
               d->GetActionItem()->setEnabled( false );
            }
         }
         /**/
         if ( offset > 1 && d->IsAction() && d->GetCaption() != Captions::Window::NAME )
         {
            d->GetActionItem()->setEnabled( true );
         }
      }
   } );
   /**/
   Action * pCloseItem = operator[](std::Captions::File::CLOSE);
   {
      if (pCloseItem != nullptr)
      {
         pCloseItem->setEnabled(Desktop->GetListMDIChildWindow().count() != 0);
      }
   }
}
//-----------------------------------------------------------------------------------------------//
bool MDIFrameWindow::event(QEvent * e)
{
   QEvent::Type uId = e->type();

   if (uId == QEvent::Polish)
   {
      run_and_wait([&]
      {
         if (OnCreate(this))
         {
            e->accept();
         }
         else
         {
            e->ignore();
         }
      });
      return e->isAccepted();
   }
   else if(uId == QEvent::WindowActivate)
   {
      /* start timer */
      run_and_wait([&]
      {
         if (OnActivate(this))
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
   else if(uId == QEvent::WindowDeactivate)
   {
      /**/
      run_and_wait([&]
      {
         if (OnDeactivate(this))
         {
            e->accept();
            //m_Timer->stop();
         }
         else
         {
            e->ignore();
         }
      });
      /**/
      return e->isAccepted();
   }
   else if (uId == QEvent::MouseButtonPress || 
      uId == QEvent::MouseButtonRelease || 
      uId == QEvent::MouseButtonDblClick || 
      uId == QEvent::MouseMove ||
      uId == QEvent::MouseMove)
   {
      run_and_wait([&]
      { 
         if (OnNotify(this, WM_MOUSEACTIVATE, e))
         {
            e->accept();
         }
         else
         {
            e->ignore();
         }
      });
      return e->isAccepted();
   }
   return QMainWindow::event(e);
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindow::closeEvent(QCloseEvent * e)
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
void MDIFrameWindow::timerEvent(QTimerEvent * e)
{
   static bool s_bCalled = false;
#if(1)
   /* run by pplx background task group */
   if (e->timerId() == Timer->timerId() && !s_bCalled)
   {
      s_bCalled = !s_bCalled;
      /**/
      if ( !OnTimer ( this, Timer.get ( ) ) )
      {
         e->ignore();
      }
      else
      {
         e->accept();
      }
      /**/
      s_bCalled = !s_bCalled;
   }
#endif
}
//-----------------------------------------------------------------------------------------------//
