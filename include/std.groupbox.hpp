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
   class _DYNAMICLINK GroupBox: public QGroupBox
   {
      Q_OBJECT
   public:
      explicit GroupBox(std::ustring const & szCaption = ustring(), QWidget * pOwner = nullptr);
      virtual ~GroupBox();
      DECLARE_OPERATOR(GroupBox);
   signals:
      void OnClicked(bool const & bChecked, GroupBox * Sender);
      void OnToggled(bool const & bEnabled, GroupBox * Sender);

   protected:
      void SetNotifyEverthing(bool const & bOK = true);
   };
};
//-----------------------------------------------------------------------------------------------//

