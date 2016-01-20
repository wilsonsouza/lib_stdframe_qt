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
#include <std.action.hpp>
#include <std.tabbeddefs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK TabbedDelegate: public Action
   {
      Q_OBJECT
   public:
      TabbedDelegate(QTabWidget * pTabbed);
      virtual void const OnCommand(bool const & bChecked, Action * Sender);
      DECLARE_OPERATOR(TabbedDelegate);
   };
};