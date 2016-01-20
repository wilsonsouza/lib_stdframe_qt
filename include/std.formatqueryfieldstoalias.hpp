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
#include <std.labelmodels.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   template <class T = LabelModels<>, class L = StringList >
   class FormatQueryFieldsToAlias: public L
   {
   public:
      explicit FormatQueryFieldsToAlias(T const & lmMapper);
      virtual L const & GetResult() const;

      DECLARE_OPERATOR(FormatQueryFieldsToAlias)
      __declspec(property(get=GetResult)) L const & Result;
   };
   //-----------------------------------------------------------------------------------------------//
   template <class T, class L> __inline
   FormatQueryFieldsToAlias<T, L>::FormatQueryFieldsToAlias(T const & tMapper):T(), L()
   {
      append(tMapper.FormattedQueryFieldsToAlias);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class L> __inline 
   L const & FormatQueryFieldsToAlias<T, L>::GetResult() const
   {
      return *this;
   }
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//
