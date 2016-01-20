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
   class _DYNAMICLINK TreeWidgetItem: public QTreeWidgetItem, public QObject
   {
   public:
      TreeWidgetItem(unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(nType){}
      TreeWidgetItem(StringList const & strListQueue,
         unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(strListQueue, nType){}
      TreeWidgetItem(QTreeWidget * pOwner,
         unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(pOwner, nType){}
      TreeWidgetItem(QTreeWidget * pOwner,
         StringList const & oListQueue,
         unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(pOwner, oListQueue, nType){}
      TreeWidgetItem(QTreeWidget * pOwner,
         TreeWidgetItem * pItem, unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(pOwner, pItem, nType){}
      TreeWidgetItem(TreeWidgetItem * pItem,
         unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(pItem, nType){}
      TreeWidgetItem(TreeWidgetItem * pItem,
         StringList const & oListQueue, unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(pItem, oListQueue, nType){}
      TreeWidgetItem(TreeWidgetItem * pOwner,
         TreeWidgetItem * pPreceding, unsigned int const &  nType = QTreeWidgetItem::Type) :
         QTreeWidgetItem(pOwner, pPreceding, nType){}
      TreeWidgetItem(TreeWidgetItem const & oOther) :QTreeWidgetItem(oOther){}
      virtual ~TreeWidgetItem(){}
      //propertys
      DECLARE_OPERATOR(TreeWidgetItem);
      __declspec(property(get = text, put = setText)) std::ustring Text;
      __declspec(property(get = icon, put = setIcon)) QIcon Icon;
   };
};
//-----------------------------------------------------------------------------------------------//
