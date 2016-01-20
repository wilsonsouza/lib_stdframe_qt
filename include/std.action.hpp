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
   class _DYNAMICLINK Action;
   class IAction : public QAction
   {
   public:
      explicit IAction(QObject * pOwner) :QAction(pOwner){}
      explicit IAction(ustring const & szCaption, QObject * pOwner) :QAction(szCaption, pOwner){}
      explicit IAction(QIcon const & oIcon, ustring const & szCaption, QObject * pOwner) :
         QAction(oIcon, szCaption, pOwner){}
      virtual ~IAction(){}
      virtual void const OnChanged(Action * pSender) = 0;
      virtual void const OnHovered(Action * pSender) = 0;
      virtual void const OnToggled(bool const & bChecked, Action * pSender) = 0;
      virtual void const OnCommand(bool const & bChecked, Action * pSender) = 0;
      virtual void const OnUpdateUI(Action * pSender, bool const & bValue, unsigned int const & uiValue) = 0;
   protected:
      bool m_bIsLeftPressed;
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK Menu;
   class _DYNAMICLINK Menubar;
   class _DYNAMICLINK MDIFrameWindow;
   class _DYNAMICLINK MainWindow;
   class _DYNAMICLINK Action: public IAction
   {
      Q_OBJECT
   public:
      enum 
      { 
         ENABLED = 1, 
         CHECKED 
      };
   public:
      explicit Action(QObject * pOwner);
      explicit Action(ustring const & strText, QObject * pOwner);
      explicit Action(QIcon const & hIcon, ustring const & strText, QObject * pOwner);
      virtual ~Action();
      virtual operator const QAction *() const;
      /**/
      DECLARE_OPERATOR(Action);
   public:
      /* virtual methods */
      virtual void const OnChanged(Action * pSender);
      virtual void const OnHovered(Action * pSender);
      virtual void const OnToggled(bool const & bChecked, Action * pSender);
      virtual void const OnCommand(bool const & bChecked, Action * pSender);
      virtual void const OnUpdateUI(Action * pSender, bool const & bValue, unsigned int const & uiValue);

   protected:
      virtual void const SetNotifyEverthing();
   };
   //-----------------------------------------------------------------------------------------------//
};