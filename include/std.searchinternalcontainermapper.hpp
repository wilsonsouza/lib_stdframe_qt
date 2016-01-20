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
#include <std.generatecontainermapper.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   template <class T = Widget *>
   class _DYNAMICLINK SearchInternalContainerMapper
   {
      typedef QHash<std::ustring, std::Widget *> HashT;
   public:
      SearchInternalContainerMapper(std::shared_ptr<GenerateContainerMapper<T, HashT>> const & pgcMapper)
      {
         m_strName = std::ustring();
         m_pgcMapper = std::shared_ptr<GenerateContainerMapper<T, HashT>>(
            new GenerateContainerMapper<T, HashT>(pgcMapper));
      }
      virtual ~SearchInternalContainerMapper()
      {
         //remove all memory address
      }
      SearchInternalContainerMapper<T> & Search(std::ustring const & strName)
      {
         m_strName = strName;
         return *this;
      }
      T GetResult()
      {
         return m_pgcMapper->Result->value(m_strName);
      }
      void const SetEnabled(ustring const & ustrID, bool const & bEnabled, bool const & bAll = false)
      {
         if(bAll)
         {
            std::shared_ptr<GenerateContainerMapper<T, HashT>::WidgetHashMap> const & pQueue = 
               std::shared_ptr<GenerateContainerMapper<T, HashT>::WidgetHashMap>(
               new GenerateContainerMapper<T, HashT>::WidgetHashMap(m_pgcMapper->WidgetListToMapper().Result));

            if(pQueue->empty())
               return;

            for(GenerateContainerMapper<T, HashT>::WidgetHashMap::const_iterator i = 
               pQueue->begin(); i != pQueue->end(); i++)
               i.value()->Enabled = bEnabled;
         }
         else
         {
            Widget * pWidgetT = Search(ustrID).Result;

            if(pWidgetT)
               pWidgetT->Enabled = bEnabled;
         }
      }
      DECLARE_OPERATOR(SearchInternalContainerMapper)
      __declspec(property(get=GetResult)) T Result;
   protected:
      std::ustring m_strName;
      std::shared_ptr<GenerateContainerMapper<T, HashT>> m_pgcMapper;
   };
};