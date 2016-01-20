//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.checkbox.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
CheckBox::CheckBox(QWidget * pOwner, 
   std::ustring const & strCaption, 
   std::ustring const & strName, 
   bool const & bEnabled, 
   bool const & bChecked):
QCheckBox(strCaption, pOwner)
{
   this->SetName(strName);
   this->setEnabled(bEnabled);
   setChecked(bChecked);
   this->SetNotifyEverything();
}
//-----------------------------------------------------------------------------------------------//
CheckBox::CheckBox(std::ustring const & strCaption,
   std::ustring const & strName, 
   bool const & bEnabled, 
   bool const & bChecked):
QCheckBox(strCaption, nullptr)
{
   this->SetName(strName);
   setEnabled(bEnabled);
   setChecked(bChecked);
   this->SetNotifyEverything();
}
//-----------------------------------------------------------------------------------------------//
CheckBox::~CheckBox()
{
   this->disconnect();
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall CheckBox::SetNotifyEverything()
{
   this->connect(this, &QCheckBox::stateChanged,[=](int nState)
   { 
      emit OnStateChanged(Qt::CheckState(nState), this); 
   });
}
//-----------------------------------------------------------------------------------------------//
