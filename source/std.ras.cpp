//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.ras.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
std::ras::ras()
{
   m_pRasConn = std::shared_ptr<RASCONN>(new RASCONN);
   m_pRasConnStatus = std::shared_ptr<RASCONNSTATUS>(new RASCONNSTATUS);
   /**/
   m_pRasConn->dwSize = sizeof(RASCONN);
   m_pRasConnStatus->dwSize = sizeof(RASCONNSTATUS);
}
//-----------------------------------------------------------------------------------------------//
std::ras::~ras()
{
}
//-----------------------------------------------------------------------------------------------//
bool const std::ras::IsRasConnected()
{
   DWORD dwCb = m_pRasConn->dwSize;
   DWORD dwConnectionsCount = 1;
   /**/
   DWORD dwSuccess = RasEnumConnectionsW(m_pRasConn.operator->(), 
      &dwCb,
      &dwConnectionsCount);
   /**/
   if(dwSuccess == ERROR_SUCCESS)
   {
      if((dwSuccess = RasGetConnectStatusW(m_pRasConn->hrasconn, 
         m_pRasConnStatus.operator->())) == ERROR_SUCCESS)
         if(m_pRasConnStatus->rasconnstate == RASCS_Connected)
            return true;
   }
   return false;
}
//-----------------------------------------------------------------------------------------------//
