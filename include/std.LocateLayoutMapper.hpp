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
   template <typename T = QLayout *>
   class LocateLayoutMapper: 
      public std::GenerateContainerMapper<T, QHash<std::ustring, std::Widget *>>
   {
      typedef QHash<std::ustring, std::Widget *> HashT;
   public:
      explicit LocateLayoutMapper(T pType):std::GenerateContainerMapper<T, HashT>(pType)
      {
      }
      virtual ~LocateLayoutMapper()
      {
      }
      template <class TOut> TOut * CastT(QObject * pObjPtr)
      {
         return reinterpret_cast<TOut *>(pObjPtr);
      }
      template <class TOut> TOut * FindT(std::ustring const & strName)
      {
         std::Widget * pWnd = Result->value(strName);
         return CastT<TOut>(pWnd);
      }
   };
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//
