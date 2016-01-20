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
   class _DYNAMICLINK CheckBox: public QCheckBox
   {
      Q_OBJECT
   public:
      explicit CheckBox(QWidget * pOwner, 
         std::ustring const & strCaption = std::ustring(),
         std::ustring const & strName = std::ustring(),
         bool const & bEnabled = true,
         bool const & bChecked = false);
      explicit CheckBox(std::ustring const & strCaption,
         std::ustring const & strName = std::ustring(),
         bool const & bEnabled = true,
         bool const & bChecked = false);
      virtual ~CheckBox();

      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(CheckBox);
      //
      __declspec(property(get=isChecked, put=setChecked)) bool Checked;
      __declspec(property(get=isEnabled, put=setEnabled)) bool Enabled;
   public:
  signals:
      void OnStateChanged(Qt::CheckState const & csState, CheckBox * Sender);

   protected:
      virtual void const __fastcall SetNotifyEverything();
   };
};
//-----------------------------------------------------------------------------------------------//

