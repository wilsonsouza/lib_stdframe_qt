//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//
// Last updated by wilson.souza 4-16-2015 modified table operations and events
//-----------------------------------------------------------------------------------------------//
#include <std.table.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Table::Table(QWidget * pOwner, int const & nRows, int const & nCols, std::ustring const & szName):
QTableWidget(pOwner)
{
   SetTableMenu(new Menu(this, Captions::Table::POPUPMENU_NAME));
   GetTableMenu()->Create(TableWidgetItems(), new TableDelegate(this));
   //
   SetName(szName);
   /**/
   if(nRows > 0 && nCols > 0)
   {
      this->setColumnCount(nCols);
      this->setRowCount(nRows);
   }

   //Update columns
   this->resizeColumnsToContents();
   this->setContextMenuPolicy(Qt::DefaultContextMenu);
   //register all signals
   this->SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
void Table::SetNotifyEverthing()
{
   this->connect(this, &QTableWidget::cellActivated,[=](int x, int y)
   { 
      this->OnCellActivated(x, y, this); 
   });
   this->connect(this, &QTableWidget::cellChanged,[=](int x, int y)
   {
      this->OnCellChanged(x, y, this);
   });
   this->connect(this, &QTableWidget::cellClicked,[=](int x, int y)
   {
      this->OnCellClicked(x, y, this);
   });
   this->connect(this, &QTableWidget::cellDoubleClicked,[=](int x, int y)
   {
      this->OnCellDoubleclicked(x, y, this);
   });
   this->connect(this, &QTableWidget::cellEntered,[=](int x, int y)
   {
      this->OnCellEntered(x, y, this);
   });
   this->connect(this, &QTableWidget::cellPressed,[=](int x, int y)
   {
      this->OnCellPressed(x, y, this);
   });
   this->connect(this, &QTableWidget::cellWidget,[=](int x, int y)
   {
      this->OnCellWidget(x, y, this);
   });
   this->connect(this, &QTableWidget::currentCellChanged,[=](int x, int y, int oldx, int oldy)
   {
      this->OnCurrentCellChanged(x, y, oldx, oldy, this);
   });
   this->connect(this, &QTableWidget::currentItemChanged,[=](QTableWidgetItem * c, QTableWidgetItem * p)
   {
      this->OnCurrentItemChanged(c, p, this);
   });
   this->connect(this, &QTableWidget::itemActivated,[=](QTableWidgetItem * p)
   {
      this->OnItemActivated(p, this);
   });
   this->connect(this, &QTableWidget::itemChanged,[=](QTableWidgetItem * p)
   {
      this->OnItemChanged(p, this);
   });
   this->connect(this, &QTableWidget::itemClicked,[=](QTableWidgetItem * p)
   {
      this->OnItemClicked(p, this);
   });
   this->connect(this, &QTableWidget::itemDoubleClicked,[=](QTableWidgetItem * p)
   {
      this->OnItemDoubleClicked(p, this);
   });
   this->connect(this, &QTableWidget::itemEntered,[=](QTableWidgetItem * p)
   {
      this->OnItemEntered(p, this);
   });
   this->connect(this, &QTableWidget::itemPressed,[=](QTableWidgetItem * p)
   {
      this->OnItemPressed(p, this);
   });
   this->connect(this, &QTableWidget::itemSelectionChanged,[=]()
   {
      this->OnItemSelectionChanged(this);
   });
}
//-----------------------------------------------------------------------------------------------//
