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
#include <std.generatecontainermapper.hpp>
#include <std.searchinternalcontainermapper.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class LocateControlMapper: 
      public std::GenerateContainerMapper<QWidget *, QHash<std::ustring, std::Widget *>>
   {
       typedef QHash<std::ustring, std::Widget *> HashT;
   public:
      explicit LocateControlMapper(QWidget * pControl):
      std::GenerateContainerMapper<QWidget *, HashT>(pControl)
      {
      }
      virtual ~LocateControlMapper()
      {
      }
      template <class T> T * CastT(std::Widget * pWidget)
      {
         return reinterpret_cast<T *>(pWidget);
      }
      template <class T> T * CastTo(std::Widget * pWnd)
      {
         return reinterpret_cast<T *>(pWnd);
      }
      template <class T> T * SearchByName(std::ustring const & szName)
      {
         return CastT<T>(Mapper->value(szName));
      }
      template <class T> T * FindT(std::ustring const & szName)
      {
         return CastT<T>(Mapper->value(szName));
      }
   };
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//
