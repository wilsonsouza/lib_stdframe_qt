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
#include <std.defs.hpp>
#include <std.menuitems.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK MenuBar;
   class _DYNAMICLINK Action;
   class _DYNAMICLINK SubMenuItemData;
   class _DYNAMICLINK MenuItemData;
   class _DYNAMICLINK Menu : public QMenu
   {
      Q_OBJECT
   public:
      Menu(QWidget * ponwer = nullptr, 
           std::ustring const & strtitle = std::ustring(), 
           std::ustring const & strName = std::ustring());
      ~Menu();
      Action * __fastcall operator [](std::ustring strid);
      MenuItems & GetItems();

      virtual void const Create(MenuItems const & items, Action * Sender);
      virtual Action *  Execute(QPoint const * lppt = nullptr, Action * lpAction = nullptr);

      DECLARE_OPERATOR(Menu)

      __declspec(property(get=GetItems)) MenuItems & Items;
      __declspec(property(get=isEmpty)) bool const Empty;
      __declspec(property(get=isTearOffEnabled)) bool const IsRearoffEnabled;
      __declspec(property(get=isTearOffMenuVisible)) bool const IstearoffMenuVisible;
      __declspec(property(get=title, put=setTitle)) std::ustring const & Title;
      __declspec(property(get=activeAction, put=setActiveAction)) Action * ActiveAction;
      __declspec(property(get=defaultAction, put=setDefaultAction)) Action * DefaultAction;
      __declspec(property(get=Icon, put=SetIcon)) QIcon Icon;
      __declspec(property(get=MenuAction)) QAction const * MenuAction;
      __declspec(property(get=parent, put=setParent)) QObject * Parent;
      __declspec(property(get=objectName, put=setObjectName)) std::ustring Name;
      __declspec(property(put=installEventFilter)) QObject * InstallEventFilter;
      __declspec(property(put=removeEventFilter)) QObject * UninstallEventFilter;

   signals:
      void OnAbouttoHide(Menu * Sender);
      void OnAbouttoShow(Menu * Sender);
      void OnHovered(Action * pAction, Menu * Sender);
      void OnCommand(Action * pAction, Menu * Sender);

   protected:
      virtual Menu const * CreateSub(QList<MenuItemData *> const & items, Action * Sender);

   protected:
      MenuItems m_Items;
      virtual void SetNotifyEverthing();
   };
   //-----------------------------------------------------------------------------------------------//
};
