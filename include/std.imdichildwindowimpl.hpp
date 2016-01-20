//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2015
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defsx.hpp>
#include <std.widgetimpl.hpp>
#include <std.icons.hpp>
//-----------------------------------------------------------------------------------------------//
namespace sql
{
   class _DYNAMICLINK Query;
   class _DYNAMICLINK Table;
};
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK MDIChildWindow;
   class _DYNAMICLINK IMDIChildWindowImpl: 
      public QMdiSubWindow, public task_group
   {
   public:
      explicit IMDIChildWindowImpl(QWidget * pOwner,
         ustring const & szName = ustring(), Qt::WindowFlags f = 0) :
         QMdiSubWindow(pOwner, f)
      {
         SetName(szName);
      }
      virtual ~IMDIChildWindowImpl(){}
      virtual void const __fastcall Close() = 0;

      DECLARE_PROPERTYS(1);                                                  
      DECLARE_OPERATOR(IMDIChildWindowImpl);
      set_property(shared_ptr<IconsImplEx<>>, IconsList);
   private:
      virtual bool const __fastcall OnCreate(MDIChildWindow * pWnd) = 0;
      virtual bool const __fastcall OnClose(MDIChildWindow * pWnd) = 0;
      virtual bool const __fastcall OnActivate(MDIChildWindow * pWnd) = 0;
      virtual bool const __fastcall OnDeactivate(MDIChildWindow * pWnd) = 0;
      virtual bool const __fastcall OnShow(MDIChildWindow * pWnd, unsigned int const & uMode) = 0;
      virtual bool const __fastcall OnContextMenuRequested(QPoint const & p, MDIChildWindow * pWnd) = 0;
      virtual bool const __fastcall OnWindowStateChanged(MDIChildWindow * pWnd, Qt::WindowStates wsOld, Qt::WindowStates wsNew) = 0;
      virtual bool const __fastcall OnNotify(MDIChildWindow * pWnd, long lMsg, void const * pMsg) = 0;
   };
};