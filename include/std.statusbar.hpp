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
//-----------------------------------------------------------------------------------------------//
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK StatusBar: public QStatusBar
   {
   public:
      explicit StatusBar(QWidget * pOwner = nullptr, std::ustring const & strName = "");
      virtual ~StatusBar();

      virtual void AddPermanent(QWidget * lpWidget, int nStrecthValue = 0);
      virtual void Add(QWidget * lpWidget, int nStrecthValue = 0);
      virtual void Remove(QWidget * lpWidget);
      virtual int  InsertPermanent(int nIndex, QWidget * lpWidget, int nStrecthValue = 0);
      virtual int  Insert(int nIndex, QWidget * lpWidget, int nStrecthValue = 0);
      virtual void OnMessageChanged(std::ustring const & strMsg, StatusBar * Sender);
      //
      //propertys
      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(StatusBar);

      __declspec(property(get = currentMessage)) std::ustring CurrentMessage;
      __declspec(property(get = isSizeGripEnabled, put = setSizeGripEnabled)) bool SizeGripEnabled;
      __declspec(property(get = visible, put = setVisible)) bool Visible;
   protected:
      shared_ptr<QList<QWidget *>> m_pListWidget;
   };
};