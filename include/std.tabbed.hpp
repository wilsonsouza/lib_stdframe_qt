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
#include <std.widget.hpp>
#include <std.tabbeddefs.hpp>
#include <std.tabbedmenuitems.hpp>
#include <std.tabbedindex.hpp>
#include <std.tabbeddelegate.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK Tabbed : public QTabWidget
   {
      Q_OBJECT
   public:
      Tabbed(QWidget * pOwner = nullptr, std::ustring const & strName = std::ustring());
      virtual ~Tabbed();
      virtual int  __fastcall GetCount() const;
      Widget * __fastcall operator[](std::ustring const & strName);
      Widget * __fastcall operator[](unsigned int uTabIndex);
      virtual void const SetTabEnabled(int const & nIndex, bool const & bEnabled);
      virtual void const SetTabEnabled(bool const & bEnabled);
      virtual bool IsTabEnabled(int const nIndex) const;
      virtual QList<bool> IsTabEnabled() const;
      virtual void const SetTabIcon(QWidget * pWidget, QIcon const & qIcon);
      virtual void const SetCurrentIndex(QWidget * pWidget);
      virtual void Update() const;
      virtual TabbedIndex * IsTabEnabled(TabbedIndex * _pTabbedIndex);
      //-----------------------------------------------------------------------------------------------//
      virtual void const TabEnabled(TabbedIndex * _pTabbedIndex);
      //-----------------------------------------------------------------------------------------------//
      int GetIndex(QWidget * pWidgetP);
      //-----------------------------------------------------------------------------------------------//
      DECLARE_OPERATOR(Tabbed);
      //propertys
      __declspec(property(put=removeTab)) int RemoveTab;
      __declspec(property(get=count)) int Count;
      __declspec(property(get=isMovable, put=setMovable)) bool Movable;
      __declspec(property(get=isHidden, put=setHidden)) bool Hidden;
      __declspec(property(get=currentIndex, put=setCurrentIndex)) int CurrentIndex;
      __declspec(property(get=currentWidget, put=setCurrentWidget)) QWidget * CurrentWidget;
      __declspec(property(get=documentMode, put=setDocumentMode)) bool DocumentMode;
      __declspec(property(get=tabPosition, put=setTabPosition)) int TabPosition;
      __declspec(property(get=tabShape, put=setTabShape)) int TabShape;
      __declspec(property(get=tabsClosable, put=setTabsClosable)) bool TabsCloseable;
      __declspec(property(get=usesScrollButtons, put=setUsesScrollButtons)) bool UsesScrollButtons;
      __declspec(property(get=minimumSizeHint)) QSize const MinimumSizeHint;
      __declspec(property(get=tabBar, put=setTabBar)) QTabBar * Tabbar;

      DECLARE_PROPERTYS(1)
   public:
      std::shared_ptr<Menu> m_pContextMenu;
   signals:
      void OnCurrentChanged(int nIndex, Tabbed * Sender);
      void OnTabCloseRequested(int nIndex, Tabbed * Sender);
      void OnTabMoved(int const & from, int const & to, Tabbed * Sender);
      void OnUpdateUI(int const & nIndex, bool const & bEnabled);
   protected:
      //-----------------------------------------------------------------------------------------------//
      virtual void mousePressEvent(QMouseEvent * pMouseEvent);
      virtual bool event(QEvent * pEvent);
   private:
      TabbedIndex * m_pTabbedIndex;
   };
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//