//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.winsys.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
WinSys::WinSys():WinSysInfo(new SC_WINSYSINFO)
{
   LPSC_WINSYSINFO p = get();
   /**/
   p->pHardware = shared_ptr<HW_PROFILE_INFO>(new HW_PROFILE_INFO);
   p->pSystem = shared_ptr<SYSTEM_INFO>(new SYSTEM_INFO);
   p->pVersion = shared_ptr<OSVERSIONINFOW>(new OSVERSIONINFOW);
   /* alloc mapper processor */
   m_pProcessorList = ProcessorList(new ProcessorListInfo());
   /* alloc mapper processor feature */
   m_pProcessorFeatureList = ProcessorList(new ProcessorListInfo());
   /* fill */
   int i = 0;

   for(i; i < int(sizeof(std::g_pProcessorList) / sizeof(*std::g_pProcessorList)); ++i)
   {
      PSC_LISTPROCESSORINFO pListProcessorInfo = 
         const_cast<PSC_LISTPROCESSORINFO>(g_pProcessorList + i);
      m_pProcessorList->append(pListProcessorInfo);
   }

   for(i = 0; i < int(sizeof(std::g_pProcessorFeatureList) / sizeof(*std::g_pProcessorFeatureList)); ++i)
   {
      PSC_LISTPROCESSORINFO pListProcessorFeature = 
         const_cast<PSC_LISTPROCESSORINFO>(g_pProcessorFeatureList + i);
      m_pProcessorFeatureList->append(pListProcessorFeature);
   }
}
//-----------------------------------------------------------------------------------------------//
WinSys::~WinSys()
{
}
//-----------------------------------------------------------------------------------------------//
WinSysInfo const & WinSys::GetCurrentUserInfo()
{
   LPSC_WINSYSINFO p = get();
   /**/
   p->pHardware;
   return *this;
}
//-----------------------------------------------------------------------------------------------//
WinSysInfo const & WinSys::GetCurrentComputerInfo()
{
   LPSC_WINSYSINFO p = get();
   /**/
   GetSystemInfo(p->pSystem.get());
   /**/
   return *this;
}
//-----------------------------------------------------------------------------------------------//
WinSysInfo const & WinSys::GetCurrentOSInfo()
{
   LPSC_WINSYSINFO p = get();
   /**/
   p->pVersion->dwOSVersionInfoSize = sizeof(p->pVersion.operator*());
   GetVersionExW(p->pVersion.get());
   /**/
   return *this;
}
//-----------------------------------------------------------------------------------------------//
