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
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class WaitCursor: public QCursor
   {
   private:
      QWidget * m_pOwner;
      QCursor m_OldCursor;
   public:
      WaitCursor(QWidget * pOwner = nullptr) :QCursor(Qt::WaitCursor), m_pOwner(pOwner)
      {
         if (pOwner)
         {
            m_OldCursor = m_pOwner->cursor();
            pOwner->setCursor(*this);
         }
      }
      virtual ~ WaitCursor()
      {
         Restore();
      }
      virtual void const Wait()
      {
         if (m_pOwner)
            m_pOwner->setCursor(*this);
         else
            QApplication::setOverrideCursor(*this);
      }
      virtual void const Restore()
      {
         if (m_pOwner)
            m_pOwner->setCursor(m_OldCursor);
         else
            QApplication::restoreOverrideCursor();
      }
   };
};