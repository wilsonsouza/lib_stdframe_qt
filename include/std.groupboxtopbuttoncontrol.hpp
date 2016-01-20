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
#include <std.defsx.hpp>
#include <std.widget.hpp>
#include <std.groupboximpl.hpp>
#include <std.icons.hpp>
#include <std.layouts.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Label;
   class _DYNAMICLINK ToolButton;
   class _DYNAMICLINK GroupBoxTopButtonControl: public Widget
   {
      Q_OBJECT
   public:
      GroupBoxTopButtonControl();
      explicit GroupBoxTopButtonControl(std::ustring const & strCaption, std::ustring const & strName = std::ustring());
      virtual ~GroupBoxTopButtonControl();
      virtual void Create();
      DECLARE_OPERATOR(GroupBoxTopButtonControl);
      set_property(GroupBoxImpl<> *, Group);
      set_property(Label *, Caption);
      set_property(ToolButton *, TopPlus);
      set_property(VerticalBox *, VerticalLay);
      set_property(shared_ptr<IconsImplEx<>>, IconsList);
   };
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//
