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
#include <std.menu.hpp>
#include <std.tabledefs.hpp>
#include <std.tabledelegate.hpp>
#include <std.tablewidgetitem.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK Table: public QTableWidget
   {
      Q_OBJECT
   public:
      Table(QWidget * pOwner = nullptr, 
         int const & nRows = 0, 
         int const & nCols = 0, 
         std::ustring const & szName = std::ustring());
      __inline virtual ~Table()
      {
         this->disconnect();
      }
   public slots:
      virtual void OnCellActivated(int row, int column, Table * Sender){} 
      virtual void OnCellChanged(int row, int column, Table * Sender){}  
      virtual void OnCellClicked(int row, int column, Table * Sender){}  
      virtual void OnCellDoubleclicked(int row, int column, Table * Sender){}  
      virtual void OnCellEntered(int row, int column, Table * Sender){}  
      virtual void OnCellPressed(int row, int column, Table * Sender){}  
      virtual void OnCellWidget(int x, int y, Table * Sender){}
      virtual void OnCurrentCellChanged(int currentrow, int currentcolumn, int previousrow, int previouscolumn, Table * Sender){}  
      virtual void OnCurrentItemChanged(QTableWidgetItem * current, QTableWidgetItem * previous, Table * Sender){}  
      virtual void OnItemActivated(QTableWidgetItem * item, Table * Sender){}  
      virtual void OnItemChanged(QTableWidgetItem * item, Table * Sender){}  
      virtual void OnItemClicked(QTableWidgetItem * item, Table * Sender){}  
      virtual void OnItemDoubleClicked(QTableWidgetItem * item, Table * Sender){}  
      virtual void OnItemEntered(QTableWidgetItem * item, Table * Sender){}  
      virtual void OnItemPressed(QTableWidgetItem * item, Table * Sender){}  
      virtual void OnItemSelectionChanged(Table * Sender){}  
      //
      virtual void OnCustomContextMenuRequested(const QPoint & pos, Table * Sender){}
      //
   public:
      DECLARE_OPERATOR(Table);
      CREATE_PROPERTY_READWRITE(QTableWidgetItem *, m_p, QTableWidgetItem *, CurrentItem, QTableWidgetItem *);
      CREATE_PROPERTY_READWRITE(std::Menu *, m_p, std::Menu, TableMenu, std::Menu *);
      CREATE_PROPERTY_READONLY(std::shared_ptr<QMutex>, m_p, TableMutex);

   private:
      virtual void SetNotifyEverthing();
   };
   //-----------------------------------------------------------------------------------------------//
};
//-----------------------------------------------------------------------------------------------//