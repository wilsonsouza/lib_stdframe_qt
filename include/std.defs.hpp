//-----------------------------------------------------------------------------------------------//
// stdx.frame.x86 for Windows
//
// Created by Wilson.Souza 2012
// For 
//
// WR Developer
// (c) 2012, 2013, 2014, 2015
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <qtcore/qtcore>
#include <qtgui/qtgui>
#include <qtwidgets/qtwidgets>
#include <typeinfo>
#include <functional>
#include <memory>
#include <ppl.h>
#include <exception>
#include <string>
#include <map>
#include <hash_map>
#include <list>
#include <string>
//-----------------------------------------------------------------------------------------------//
#include <std.ustring.hpp>
using namespace Concurrency;
//-----------------------------------------------------------------------------------------------//
#define STD(s)   #s
#define _DISABLED 0
//-----------------------------------------------------------------------------------------------//
#if defined(_WINDLL)
   #define _DYNAMICLINK Q_DECL_EXPORT //(dllexport)
#else
   #define _DYNAMICLINK 
#endif
//-----------------------------------------------------------------------------------------------//
namespace std
{
   typedef enum Command
   {
      IDDOK = 1,
      IDDCANCEL,
      IDDHELP,
   } Command;
   //-----------------------------------------------------------------------------------------------//
   typedef enum WMessages
   {
      WM_ICONSIZECHANGED = 1,
      WM_TOOLBUTTONSTYLECHANGED,
      WM_STYLEMODIFIED,
      WM_TREEWIDGET_CURRENTITEMCHANGED,
      WM_TREEWIDGET_ITEMACTIVATED,
      WM_TREEWIDGET_ITEMCHANGED,
      WM_TREEWIDGET_ITEMCLICKED,
      WM_TREEWIDGET_ITEMCOLLAPSED,
      WM_TREEWIDGET_ITEMDOUBLECLICKED,
      WM_TREEWIDGET_ITEMENTERED,
      WM_TREEWIDGET_ITEMEXPANDED,
      WM_TREEWIDGET_ITEMPRESSED,
      WM_TREEWIDGET_ITEMSELECTIONCHANGED,
      WM_TREEWIDGET_UPDATEITEMS,
      WM_LOADDATA
   }WMessages;
   //-----------------------------------------------------------------------------------------------//
#define DECLARE_OPERATOR(_name) \
   public:\
   virtual operator _name *() { return this; }\
   virtual std::ustring const GetClassName() const { return std::ustring(#_name); }\
   virtual _name * operator->() { return  this; }\
   virtual _name & operator *() { return *this; }\
   virtual _name * Get##_name() { return this; }\
   virtual std::ustring GetName(){ return QObject::objectName(); }\
   virtual void const __fastcall SetName(std::ustring const & szName = std::ustring())\
                           {\
   static int s_controlcounter = 0;\
   s_controlcounter++;\
   QObject::setObjectName(szName.isEmpty() ? std::ustring(GetClassName()) + std::ustring("%1").arg(s_controlcounter) : szName); \
                     }\
               __declspec(property(get=GetName, put=SetName)) std::ustring Name;\
   //-----------------------------------------------------------------------------------------------//
#define DECLARE_PROPERTY_METHOD(_get, _set, _type, _newname, _notify)\
   public:\
   virtual void Set##_newname(_type t){ _type old = _get(); _set(t); _notify(this, old, t); }\
   virtual _type Get##_newname(){ return _get();}\
   //-----------------------------------------------------------------------------------------------//
#define set_property(type, name)\
   protected:\
   type m_##name;\
   public:\
   virtual void const __stdcall Set##name(type value)\
                  {\
 m_##name = value;\
                   }\
   virtual type       __stdcall Get##name()\
                  {\
 return m_##name;\
                   }\
__declspec(property(get=Get##name, put=Set##name)) type name;\
   //-----------------------------------------------------------------------------------------------//
#define set_property_readonly(type, name)\
   protected:\
   type m_##name;\
   public:\
   virtual type __stdcall Get##name()\
      {\
 return name;\
       }\
   //-----------------------------------------------------------------------------------------------//
#define DECLARE_LAYOUT_OPERATOR(Class)\
   public:\
   virtual Class * GetLayout() const { return m_pDeclareLayoutOperator; }\
   protected:\
   Class * m_p##Class
   //-----------------------------------------------------------------------------------------------//
#define ALLOC_LAYOUT_OPERATOR(Class, Super)\
   m_p##Class = new Class(Super)
   //-----------------------------------------------------------------------------------------------//
#define SET_CLASS_NAME(first, second)\
   Name = first; if(Name.isEmpty()) Name = second;
   //-----------------------------------------------------------------------------------------------//
#define DECLARE_PROPERTY_READONLY(prefix, _class, varname)\
   public:\
   virtual _class GetProperty##varname() { return prefix##varname; }\
   virtual QString const __fastcall GetName##varname(){ return #varname; }\
   virtual QString const __fastcall GetType##varname(){ return #_class; }\
   virtual QString const __fastcall GetPrefix##varname(){ return #prefix; }\
   //-----------------------------------------------------------------------------------------------//
#define DECLARE_PROPERTY_READWRITE(prefix, _ret, varname, _param)\
   public:\
   virtual _ret GetProperty##varname() { return prefix##varname; }\
   virtual void SetProperty##varname(_param p) { prefix##varname = p; }\
   //-----------------------------------------------------------------------------------------------//
#define CREATE_PROPERTY_READONLY(_classtype, prefix, varname) set_property(_classtype, varname)
   //-----------------------------------------------------------------------------------------------//
#define CREATE_PROPERTY_READWRITE(_classtype, _prefix, _out, _var, _in) set_property(_classtype, _var)
   //-----------------------------------------------------------------------------------------------//
   typedef QStringList StringList;
   typedef QVariant    Variant;
   typedef QString     qstring;
   //----------------------------------------------------------------------------------------------//
   #define DECLARE_PROPERTYS(n)
   //-----------------------------------------------------------------------------------------------//
#if defined(SQL_MANAGER_X86_LIB) && defined(_DEBUG) && defined(_M_IX86)
   #pragma comment(lib,"e:/projects/sql.manager.x86/win32/debug/sql.manager.x86.debug.lib")
#endif
   /**/
#if defined(SQL_MANAGER_X86_LIB) && !defined(_DEBUG) && defined(_M_IX86)
#pragma comment(lib, "e:/projects/sql.manager.x86/win32/release/sql.manager.x86.lib")
#endif
   /**/
#if defined(SQL_MANAGER_X86_LIB) && defined(_DEBUG) && defined(_M_X64)
#pragma comment(lib, "e:/projects/sql.manager.x86/x64/debug/sql.manager.x64.debug.lib")
#endif
   /**/
#if defined(SQL_MANAGER_X86_LIB) && !defined(_DEBUG) && defined(_M_X64)
#pragma comment(lib, "e:/projects/sql.manager.x86/x64/release/sql.manager.x64.lib")
#endif

   /**/
#if defined(STDX_FRAME_X86_LIB) && defined(_DEBUG) && defined(_M_XI86)
#pragma comment(lib, "e:/projects/stdx.frame.x86/win32/debug/stdxframex86debug.lib")
#endif
   /**/
#if defined(STDX_FRAME_X86_LIB) && !defined(_DEBUG) && defined(_M_XI86)
#pragma comment(lib, "e:/projects/stdx.frame.x86/win32/release/stdxframex86.lib")
#endif
   /**/
#if defined(STDX_FRAME_X86_LIB) && defined(_DEBUG) && defined(_M_X64)
#pragma comment(lib, "e:/projects/stdx.frame.x86/x64/debug/stdxframex86debug.x64.lib")
#endif
   /**/
#if defined(STDX_FRAME_X86_LIB) && !defined(_DEBUG) && defined(_M_X64)
#pragma comment(lib, "e:/projects/stdx.frame.x86/x64/release/stdxframex64.lib")
#endif
   /**/
   //-----------------------------------------------------------------------------------------------//
   namespace Library
   {
      static qstring VERSION = "1.0.2012";
      _DYNAMICLINK qstring const __cdecl GetVersion();
   };
};
/*eof*/
