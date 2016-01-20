//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.radiobutton.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
RadioButton::RadioButton(QWidget * pOwner, 
                                 std::ustring const & strName,
                                 bool const & bEnabled, 
                                 bool const & bChecked):
QRadioButton(pOwner)
{
   SetName(strName);
   setEnabled(bEnabled);
   setChecked(bChecked);

   connect(this, &QRadioButton::clicked,[=](bool bChecked)
   { 
      emit OnClicked(bChecked, this); 
   });
}
//-----------------------------------------------------------------------------------------------//
RadioButton::RadioButton(std::ustring const & strCaption, 
                                 std::ustring const & strName, 
                                 QWidget * pOwner):
QRadioButton(strCaption, pOwner)
{
   SetName(strName);
   setEnabled(true);
   setChecked(false);

   connect(this, &QRadioButton::clicked,[=](bool bChecked)
   { 
      emit OnClicked(bChecked, this); 
   });
}
//-----------------------------------------------------------------------------------------------//
RadioButton::~RadioButton()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
