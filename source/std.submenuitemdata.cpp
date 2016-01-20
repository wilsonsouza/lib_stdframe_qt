//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.submenuitemdata.hpp>
#include <std.menuitemdata.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
SubMenuItemData::SubMenuItemData():QList<MenuItemData *>()
{
}
//-----------------------------------------------------------------------------------------------//
bool SubMenuItemData::Empty() const
{
   return count() == 0;
}
//-----------------------------------------------------------------------------------------------//
MenuItemData * SubMenuItemData::operator[](std::ustring const & Name)
{
   return FindData(Name);
}
//-----------------------------------------------------------------------------------------------//
MenuItemData * SubMenuItemData::FindSubData(std::ustring const & Name, SubMenuItemData * d)
{
   for(iterator i = d->begin(); i != d->end(); i++)
   {
      MenuItemData * p = i.operator*();

      if(p->GetCaption() == Name)
         return p;

      if(p->IsSubMenu())
         if(p = FindSubData(Name, p->GetSubMenuItem().operator->()))
            return p;
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
MenuItemData * SubMenuItemData::FindData(std::ustring const & Name)
{
   for(iterator i = begin(); i != end(); i++)
   {
      MenuItemData * d = i.operator*();

      if(d->GetCaption() == Name)
         return d;

      if(d->IsSubMenu())
         if(d = FindSubData(Name, d->GetSubMenuItem().operator->()))
            return d;
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
