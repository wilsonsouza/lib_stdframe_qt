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
#include <std.dialogex.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK AboutDialog: public DialogEx
   {
      Q_OBJECT
   public:
      AboutDialog(QWidget * pOwner, std::ustring const & strCaption);
      virtual ~AboutDialog();
      virtual bool const __fastcall OnCreate(DialogEx * pDlg);
      DECLARE_OPERATOR(AboutDialog);
   };
};