//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.linedate.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
LineDate::LineDate(QWidget * pOwner, std::ustring const & strName):
LineEdit(pOwner, std::ustring(), 0xA, 0x64, strName)
{
   SetName(strName);
   SetInputMask(IDSDATEMASK);
   setText(QDate().toString(IDSDATEMASK));
}
//-----------------------------------------------------------------------------------------------//
LineDate::LineDate(QDate const & dValue, std::ustring const & strName):
LineEdit(nullptr, std::ustring(), 0xA, 0x64, strName)
{
   SetName(strName);
   SetInputMask(IDSDATEMASK);
   setText(dValue.toString(IDSDATEMASK));
}
//-----------------------------------------------------------------------------------------------//
LineDate::LineDate(std::ustring const & strDate, 
   std::ustring const & strName, std::ustring const & strFormat):
LineEdit(nullptr, strDate, 6, 0x64, strName)
{
   SetName(strName);
   SetInputMask(strFormat);
}
//-----------------------------------------------------------------------------------------------//
LineDate::~LineDate()
{
}
//-----------------------------------------------------------------------------------------------//

