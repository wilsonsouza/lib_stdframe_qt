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
#include <std.action.hpp>
#include <std.toolbaritems.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK ToolBar: public QToolBar
   {
      Q_OBJECT   
   public:
      ToolBar(std::ustring const & strCaption, QWidget * pOwner = nullptr, std::ustring const & strName = "");
      virtual ~ToolBar();
      virtual void const __fastcall Create(ToolBarItems * pItems);
      virtual void const __fastcall SetEnabled(std::ustring const & strButtonName, bool const bEnabled);
      virtual bool const __fastcall IsEnabled(std::ustring const & strButtonName);

      //propertys
      DECLARE_OPERATOR(ToolBar);
   signals:
      void  OnCommand(Action * pAction, ToolBar * pSender);
      void  OnAllowedAreasChanged(Qt::ToolBarAreas tbAreas, ToolBar * pSender);
      void  OnIconSizeChanged(const QSize & sIconsize, ToolBar * pSender);
      void  OnMovableChanged(bool const & bMovable, ToolBar * pSender);
      void  OnOrientationChanged(Qt::Orientation oOrientation, ToolBar * pSender);
      void  OnToolButtonStyleChanged(Qt::ToolButtonStyle tbStyle,  ToolBar * pSender);
      void  OnTopLevelChanged(bool const & bTopLevel,  ToolBar * pSender); 
      void  OnVisibilityChanged(bool const & bVisible,  ToolBar * pSender);

   protected:
      virtual void SetNotifyEverthing();
   };
   //-----------------------------------------------------------------------------------------------//
};