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
//-----------------------------------------------------------------------------------------------//
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK TableWidgetItem: 
      public QTableWidgetItem, public QObject
   {
   public:
      TableWidgetItem(int ntype, std::ustring const & strName):QTableWidgetItem(ntype){}
      TableWidgetItem(std::ustring const & strtext, int ntype = Type, std::ustring const & strName = std::ustring()):
      QTableWidgetItem(strtext, ntype){}
      TableWidgetItem(QIcon const & QIcon, std::ustring const & strtext, int ntype = Type, std::ustring const & strName = std::ustring()):
      QTableWidgetItem(QIcon, strtext, ntype){}
      TableWidgetItem(TableWidgetItem const & titem, std::ustring const & strName):QTableWidgetItem(titem){}
      DECLARE_OPERATOR(TableWidgetItem);
   };
};