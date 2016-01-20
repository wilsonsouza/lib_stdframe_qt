//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.button.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Button::Button(std::ustring const & strCaption, 
   QIcon const & Icon, 
   std::ustring const & strName, 
   bool const & bEnabled):QPushButton(Icon, strCaption, nullptr)
{
   this->SetName(strName);
   setEnabled(bEnabled);
   this->SetNotifyEverything();
}
//-----------------------------------------------------------------------------------------------//
Button::Button(QWidget * pOwner, 
         std::ustring const & strCaption, 
         QIcon const & _Icon, 
         bool const & bEnabled):QPushButton(_Icon, strCaption, pOwner)
{
   SetName(strCaption);
   setEnabled(bEnabled);
   this->SetNotifyEverything();
}
//-----------------------------------------------------------------------------------------------//
Button::Button(QWidget * pOwner, 
         std::ustring const & strCaption, 
         std::ustring const & strName, 
         QIcon const & _Icon, 
         bool const & bEnabled):QPushButton(_Icon, strCaption, pOwner)
{
   SetName(strName);
   setEnabled(bEnabled);
   this->SetNotifyEverything();
}
//-----------------------------------------------------------------------------------------------//
Button::~Button()
{
   this->SetNotifyEverything(false);
}
//-----------------------------------------------------------------------------------------------//
void const Button::ShowMenu()
{
   this->showMenu();
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall::Button::SetNotifyEverything(bool const bEnabled)
{
   if(bEnabled)
   {
      connect(this, &QPushButton::clicked,[this](bool bChecked)
      {
         emit OnClicked(bChecked, this);
      });
   }
   else
      disconnect();
}
//-----------------------------------------------------------------------------------------------//
