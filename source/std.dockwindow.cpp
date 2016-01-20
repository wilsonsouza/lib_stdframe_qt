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
#include <std.dockwindow.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
DockWindow::DockWindow(std::ustring const & strtitle, QWidget * pOwner, std::ustring const & strName, Qt::WindowFlags wfflags):
QDockWidget(strtitle, pOwner, wfflags)
{
   SetName(strName);
}
//-----------------------------------------------------------------------------------------------//
DockWindow::~DockWindow()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
void DockWindow::SetNotifyEverthing()
{
   connect(this, &QDockWidget::allowedAreasChanged,[=](Qt::DockWidgetAreas dwaMode)
   {
      emit OnAllowedAreasChanged(dwaMode, this);
   });
   connect(this, &QDockWidget::dockLocationChanged,[=](Qt::DockWidgetArea dwaMode)
   {
      emit OnDockLocationChanged(dwaMode, this);
   });
   connect(this, &QDockWidget::featuresChanged,[=](QDockWidget::DockWidgetFeatures dwfMode)
   {
      emit OnFeaturesChanged(dwfMode, this);
   });
   connect(this, &QDockWidget::topLevelChanged,[=](bool bTop)
   {
      emit OnToplevelChanged(bTop, this);
   });
   connect(this, &QDockWidget::visibilityChanged,[=](bool bTop)
   {
      emit OnVisibilityChanged(bTop, this);
   });
}
//-----------------------------------------------------------------------------------------------//
