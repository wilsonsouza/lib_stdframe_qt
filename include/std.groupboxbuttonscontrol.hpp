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
#include <std.widgetimpl.hpp>
#include <std.groupboximpl.hpp>
#include <std.button.hpp>
#include <std.icons.hpp>
#include <std.layouts.hpp>
#include <map>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK GroupBoxButtonsControl: 
      virtual public GroupBoxImpl<VerticalBox>
   {
   public:
      explicit GroupBoxButtonsControl(std::ustring const & szCaption, 
         int const & nCols, 
         int const & nOffset);
      virtual ~GroupBoxButtonsControl();
      Button * GetButton(int const nId);
      virtual GroupBoxButtonsControl * Create();
      /**/
      typedef map<int, Button *> map_buttons;
      set_property(int, Cols);
      set_property(int, Offset);
      set_property(shared_ptr<map_buttons>, Queue);
      set_property(int, FontSize);
      set_property(unsigned int, FontStyle);
      set_property(shared_ptr<QPoint>, ButtonSize);
   };
};
//-----------------------------------------------------------------------------------------------//
