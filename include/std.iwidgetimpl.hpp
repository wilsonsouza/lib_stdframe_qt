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
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Menu;
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK IWidgetImpl : public QWidget
   {
   public:
      explicit IWidgetImpl(QWidget * pOwner = nullptr, ustring const & szName = ustring(),
         Qt::WindowFlags f = 0) :QWidget(pOwner, f)
      {
         SetName(szName);
      }
      virtual ~IWidgetImpl(){}
      /**/
      DECLARE_OPERATOR(IWidgetImpl);
      virtual void OnContextMenuRequested(QPoint const & p, IWidgetImpl * lpOwner) = 0;
   };
};