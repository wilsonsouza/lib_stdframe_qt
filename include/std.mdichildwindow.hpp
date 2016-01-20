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
#include <std.imdichildwindowimpl.hpp>
//-----------------------------------------------------------------------------------------------//
namespace sql
{
   class _DYNAMICLINK Query;
   class _DYNAMICLINK Table;
};
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class Timer;
   class _DYNAMICLINK MDIChildWindow : public IMDIChildWindowImpl
   {
   public:
      friend class MDIFrameWindow;
      friend class MenuBar;
      friend class Menu;
      friend class ToolBar;
      friend class Action;
   public:
      explicit MDIChildWindow(QWidget * pOwner, std::ustring const & szName = std::ustring(), Qt::WindowFlags wfflags = 0);
      virtual ~MDIChildWindow();

      virtual void const __fastcall Update();
      virtual void const __fastcall Show(unsigned int uMode = Window::Mode::MAXIMIZED);
      virtual void const __fastcall Close();
      virtual void const __fastcall SetWidget(QWidget * pOwner = nullptr);

      //virtual methods
      virtual bool const __fastcall OnCreate(MDIChildWindow * pWnd);
      virtual bool const __fastcall OnClose(MDIChildWindow * pWnd);
      virtual bool const __fastcall OnActivate(MDIChildWindow * pChildWnd);
      virtual bool const __fastcall OnDeactivate(MDIChildWindow * pChildWnd);
      virtual bool const __fastcall OnShow(MDIChildWindow * pChildWnd, 
         unsigned int const & uMode);
      virtual bool const __fastcall OnContextMenuRequested(QPoint const & p, MDIChildWindow * pChildWnd);
      virtual bool const __fastcall OnWindowStateChanged(MDIChildWindow * pChildWnd, 
         Qt::WindowStates wsOld, Qt::WindowStates wsNew);
      virtual bool const __fastcall OnNotify(MDIChildWindow * pWnd, long lMsg, void const * pMsg);

      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(MDIChildWindow);

      //local propertys
      __declspec(property(get=GetSQLHandle)) std::shared_ptr<sql::Query> & SingleQueryLanguageHandle;

   protected: //reimplement events method
      virtual bool event(QEvent * e);
      virtual void timerEvent(QTimerEvent * e);
      virtual void closeEvent(QCloseEvent * e);
      virtual void contextMenuEvent(QContextMenuEvent * e);

   protected:
      std::shared_ptr<sql::Query> & GetSQLHandle() const;

      CREATE_PROPERTY_READWRITE( MDIFrameWindow *, m_p, MDIFrameWindow *, FrameWindow, MDIFrameWindow * );
      CREATE_PROPERTY_READONLY( unsigned int, m_u, Mode );
      CREATE_PROPERTY_READWRITE( bool, m_b, bool const &, Terminated, bool const & );
      CREATE_PROPERTY_READONLY( WidgetImpl<> *, m_pw, VerticalBox );
      CREATE_PROPERTY_READONLY( WidgetImpl<QHBoxLayout> *, m_pw, HorizontalBox );
      CREATE_PROPERTY_READONLY( WidgetImpl<QFormLayout> *, m_pw, FormBox );
      CREATE_PROPERTY_READONLY( WidgetImpl<QGridLayout> *, m_pw, GridBox );
      set_property( shared_ptr<Timer>, Timer );
   };
};