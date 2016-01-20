//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.defsx.hpp>
#include <std.statusbar.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
StatusBar::StatusBar(QWidget * pOwner, std::ustring const & strName):QStatusBar(pOwner)
{
   this->m_pListWidget = std::shared_ptr<QList<QWidget *>>(new QList<QWidget *>());
   this->SetName(strName);
   connect(this, &QStatusBar::messageChanged,[=](std::ustring const & strMsg)
   { 
      emit OnMessageChanged(strMsg, this); 
   });
}
//-----------------------------------------------------------------------------------------------//
StatusBar::~StatusBar()
{
   disconnect();
   /* remove all widget on statubar control */
   for(auto p = this->m_pListWidget->begin(); p != this->m_pListWidget->end(); p++)
      this->Remove(p.operator*());
}
//-----------------------------------------------------------------------------------------------//
void StatusBar::AddPermanent(QWidget * pWidget, int nStrecthValue)
{
   this->m_pListWidget->append(pWidget);
}
//-----------------------------------------------------------------------------------------------//
void StatusBar::Add(QWidget * pWidget, int nStrecthValue)
{
   addWidget(pWidget, nStrecthValue);
   this->m_pListWidget->append(pWidget);
}
//-----------------------------------------------------------------------------------------------//
void StatusBar::Remove(QWidget * pWidget)
{
   removeWidget(pWidget);
   update();
   this->m_pListWidget->removeOne(pWidget);
}
//-----------------------------------------------------------------------------------------------//
int StatusBar::InsertPermanent(int nIndex, QWidget * pWidget, int nStrecthValue)
{
   return insertPermanentWidget(nIndex, pWidget,nStrecthValue);
}
//-----------------------------------------------------------------------------------------------//
int StatusBar::Insert(int nIndex, QWidget * pWidget, int nStrecthValue)
{
   this->m_pListWidget->append(pWidget);
   return insertWidget(nIndex, pWidget, nStrecthValue);
}
//-----------------------------------------------------------------------------------------------//
