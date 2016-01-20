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
#include <Ras.h>
#include <RasDlg.h>
#include <RasError.h>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class ras
   {
   public:
      ras();
      virtual ~ras();
      /**/
      virtual bool const IsRasConnected();
   protected:
      std::shared_ptr<RASCONN> m_pRasConn;
      std::shared_ptr<RASCONNSTATUS> m_pRasConnStatus;
   };
};
