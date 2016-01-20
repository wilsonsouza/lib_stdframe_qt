//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.lineedit.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
LineEdit::LineEdit():QLineEdit(std::ustring(), nullptr)
{
   SetName(GetClassName());
   SetNotifyEverthing();
   setText(std::ustring());
   setEchoMode(QLineEdit::Normal);
}
//-----------------------------------------------------------------------------------------------//
LineEdit::LineEdit(std::ustring const & strName):QLineEdit(std::ustring(), nullptr)
{
   SetName(strName);
   SetNotifyEverthing();
   setEchoMode(QLineEdit::Normal);
   setText(std::ustring());
}
//-----------------------------------------------------------------------------------------------//
LineEdit::LineEdit(std::ustring const & strName, 
   std::ustring const & strMask, 
   int const nFixedSizeWidth):QLineEdit(std::ustring(), nullptr)
{
   SetName(strName);
   SetNotifyEverthing();
   SetInputMask(strMask);
   setEchoMode(QLineEdit::Normal);
   setText(std::ustring());
   setMaxLength(strMask.length());
   /**/
   setMaximumWidth(nFixedSizeWidth);
   setMinimumWidth(nFixedSizeWidth);
   setFixedWidth(nFixedSizeWidth);
}
//-----------------------------------------------------------------------------------------------//
LineEdit::LineEdit(std::ustring const & strName, 
   int const nMaxLength, 
   int const nFixedSizeWidth):QLineEdit(std::ustring(), nullptr)
{
   SetName(strName);
   SetNotifyEverthing();
   setEchoMode(QLineEdit::Normal);
   setText(std::ustring());
   setMaxLength((int)nMaxLength);
   /**/
   setMaximumWidth((int)nFixedSizeWidth);
   setMinimumWidth((int)nFixedSizeWidth);
   setFixedWidth(nFixedSizeWidth);
}
//-----------------------------------------------------------------------------------------------//
LineEdit::LineEdit(QWidget * pOwner, int const nMaxLength):QLineEdit(std::ustring(), pOwner)
{
   SetName(GetClassName());
   SetNotifyEverthing();
   setText(std::ustring());
   setEchoMode(QLineEdit::Normal);
   setMaxLength(nMaxLength);
}
//-----------------------------------------------------------------------------------------------//
LineEdit::LineEdit(QWidget * pOwner, 
         std::ustring const & strContents,
         int const nMaxLength,
         int const nFixedSizeWidth,
         std::ustring const & strName):QLineEdit(strContents, pOwner)
{
   SetName(strName);
   SetNotifyEverthing();
   setText(strContents);
   setEchoMode(QLineEdit::Normal);
   setMaxLength(nMaxLength);
   /**/
   setMaximumWidth(nFixedSizeWidth);
   setMinimumWidth(nFixedSizeWidth);
   setFixedWidth(nFixedSizeWidth);
}
//-----------------------------------------------------------------------------------------------//
LineEdit::~LineEdit()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
void const LineEdit::SetValidator(QValidator const * pValidator)
{
   setValidator(pValidator);
}
//-----------------------------------------------------------------------------------------------//
void const LineEdit::SetInputMask(std::ustring const & strMask)
{
   int nFontSize = fontInfo().pixelSize() - 2;
   int nMaskSize = strMask.length();
   {
      if (strMask.length() > 0)
      {
         setInputMask(strMask);
         setMaxLength(strMask.length());
         /**/
         auto fnSetDimensions = [this](int n)
         {
            setMinimumWidth(n);
            setMaximumWidth(n);
         };
         /**/
         fnSetDimensions(nMaskSize * nFontSize);
         show();
      }
   }
}
//-----------------------------------------------------------------------------------------------//
void const LineEdit::SetNotifyEverthing(bool bEnabled)
{
#if(1)
   if(bEnabled)
   {
      connect(this, &QLineEdit::cursorPositionChanged,[=](int nOldPos, int nNewPos)
      { 
         if ( OnCursorPositionChanged )
            OnCursorPositionChanged ( nOldPos, nNewPos, this );
      });
      connect(this, &QLineEdit::editingFinished,[=]()
      { 
         if ( OnEditingFinished )
            OnEditingFinished ( this );
      });
      connect(this, &QLineEdit::returnPressed,[=]()
      { 
         if ( OnReturnPressed )
            OnReturnPressed ( this );
      });
      connect(this, &QLineEdit::selectionChanged,[=]()
      { 
         if ( OnSelectionChanged )
            OnSelectionChanged ( this );
      });
      connect(this, &QLineEdit::textChanged,[=](std::ustring const & strData)
      { 
         if ( OnTextChanged )
            OnTextChanged ( strData, this );
      });
      connect(this, &QLineEdit::textEdited,[=](std::ustring const & strData)
      { 
         if ( OnTextEdited )
            OnTextEdited ( strData, this );
      });
   }
   else
      disconnect();
#endif
}
//-----------------------------------------------------------------------------------------------//
void LineEdit::keyPressEvent(QKeyEvent * e)
{
   int nKey = e->key();
   {
      if ( ( nKey == Qt::Key_Tab || nKey == Qt::Key_Return ) && OnReturnPressed )
      {
         OnReturnPressed ( this );
      }
      else if ( nKey >= Qt::Key_A && nKey <= Qt::Key_Z || nKey >= Qt::Key_0 && nKey <= Qt::Key_9 )
      {
         if ( OnTextChanged )
            OnTextChanged ( text ( ), this );
      }
      else if ( nKey == Qt::Key_Escape )
      {
         /* initialize edit */
         OldData = text ( );
         setText ( ustring { } );
      }
      else
      {
         QLineEdit::keyPressEvent(e);
      }
   }
}
//-----------------------------------------------------------------------------------------------//
bool const LineEdit::SetFocusNextChild()
{
   return focusNextChild();
}
//-----------------------------------------------------------------------------------------------//
bool const LineEdit::SetFocusPreviousChild()
{
   return focusPreviousChild();
}
//-----------------------------------------------------------------------------------------------//

