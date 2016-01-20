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
//-----------------------------------------------------------------------------------------------//
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK TabbedIndex: public shared_ptr<QList<QWidget *>>
   {
   public:
      explicit TabbedIndex(QTabWidget * pTabbed):
         shared_ptr<QList<QWidget *>>(new QList<QWidget *>()), m_pTabbed(pTabbed)
      {
      }
      //-----------------------------------------------------------------------------------------------//
      explicit TabbedIndex(QTabWidget * pTabbed, int const & _nIndex):
      shared_ptr<QList<QWidget *>>(new QList<QWidget *>()), 
      m_pTabbed(pTabbed), m_index(_nIndex)
      {
      }
      //-----------------------------------------------------------------------------------------------//
      int GetIndex() const
      {
         return m_index;
      }
      //-----------------------------------------------------------------------------------------------//
      void const SetIndex(int const & _nIndex)
      {
         m_index = _nIndex;
      }
      //-----------------------------------------------------------------------------------------------//
      bool IsEnabled()
      {
         if(m_pTabbed)
            return m_pTabbed->isTabEnabled(m_index);
         return false;
      }
      //-----------------------------------------------------------------------------------------------//
      void const SetEnabled(bool bEnabled)
      {
         if(m_pTabbed)
            m_pTabbed->setTabEnabled(m_index, bEnabled);
      }
      //-----------------------------------------------------------------------------------------------//
      void const SetAllEnabled(bool bEnabled)
      {
         for(int i = 0; i < m_pTabbed->count(); ++i)
            m_pTabbed->setTabEnabled(i, bEnabled);
      }
      //-----------------------------------------------------------------------------------------------//
      void const Update()
      {
         auto & p = shared_ptr < QList<QWidget *>>(*this);
         {
            p->clear();

            for (int i = 0; i < m_pTabbed->count(); ++i)
            {
               p->append(m_pTabbed->widget(i));
            }
         }
      }
      //-----------------------------------------------------------------------------------------------//
      __declspec(property(get=GetIndex, put=SetIndex)) int Index;
      __declspec(property(get=IsEnabled, put=SetEnabled)) bool Enabled;
   protected:
      int m_index;
      QTabWidget * m_pTabbed;
   };
};