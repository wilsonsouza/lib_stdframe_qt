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
#include <std.iwidgetimpl.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Widget : public IWidgetImpl
   {
   public:
      explicit Widget(QWidget * lpOwner = nullptr, Qt::WindowFlags f = 0);
      virtual ~Widget();
      operator QWidget *();
      //-----------------------------------------------------------------------------------------------//
      DECLARE_OPERATOR(Widget);
      set_property(std::Menu *, Menu);
      virtual void OnContextMenuRequested(QPoint const & point, IWidgetImpl * lpOwner);
   protected:
      virtual void mousePressEvent(QMouseEvent * e);
   };
};