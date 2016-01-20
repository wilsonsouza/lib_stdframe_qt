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
   //-----------------------------------------------------------------------------------------------//
   namespace Captions
   {
      namespace Tabbed
      {
         static std::ustring POSITION         = ustring("Posição");
         static std::ustring SHAPE            = ustring("Modelo");
         static std::ustring CLOSE            = ustring("Fechar");
         static std::ustring NEXT             = ustring("Proximo");
         static std::ustring PREVIEW          = ustring("Anterior");
         static std::ustring PROPERTYS        = ustring("Propriedades");
         //-----------------------------------------------------------------------------------------------//
         static std::ustring POSITION_NORTH   = ustring("Acima das Paginas");
         static std::ustring POSITION_SOUTH   = ustring("Abaixo das Paginas");
         static std::ustring POSITION_WEST    = ustring("A Esquerda das Paginas");
         static std::ustring POSITION_EAST    = ustring("A Direita das Paginas");
         static std::ustring SHAPE_ROUNDED    = ustring("Cantos Redondos");
         static std::ustring SHAPE_TRIANGULAR = ustring("Cantos Triangulares");
         //-----------------------------------------------------------------------------------------------//
         static std::ustring NAME             = ustring("Tabbed-Popup-Menu");
      };
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Icons
   {
      class _DYNAMICLINK Tabbed
      {
      public:
         QIcon * NORTH;       //= QIcon("Action-arrow-up.ico");
         QIcon * SOUTH;       //= QIcon("Action-arrow-down.ico");
         QIcon * WESTH;       //= QIcon("Action-arrow-left.ico");
         QIcon * EAST;        //= QIcon("Action-arrow-right.ico");
         QIcon * CLOSE;       //= QIcon("Action-cancel.ico");
         QIcon * PROPERTYS;   //= QIcon("App-win-settings.ico");
         QIcon * NEXT;        //= QIcon("Action-arrow-blue-double-right.ico");
         QIcon * PREVIEW;     //= QIcon("Action-arrow-blue-double-left.ico");
      public:
         Tabbed()
         {
            NORTH       = new QIcon("Action-arrow-up.ico");
            SOUTH       = new QIcon("Action-arrow-down.ico");
            WESTH       = new QIcon("Action-arrow-left.ico");
            EAST        = new QIcon("Action-arrow-right.ico");
            CLOSE       = new QIcon("Action-cancel.ico");
            PROPERTYS   = new QIcon("App-win-settings.ico");
            NEXT        = new QIcon("Action-arrow-blue-double-right.ico");
            PREVIEW     = new QIcon("Action-arrow-blue-double-left.ico");
         }
      };
   };
};