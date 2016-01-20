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
   class _DYNAMICLINK Button: public QPushButton
   {
      Q_OBJECT
   public:
      explicit Button(std::ustring const & strCaption, 
             QIcon const & Icon, 
             std::ustring const & strName = std::ustring(), 
             bool const & bEnabled = false);
      explicit Button(QWidget * pOwner, 
             std::ustring const & strCaption, 
             QIcon const & _Icon = QIcon(), 
             bool const & bEnabled = false);
      explicit Button(QWidget * pOwner, 
             std::ustring const & strCaption, 
             std::ustring const & strName, 
             QIcon const & _Icon = QIcon(), 
             bool const & bEnabled = false);
      virtual  ~Button();
      void const ShowMenu();
      DECLARE_OPERATOR(Button);

   signals:
      void OnClicked(bool const & bChecked, std::Button * Sender);

   protected:
      virtual void const __fastcall SetNotifyEverything(bool const bEnabled = true);
   };
};
//-----------------------------------------------------------------------------------------------//

