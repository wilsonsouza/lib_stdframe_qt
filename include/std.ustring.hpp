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
#include <memory>

namespace std
{
   typedef QString qstring;
   typedef QStringList stringlist;
   /**/
   class Q_DECL_EXPORT ustring : public qstring
   {
   public:
      ustring() :qstring(){}
      ustring ( char const * pstr ) :qstring ( this->fromLatin1 ( pstr ) ) { }
      ustring(qstring const & str) :qstring(str){}
      ustring(ustring const & str) :qstring(str){}
      //-----------------------------------------------------------------------------------------------//
      ustring(std::wstring const & str) : qstring()
      {
         push_back ( this->fromUtf16 ( str.c_str ( ) ) );
      }
      //-----------------------------------------------------------------------------------------------//
      ustring ( wchar_t const * wp ) :qstring ( )
      {
         push_back ( this->fromUtf16 ( wp ) );
      }
      //-----------------------------------------------------------------------------------------------//
      bool const compare(wstring const & str) const
      {
         return qstring::compare ( this->fromUtf16 ( str.c_str() ) ) == 0;
      }
      //-----------------------------------------------------------------------------------------------//
      operator wstring const () const
      {
         return std::wstring ( const_cast< wchar_t * >( utf16 ( ) ) );
      }
      //-----------------------------------------------------------------------------------------------//
      operator const string() const
      {
         return std::string ( toLatin1 ( ).data ( ) );
      }
      //-----------------------------------------------------------------------------------------------//
      string to_string() const
      {
         return std::string ( toLatin1 ( ).data ( ) );
      }
      //-----------------------------------------------------------------------------------------------//
      wstring to_wstring ( ) const /*to_wstring, towstring()*/
      {
         return std::wstring ( const_cast< wchar_t * >( utf16 ( ) ) );
      }
      //-----------------------------------------------------------------------------------------------//
      ustring & bind(ustring const & str)
      {
         this->arg(str);
         return *this;
      }
      //-----------------------------------------------------------------------------------------------//
      ustring & bind(wstring const & str)
      {
         this->arg ( this->fromUtf16 ( str.c_str ( ) ) );
         return *this;
      }
      //-----------------------------------------------------------------------------------------------//
      ustring & bind(string const & str)
      {
         this->arg ( str.c_str ( ) );
         return *this;
      }
      //-----------------------------------------------------------------------------------------------//
      ustring & bind(wchar_t const * w)
      {
         this->arg ( this->fromUtf16 ( w ) );
         return *this;
      }
      //-----------------------------------------------------------------------------------------------//
      ustring & bind(stringlist const & s, ustring const & sep = ",")
      {
         this->arg ( s.join ( sep ) );
         return *this;
      }
      //-----------------------------------------------------------------------------------------------//
      ustring & bind(std::list<int> const & l, ustring const & sep = ",")
      {
         std::shared_ptr<stringlist> s { new stringlist { } };
         {
            for ( auto && i : l )
               s->push_back ( ustring { "%1" }.arg ( i ) );
            /**/
            this->arg ( s->join ( sep ) );
         }
         return *this;
      }
      //-----------------------------------------------------------------------------------------------//
      __declspec(property(get = isEmpty)) bool empty;
   };
   //-----------------------------------------------------------------------------------------------//
};