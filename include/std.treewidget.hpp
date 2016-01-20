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
   class _DYNAMICLINK Menu;
   class _DYNAMICLINK TreeWidget : public QTreeWidget
   {
      Q_OBJECT
   public:
      explicit TreeWidget(QWidget * pOwner = nullptr, std::ustring const & strName = std::ustring());
      virtual ~TreeWidget();

      /* find */
      virtual QTreeWidgetItem * FindChild(std::ustring const & strData, 
         int const & nIndex = 0, bool const & bExactly = true);
      virtual QTreeWidgetItem * FindData(std::ustring const & strData, 
         int const & nIndex, bool const & bExactly = true);
      virtual std::shared_ptr<QList<QTreeWidgetItem *>> FindItems(const std::ustring & strText, 
         Qt::MatchFlags flags, int const & nColumn = 0 );
      /**/
      virtual void const __fastcall UpdateColumns(QStringList const strListColumns);
      virtual void const __fastcall UpdateColumnsByHeaderCount();
      //propertys
   private:
      virtual void SetNotifyEverthing();

   public:
   signals:
      void OnCurrentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous, TreeWidget * Sender); 
      void OnItemActivated(QTreeWidgetItem * item, int const & nColumn, TreeWidget * Sender);  
      void OnItemChanged(QTreeWidgetItem * item, int const & nColumn, TreeWidget * Sender); 
      void OnItemClicked(QTreeWidgetItem * item, int const & nColumn, TreeWidget * Sender); 
      void OnItemCollapsed(QTreeWidgetItem * item, TreeWidget * Sender);  
      void OnItemDoubleClicked(QTreeWidgetItem * item, int const & nColumn, TreeWidget * Sender);
      void OnItemEntered(QTreeWidgetItem * item, int const & nColumn, TreeWidget * Sender);
      void OnItemExpanded(QTreeWidgetItem * item, TreeWidget * Sender); 
      void OnItemPressed(QTreeWidgetItem * item, int const & nColumn, TreeWidget * Sender);
      void OnItemSelectionChanged( TreeWidget * Sender);
      void OnNotify(TreeWidget * Sender, long const & wID, void const * pData);

      DECLARE_OPERATOR(TreeWidget);
      CREATE_PROPERTY_READONLY(Menu *, m_p, MenuContext);
      CREATE_PROPERTY_READONLY(QWidget *, m_p, AttchWnd);
   };
};
//-----------------------------------------------------------------------------------------------//