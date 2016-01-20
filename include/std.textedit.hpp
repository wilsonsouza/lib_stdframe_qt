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
   class _DYNAMICLINK TextEdit: public QTextEdit
   {
      Q_OBJECT
   public:
      TextEdit(QWidget * pOwner = nullptr,
         std::ustring const & strContents = std::ustring(),
         std::ustring const & strName = std::ustring())
      {
         Name = strName;
      }
      TextEdit(std::ustring const & strContents, std::ustring const & strName)
      {
         Name = strName;
      }
      virtual ~TextEdit(){}

      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(TextEdit);
   signals:
      void  OnCopyAvailable(bool bYes, TextEdit * Sender);
      void  OnCurrentCharFormatChanged(const QTextCharFormat & f, TextEdit * Sender);
      void  OnCursorPositionChanged(TextEdit * Sender);
      void  OnRedoAvailable(bool bOK, TextEdit * Sender);
      void  OnSelectionChanged(TextEdit * Sender);
      void  OnTextChanged(TextEdit * Sender);
      void  OnUndoAvailable(bool bOK, TextEdit * Sender);

   protected:
      void SetNotifyEverthing(bool bEnabled = true)
      {
         if (bEnabled)
         {
            connect(this, &QTextEdit::copyAvailable, [=](bool bOK){ emit OnCopyAvailable(bOK, this); });
            connect(this, &QTextEdit::currentCharFormatChanged, [=](const QTextCharFormat & f){ emit OnCurrentCharFormatChanged(f, this); });
            connect(this, &QTextEdit::cursorPositionChanged, [=](){ emit OnCursorPositionChanged(this); });
            connect(this, &QTextEdit::redoAvailable, [=](bool bOK){ emit OnRedoAvailable(bOK, this); });
            connect(this, &QTextEdit::selectionChanged, [=](){ emit OnSelectionChanged(this); });
            connect(this, &QTextEdit::textChanged, [=](){ emit OnTextChanged(this); });
            connect(this, &QTextEdit::undoAvailable, [=](bool bOK){ emit OnUndoAvailable(bOK, this); });
         }
         else
         {
            disconnect();
         }
      }
   };
};
//-----------------------------------------------------------------------------------------------//

