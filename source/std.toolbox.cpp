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
#include <std.toolbox.hpp>
#include <std.widget.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
ToolBox::ToolBox(QWidget * pOwner, std::ustring const & strName, Qt::WindowFlags wf):
QToolBox(pOwner, wf)
{
   SetName(strName);
   connect(this, &QToolBox::currentChanged,[=](int nIndex)
   { 
      emit OnCurrentChanged(nIndex, this); 
   });
}
//-----------------------------------------------------------------------------------------------//
ToolBox::ToolBox(std::ustring const & strName, Qt::WindowFlags wf):
QToolBox(nullptr, wf)
{
   SetName(strName);
   connect(this, &QToolBox::currentChanged,[=](int nIndex)
   {
      emit OnCurrentChanged(nIndex, this);
   });
}
//-----------------------------------------------------------------------------------------------//

