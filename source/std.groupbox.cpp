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
#include <std.groupbox.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
GroupBox::GroupBox(std::ustring const & strCaption, QWidget * pOwner):QGroupBox(strCaption, pOwner)
{
   SetName(GetClassName());
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
GroupBox::~GroupBox()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
void GroupBox::SetNotifyEverthing(bool const & bOK)
{
   if(bOK)
   {
      connect(this, &QGroupBox::clicked,[=](bool bChecked)
      { 
         emit OnClicked(bChecked, this); 
      });
      connect(this, &QGroupBox::toggled,[=](bool bOK)
      { 
         emit OnToggled(bOK, this); 
      });
   }
   else
      disconnect();
}
//-----------------------------------------------------------------------------------------------//

