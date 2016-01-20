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
   class LCDNumber: public QLCDNumber
   {
      Q_OBJECT
   public:
      explicit LCDNumber(QWidget * pOwner, 
         int nDigits, std::ustring const & szName = std::ustring());
      virtual ~LCDNumber();

      DECLARE_OPERATOR(LCDNumber);
signals:
      void OnOverflow(std::LCDNumber * pSender);
   };
   //-----------------------------------------------------------------------------------------------//
   __inline LCDNumber::LCDNumber(QWidget * pOwner, 
      int nDigits, std::ustring const & szName):
   QLCDNumber(nDigits, pOwner)
   {
      QObject::connect(this, &QLCDNumber::overflow,[=](){ emit OnOverflow(this); });
      SetName(szName); // = strName.isEmpty() ? ClassName : strName;
   }
   //-----------------------------------------------------------------------------------------------//
   __inline LCDNumber::~LCDNumber()
   {
      disconnect();
   }
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//
