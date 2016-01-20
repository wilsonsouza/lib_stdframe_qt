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
   class _DYNAMICLINK RadioButton: public QRadioButton
   {
      Q_OBJECT
   public:
      explicit RadioButton(QWidget * pOwner = nullptr, 
                  std::ustring const & strName = std::ustring(),
                  bool const & bEnabled = true, 
                  bool const & bChecked = false);
      explicit RadioButton(std::ustring const & strCaption, 
                  std::ustring const & strName = std::ustring(), QWidget * pOwner = nullptr);
      virtual ~RadioButton();

      //propertys
      DECLARE_OPERATOR(RadioButton);
   signals:
      void OnClicked(bool const & bClicked, RadioButton * pSender);
   };
};
//-----------------------------------------------------------------------------------------------//

