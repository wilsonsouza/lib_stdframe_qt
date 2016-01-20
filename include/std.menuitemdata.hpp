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
#include <std.captions.hpp>
#include <std.action.hpp>
#include <std.submenuitemdata.hpp>
#include <std.menuitemdata.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Action;
   class _DYNAMICLINK MenuItemData: public QObject
   {
   public:
      MenuItemData(std::ustring const & strName, 
                   QIcon const & Icon = QIcon(), 
                   bool const & bEnabled = false, 
                   bool const & bChecked = false);
      virtual bool const IsSeparator() const;
      virtual bool const IsAction() const;
      virtual bool const IsSubMenu() const;
      virtual MenuItemData & operator[](MenuItemData * d);
      virtual MenuItemData & operator+(MenuItemData * d);
      DECLARE_OPERATOR(MenuItemData);

      set_property(shared_ptr<QIcon>, Icon);
      set_property(QAction *, ActionItem);
      set_property(shared_ptr<SubMenuItemData>, SubMenuItem);
      set_property(long, ID);
      set_property(ustring, Caption);
      set_property(bool, Enabled);
      set_property(bool, Checked);
   };
};