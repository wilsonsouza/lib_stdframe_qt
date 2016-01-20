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
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK MenuItemData;
   class _DYNAMICLINK MenuItems: 
      virtual public QObject,
      public QList<MenuItemData *>
   {
   public:
      explicit MenuItems(std::ustring const & strName = std::ustring());
      explicit MenuItems(MenuItems const &);
      virtual ~MenuItems(){}
      virtual MenuItems & operator+(MenuItemData * d);
              MenuItems & Separator();
      MenuItemData * FindItem(std::ustring const & Name);
      set_property(ustring, Caption);
      set_property(ustring, Name);
   };
};