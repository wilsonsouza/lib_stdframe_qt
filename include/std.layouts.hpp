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
   //-----------------------------------------------------------------------------------------------//
   class VerticalBox;   //QVBoxLayout
   class HorizontalBox; //QHBoxLayout
   class FormBox;       //QFormLayout
   class StackedBox;    //QStackedLayout
   class GridBox;       //QGridLayout
   //-----------------------------------------------------------------------------------------------//
   class VerticalBox: public QVBoxLayout
   {
   public:
      VerticalBox():QVBoxLayout(){}
      explicit VerticalBox(QWidget * pOwner):QVBoxLayout(pOwner){}
   };
   //-----------------------------------------------------------------------------------------------//
   class HorizontalBox: public QHBoxLayout
   {
   public:
      HorizontalBox():QHBoxLayout(){}
      explicit HorizontalBox(QWidget * pOwner):QHBoxLayout(pOwner){}
   };
   //-----------------------------------------------------------------------------------------------//
   class FormBox: public QFormLayout
   {
   public:
      FormBox():QFormLayout(){}
      explicit FormBox(QWidget * pOwner):QFormLayout(pOwner){}
   };
   //-----------------------------------------------------------------------------------------------//
   class StackedBox: public QStackedLayout
   {
   public:
      StackedBox():QStackedLayout(){}
      explicit StackedBox(QWidget * pOwner):QStackedLayout(pOwner){}
   };
   //-----------------------------------------------------------------------------------------------//
   class GridBox: public QGridLayout
   {
   public:
      GridBox():QGridLayout(){}
      explicit GridBox(QWidget * pOwner):QGridLayout(pOwner){}
   };
   //-----------------------------------------------------------------------------------------------//
   template <class T = VerticalBox> 
   class LayoutImpl: public T
   {
   public:
      LayoutImpl():T(){}
      explicit LayoutImpl(QWidget * pOwner):T(pOwner){}
   };
   //-----------------------------------------------------------------------------------------------//
};