//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.idialogeximpl.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK DialogEx: public IDialogExImpl
   {
      Q_OBJECT
   public:
      explicit DialogEx(QWidget * pOwner, 
         Qt::WindowFlags wf, std::ustring const & strName = std::ustring());
      virtual ~DialogEx();
      virtual int  const __fastcall DoModal();
      virtual void const __fastcall Show();

      DECLARE_OPERATOR(DialogEx);
   public:
      virtual bool const __fastcall OnCreate(DialogEx * pDlg);
      virtual bool const __fastcall OnClose(DialogEx * pDlg);
      virtual bool const __fastcall OnTimer(DialogEx * pDlg, std::Timer * pTimer);
      virtual bool const __fastcall OnNotify(QObject * pSender, 
         QEvent * pEvent, void const * pData);
      virtual bool const __fastcall OnCommand(QObject * lpOwner, void const * pData);
      /**/
   protected:
      virtual bool event(QEvent * e);
      virtual void closeEvent(QCloseEvent * e);
      virtual void timerEvent(QTimerEvent * e);
   };
};
//-----------------------------------------------------------------------------------------------//