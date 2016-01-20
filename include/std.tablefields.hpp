//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   struct TableFields
   {
      std::ustring strFieldName;
      std::ustring strLabelName;
      std::ustring strFieldAlias;
      std::ustring strFieldMask;
      int nLength;
      int nDecimals;

      TableFields(TableFields const & in);
      TableFields(std::ustring const & strFieldName,
                  std::ustring const & strFieldAlias = std::ustring(),
                  std::ustring const & strLabelName = std::ustring(),
                  std::ustring const & strFieldMask = std::ustring());
   };
   //-----------------------------------------------------------------------------------------------//
   __inline TableFields::TableFields(TableFields const & in)
   {
      strFieldName = in.strFieldName;
      strFieldAlias = in.strFieldAlias;
      strLabelName = in.strLabelName;
      strFieldMask = in.strFieldMask;
   }
   //-----------------------------------------------------------------------------------------------//
   __inline TableFields::TableFields(std::ustring const & strFieldName,
                                     std::ustring const & strFieldAlias,
                                     std::ustring const & strLabelName,
                                     std::ustring const & strFieldMask)
   {
      this->strFieldName = strFieldName;
      this->strFieldAlias = strFieldAlias;
      this->strLabelName = strLabelName;
      this->strFieldMask = strFieldMask;
   }
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//


