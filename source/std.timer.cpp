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
#include <std.timer.hpp>
#include <std.mainwindow.hpp>
#include <std.mdichildwindow.hpp>
#include <std.dialogex.hpp>
#include <std.application.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Timer::Timer(QObject * pOwner, std::ustring const & strName):
QTimer(pOwner)
{
   SetName(strName);
}
//-----------------------------------------------------------------------------------------------//
Timer::Timer(int const & nInterval, std::ustring const & strName)
{
   SetName(strName);
   setInterval(nInterval);
}
//-----------------------------------------------------------------------------------------------//
Timer::~Timer()
{
   stop();
}
//-----------------------------------------------------------------------------------------------//
void const Timer::Start(int const nmilleseconds) 
{ 
   QTimer::start(nmilleseconds);  
}
//-----------------------------------------------------------------------------------------------//
void const Timer::SetSingleShot(int nMilleseconds, QObject * Sender, const char * lpszSlot)
{
   //call QTimer::singleShot to make interval of called
   QTimer::singleShot(nMilleseconds, Sender, lpszSlot);
}
//-----------------------------------------------------------------------------------------------//
void Timer::timerEvent(QTimerEvent * e)
{
   int n = e->timerId();
   /**/
   if (n == TimerID)
   {
      e->accept();
      qApp->sendEvent(parent(), e);
      return;
   }
   return QTimer::timerEvent(e);
}
//-----------------------------------------------------------------------------------------------//
