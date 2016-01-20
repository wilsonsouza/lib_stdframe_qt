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
#include <std.groupbox.hpp>
#include <std.layouts.hpp>
#include <std.treewidget.hpp>
#include <std.treewidgetitem.hpp>
#include <std.treeview.hpp>
//-----------------------------------------------------------------------------------------------//

namespace std
{
   //-----------------------------------------------------------------------------------------------//
   template <class T = std::TreeWidget, class L = std::VerticalBox> 
   class _DYNAMICLINK GroupBoxWidgetImpl: public GroupBox, public L
   {
   public:
      explicit GroupBoxWidgetImpl(std::ustring const & strCaption);
      virtual ~GroupBoxWidgetImpl(){}

      DECLARE_OPERATOR(GroupBoxWidgetImpl)
   public:
      CREATE_PROPERTY_READONLY(T *, m_p, Control)
   };
   //-----------------------------------------------------------------------------------------------//
   template <class T, class L> inline
   GroupBoxWidgetImpl<T, L>::GroupBoxWidgetImpl(std::ustring const & strCaption):
   GroupBox(strCaption, nullptr),
   L(this)
   {
      Name = ClassName;
      addWidget(m_pControl = new T());
   }
   //-----------------------------------------------------------------------------------------------//
};