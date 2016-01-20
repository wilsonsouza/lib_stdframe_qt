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
#include <std.widget.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   template <typename T = QVBoxLayout>
   class _DYNAMICLINK WidgetImpl: virtual public Widget, virtual public T
   {
   public:
      explicit WidgetImpl(QWidget * pOwner = nullptr, std::ustring const & strName = std::ustring());
      virtual ~ WidgetImpl();
      virtual void addLabel(QWidget * pLabel, QWidget * pOwner);
      DECLARE_OPERATOR(WidgetImpl)
   };
   //-----------------------------------------------------------------------------------------------//
   template <class T> WidgetImpl<T>::WidgetImpl(QWidget * pOwner, std::ustring const & strName):
   Widget(pOwner, 0),
   T(this)
   {
      SetName(strName);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T> WidgetImpl<T>::~WidgetImpl()
   {
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T> void WidgetImpl<T>::addLabel(QWidget * pLabel, QWidget * pOwner)
   {
      addWidget(pLabel);
      addWidget(pOwner);
   }
   //-----------------------------------------------------------------------------------------------//
};