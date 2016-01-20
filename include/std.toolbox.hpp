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
   class _DYNAMICLINK Widget;
   class _DYNAMICLINK ToolBox: public QToolBox
   {
      Q_OBJECT
   public:
      ToolBox(QWidget * pOwner, std::ustring const & strName = std::ustring(), Qt::WindowFlags wf = 0);
      ToolBox(std::ustring const & strName, Qt::WindowFlags wf = 0);
      virtual ~ToolBox();
      //
      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(ToolBox);
   signals:
      void OnCurrentChanged(int _index, ToolBox * Sender);
   };
};
//-----------------------------------------------------------------------------------------------//

