//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.defsx.hpp>
#include <std.popup.hpp>
#include <std.mainwindow.hpp>
#include <std.action.hpp>
#include <std.menubar.hpp>
#include <std.mdiframewindow.hpp>
#include <std.mdiframewindowarea.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MenuBar::MenuBar(QWidget * pOwner, std::ustring const & strName):QMenuBar(pOwner)
{
   SetName(strName);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
MenuBar::~MenuBar()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MenuBar::Create(Popup const & items, Action * Sender)
{
   //for(Popup::const_iterator i = items.begin(); i.operator!=(items.end()); i.operator++())
   //{
   //   MenuItems * p = i.value();

   //   if(p->m_strName.contains(IDM_SEPARATOR))
   //      addSeparator();
   //   else
   //   {
   //      Menu * ptr = new Menu(nullptr, std::ustring(), p->m_strName);
   //      ptr->Create(*p, Sender);
   //      addMenu(ptr);
   //   }
   //}
}
//-----------------------------------------------------------------------------------------------//
Action * __fastcall MenuBar::operator [](std::ustring strid)
{
   return findChild<Action *>(strid);
}
//-----------------------------------------------------------------------------------------------//
void const MenuBar::SetEnable(std::ustring const & strid, bool bEnabled)
{
   Action * item = operator[](strid);

   if(item != nullptr)
      item->setEnabled(bEnabled);
}
//-----------------------------------------------------------------------------------------------//
bool MenuBar::GetEnabled(std::ustring const & strid)
{
   Action * item = operator[](strid);

   if(item != nullptr)
      return item->isEnabled();

   return false;
}
//-----------------------------------------------------------------------------------------------//
void const MenuBar::EnabledMDIActions(MDIFrameWindow *pFrame)
{
   shared_ptr<MenuItems> items(new WindowItems());

   for(auto i = items->begin(); i != items->end(); i++)
   {
      MenuItemData * d = i.operator*();

      if(!d->IsSeparator())
      {
         int nCounter = pFrame->GetDesktop()->GetListMDIChildWindow().count();

         if (d->GetCaption() == Captions::Window::NEXT ||
            d->GetCaption() == Captions::Window::PREVIOUS ||
            d->GetCaption() == Captions::Window::CLOSEALL)
            SetEnable(d->GetCaption(), nCounter > 1);
         else
            SetEnable(d->GetCaption(), nCounter > 0);
      }
   }
}
//-----------------------------------------------------------------------------------------------//
void MenuBar::focusInEvent(QFocusEvent * pFocusEvent)
{
   MDIFrameWindow * pFrame = dynamic_cast<MDIFrameWindow *>(parent());

   if(pFrame)
      EnabledMDIActions(pFrame);
}
//-----------------------------------------------------------------------------------------------//
MainWindow * MenuBar::GetMainWindow() const
{
   return reinterpret_cast<MainWindow *>(parent());
}
//-----------------------------------------------------------------------------------------------//
void MenuBar::SetNotifyEverthing()
{
   connect(this, &QMenuBar::hovered,[=](QAction * Sender)
   {
      emit OnHovered(reinterpret_cast<Action *>(Sender), this);
   });
   connect(this, &QMenuBar::triggered,[=](QAction * Sender)
   {
      emit OnCommand(reinterpret_cast<Action *>(Sender), this);
   });
}
//-----------------------------------------------------------------------------------------------//
