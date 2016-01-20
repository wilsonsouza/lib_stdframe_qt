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
#include <std.defs.hpp>
#include <std.action.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class ToolButton: public QToolButton
   {
      Q_OBJECT
   public:
      explicit ToolButton(std::ustring const & strName, QIcon const & iIcon);
      explicit ToolButton(QIcon const & iIcon, std::ustring const & strName);
      explicit ToolButton(QWidget * pOwner, std::ustring const & strName, QIcon const & iIcon);
      virtual ~ToolButton();

      DECLARE_OPERATOR(ToolButton);
      /* propertys */
   signals:
      void OnClicked(Action * pAction, ToolButton * Sender);
      void OnUpdateUI(QObject * lpOwner, QVariant oOld, QVariant oNew);

   protected:
      virtual void SetNotifyEverthing();
   };
};
//-----------------------------------------------------------------------------------------------//
