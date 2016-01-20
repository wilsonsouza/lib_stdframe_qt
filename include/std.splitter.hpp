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
   class _DYNAMICLINK Splitter: public QSplitter
   {
      Q_OBJECT
   public:
      typedef Qt::Orientation ORIENTATION;
   public:
      Splitter(QWidget * pOwner, 
         std::ustring const & strName = std::ustring(), 
         Qt::Orientation direction = Qt::Horizontal):QSplitter(direction, pOwner)
      {
         SetName(strName);
         connect(this, &QSplitter::splitterMoved,[=](int p, int i)
         { 
            emit OnSplitterMoved(p, i, this); 
         });
      }
      virtual ~Splitter()
      {
         disconnect();
      }
      QWidget * operator[](unsigned int uIndex)
      {
         return this->widget(uIndex);
      }
      //propertys
      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(Splitter);
   signals:
      void OnSplitterMoved(int const & _p, int const & _i, Splitter * Sender);
   };
};
//-----------------------------------------------------------------------------------------------//

