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
#include <std.lineedit.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK LineGroup: 
      public QMap<std::ustring, LineEdit *>, public QObject
   {
   public:
      LineGroup();
      LineGroup(QWidget * pParent, QStringList const & strListQueue);
      LineGroup(QWidget * pParent, QMap<std::ustring, int> const & qQueue);
      virtual ~LineGroup();

      DECLARE_OPERATOR(LineGroup);
   };
};
//-----------------------------------------------------------------------------------------------//

