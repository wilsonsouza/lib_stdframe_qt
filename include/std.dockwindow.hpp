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
//-----------------------------------------------------------------------------------------------//
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK DockWindow: public QDockWidget
   {
      Q_OBJECT
   public:
      DockWindow(std::ustring const & strtitle, QWidget * pOwner = nullptr, std::ustring const & strName = std::ustring(), Qt::WindowFlags wfflags = 0);
      virtual ~DockWindow();

   signals:
      void OnAllowedAreasChanged(Qt::DockWidgetAreas _dwa, DockWindow * Sender);
      void OnDockLocationChanged(Qt::DockWidgetArea  _dwa, DockWindow * Sender);
      void OnFeaturesChanged(QDockWidget::DockWidgetFeatures _f, DockWindow * Sender);
      void OnToplevelChanged(bool _btop, DockWindow * Sender);
      void OnVisibilityChanged(bool _bvisible, DockWindow * Sender);

   public:
      //propertys
      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(DockWindow);

      __declspec(property(get=allowedAreas, put=setAllowedAreas)) Qt::DockWidgetAreas AllowedAreas;
      __declspec(property(get=features, put=setFeatures)) QDockWidget::DockWidgetFeatures Features;
      __declspec(property(get=floating, put=setFloating)) bool IsFloating;
      __declspec(property(get=titleBarWidget)) QWidget * TitlebarWidget;
      __declspec(property(get=toggleViewAction)) QAction * ToggleViewAction;
   protected:
      virtual void SetNotifyEverthing();
   };
   //-----------------------------------------------------------------------------------------------//
};