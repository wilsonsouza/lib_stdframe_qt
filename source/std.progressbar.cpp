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
#include <std.progressbar.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
ProgressBar::ProgressBar(QWidget * lpOwner, std::ustring const & strName):QProgressBar(lpOwner)
{
   SetName(strName);
}
//-----------------------------------------------------------------------------------------------//
ProgressBar::~ProgressBar()
{
}
//-----------------------------------------------------------------------------------------------//
bool ProgressBar::OnValueChanged(int nValue, long lMsg, std::ProgressBar * lpSender, void * pExtra)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
void ProgressBar::setValue(int nValue)
{
   if (OnValueChanged(nValue, PSB_VALUE, this))
   {
      QProgressBar::setValue(nValue);
   }
}
//-----------------------------------------------------------------------------------------------//
void ProgressBar::setMaximum(int maximum)
{
   if (OnValueChanged(maximum, PSB_MAXIMUM, this))
   {
      QProgressBar::setMaximum(maximum);
   }
}
//-----------------------------------------------------------------------------------------------//
void ProgressBar::setMinimum(int minimum)
{
   if (OnValueChanged(minimum, PSB_MINIMUM, this))
   {
      QProgressBar::setMinimum(minimum);
   }
}
//-----------------------------------------------------------------------------------------------//
void ProgressBar::setRange(int minimum, int maximum)
{
   if (OnValueChanged(minimum, PSB_RANGE, this, &maximum))
   {
      QProgressBar::setRange(minimum, maximum);
   }
}
//-----------------------------------------------------------------------------------------------//
