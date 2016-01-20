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
#include <std.defsx.hpp>
#include <std.menuitemdata.hpp>
#include <std.menuitems.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK TabbedMenuItems: public MenuItems, public Icons::Tabbed
   {
   public:
      TabbedMenuItems():MenuItems(Captions::Tabbed::NAME)
      {
         using namespace Captions::Tabbed;

         MenuItemData * p = new MenuItemData(POSITION);
         MenuItemData * s = new MenuItemData(SHAPE);

         p->operator+(new MenuItemData(POSITION_EAST, *EAST, true));
         p->operator+(new MenuItemData(POSITION_EAST, *EAST, true));
         p->operator+(new MenuItemData(POSITION_NORTH, *NORTH, true));
         p->operator+(new MenuItemData(POSITION_SOUTH, *SOUTH, true));
         p->operator+(new MenuItemData(POSITION_WEST, *WESTH, true));

         s->operator+(new MenuItemData(SHAPE_ROUNDED, QIcon(), true));
         s->operator+(new MenuItemData(SHAPE_TRIANGULAR, QIcon(), true));

         operator+(p);
         operator+(s);
         operator+(new MenuItemData(Tokens::SEPARATOR));
         operator+(new MenuItemData(Captions::Tabbed::NEXT, *NEXT, true));
         operator+(new MenuItemData(Captions::Tabbed::PREVIEW, *PREVIEW, true));
         operator+(new MenuItemData(Tokens::SEPARATOR));
         operator+(new MenuItemData(Captions::Tabbed::PROPERTYS, *PROPERTYS, true));
         operator+(new MenuItemData(Captions::Tabbed::CLOSE, *CLOSE, true));
      }
      DECLARE_OPERATOR(TabbedMenuItems)
   };
};