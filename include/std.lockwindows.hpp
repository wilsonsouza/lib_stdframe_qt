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
   /* lock work station */
   class _DYNAMICLINK LockWindows
   {
   public:
      LockWindows();
      virtual ~LockWindows();
      virtual bool Lock();
   };
};
//-----------------------------------------------------------------------------------------------//
__inline std::LockWindows::LockWindows()
{
}
//-----------------------------------------------------------------------------------------------//
__inline std::LockWindows::~LockWindows()
{
}
//-----------------------------------------------------------------------------------------------//
__inline bool std::LockWindows::Lock()
{
   if(!LockWorkStation())
      return false;
   return true;
}
//-----------------------------------------------------------------------------------------------//
#endif