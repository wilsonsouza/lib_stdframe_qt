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
#include <std.mainwindow.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK MDIChildWindow;
   class _DYNAMICLINK MDIFrameWindowArea;
   class _DYNAMICLINK Timer;
   class _DYNAMICLINK MDIFrameWindow: public MainWindow
   {
      //Q_OBJECT
   public:
      explicit MDIFrameWindow(QWidget * pOwner, 
         std::Application * pApplication, 
         std::ustring const strName = std::ustring(), 
         Qt::WindowFlags wfflags = 0);
      virtual ~MDIFrameWindow();

      //child window controls
      virtual void ActivateNextChildWindow();
      virtual void ActivatePreviousChildWindow();
      virtual void Cascade();
      virtual void CloseActiveChildWindow();
      virtual void CloseAllChildWindows();
      virtual void SetActiveMDIChildWindow(MDIChildWindow * pChildWnd);
      virtual void Tile();
      virtual void OnProcessInternalMDIChildWindowCommands(MainWindow * pWnd, std::ustring const & strmdid);
      virtual void UpdateAllMDIChildWindows();

      virtual bool const __fastcall IsMDIChildWindowExists(std::ustring const & strName);
      virtual void const __fastcall EnableMDIActions(std::MenuItems const * pItems);

      DECLARE_OPERATOR(MDIFrameWindow);
   public:
      virtual bool const __fastcall OnCreate(QWidget * pWnd);
      virtual bool const __fastcall OnClose(QWidget * pWnd);
      virtual bool const __fastcall OnActivate(QWidget * pWnd);
      virtual bool const __fastcall OnDeactivate(QWidget * pWnd);
      virtual bool const __fastcall OnShowWindow(QWidget * pWnd, unsigned int const & uMode);
      virtual bool const __fastcall OnUpdateUI(QWidget * pWnd, MenuItemData * pUI, bool const & bEnabled);
      virtual bool const __fastcall OnNotify(QObject * pWnd, unsigned long ulMsg, void const * pData);
      virtual bool const __fastcall OnCommand(bool const & bChecked, Action * pAc);
      virtual bool const __fastcall OnTimer(QWidget * pWnd, std::Timer * pTimer);

   protected:
      virtual bool event(QEvent * e);
      virtual void timerEvent(QTimerEvent * e);
      virtual void closeEvent(QCloseEvent * e);

      CREATE_PROPERTY_READONLY(std::MDIFrameWindowArea *, m_p, Desktop)
      CREATE_PROPERTY_READONLY(shared_ptr<std::Timer>, m_p, Timer)
      CREATE_PROPERTY_READONLY(std::Application *, m_p, MainApplication)
   };
};