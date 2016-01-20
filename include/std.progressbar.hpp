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
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK ProgressBar: public QProgressBar
   {
   public:
      explicit ProgressBar(QWidget * lpOwner, std::ustring const & szName = std::ustring());
      virtual  ~ProgressBar();
      virtual void setValue(int value);
      virtual void setMaximum(int maximum);
      virtual void setMinimum(int minimum);
      virtual void setRange(int minimum, int maximum);
      /**/
      DECLARE_OPERATOR(ProgressBar);
      /* event */
      enum
      {
         PSB_VALUE = 0xff,
         PSB_MAXIMUM,
         PSB_MINIMUM,
         PSB_RANGE
      };
      /**/
      virtual bool OnValueChanged(int nValue, long lMsg, std::ProgressBar * lpOwner, void * pExtra = nullptr);
   };
};
//-----------------------------------------------------------------------------------------------//

