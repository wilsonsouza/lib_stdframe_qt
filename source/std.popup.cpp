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
#include <std.menu.hpp>
#include <std.popup.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Popup::Popup(std::ustring const & strName)
{
   SetCaption(strName);
   SetName(strName);
}
//-----------------------------------------------------------------------------------------------//
Popup & Popup::operator+(MenuItems * i)
{
   if(i)
      append(i);

   return *this;
}
//-----------------------------------------------------------------------------------------------//
Popup & Popup::operator+(Popup const & p)
{
   for(auto i = p.begin(); i != p.end(); i++)
      this->append(i.operator*());
   return *this;
}
//-----------------------------------------------------------------------------------------------//
MenuItemData * Popup::operator[](std::ustring const & strItemName) //get Menuitem
{
   for(auto i = begin(); i != end(); i++)
   {
      MenuItemData * p = i.operator*()->FindItem(strItemName);

      if(p)
         return p;
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
MenuItems * Popup::operator()(std::ustring const & strName) //get Menu
{
   for(auto i = begin(); i != end(); i++)
   {
      MenuItems * p = i.operator*();

      if(!p->GetCaption().isEmpty())
      {
         if(p->GetCaption() == strName)
            return p;
      }
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
MenuItems * Popup::FindPopup(std::ustring const & strName)
{
   return Popup::operator()(strName);
}
//-----------------------------------------------------------------------------------------------//
template <class T>  T * Popup::Find(std::ustring const & strName)
{
   return reinterpret_cast<T *>(FindPopup(strName));
}
//-----------------------------------------------------------------------------------------------//
MenuItemData * Popup::FindItem(std::ustring const & strName)
{
   return Popup::operator[](strName);
}
//-----------------------------------------------------------------------------------------------//
