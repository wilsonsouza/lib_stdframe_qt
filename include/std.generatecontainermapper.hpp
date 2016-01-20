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
#include <std.widget.hpp>

namespace std
{
   //-----------------------------------------------------------------------------------------------//
   template <class TWidget = QWidget *, 
             class TMap = QHash<std::ustring, Widget *>>
   class _DYNAMICLINK GenerateContainerMapper
   {
   public:
      typedef TMap WidgetHashMap;
   public:
      GenerateContainerMapper(TWidget pWidget, TMap mapper = TMap())
      {
         m_Controls = pWidget;
         m_Mapper  = std::shared_ptr<TMap>(new TMap(mapper));
         WidgetListToMapper();
      }
      GenerateContainerMapper(std::shared_ptr<GenerateContainerMapper<TWidget, TMap>> const & pgcMapper)
      {
         std::shared_ptr<GenerateContainerMapper<TWidget, TMap>> & pgcM = 
            const_cast<std::shared_ptr<GenerateContainerMapper<TWidget, TMap>> &>(pgcMapper);

         m_Controls = pgcM->operator*().m_Controls;
         m_Mapper = std::shared_ptr<TMap>(new TMap(pgcMapper->operator*().GetMapper().operator*()));
      }
      virtual ~GenerateContainerMapper()
      {
      }
      GenerateContainerMapper<TWidget, TMap> & WidgetListToMapper()
      {
         auto list = m_Controls->findChildren<QWidget *>();

         for(auto i = list.begin(); i != list.end(); i++)
         {
            QWidget * pWnd = i.operator*();

            if(pWnd)
               m_Mapper->operator[](pWnd->objectName()) = reinterpret_cast<Widget *>(pWnd);
         }

         return *this;
      }
      /**/
      CREATE_PROPERTY_READONLY(std::shared_ptr<TMap>, m_p, Result)
      CREATE_PROPERTY_READONLY(std::shared_ptr<TMap>, m_p, Mapper)
      CREATE_PROPERTY_READONLY(TWidget, m_p, Controls)
   };
};