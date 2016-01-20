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
#include <std.action.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK TableDelegate: public Action
   {
      Q_OBJECT
   public:
      TableDelegate(QWidget * pOwner);
      virtual ~TableDelegate();
      DECLARE_OPERATOR(TableDelegate)
   public slots:
      virtual void const OnCommand(bool const & bChecked, Action * Sender);
   };
};