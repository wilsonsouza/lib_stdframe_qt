//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.linegroup.hpp>
#include <std.lineedit.hpp>
#include <std.linedate.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
LineGroup::LineGroup()
{
   clear();
}
//-----------------------------------------------------------------------------------------------//
LineGroup::LineGroup(QWidget * pParent, QStringList const & strListQueue)
{
   for(QStringList::const_iterator i = strListQueue.begin(); i != strListQueue.end(); i++)
      operator[](i.operator*()) = new LineEdit(pParent, std::ustring(), 0xff, 0x64, i.operator*());
}
//-----------------------------------------------------------------------------------------------//
LineGroup::LineGroup(QWidget * pParent, QMap<std::ustring, int> const & qQueue)
{
   for(auto i = qQueue.begin(); i != qQueue.end(); i++)
   {
      LineEdit * pLine = new LineEdit(pParent, std::ustring(), 0xff, i.value(), i.key());
      operator[](i.key()) = pLine;
   }
}
//-----------------------------------------------------------------------------------------------//
LineGroup::~LineGroup()
{
   clear();
}
//-----------------------------------------------------------------------------------------------//

