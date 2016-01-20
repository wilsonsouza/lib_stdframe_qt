//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.action.hpp>
#include <std.submenuitemdata.hpp>
#include <std.menuitemdata.hpp>
#include <std.menuitems.hpp>
#include <std.menu.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Menu::Menu(QWidget * powner, std::ustring const & strtitle, std::ustring const & strName):QMenu(strtitle, powner)
{
   SetName(strName);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
Menu::~Menu()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
Action * __fastcall Menu::operator[](std::ustring strid)
{
   return findChild<Action *>(strid);
}
//-----------------------------------------------------------------------------------------------//
MenuItems & Menu::GetItems()
{
   return m_Items;
}
//-----------------------------------------------------------------------------------------------//
void const Menu::Create(MenuItems const & items, Action * Sender)
{
   //for(MenuItems::const_iterator i = items.begin(); i != items.end(); i++)
   //{
   //   MenuItemData * d = i.value();

   //   if(d->IsSeparator())
   //      addSeparator();
   //   else
   //   {
   //      Action * ptr = new Action(d->m_strName, this);

   //      if(!d->m_Icon.isNull())
   //         ptr->_Icon = d->m_Icon;

   //      ptr->Name = d->m_strName;
   //      ptr->enabled = d->m_bEnabled;
   //      ptr->checked = d->mbChecked;

   //      if(!d->IsSubMenu())
   //         addMenu(reinterpret_cast<QMenu *>(const_cast<Menu *>(createsub(d->m_SubMenu, Sender))));
   //      else
   //      {
   //         if(Sender)
   //            QObject::connect(ptr, &QAction::triggered,
   //            [=](bool bChecked){ Sender->OnCommand(bChecked, ptr); });

   //         //Update Action
   //         d->m_Action = ptr;
   //         m_Items.operator[](d->m_strName) = d;
   //      }
   //   }
   //}
}
//-----------------------------------------------------------------------------------------------//
Menu const * Menu::CreateSub(QList<MenuItemData *> const & items, Action * Sender)
{
   //Menu * p = new Menu(this);

   //for(MenuItems::const_iterator i = items.begin(); i != items.end(); i++)
   //{
   //   MenuItemData * d = i.value();

   //   if(d->IsSeparator())
   //      p->addSeparator();
   //   else
   //   {
   //      Action * ptr = new Action(d->m_strName, this);

   //      if(!d->m_Icon.isNull())
   //         ptr->_Icon = d->m_Icon;

   //      ptr->Name = d->m_strName;
   //      ptr->enabled = d->m_bEnabled;
   //      ptr->checked = d->mbChecked;

   //      if(!d->IsSubMenu())
   //         p->addMenu(reinterpret_cast<QMenu *>(const_cast<Menu *>(createsub(d->m_SubMenu, Sender))));
   //      else
   //      {
   //          if(Sender)
   //             QObject::connect(ptr, &QAction::triggered,
   //             [=](bool bChecked){ Sender->OnCommand(bChecked, Sender); });

   //         d->m_Action = ptr;
   //         m_Items.operator[](d->m_strName) = d;
   //      }
   //   }
   //}
   //return p;
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
Action *  Menu::Execute(QPoint const * lppt, Action * lpAction)
{
   Action * lpBuild = nullptr;

   if(lppt && lpAction)
      lpBuild = reinterpret_cast<Action *>(exec(const_cast<QPoint &>(*lppt), lpAction));

   if(lppt && !lpAction)
      lpBuild = reinterpret_cast<Action *>(exec(const_cast<QPoint &>(*lppt)));

   return lpBuild;
}
//-----------------------------------------------------------------------------------------------//
void Menu::SetNotifyEverthing()
{
   //no code
   connect(this, &QMenu::aboutToHide, [=]()
   {
      emit OnAbouttoHide(this);
   });
   connect(this, &QMenu::aboutToShow, [=]()
   {
      emit OnAbouttoShow(this);
   });
   connect(this, &QMenu::hovered,[=](QAction * Sender)
   {
      emit OnHovered(reinterpret_cast<Action *>(Sender), this);
   });
   connect(this, &QMenu::triggered, [=](QAction * Sender)
   { 
      emit OnCommand(reinterpret_cast<Action *>(Sender), this); 
   });
}
//-----------------------------------------------------------------------------------------------//
