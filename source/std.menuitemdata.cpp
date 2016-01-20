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
#include <std.menuitemdata.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MenuItemData::MenuItemData(std::ustring const & strName, 
                           QIcon const & oIcon, 
                           bool const & bEnabled, 
                           bool const & bChecked)
{
   SetName(strName);
   SetCaption(strName);
   SetIcon(shared_ptr<QIcon>(new QIcon(oIcon)));
   SetActionItem(nullptr);
   SetSubMenuItem(shared_ptr<SubMenuItemData>(new SubMenuItemData));
   SetID(0);
   SetEnabled(bEnabled);
   SetChecked(bChecked);
}
//-----------------------------------------------------------------------------------------------//
bool const MenuItemData::IsSeparator() const
{
   return m_Caption.contains(Tokens::SEPARATOR);
}
//-----------------------------------------------------------------------------------------------//
bool const MenuItemData::IsAction() const
{
   return m_ActionItem != nullptr;
}
//-----------------------------------------------------------------------------------------------//
bool const MenuItemData::IsSubMenu() const
{
   return !m_SubMenuItem->Empty();
}
//-----------------------------------------------------------------------------------------------//
MenuItemData & MenuItemData::operator[](MenuItemData * d)
{
   GetSubMenuItem()->append(d);
   return *this;
}
//-----------------------------------------------------------------------------------------------//
MenuItemData & MenuItemData::operator+(MenuItemData * d)
{
   GetSubMenuItem()->append(d);
   return *this;
}
//-----------------------------------------------------------------------------------------------//