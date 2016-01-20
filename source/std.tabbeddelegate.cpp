//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.tabbeddelegate.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
TabbedDelegate::TabbedDelegate(QTabWidget * pTabbed):Action(pTabbed)
{
}
//-----------------------------------------------------------------------------------------------//
void const TabbedDelegate::OnCommand(bool const & bChecked, Action * Sender)
{
   std::ustring strName = Sender->GetName();
   QTabWidget * pTabbed = reinterpret_cast<QTabWidget *>(parent());

   if(pTabbed == nullptr)
      return;

   if(strName == Captions::Tabbed::POSITION_NORTH)
      pTabbed->setTabPosition(QTabWidget::North);
   else if(strName == Captions::Tabbed::POSITION_SOUTH)
      pTabbed->setTabPosition(QTabWidget::South);
   else if(strName == Captions::Tabbed::POSITION_EAST)
      pTabbed->setTabPosition(QTabWidget::East);
   else if(strName == Captions::Tabbed::POSITION_WEST)
      pTabbed->setTabPosition(QTabWidget::West);

   Sender->setChecked(!Sender->isChecked());
   return;
}
//-----------------------------------------------------------------------------------------------//
