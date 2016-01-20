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
#include <std.defsx.hpp>
#include <std.layouts.hpp>
#include <std.icons.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Button;
   class _DYNAMICLINK Timer;
   class _DYNAMICLINK DialogEx;
   class _DYNAMICLINK CheckBox;
   class _DYNAMICLINK IDialogExImpl : 
      public QDialog, public task_group
   {
   public:
      explicit IDialogExImpl(QWidget * lpOwner = nullptr,
         Qt::WindowFlags f = 0, ustring const & szName = ustring()) :
         QDialog(lpOwner, f)
      {
         SetName(szName);
         setWindowTitle(szName);
         m_IconsList = shared_ptr<IconsImplEx < >>(new IconsImplEx < >());
         m_VerticalLay = new VerticalBox(this);
         m_HorizontalLay = new HorizontalBox();
         m_HorizontalLayButtons = new HorizontalBox();
      }
      virtual ~IDialogExImpl(){}
      virtual bool const __fastcall OnCreate(DialogEx * pDlg) = 0;
      virtual bool const __fastcall OnClose(DialogEx * pDlg) = 0;
      virtual bool const __fastcall OnTimer(DialogEx * pDlg, std::Timer * pTimer) = 0;
      virtual bool const __fastcall OnNotify(QObject * pSender,
         QEvent * pEvent, void const * pData) = 0;
      virtual bool const __fastcall OnCommand(QObject * lpOwner, void const * pData) = 0;
      /**/
      set_property(Button *, OK);
      set_property(Button *, Cancel);
      set_property(Button *, Help);
      set_property(shared_ptr<IconsImplEx < >>, IconsList);
      set_property(VerticalBox *, VerticalLay);
      set_property(HorizontalBox *, HorizontalLay);
      set_property(HorizontalBox *, HorizontalLayButtons);
      set_property(shared_ptr<Timer>, Timer);
      /**/
      DECLARE_OPERATOR(IDialogExImpl);
   };
};