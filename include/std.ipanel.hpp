//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2015
//
// Dedalus Prime
// (c) 2015
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.widget.hpp>
#include <std.layouts.hpp>

namespace std
{
   class Q_DECL_EXPORT IPanel : public Widget
   {
   public:
      IPanel(QWidget * pOwner, ustring const & szName);
      virtual ~IPanel();
      virtual IPanel * Create();
      /**/
      virtual bool OnNotify(QWidget * pOwner, QEvent * pEvent, void const * pData) = 0;
   };
}
