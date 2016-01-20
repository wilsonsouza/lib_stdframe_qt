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

namespace std
{
   typedef struct _SC_LISTPROCESSORINFO
   {
      DWORD dwID;
      ustring strName;
   }SC_LISTPROCESSORINFO, *PSC_LISTPROCESSORINFO, *LPSC_LISTPROCESSOINFO;

   static SC_LISTPROCESSORINFO const g_pProcessorList[] =
   {
      { PROCESSOR_ARCHITECTURE_AMD64,  "x64 AMD or Intel." },
      { PROCESSOR_ARCHITECTURE_ARM,    "ARM." },
      { PROCESSOR_ARCHITECTURE_IA64,   "Intel Itanium." },
      { PROCESSOR_ARCHITECTURE_INTEL,  "Intel." },
      { PROCESSOR_ARCHITECTURE_UNKNOWN,"Unknow." }
   };

   static SC_LISTPROCESSORINFO const g_pProcessorFeatureList[] =
   {
 /*     { PF_ARM_64BIT_LOADSTORE_ATOMIC, 
      "The 64-bit load/store atomic instructions are available." },*/
 /*     { PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE,
      "The divide instructions are available." },*/
 /*     { PF_ARM_EXTERNAL_CACHE_AVAILABLE, "The external cache is available." },*/
 //*     { PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE,
 //     "The floating-point multiply-accumulate instruction is available." },
 //     { PF_ARM_VFP_32_REGISTERS_AVAILABLE, */
 //     "The VFP/Neon: 32 x 64bit register bank is present." },
      { PF_3DNOW_INSTRUCTIONS_AVAILABLE, "The 3D-Now instruction set is available." },
      { PF_CHANNELS_ENABLED, "The processor channels are enabled." },
      { PF_COMPARE_EXCHANGE_DOUBLE, 
      "The atomic compare and exchange operation (cmpxchg) is available. " },
      { PF_COMPARE_EXCHANGE128, 
      "The atomic compare and exchange 128-bit operation (cmpxchg16b) is available. " },
      { PF_COMPARE64_EXCHANGE128, 
      "The atomic compare 64 and exchange 128-bit operation (cmp8xchg16) is available." },
 /*     { PF_FASTFAIL_AVAILABLE, "_fastfail() is available." },*/
      { PF_FLOATING_POINT_EMULATED, 
      "Floating-point operations are emulated using a software emulator." },
      { PF_FLOATING_POINT_PRECISION_ERRATA, 
      "On a Pentium, a floating-point precision error can occur in rare circumstances." },
      { PF_MMX_INSTRUCTIONS_AVAILABLE, "The MMX instruction set is available." },
      { PF_NX_ENABLED, "Data execution prevention is enabled." },
      { PF_PAE_ENABLED, "The processor is PAE-enabled. \n"
      "For more information, see Physical Address Extension." },
      { PF_RDTSC_INSTRUCTION_AVAILABLE, "The RDTSC instruction is available." },
      //{ PF_RDWRFSGSBASE_AVAILABLE, 
      //"RDFSBASE, RDGSBASE, WRFSBASE, and WRGSBASE instructions are available." },
      //{ PF_SECOND_LEVEL_ADDRESS_TRANSLATION, 
      //"Second Level Address Translation is supported by the hardware." },
      //{ PF_SSE3_INSTRUCTIONS_AVAILABLE, "The SSE3 instruction set is available." },
      //{ PF_VIRT_FIRMWARE_ENABLED, "Virtualization is enabled in the firmware." },
      { PF_XMMI_INSTRUCTIONS_AVAILABLE, "The SSE instruction set is available." },
      { PF_XMMI64_INSTRUCTIONS_AVAILABLE, "The SSE2 instruction set is available." },
      { PF_XSAVE_ENABLED, 
      "The processor implements the XSAVE and XRSTOR instructions.\n"
      "Windows Server 2008, Windows Vista, Windows Server 2003, and Windows XP/2000:\n"
      "This feature is not supported until Windows 7 and Windows Server 2008 R2."
      }
   };

   typedef struct _SC_WINSYSINFO
   {
      ustring      strOSName;
      ustring      strServicePackName;
      ustring      strProcessorName;
      ustring      strUserName;
      ustring      strDomainName;
      ustring      strComputerName;
      shared_ptr<OSVERSIONINFOW> pVersion;
      shared_ptr<SYSTEM_INFO> pSystem;
      shared_ptr<HW_PROFILE_INFO> pHardware;
   }SC_WINSYSINFO, *PSC_WINSYSINFO, *LPSC_WINSYSINFO;

   typedef shared_ptr<QList<PSC_LISTPROCESSORINFO>> ProcessorList;
   typedef QList<PSC_LISTPROCESSORINFO>             ProcessorListInfo;
   typedef QList<PSC_LISTPROCESSORINFO>::Iterator   ProcessorListIterator;
   typedef ProcessorList                            ProcessorFeatureList;
   typedef ProcessorListIterator                    ProcessorFeatureListIterator;
   typedef shared_ptr<SC_WINSYSINFO>                WinSysInfo;

   class _DYNAMICLINK WinSys: public WinSysInfo, public QObject
   {
   public:
      WinSys();
      virtual ~WinSys();

      virtual WinSysInfo const & GetCurrentUserInfo();
      virtual WinSysInfo const & GetCurrentComputerInfo();
      virtual WinSysInfo const & GetCurrentOSInfo();

      DECLARE_OPERATOR(WinSys);
   protected:
      ProcessorList m_pProcessorList;
      ProcessorFeatureList m_pProcessorFeatureList;
   };
};