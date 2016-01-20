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

namespace std
{
   template <class T = LabelModels<>, class H = T::THashStringTableFieldsPointer >
   class LabelModelsToHashMapper: public H
   {
   public:
      LabelModelsToHashMapper();
      explicit LabelModelsToHashMapper(T const & tMapper);
      H const & GetResult() const;

      DECLARE_OPERATOR(LabelModelsToHashMapper)
      __declspec(property(get=GetResult)) H const & Result;
   };
   //-----------------------------------------------------------------------------------------------//
   template < class T, class H > __inline 
   LabelModelsToHashMapper< T, H >::LabelModelsToHashMapper():H()
   {
   }
   //-----------------------------------------------------------------------------------------------//
   template < class T, class H > __inline 
   LabelModelsToHashMapper< T, H >::LabelModelsToHashMapper(T const & tMapper):H()
   {
      H::operator=(tMapper.GetListToHashMapper());
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H > __inline 
   H const & LabelModelsToHashMapper< T, H >::GetResult() const
   {
      return *this;
   }
   //-----------------------------------------------------------------------------------------------//
};