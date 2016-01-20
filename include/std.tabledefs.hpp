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
#include <std.menuitems.hpp>
#include <std.menuitemdata.hpp>
#include <std.submenuitemdata.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace Captions
   {
      namespace Table
      {
         static std::ustring POPUPMENU_NAME        = ustring("Table_PopupMenu");
         static std::ustring INCLUIR               = ustring("&Incluir");
         static std::ustring ALTERAR               = ustring("A&lterar");
         static std::ustring EXCLUIR               = ustring("&Excluir");
         static std::ustring CANCELAR              = ustring("&Cancelar");
         static std::ustring PESQUISAR             = ustring("Pesquisar");
         static std::ustring IMPRIMIR              = ustring("Im&primir");
         static std::ustring VISUALIZAR_IMPRESSAO  = ustring("&Visualizar Impressão");
         static std::ustring CONFIGURAR_PAGINA     = ustring("Con&figurar Pagina");
         static std::ustring CONFIGURAR_IMPRESSORA = ustring("Confi&gurar Impressora");
         static std::ustring IMPORTAR              = ustring("Importar");
         static std::ustring EXPORTAR              = ustring("Exportar");
         static std::ustring PROPERTYS             = ustring("Propriedades");
      };
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Icons
   {
      class _DYNAMICLINK Table
      {
      public:
         QIcon * INCLUIR;
         QIcon * ALTERAR;
         QIcon * CANCELAR;
         QIcon * PESQUISAR;
         QIcon * IMPRIMIR;
         QIcon * PROPERTYS;
      public:
         Table()
         {
            INCLUIR              = new QIcon("Action-edit-add.ico");
            ALTERAR              = new QIcon("Action-edit.ico");
            CANCELAR             = new QIcon("Action-delete.ico");
            PESQUISAR            = new QIcon("Action-find.ico");
            IMPRIMIR             = new QIcon("Action-File-print.ico");
            PROPERTYS            = new QIcon("App-win-settings.ico");
         }
      };
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK TableWidgetItems: public MenuItems, public Icons::Table
   {
   public:
      TableWidgetItems():MenuItems(Captions::Table::POPUPMENU_NAME)
      {
         operator+(new MenuItemData(Captions::Table::INCLUIR, *INCLUIR));
         operator+(new MenuItemData(Captions::Table::ALTERAR, *ALTERAR));
         operator+(new MenuItemData(Captions::Table::EXCLUIR));
         operator+(new MenuItemData(Captions::Table::CANCELAR, *CANCELAR));
         operator+(new MenuItemData(Captions::Table::PESQUISAR, *PESQUISAR));
         Separator();
         operator+(new MenuItemData(Captions::Table::PROPERTYS, *PROPERTYS));
      }
      DECLARE_OPERATOR(TableWidgetItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK TableWidgetSelectionRange: 
      public QTableWidgetSelectionRange, public QObject
   {
   public:
      TableWidgetSelectionRange() :QTableWidgetSelectionRange(){}
      TableWidgetSelectionRange(int nTop,
         int nLeft,
         int nBottom,
         int nRight) :
         QTableWidgetSelectionRange(nTop, nLeft, nBottom, nRight){}
      TableWidgetSelectionRange(QTableWidgetSelectionRange const & Other) :
         QTableWidgetSelectionRange(Other){}

      //propertys
      __declspec(property(get=bottomRow)) int BottomRow;
      __declspec(property(get=columnCount)) int ColumnCount;
      __declspec(property(get=leftColumn)) int LeftColumn;
      __declspec(property(get=rightColumn)) int RightColumn;
      __declspec(property(get=rowCount)) int RowCount;
      __declspec(property(get=topRow)) int TopRow;

      DECLARE_OPERATOR(TableWidgetSelectionRange);
   };
};