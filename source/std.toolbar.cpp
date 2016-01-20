//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.menu.hpp>
#include <std.menuitemdata.hpp>
#include <std.menuitems.hpp>
#include <std.toolbar.hpp>
#include <std.toolbaritems.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
ToolBar::ToolBar(std::ustring const & strCaption, QWidget * pOwner, std::ustring const & strName):
QToolBar(strCaption, pOwner)
{
   SetName(strName);
}
//-----------------------------------------------------------------------------------------------//
ToolBar::~ToolBar()
{
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall ToolBar::Create(ToolBarItems * pItems)
{
   for(auto p = pItems->begin(); p != pItems->end(); p++)
   {
      MenuItemData * d = p.operator*();

      if(d->IsSeparator())
         addSeparator();
      else
         if(d->IsAction())
            addAction(d->GetActionItem());
   }
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall ToolBar::SetEnabled(std::ustring const & strButtonName, bool const bEnabled)
{
   QAction * _lpAction = QObject::findChild<QAction *>(strButtonName);

   if(_lpAction)
      _lpAction->setEnabled(bEnabled);
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall ToolBar::IsEnabled(std::ustring const & strButtonName)
{
   QAction * lpp = QObject::findChild<QAction *>(strButtonName);

   if(lpp)
      return lpp->isEnabled();

   return false;
}
//-----------------------------------------------------------------------------------------------//
void ToolBar::SetNotifyEverthing()
{
   connect(this, &QToolBar::actionTriggered,[=](QAction * Sender)
   { 
      emit OnCommand(reinterpret_cast<Action *>(Sender), this); 
   });
   connect(this, &QToolBar::allowedAreasChanged,[=](Qt::ToolBarAreas tbaFlags)
   { 
      emit OnAllowedAreasChanged(tbaFlags, this); 
   });
   connect(this, &QToolBar::iconSizeChanged,[=](QSize const & sIcon)
   {
      emit OnIconSizeChanged(sIcon, this);
   });
   connect(this, &QToolBar::movableChanged,[=](bool bMovable)
   {
      emit OnMovableChanged(bMovable, this);
   });
   connect(this, &QToolBar::orientationChanged,[=](Qt::Orientation oMode)
   {
      emit OnOrientationChanged(oMode, this);
   });
   connect(this, &QToolBar::toolButtonStyleChanged,[=](Qt::ToolButtonStyle tbsMode)
   {
      emit OnToolButtonStyleChanged(tbsMode, this);
   });
   connect(this, &QToolBar::topLevelChanged,[=](bool bTopLevel)
   {
      emit OnTopLevelChanged(bTopLevel, this);
   });
   connect(this, &QToolBar::visibilityChanged,[=](bool bVisible)
   {
      emit OnVisibilityChanged(bVisible, this);
   });
}
//-----------------------------------------------------------------------------------------------//
