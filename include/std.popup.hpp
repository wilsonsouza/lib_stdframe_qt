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
#include <std.menuitems.hpp>
#include <std.menuitemdata.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Popup: public QList<MenuItems *>, public QObject
   {
   public:
      explicit Popup(std::ustring const & strName = std::ustring());
      Popup & operator+(MenuItems * i);
      Popup & operator+(Popup const & p);
      virtual MenuItemData  * operator[](std::ustring const & strItemName);
      virtual MenuItems * operator()(std::ustring const & strName);
      virtual MenuItems * FindPopup(std::ustring const & strName);
      template <class T> T * Find(std::ustring const & strName);
      virtual MenuItemData * FindItem(std::ustring const & strName);//search_item

      DECLARE_OPERATOR(Popup);
      set_property(ustring, Caption);
   };
};