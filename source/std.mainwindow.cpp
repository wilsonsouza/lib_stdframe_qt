//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.defs.hpp>
#include <std.application.hpp>
#include <sql.query.hpp>
#include <std.menu.hpp>
#include <std.mainwindow.hpp>
#include <std.dialogex.hpp>
#include <std.toolbar.hpp>
#include <std.menubar.hpp>
#include <std.statusbar.hpp>
#include <std.captions.hpp>
#include <std.aboutdialog.hpp>
#include <std.popup.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MainWindow::MainWindow(QWidget * pOwner, std::ustring const & szName, Qt::WindowFlags wfflags):
IMainWindowImpl(pOwner, szName, wfflags)
{
   SetApplicationHandle(static_cast<std::Application *>(QCoreApplication::instance()));
   /**/
   if ( m_ApplicationHandle->organizationName().isEmpty() )
   {
      m_ApplicationHandle->setOrganizationName( std::Names::COMPANY );
   }
   /**/
   m_ApplicationHandle->setOrganizationDomain(std::Names::COPYRIGHT);
   /**/
   SetMode(SW_NORMAL);
   SetTerminated(false);
   SetToolBarHandle(nullptr);
   SetPrinter(new QPrinter());
   SetSettings(shared_ptr<QSettings>(new QSettings
   {
      m_ApplicationHandle->organizationName(), m_ApplicationHandle->applicationName(), this
   }));
   SetStyles(MapperStyles(new AllocMapperStyles()));
   /**/
   m_Styles->operator[](Captions::Style::FUSION) = Styles::FUSION;
   m_Styles->operator[](Captions::Style::WINDOWS) = Styles::WINDOWS;
   m_Styles->operator[](Captions::Style::XP) = Styles::WINDOWSXP;
   m_Styles->operator[](Captions::Style::MACINTOSH) = Styles::MACINTOSH;
   /**/
   m_szStyleName = m_Settings->value(RegKey::STYLES, Styles::WINDOWS).toString();
   /**/
   std::IteratorMapperStyles p = m_Styles->find(m_szStyleName);
   {
      /**/
      if ( p != m_Styles->end() )
      {
         QApplication::setStyle( p.value() );
      }
   }
   /**/
   /**/
   //connect(this, &QMainWindow::iconSizeChanged,[=](const QSize & isChanged)
   //{
   //   //resend signal to
   //   //WM_ICONSIZECHANGED
   //   run([this, &isChanged]
   //   {
   //      OnNotify(this, WM_ICONSIZECHANGED, (void *)(&isChanged));
   //   });
   //});
   //connect(this, &QMainWindow::toolButtonStyleChanged,[=](Qt::ToolButtonStyle tbStyle)
   //{
   //   //resend signal to
   //   //WM_TOOLBUTTONSTYLECHANGED
   //   run([this, &tbStyle]
   //   {
   //      OnNotify(this, WM_TOOLBUTTONSTYLECHANGED, (void *)(&tbStyle));
   //   });
   //});
}
//-----------------------------------------------------------------------------------------------//
MainWindow::~MainWindow()
{
   disconnect();
   cancel();
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::CreateDock(std::ustring const & strdockName, DockWindow * pDock)
{
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::CreateToolBar(ToolBarItems * pItems, std::ustring const & strName)
{
   if(GetToolBarHandle() == nullptr)
   {
      SetToolBarHandle(new ToolBar(GetName(), this, strName));

      if ( strName.isEmpty() )
      {
         GetToolBarHandle()->SetName( m_ToolBarHandle->GetClassName() );
      }
      /**/
      GetToolBarHandle()->Create(pItems);
      addToolBar(GetToolBarHandle());
   }
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::CreateToolBar(Popup * pHandle)
{
   ToolBarItems * pItems = new ToolBarItems(pHandle->GetCaption());
   {
      std::for_each( pHandle->begin(), pHandle->end(), [&]( MenuItems * m )
      {
         std::for_each( m->begin(), m->end(), [&]( MenuItemData * d )
         {
            if ( !d->GetIcon()->isNull() )
            {
               pItems->operator+( d );
            }
         } );
      } );

      //Create ToolBar
      if ( pItems->count() )
      {
         CreateToolBar( pItems, pItems->GetCaption() );
      }
   }
}
//-----------------------------------------------------------------------------------------------//
QMenu * __stdcall MainWindow::CreatePopup(MenuItems * pItems, QMenuBar * pRoot)
{
   QMenu * pMenu = new QMenu(pItems->Caption, pRoot);
   {
      pMenu->setObjectName(pItems->Caption);
      /**/
      std::for_each( pItems->begin(), pItems->end(), [&]( MenuItemData * d )
      {
         if ( d->IsSeparator() )
         {
            d->ActionItem = pMenu->addSeparator();
         }
         else
         {
            if (d->IsSubMenu())
            {
               QMenu * pSub = CreateSubPopup(d);

               if (pSub)
               {
                  pMenu->addMenu(pSub);
               }
            }
            else
            {
               SetPopupAction(d, pMenu);
            }
         }
      } );
      /**/
      pRoot->addMenu(pMenu);
   }
   return pMenu;
}
//-----------------------------------------------------------------------------------------------//
QMenu * __stdcall MainWindow::CreateSubPopup(MenuItemData * pItemData)
{
   if ( pItemData->SubMenuItem->empty() )
   {
      return nullptr;
   }
   /**/
   QMenu * pMenu{ new QMenu(pItemData->Caption) };
   /**/
   std::for_each( pItemData->SubMenuItem->begin(), pItemData->SubMenuItem->end(), [&]( MenuItemData * d )
   {
      if ( d->IsSeparator() )
      {
         d->ActionItem = pMenu->addSeparator();
      }
      else
      {
         if (d->SubMenuItem->count() > 0)
         {
            QMenu * pSub = CreateSubPopup(d);
            /**/
            if ( pSub )
            {
               pMenu->addMenu( pSub );
            }
         }
         else
         {
            SetPopupAction(d, pMenu);
         }
      }
   } );
   return pMenu;
}
//-----------------------------------------------------------------------------------------------//
void __stdcall MainWindow::SetPopupAction(MenuItemData * pItemData, QMenu * pMenu)
{
   MenuItemData * d = pItemData;
   {
      QAction * p = pMenu->addAction( d->Caption );
      {
         d->ActionItem = p;
      }
      /**/
      if ( !d->Icon->isNull() )
      {
         d->ActionItem->setIcon( d->Icon.operator*( ) );
      }
      /**/
      d->ActionItem->setChecked(d->Checked);
      d->ActionItem->setEnabled(d->Enabled);
      d->ActionItem->setObjectName(d->Caption);
      d->ActionItem->setIconVisibleInMenu(true);
      /**/
      QObject::connect(p, &QAction::triggered, [=](bool bChecked)
      {
         //call by pplx
         OnCommand(bChecked, reinterpret_cast<Action *>(p));
      });
      /**/
      if ( d->Caption.contains( Captions::Help::ABOUT ) )
      {
         d->ActionItem->setText(d->Caption.arg(m_ApplicationHandle->applicationName()));
         d->ActionItem->setIcon(m_ApplicationHandle->windowIcon());
         d->Icon->swap(d->ActionItem->icon());
         d->ActionItem->setEnabled(true);
         return;
      }
      /**/
      if ( d->Caption.contains( Captions::View::STATUSBAR ) || d->Caption.contains( Captions::View::TOOLBAR ) )
      {
         d->ActionItem->setEnabled(true);
         return;
      }
   }
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::CreateMenuBar(Popup * pHandle, Action * pAction, std::ustring const & szName)
{
   QMenuBar * pRoot{ menuBar() };
   {
      /* call by pplx */
      std::for_each( pHandle->begin(), pHandle->end(), [&] ( MenuItems * p )
      {
         CreatePopup( p, pRoot );
      } );
      /**/
      setMenuBar(pRoot);
   }
}
//-----------------------------------------------------------------------------------------------//
std::shared_ptr<Popup> const & __fastcall MainWindow::GetPopup() const
{
   return *this;
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::Update()
{
   /* run in background mode */
   Show(m_Mode); 
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::Show(unsigned int uMode)
{
   /* notify show window command and decision */
   if (!OnShow(this, uMode))
   {
      return;
   }
   /**/
   if (uMode != m_Mode)
   {
      m_Mode = uMode;
   }
   /**/
   if (uMode == Window::Mode::HIDE)
   {
      hide();
      return;
   }
   /**/
   if (uMode == Window::Mode::MAXIMIZED)
   {
      showMaximized();
      return;
   }
   /**/
   if (uMode == Window::Mode::MINIMIZED)
   {
      showMinimized();
      return;
   }
   /**/
   if (uMode == Window::Mode::NORMAL)
   {
      show();
      return;
   }
}
//-----------------------------------------------------------------------------------------------//
void const    __fastcall MainWindow::Close()
{
   m_Settings->setValue(RegKey::STYLES, m_szStyleName);
   /*cancel all task in pplx running*/
   if ( QMainWindow::close() )
   {
      cancel();
      Terminated = true;
   }
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::SetChangeStyle(std::ustring const & strStyle)
{
#if(QT_VERSION < 0x050000)
   if(strStyle == Captions::style::CDE)
      return qapplication::setStyle(new qcdestyle);

#if defined(OS_MAC)
   if(strStyle == Captions::style::MACINTOSH)
      qapplication::setStyle(new qmacstyle);
#endif

   if(strStyle == Captions::style::MOTIF)
      qapplication::setStyle(new qmotifstyle);

   if(strStyle == Captions::style::PLASTIQUE)
      qapplication::setStyle(new qplastiquestyle);

   if(strStyle == Captions::style::VISTA)
      qapplication::setStyle(new qwindowsvistastyle);

   if(strStyle == Captions::style::WINDOWS)
      qapplication::setStyle(new qwindowsstyle);

   if(strStyle == Captions::style::XP)
      qapplication::setStyle(new qwindowsxpstyle);
#else
   /**/
   std::IteratorMapperStyles p = m_Styles->find(strStyle);
   /**/
   if(p != m_Styles->end())
   {
      QApplication::setStyle(p.value());
      m_szStyleName = p.key();
   }
#if(0)
   if(strStyle == Captions::Style::WINDOWS)
      QApplication::setStyle(Styles::WINDOWS);

   if(strStyle == Captions::Style::FUSION)
      QApplication::setStyle(Styles::FUSION);

   if(strStyle == Captions::Style::XP)
      QApplication::setStyle(Styles::WINDOWSXP);

   if(strStyle == Captions::Style::MACINTOSH)
      QApplication::setStyle(Styles::MACINTOSH);
#endif
#endif
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::UpdateProcess()
{
   qApp->processEvents();
}
//-----------------------------------------------------------------------------------------------//
Widget * __fastcall MainWindow::FindChildWindow(std::ustring const & strName)
{
   Widget * pWnd = reinterpret_cast<Widget *>(findChild<QWidget *>(strName));
   {
      if ( pWnd )
      {
         return pWnd;
      }
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
void const MainWindow::EnableMenuItem(std::ustring const & strName, bool const & bEnabled)
{
   if(shared_ptr<Popup>(*this)->count())
   {
      MenuItemData * p = shared_ptr<Popup>(*this)->operator[](strName);

      if(p)
      {
         p->GetActionItem()->setEnabled(bEnabled);
         OnUpdateUI(this, p, bEnabled);
      }
   }
}
//-----------------------------------------------------------------------------------------------//
void const MainWindow::EnableMenuItem(StringList const & lNames, bool const & bEnabled)
{
   std::for_each( lNames.cbegin(), lNames.cend(), [&] ( std::ustring s )
   { 
      EnableMenuItem( s, bEnabled );
   } );
}
//-----------------------------------------------------------------------------------------------//
bool const MainWindow::IsMenuItemEnabled(std::ustring const & strName) const
{
   MenuItemData * d = std::shared_ptr<Popup>(*this)->operator[](strName);
   {
      if ( d )
      {
         return d->GetActionItem()->isEnabled();
      }
   }
   return false;
}
//-----------------------------------------------------------------------------------------------//
Action * MainWindow::operator[](std::ustring const & Name) const
{
   MenuItemData * d = std::shared_ptr<Popup>(*this)->operator[](Name);
   {
      if ( d )
      {
         return reinterpret_cast< Action * >( d->GetActionItem() );
      }
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MainWindow::DispatchEventLooper( bool const & bAll )
{
   if ( bAll )
   {
      qApp->processEvents( QEventLoop::AllEvents );
   }
   else
   {
      qApp->processEvents( QEventLoop::ExcludeUserInputEvents );
   }
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MainWindow::OnCommand(bool const & bChecked, Action * pAc)
{
   ustring szCaption = pAc->objectName();
   /**/
   if(szCaption == Captions::View::STATUSBAR)
   {
      QStatusBar * s = statusBar();
      bool bVisible = s->isVisible();
      /**/
      s->setVisible(!bVisible);
      pAc->setChecked(!bVisible);
      m_Settings->setValue(RegKey::STATUSBAR, !bVisible);
      return true;
   }
   /**/
   if(szCaption == Captions::View::TOOLBAR)
   {
      bool bVisible;
      QToolBar * t = GetToolBarHandle();

      if (t != nullptr)
      {
         bool bVisible = t->isVisible();
         /**/
         t->setVisible(!bVisible);
         pAc->setChecked(!bVisible);
         m_Settings->setValue(RegKey::TOOLBAR, !bVisible);
      }
      return true;
   }
   /**/
   if(szCaption.contains(Captions::Help::ABOUT))
   {
      /* new c++ supported */
      std::shared_ptr<std::AboutDialog> pDlg(new std::AboutDialog
      {
         this, qApp->applicationDisplayName()
      });
      pDlg->DoModal();
      return true;
   }
   /**/
   return false;
}
//-----------------------------------------------------------------------------------------------//
bool MainWindow::event(QEvent * e)
{
   int n = e->type();
   /**/
   if (n == QEvent::WindowIconChange)
   {
      run_and_wait([&]
      {
         QSize s = iconSize();
         /**/
         if ( OnNotify( this, WM_ICONSIZECHANGED, &s ) )
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
   else if (n == QEvent::ApplicationWindowIconChange)
   {
      run_and_wait([&]
      {
         QIcon i = qApp->windowIcon();
         /**/
         if ( OnNotify( this, WM_GETICON, &i ) )
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
   else if (n == QEvent::Close)
   {
      run_and_wait([&]
      {
         if ( OnClose( this ) )
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
bool const __fastcall MainWindow::OnCreate(QWidget * pWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MainWindow::OnClose(QWidget * pWnd)
{
   /* cancel pplx task group */
   cancel();
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MainWindow::OnActivate(QWidget * pWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MainWindow::OnDeactivate(QWidget * pWnd)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MainWindow::OnShow(QWidget * pWnd, unsigned int const & uMode)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MainWindow::OnUpdateUI(QWidget * pWnd, 
   MenuItemData * pUI, bool const & bEnabled)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MainWindow::OnNotify(QObject * pWnd, unsigned long ulMsg, void const * pData)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
Action * MainWindow::FindMenuItem(std::ustring const & strName) const
{
   return MainWindow::operator[](strName);
}
//-----------------------------------------------------------------------------------------------//
