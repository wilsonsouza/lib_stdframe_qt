//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.menuitemdata.hpp>
#include <std.menuitems.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MenuItems::MenuItems(std::ustring const & strName)
{
   SetName(strName);
   SetCaption(strName);
}
//-----------------------------------------------------------------------------------------------//
MenuItems::MenuItems(MenuItems const & oMenuItems)
{
   SetName(oMenuItems.m_Name);
   SetCaption(oMenuItems.m_Caption);
}
//-----------------------------------------------------------------------------------------------//
MenuItems & MenuItems::operator+(MenuItemData * d)
{
   if(d)
      this->append(d);

   return *this;
}
//-----------------------------------------------------------------------------------------------//
MenuItems & MenuItems::Separator()
{
   return operator+(new MenuItemData(Tokens::SEPARATOR));
}
//-----------------------------------------------------------------------------------------------//
MenuItemData * MenuItems::FindItem(std::ustring const & Name)
{
   MenuItemData * out = nullptr;

   for(iterator i = begin(); i != end(); i++)
   {
      MenuItemData * cur = i.operator*();

      if(cur->GetCaption() == Name)
         return cur;

      if(cur->IsSubMenu())
         if(cur = cur->GetSubMenuItem()->FindData(Name))
            return cur;
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
