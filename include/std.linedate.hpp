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
#include <std.lineedit.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   static std::ustring const IDSDATEFORMAT = std::ustring("DD/MM/YYYY");
   static std::ustring const IDSDATEMASK   = std::ustring("99/99/9999");
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK LineDate: public LineEdit
   {
      Q_OBJECT
   public:
      explicit LineDate(QWidget * pOwner, std::ustring const & strName = std::ustring());
      explicit LineDate(QDate const & dValue, std::ustring const & strName = std::ustring());
      explicit LineDate(std::ustring const & strDate, 
         std::ustring const & strName = std::ustring(),
         std::ustring const & strFormat = IDSDATEMASK);
      virtual ~LineDate();
      DECLARE_OPERATOR(LineDate)
   };
};
//-----------------------------------------------------------------------------------------------//

