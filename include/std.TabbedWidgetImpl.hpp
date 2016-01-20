//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.layouts.hpp>
#include <std.treewidget.hpp>
#include <std.treewidgetitem.hpp>
#include <std.treeview.hpp>
//-----------------------------------------------------------------------------------------------//

namespace std
{
   //-----------------------------------------------------------------------------------------------//
   template <class T = std::TreeWidget>
   class _DYNAMICLINK TabbedWidgetImpl: public Tabbed
   {
   public:
      explicit TabbedWidgetImpl(std::ustring const & strCaption) :Tabbed(nullptr)
      {
         SetName(strCaption);
         addTab(m_Control = new T(), strCaption);
      }
      virtual ~TabbedWidgetImpl(){}

      DECLARE_OPERATOR(TabbedWidgetImpl);
      CREATE_PROPERTY_READONLY(T *, m_p, Control);
   };
};