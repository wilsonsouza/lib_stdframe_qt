//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.menu.hpp>
#include <std.tabbed.hpp>
#include <std.tabbeddelegate.hpp>
#include <std.tabbedindex.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Tabbed::Tabbed(QWidget * pOwner, std::ustring const & strName):QTabWidget(pOwner)
{
   m_pTabbedIndex = new TabbedIndex(this);
   /**/
   SetName(strName);
   {
      m_pContextMenu = std::shared_ptr<Menu>(new Menu(this, Captions::Tabbed::NAME));
      m_pContextMenu->Create(TabbedMenuItems(), new TabbedDelegate(this));
   }
                                                                  
   TabsCloseable = false;
   connect(this, &QTabWidget::customContextMenuRequested,[=](QPoint const & _Point)
   {
      m_pContextMenu->Execute(&_Point);
   });
   connect(this, &QTabWidget::currentChanged,[=](int nIndex)
   { 
      emit OnCurrentChanged(nIndex, this); 
   });
   connect(this, &QTabWidget::tabCloseRequested,[=](int nIndex)
   { 
      emit OnTabCloseRequested(nIndex, this); 
   });

   QTabBar * pTabBar = QTabWidget::tabBar();
   {
      connect(pTabBar, &QTabBar::tabMoved,[=](int nFrom, int nTo)
      {
      emit OnTabMoved(nFrom, nTo, this);
      });
   }
}
//-----------------------------------------------------------------------------------------------//
Tabbed::~Tabbed()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
int __fastcall Tabbed::GetCount() const
{
   return count();
}
//-----------------------------------------------------------------------------------------------//
Widget * __fastcall Tabbed::operator[](std::ustring const & strName)
{
   Widget * pWidgetT = nullptr;

   for (int i = 0; i < Count; ++i)
   {
      if (widget(i)->objectName() == strName)
         return reinterpret_cast<Widget *>(widget(i));
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
Widget * __fastcall Tabbed::operator[](unsigned int uTabIndex)
{
   return reinterpret_cast<Widget *>(widget(uTabIndex));
}
//-----------------------------------------------------------------------------------------------//
void const Tabbed::SetTabEnabled(int const & nIndex, bool const & bEnabled)
{
   setTabEnabled(nIndex, bEnabled);
}
//-----------------------------------------------------------------------------------------------//
void const Tabbed::SetTabEnabled(bool const & bEnabled)
{
   for(int i = 0; i < Count; ++i)
      setTabEnabled(i, bEnabled);
}
//-----------------------------------------------------------------------------------------------//
bool Tabbed::IsTabEnabled(int const nIndex) const
{
   return isTabEnabled(nIndex);
}
//-----------------------------------------------------------------------------------------------//
QList<bool> Tabbed::IsTabEnabled() const
{
   QList<bool> lsQueue;
         
   for(int i = 0; i < count(); ++i)
      lsQueue.append(isTabEnabled(i));
   return lsQueue;
}
//-----------------------------------------------------------------------------------------------//
void const Tabbed::SetTabIcon(QWidget * pWidget, QIcon const & qIcon)
{
   int i = GetIndex(pWidget);

   if(i != -1)            
      setTabIcon(i, qIcon);
}  
//-----------------------------------------------------------------------------------------------//
void const Tabbed::SetCurrentIndex(QWidget * pWidget)
{
   int n = this->indexOf(pWidget);
   {
      if (n != -1)
      {
         setCurrentIndex(n);
      }
   }
}
//-----------------------------------------------------------------------------------------------//
void Tabbed::Update() const
{
   m_pTabbedIndex->Update();
}
//-----------------------------------------------------------------------------------------------//
void Tabbed::mousePressEvent(QMouseEvent * pMouseEvent)
{
   if(pMouseEvent->button() == Qt::RightButton)
      emit customContextMenuRequested(pMouseEvent->pos()); 
}
//-----------------------------------------------------------------------------------------------//
TabbedIndex * Tabbed::IsTabEnabled(TabbedIndex * _pTabbedIndex)
{
   if(_pTabbedIndex != nullptr)
      _pTabbedIndex->SetEnabled(IsTabEnabled(_pTabbedIndex->Index));

   return _pTabbedIndex;
}
//-----------------------------------------------------------------------------------------------//
void const Tabbed::TabEnabled(TabbedIndex * _pTabbedIndex)
{
   if(_pTabbedIndex != nullptr)
      SetTabEnabled(_pTabbedIndex->Index, _pTabbedIndex->Enabled);
}
//-----------------------------------------------------------------------------------------------//
int Tabbed::GetIndex(QWidget * pWidgetP)
{
   return indexOf(pWidgetP);
}
//-----------------------------------------------------------------------------------------------//
bool Tabbed::event(QEvent * pEvent)
{
   //for(int i; i < this->count(); ++i)
   //   setTabToolTip(i, std::ustring("Clique aqui para fechar..."));

   return QTabWidget::event(pEvent);
}
//-----------------------------------------------------------------------------------------------//

