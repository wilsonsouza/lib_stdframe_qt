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
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK MenuItemData;
   class _DYNAMICLINK SubMenuItemData: public QList<MenuItemData *>
   {
   public:
      SubMenuItemData();
      virtual ~SubMenuItemData(){}

      bool Empty() const;
      virtual MenuItemData * operator[](std::ustring const & Name);
      virtual MenuItemData * FindData(std::ustring const & Name);
   protected:
      virtual MenuItemData * FindSubData(std::ustring const & Name, SubMenuItemData * d);
   };
};