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
   class _DYNAMICLINK Timer: public QTimer
   {
   public:
      Timer(QObject * pOwner, std::ustring const & strName = std::ustring());
      Timer(int const & interval = 5000 , std::ustring const & strName = std::ustring());
      virtual ~Timer();

      __declspec(property(get=isActive)) bool IsActive;
      __declspec(property(get=interval, put=setInterval)) int const Interval;
      __declspec(property(get=isSingleShot, put=setSingleShot)) bool const SingleShot;
      __declspec(property(get=timerId)) int const TimerID;

      virtual  void const Start(int const nmilleseconds = 0x64);
      //static
      static void const SetSingleShot(int nmilleseconds, QObject * preceive, const char * pszmember);
      //propertys
      DECLARE_PROPERTYS(0);
      DECLARE_OPERATOR(Timer);
   private:
      virtual void timerEvent(QTimerEvent * e);
   };
};
//-----------------------------------------------------------------------------------------------//

