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
   class _DYNAMICLINK MDIFrameWindowArea: public QMdiArea, public task_group
   {
      //Q_OBJECT
   public:
      MDIFrameWindowArea(QWidget * pOwner = nullptr, std::ustring const & strName = "");
      virtual ~MDIFrameWindowArea();
      virtual void AddScrollBar(QWidget * pScrollbar, Qt::Alignment Align);

      virtual QList<QMdiSubWindow *> __fastcall GetListMDIChildWindow() const;
      virtual MDIChildWindow *   __fastcall GetActiveMDIChildWindow() const;

      //operators
      virtual MDIChildWindow *    __fastcall operator[](unsigned int uIndex);
      virtual MDIChildWindow *    __fastcall operator[](std::ustring const & strName);

      DECLARE_OPERATOR(MDIFrameWindowArea);
      DECLARE_PROPERTYS(0);
      set_property(std::MDIFrameWindow *, FrameWindow);
   protected:
      virtual bool event(QEvent * e);
      virtual void childEvent(QChildEvent * e);
   };
   //-----------------------------------------------------------------------------------------------//
};