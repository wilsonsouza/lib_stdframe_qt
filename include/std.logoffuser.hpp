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
#if defined(Q_OS_WIN)
namespace std
{
   class _DYNAMICLINK LogoffUser
   {
   public:
      LogoffUser();
      virtual ~LogoffUser();
      virtual bool const CurrentUser() const;
   };
};
//-----------------------------------------------------------------------------------------------//
__inline std::LogoffUser::LogoffUser()
{
}
//-----------------------------------------------------------------------------------------------//
__inline std::LogoffUser::~~LogoffUser()
{
}
//-----------------------------------------------------------------------------------------------//
__inline bool const std::LogoffUser::CurrentUser() const
{
   if(ExitWindowsEx(EWX_LOGOFF, 0))
      return true;
   return false;
}
//-----------------------------------------------------------------------------------------------//
