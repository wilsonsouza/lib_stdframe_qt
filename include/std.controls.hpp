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
#include <std.widget.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Control; 
   class _DYNAMICLINK IControl : public Widget
   {
   public:
      explicit IControl(QWidget * pOwner = nullptr, ustring const & szName = ustring());
      virtual ~IControl(){}
      /**/
      virtual bool OnAction(Control * Sender, QActionEvent * paEvent) = 0;
      virtual bool OnChange(Control * Sender, QEvent * pEvent) = 0;
      virtual bool OnClose(Control * Sender, QEvent * pEvent) = 0;
      virtual bool OnContextMenu(Control * Sender, QContextMenuEvent * pcmEvent) = 0;
      virtual bool OnDragEnter(Control * Sender, QDragEnterEvent * pdeEvent) = 0;
      virtual bool OnDragLeave(Control * Sender, QDragLeaveEvent * pdlEvent) = 0;
      virtual bool OnDragMove(Control * Sender, QDragMoveEvent * pdmEvent) = 0;
      virtual bool OnDrop(Control * Sender, QDropEvent * pdeEvent) = 0;
      virtual bool OnEnter(Control * Sender, QEvent * pEvent) = 0;
      virtual bool OnFocusIn(Control * Sender, QFocusEvent * pEvent) = 0;
      virtual bool OnFocusOut(Control * Sender, QFocusEvent * pEvent) = 0;
      virtual bool OnHide(Control * Sender, QHideEvent * pEvent) = 0;
      virtual bool OnInputMethod(Control * Sender, QInputMethodEvent * pimEvent) = 0;
      virtual bool OnKeyPress(Control * Sender, QKeyEvent * pEvent) = 0;
      virtual bool OnKeyRelease(Control * Sender, QKeyEvent * pEvent) = 0;
      virtual bool OnLeave(Control * Sender, QEvent * pEvent) = 0;
      virtual bool OnMouseDoubleClick(Control * Sender, QMouseEvent * pEvent) = 0;
      virtual bool OnMouseMove(Control * Sender, QMouseEvent * pEvent) = 0;
      virtual bool OnMousePress(Control * Sender, QMouseEvent * pEvent) = 0;
      virtual bool OnMouseRelease(Control * Sender, QMouseEvent * pEvent) = 0;
      virtual bool OnMove(Control * Sender, QMoveEvent * pEvent) = 0;
      virtual bool OnPaint(Control * Sender, QPaintEvent * pEvent) = 0;
      virtual bool OnResize(Control * Sender, QResizeEvent * pEvent) = 0;
      virtual bool OnShow(Control * Sender, QShowEvent * pEvent) = 0;
      virtual bool OnTablet(Control * Sender, QTabletEvent * pEvent) = 0;
      virtual bool OnWheel(Control * Sender, QWheelEvent * pEvent) = 0;
      /**/
      DECLARE_OPERATOR(IControl);
   };
   //-----------------------------------------------------------------------------------------------//
   class Control : public IControl
   {
   public:
      Control(QWidget * pWidget = nullptr, std::ustring const & strName = std::ustring());
      virtual ~Control(){}
      /**/
      virtual bool OnAction(Control * Sender, QActionEvent * paEvent)
      {
         return true;
      }
      virtual bool OnChange(Control * Sender, QEvent * pEvent)
      {
         return true;
      }
      virtual bool OnClose(Control * Sender, QEvent * pEvent)
      {
         return true;
      }
      virtual bool OnContextMenu(Control * Sender, QContextMenuEvent * pcmEvent)
      {
         return true;
      }
      virtual bool OnDragEnter(Control * Sender, QDragEnterEvent * pdeEvent)
      {
         return true;
      }
      virtual bool OnDragLeave(Control * Sender, QDragLeaveEvent * pdlEvent)
      {
         return true;
      }
      virtual bool OnDragMove(Control * Sender, QDragMoveEvent * pdmEvent)
      {
         return true;
      }
      virtual bool OnDrop(Control * Sender, QDropEvent * pdeEvent)
      {
         return true;
      }
      virtual bool OnEnter(Control * Sender, QEvent * pEvent)
      {
         return true;
      }
      virtual bool OnFocusIn(Control * Sender, QFocusEvent * pEvent)
      {
         return true;
      }
      virtual bool OnFocusOut(Control * Sender, QFocusEvent * pEvent)
      {
         return true;
      }
      virtual bool OnHide(Control * Sender, QHideEvent * pEvent)
      {
         return true;
      }
      virtual bool OnInputMethod(Control * Sender, QInputMethodEvent * pimEvent)
      {
         return true;
      }
      virtual bool OnKeyPress(Control * Sender, QKeyEvent * pEvent)
      {
         return true;
      }
      virtual bool OnKeyRelease(Control * Sender, QKeyEvent * pEvent)
      {
         return true;
      }
      virtual bool OnLeave(Control * Sender, QEvent * pEvent)
      {
         return true;
      }
      virtual bool OnMouseDoubleClick(Control * Sender, QMouseEvent * pEvent)
      {
         return true;
      }
      virtual bool OnMouseMove(Control * Sender, QMouseEvent * pEvent)
      {
         return true;
      }
      virtual bool OnMousePress(Control * Sender, QMouseEvent * pEvent)
      {
         return true;
      }
      virtual bool OnMouseRelease(Control * Sender, QMouseEvent * pEvent)
      {
         return true;
      }
      virtual bool OnMove(Control * Sender, QMoveEvent * pEvent)
      {
         return true;
      }
      virtual bool OnPaint(Control * Sender, QPaintEvent * pEvent)
      {
         return true;
      }
      virtual bool OnResize(Control * Sender, QResizeEvent * pEvent)
      {
         return true;
      }
      virtual bool OnShow(Control * Sender, QShowEvent * pEvent)
      {
         return true;
      }
      virtual bool OnTablet(Control * Sender, QTabletEvent * pEvent)
      {
         return true;
      }
      virtual bool OnWheel(Control * Sender, QWheelEvent * pEvent)
      {
         return true;
      }
   };
};
//-----------------------------------------------------------------------------------------------//