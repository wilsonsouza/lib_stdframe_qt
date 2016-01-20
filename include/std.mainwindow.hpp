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
#include <std.defsx.hpp>
#include <QtPrintSupport\qtprintsupport>
#include <std.imainwindowimpl.hpp>
//-----------------------------------------------------------------------------------------------//
namespace sql
{
   class _DYNAMICLINK Query;
};
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace Names
   {
      static std::ustring const COMPANY = std::ustring("WR Devinfo");
      static std::ustring const COPYRIGHT = std::ustring("Copyright (C) %1 %2").arg(QDate().year()).arg(COMPANY);
   }

   namespace RegKey
   {
      static std::ustring const KEY       = std::ustring("Widgets");
      static std::ustring const STATUSBAR = KEY + "/StatusBar";
      static std::ustring const TOOLBAR   = KEY + "/ToolBar";
      static std::ustring const MenuBar   = KEY + "/MainMenuBar";
      static std::ustring const STYLES    = "Styles";
      static std::ustring const VIEWMODE  = KEY + "/ViewMode";
   };

   typedef std::shared_ptr<QMap<std::ustring, std::ustring>> MapperStyles; //mapper_styles
   typedef QMap<std::ustring, std::ustring>::Iterator IteratorMapperStyles;//iterator_mapper_styles
   typedef QMap<std::ustring, std::ustring> AllocMapperStyles; //alloc_mapper_styles->allocmapperstyles()
   //-----------------------------------------------------------------------------------------------//
   //class
   class _DYNAMICLINK Application;
   class _DYNAMICLINK MDIFrameWindow;
   class _DYNAMICLINK MDIChildWindow;
   class _DYNAMICLINK ToolBar;
   class _DYNAMICLINK StatusBar;
   class _DYNAMICLINK ToolBarItems;
   class _DYNAMICLINK StatusBarItems;
   class _DYNAMICLINK DockWindow;
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK MainWindow : public IMainWindowImpl
   {
      //Q_OBJECT
   public:
      friend class MDIChildWindow;
      friend class MenuBar;
      friend class StatusBar;
      friend class ToolBar;
      friend class Menu;
      friend class QApplication;
      friend class Application;

      struct StyleData
      {
         std::qstring strNewStyle;
         void * pOldStyle;

         StyleData()
         {
            strNewStyle = std::qstring();
            pOldStyle   = nullptr;
         }
         StyleData(std::qstring const & strNewStyle, void const * pOldStyle)
         {
            this->strNewStyle = const_cast<std::qstring &>(strNewStyle);
            this->pOldStyle   = const_cast<void *>(pOldStyle);
         }
         virtual ~StyleData()
         {
         }
      };
   public:
      MainWindow(QWidget * pOwner = nullptr, 
         std::ustring const & szName = std::ustring(), 
         Qt::WindowFlags wfflags = 0);
      virtual ~MainWindow();

      virtual void const __fastcall CreateDock(std::ustring const & strdockName = std::ustring(),
                                               DockWindow * pDock = nullptr);
      virtual void const __fastcall CreateToolBar(ToolBarItems * pItems,
                                                  std::ustring const & strName = std::ustring());
      virtual void const __fastcall CreateToolBar(Popup * pHandle);
      virtual void const __fastcall CreateMenuBar(Popup * pHandle,
                                                  Action * Sender,
                                                  std::ustring const & strName = std::ustring());
      //process event on queue
      virtual void const __fastcall UpdateProcess();

      //abstract method to sql handle
      virtual std::shared_ptr<sql::Query> & __fastcall GetSingleQueryLanguageHandle() = 0;

      // methods
      std::shared_ptr<Popup> const & __fastcall GetPopup() const;
      void const  __fastcall Update();
      void const  __fastcall Show(unsigned int uMode = Window::Mode::MAXIMIZED);
      void const  __fastcall Close();
      void const  __fastcall SetChangeStyle(std::ustring const & strStyle);
      Widget *    __fastcall FindChildWindow(std::ustring const & strName);

      //to MenuBar
      virtual void const EnableMenuItem(std::ustring const & strName, bool const & bEnabled);
      virtual void const EnableMenuItem(StringList const & strListNames, bool const & bEnabled);
      virtual bool const IsMenuItemEnabled(std::ustring const & strName) const;
      virtual Action * operator[](std::ustring const & strName) const;
      virtual Action * FindMenuItem(std::ustring const & strName) const;
      virtual void const __fastcall DispatchEventLooper(bool const & bAll = false);

      //propertys
      DECLARE_PROPERTYS(1)
      DECLARE_OPERATOR(MainWindow)

   public:
      virtual bool const __fastcall OnCommand(bool const & bChecked, Action * pAction);
      virtual bool const __fastcall OnCreate(QWidget * pWnd);
      virtual bool const __fastcall OnClose(QWidget * pWnd);
      virtual bool const __fastcall OnActivate(QWidget * pWnd);
      virtual bool const __fastcall OnDeactivate(QWidget * pWnd);
      virtual bool const __fastcall OnShow(QWidget * pWnd, unsigned int const & uMode);
      virtual bool const __fastcall OnUpdateUI(QWidget * pWnd, MenuItemData * pUI, bool const & bEnabled);
      virtual bool const __fastcall OnNotify(QObject * pWnd, unsigned long ulMsg, void const * pData);
      /**/
      set_property(shared_ptr<QSettings>, Settings);
      set_property(ToolBar *, ToolBarHandle);
      set_property(Application *, ApplicationHandle);
      set_property(bool, Terminated);
      set_property(unsigned int, Mode);
      set_property(QPrinter *, Printer);
      set_property(MapperStyles, Styles);
   protected:
      virtual bool event(QEvent * e);
      virtual QMenu * __stdcall CreatePopup(MenuItems * pItems, QMenuBar * pRoot);
      virtual QMenu * __stdcall CreateSubPopup(MenuItemData * pItemData);
      virtual void    __stdcall SetPopupAction(MenuItemData * pItemData, QMenu * pMenu);

signals:
      void OnPageSetup(QPageSetupDialog * pDlg, MainWindow * pWnd);
      void OnPrinterSetup(QPrintDialog * pDlg, MainWindow * pWnd);
      void OnPrintView(QPrintPreviewDialog * pDlg, MainWindow * pWnd);
      void OnPrint(QPrintDialog * pDlg, MainWindow * pWnd);

   private:
      ustring m_szStyleName;
   };
};
//-----------------------------------------------------------------------------------------------//