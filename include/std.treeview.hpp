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
   class _DYNAMICLINK TreeView: public QTreeView
   {
      Q_OBJECT
   public:
      TreeView(QWidget * pOwner = nullptr, std::ustring const & strName = std::ustring());
      virtual ~ TreeView();
      virtual void const Update();

      //-----------------------------------------------------------------------------------------------//
      //propertys
      __declspec(property(get=allColumnShowFocus)) bool const AllColumnsHowFocus;
      __declspec(property(get=autoExpandDelay, put=setAutoExpandDelay)) unsigned int const AutoExpandDelay;
      __declspec(property(get=expandOnDoubleClick, put=setExpandOnDoubleClick)) bool const ExpandOnDoubleClick;
      __declspec(property(get=header, put=setHeader)) QHeaderView HeaderView;
      __declspec(property(get=indentation, put=setIndentation)) unsigned int const Indentation;
      __declspec(property(get=isAnimated, put=setAnimated)) bool const Animated;
      __declspec(property(get=isHeaderHidden, put=setHeaderHidden)) bool const HeaderHidden;
      __declspec(property(get=isSortingEnabled, put=setSortingEnabled)) bool const SortingEnabled;
      __declspec(property(get=itemsExpandable, put=setItemsExpandable)) bool const ItemsExpandable;
      __declspec(property(get=rootIsDecorated, put=setRootIsDecorated)) bool const RootIsDecorated;
      __declspec(property(put=setAllColumnsShowFocus)) bool AllColumnsShowFocus;
      __declspec(property(get=uniformRowHeights, put=setUniformRowHeights)) bool const UniformRowHeights;
      __declspec(property(get=wordWrap, put=setWordWrap)) bool const WordWrap;

      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(TreeView);
   signals:
      void  OnCollapsed(const QModelIndex & Index, TreeView * Sender);
      void  OnExpanded(const QModelIndex & Index, TreeView * Sender); 
      void  OnActivated(const QModelIndex & Index, TreeView * Sender);  
      void  OnClicked(const QModelIndex & Index, TreeView * Sender); 
      void  OnDoubleClicked(const QModelIndex & Index, TreeView * Sender); 
      void  OnEntered(const QModelIndex & Index, TreeView * Sender); 
      void  OnPressed(const QModelIndex & Index, TreeView * Sender); 
      void  OnViewportEntered( TreeView * Sender); 
      void  OnCustomContextMenuRequested(QPoint const & pt, TreeView * Sender);

   protected:
      virtual void SetNotifyEverthing();
   };
};
//-----------------------------------------------------------------------------------------------//
