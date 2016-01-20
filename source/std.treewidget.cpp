//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.defs.hpp>
#include <std.application.hpp>
#include <std.menu.hpp>
#include <std.controls.hpp>
#include <std.treewidget.hpp>
#include <std.mdiframewindow.hpp>
#include <std.mdichildwindow.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
__thiscall TreeWidget::TreeWidget(QWidget * pOwner, std::ustring const & strName):
QTreeWidget(pOwner)
{
   SetName(strName);
   SetAttchWnd(pOwner);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
TreeWidget::~TreeWidget()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
shared_ptr<QList<QTreeWidgetItem *>> TreeWidget::FindItems(const std::ustring & strText, 
   Qt::MatchFlags flags, int const & nColumn )
{
   shared_ptr<QList<QTreeWidgetItem *>> pListItems
   {
      new (nothrow)QList<QTreeWidgetItem *>() 
   };
   ustring Out = ustring
   {
      "Coluna %1 objeto com identificacão invalida!" 
   }.arg(nColumn);

   if (nColumn < 0 || nColumn > columnCount())
   {
      throw exception
      {
         ustring
         {
            ustring{ "Coluna %1 objecto com identificação  invalida " }.arg(nColumn)
         }.to_string().c_str()
      };
   }

   pListItems->append(findItems(strText, flags, nColumn));
   {
      if (pListItems->size() == 0)
      {
         throw exception
         {
            ustring{ ustring{ "item(%s) não encontrado!" }.arg(strText) }.to_string().c_str()
         };
      }
   }
   return pListItems;
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall TreeWidget::UpdateColumns(QStringList const columns)
{
   int i = 0;

   parallel_for_each(columns.begin(), columns.end(), [&](ustring const & c)
   {
      resizeColumnToContents(i++);
   });
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall TreeWidget::UpdateColumnsByHeaderCount()
{
   parallel_for(0, header()->count(), [&](int i)
   {
      resizeColumnToContents(i);
   });
}
//-----------------------------------------------------------------------------------------------//
QTreeWidgetItem * TreeWidget::FindChild(std::ustring const & strData, 
   int const & nIndex, bool const & bExactly)
{
   int nCount = topLevelItemCount();
   /* internal sub function only compatible with CX11 version */
   auto lpfnFindChild = [this](QTreeWidgetItem * pItem, std::ustring const & strData, 
      int const & nIndex, bool bExactly)->QTreeWidgetItem *
   {
      for(int i = 0; i < pItem->childCount(); ++i)
      {
         QTreeWidgetItem * pChild = pItem->child(i);
         /**/
         if(pChild != nullptr)
         {
            std::ustring strT = pChild->text(nIndex);
                  
            if(bExactly)
               strT = strT.left(strData.length());

            if(strT == strData)
               return pChild;
         }
      }
      return nullptr;
   };
   /**/
   for(int nRow = 0; nRow < nCount; ++nRow)
   {
      QTreeWidgetItem * pTop = topLevelItem(nRow);
      /**/
      if(pTop != nullptr)
      {
         std::ustring strT = pTop->text(nIndex);
            
         if(bExactly)
            strT = strT.left(strData.length());

         if(strT == strData)
            return pTop;

         /* find subchild */
         do
         {
            if((pTop = lpfnFindChild(pTop, strData, nRow, bExactly)) == nullptr)
               break;
            else
               return pTop;
         }
         while(true);
      }
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
QTreeWidgetItem * TreeWidget::FindData(std::ustring const & strData, 
         int const & nIndex, bool const & bExactly)
{
   int nOffset = topLevelItemCount();

   for(int nRow = 0; nRow < nOffset; ++nRow)
   {
      QTreeWidgetItem * pTop = topLevelItem(nRow);
      /**/
      if(pTop != nullptr)
      {
         std::ustring strT = pTop->data(nIndex, Qt::UserRole).toString();

         /**/
         if(!bExactly)
            strT = strT.left(strData.length());
         /**/
         if(strT == strData)
            return pTop;
      }
   }
   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
void TreeWidget::SetNotifyEverthing()
{
   connect(this, &QTreeWidget::currentItemChanged,
   [=](QTreeWidgetItem * pCur, QTreeWidgetItem * pPrev)
   {
      emit OnCurrentItemChanged(pCur, pPrev, this);
   });
   connect(this, &QTreeWidget::itemActivated,[=](QTreeWidgetItem * pCur, int nColumn)
   {
      emit OnItemActivated(pCur, nColumn, this);
   });
   connect(this, &QTreeWidget::itemChanged,[=](QTreeWidgetItem * pItem, int nColumn)
   {
      emit OnItemChanged(pItem, nColumn, this);
   });
   connect(this, &QTreeWidget::itemClicked,[=](QTreeWidgetItem * pItem, int nColumn)
   {
      emit OnItemClicked(pItem, nColumn, this);
   });
   connect(this, &QTreeWidget::itemCollapsed,[=](QTreeWidgetItem * pItem)
   {
      emit OnItemCollapsed(pItem, this);
   });
   connect(this, &QTreeWidget::itemDoubleClicked,[=](QTreeWidgetItem * pItem, int nColumn)
   {
      emit OnItemDoubleClicked(pItem, nColumn, this);
   });
   connect(this, &QTreeWidget::itemEntered,[=](QTreeWidgetItem * pCur, int nColumn)
   {
      emit OnItemEntered(pCur, nColumn, this);
   });
   connect(this, &QTreeWidget::itemExpanded,[=](QTreeWidgetItem * pCur)
   {
      emit OnItemExpanded(pCur, this);
   });
   connect(this, &QTreeWidget::itemPressed,[=](QTreeWidgetItem * pCur, int nColumn)
   {
      emit OnItemPressed(pCur, nColumn, this);
   });
   connect(this, &QTreeWidget::itemSelectionChanged,[=]()
   {
      emit OnItemSelectionChanged(this);
   });
}
//-----------------------------------------------------------------------------------------------//
