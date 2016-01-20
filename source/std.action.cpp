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
#include <std.labelmodels.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Action::Action(QObject * pOwner):IAction(pOwner)
{
   SetName(GetClassName());
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
Action::Action(ustring const & strText, QObject * pOwner):IAction(strText, pOwner)
{
   SetName(strText);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
Action::Action(QIcon const & hIcon, ustring const & strText, QObject * pOwner):
IAction(hIcon, strText, pOwner)
{
   SetName(strText);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
Action::~Action()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
Action::operator const QAction *() const 
{ 
   return this;
}
//-----------------------------------------------------------------------------------------------//
void const Action::SetNotifyEverthing()
{
   connect(this, &QAction::changed, [=]()
   { 
      OnChanged(this); 
   });
   connect(this, &QAction::hovered, [=]()
   { 
      OnHovered(this); 
   });
   connect(this, &QAction::toggled, [=](bool const & bChecked)
   { 
      OnToggled(bChecked, this); 
      unsigned int uId;
      /**/
      if (isEnabled())
         uId |= ENABLED;
      /**/
      if (isChecked())
         uId |= CHECKED;
      /**/
      OnUpdateUI(this, bChecked, uId);
   });
   connect(this, &QAction::triggered, [=](bool const & bChecked)
   { 
      OnCommand(bChecked, this);
   });
}
//-----------------------------------------------------------------------------------------------//
void const Action::OnChanged(Action * pSender)
{
}
//-----------------------------------------------------------------------------------------------//
void const Action::OnHovered(Action * pSender)
{
}
//-----------------------------------------------------------------------------------------------//
void const Action::OnToggled(bool const & bChecked, Action * pSender)
{
}
//-----------------------------------------------------------------------------------------------//
void const Action::OnCommand(bool const & bChecked, Action * pSender)
{
}
//-----------------------------------------------------------------------------------------------//
void const Action::OnUpdateUI(Action * pSender, bool const & bValue, unsigned int const & uiValue)
{
}
//-----------------------------------------------------------------------------------------------//
