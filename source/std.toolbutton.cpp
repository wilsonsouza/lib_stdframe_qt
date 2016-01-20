//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.toolbutton.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
ToolButton::ToolButton(std::ustring const & strName, QIcon const & iIcon):QToolButton()
{
   SetName(strName);
   setIcon(iIcon);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
ToolButton::ToolButton(QIcon const & iIcon, std::ustring const & strName):QToolButton()
{
   SetName(strName);
   setIcon(iIcon);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
ToolButton::ToolButton(QWidget * pOwner, std::ustring const & strName, QIcon const & iIcon):QToolButton(pOwner)
{
   SetName(strName);
   setIcon(iIcon);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
ToolButton::~ToolButton()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
void ToolButton::SetNotifyEverthing()
{
   //redirect method call
   connect(this, &QToolButton::clicked,[this]()
   {
      emit OnClicked(reinterpret_cast<Action *>(defaultAction()),  this);
   });
   connect(this, &QToolButton::toggled,[this](bool bChecked)
   {
      emit OnUpdateUI(this, bChecked, isEnabled());
   });
}
//-----------------------------------------------------------------------------------------------//
