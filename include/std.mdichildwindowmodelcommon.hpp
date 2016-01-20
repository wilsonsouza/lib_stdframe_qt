//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.common.hpp>
#include <std.labelmodels.hpp>
#include <std.icons.hpp>
#include <std.tabbed.hpp>
#include <std.TabbedWidgetImpl.hpp>
#include <std.displayprogressbar.hpp>
#include <std.searchwidgetcontrol.hpp>
#include <std.captions.hpp>
#include <std.libbs.hpp>
#include <std.mdichildwindow.hpp>
#include <std.widgetimpl.hpp>
#include <std.layouts.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK MDIChildWindowModelCommon: 
      public MDIChildWindow, public LabelModels<>, public Libbs::Icons
   {
   public:
      enum
      {
         MWC_APPEND = 0x00000001,
         MWC_DELETE = 0x00000002,
         MWC_MODIFY = 0x00000004,
         MWC_SEARCH = 0x00000008,
         MWC_VIEWED = 0x00000010
      };
      /**/
      enum
      {
         TAB_DETAILS,
         TAB_SEARCH
      };
   public:
      explicit MDIChildWindowModelCommon(QWidget * pOwner, std::ustring const & strCaption);
      virtual ~MDIChildWindowModelCommon();
      //virtual abstract methods
      virtual void const OnPrepareWidgets();
      virtual void const OnCreateFilter() = 0;
      virtual bool const OnLoad() = 0;
      virtual void const OnCreateWidgets() = 0;
      virtual void const OnFillWidgetsData(QObject * pData) = 0;

      DECLARE_OPERATOR(MDIChildWindowModelCommon);
      set_property(int, OldTabWidth);
      set_property(TabbedWidgetImpl<> *, TabbedWidget);
      set_property(SearchWidgetControl *, SearchWidget);
      set_property(shared_ptr<sql::Table>, Table);
      set_property(unsigned int, ManagerId);
      set_property(int, StartYearFilter);
      set_property(WidgetImpl<std::VerticalBox> *, VerticalBody);

      virtual bool const __fastcall OnCreate(MDIChildWindow * pWnd);
      virtual void const __fastcall OnCreateNoAttached(MDIChildWindow * pWnd);
      virtual void OnInitialize() = 0;
   };
};
//-----------------------------------------------------------------------------------------------//
