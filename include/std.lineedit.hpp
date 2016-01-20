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
   class _DYNAMICLINK LineEdit: public QLineEdit
   {
      Q_OBJECT
   public:
      LineEdit();
      //-----------------------------------------------------------------------------------------------//
      explicit LineEdit(std::ustring const & strName);
      //-----------------------------------------------------------------------------------------------//
      explicit LineEdit(std::ustring const & strName,
         std::ustring const & strMask,
         int const nFixedSizeWidth);
      //-----------------------------------------------------------------------------------------------//
      explicit LineEdit(std::ustring const & strName, 
         int const nMaxLength, 
         int const nFixedSizeWidth);
      //-----------------------------------------------------------------------------------------------//
      explicit LineEdit(QWidget * pOwner, int const nMaxLength = 0xff);
      //-----------------------------------------------------------------------------------------------//
      explicit LineEdit(QWidget * pOwner,
               std::ustring const & strContents,
               int const nMaxLength = 0xff,
               int const nFixedSizeWidth = 0x32,
               std::ustring const & strName = std::ustring());
      //-----------------------------------------------------------------------------------------------//
      virtual ~LineEdit();
      virtual void const SetValidator(QValidator const * pValidator);
      virtual void const SetInputMask(std::ustring const & strMask);
      virtual bool const SetFocusNextChild();
      virtual bool const SetFocusPreviousChild();
      DECLARE_OPERATOR(LineEdit);
      /* properties */
      set_property ( std::ustring, OldData );

      /* events method call */
      set_property ( std::function<void ( int, int, LineEdit * )>, OnCursorPositionChanged );
      set_property ( std::function<void ( LineEdit * )>, OnEditingFinished );
      set_property ( std::function<void ( LineEdit * )>, OnReturnPressed );
      set_property ( std::function<void ( ustring const &, LineEdit * )>, OnTextChanged );
      set_property ( std::function<void ( ustring const &, LineEdit *)>, OnTextEdited );
      set_property ( std::function<void ( LineEdit * )>, OnSelectionChanged );

   protected:
      void const SetNotifyEverthing(bool bEnabled = true);

   protected:
      virtual void keyPressEvent(QKeyEvent * pKey);
   };
};
//-----------------------------------------------------------------------------------------------//

