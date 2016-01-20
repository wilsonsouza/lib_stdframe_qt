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
//-----------------------------------------------------------------------------------------------//
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK MainWindow;
   class _DYNAMICLINK MDIFrameWindow;
   class _DYNAMICLINK Popup;
   class _DYNAMICLINK Action;
   class _DYNAMICLINK Menu;
   class _DYNAMICLINK MenuBar: public QMenuBar
   {
      Q_OBJECT
      friend class MainWindow;
      friend class MDIFrameWindow;
      friend class Menu;
   public:
      MenuBar(QWidget * pOwner = nullptr, std::ustring const & strName = std::ustring());
      virtual ~MenuBar();
      void const __fastcall Create(Popup const & pp, Action * Sender);
      Action * __fastcall operator [](std::ustring strID);

      //set
      virtual void const SetEnable(std::ustring const & strID, bool bEnabled);
      virtual bool GetEnabled(std::ustring const & strID);
      virtual void const EnabledMDIActions(MDIFrameWindow * pWnd);
      MainWindow * GetMainWindow() const;

      DECLARE_OPERATOR(MenuBar);
   signals:
      void  OnHovered(Action * Action, MenuBar * Sender);
      void  OnCommand(Action * Action, MenuBar * Sender);
   protected:
      virtual void focusInEvent(QFocusEvent * pFocusEvent);
      virtual void SetNotifyEverthing();
   };
};