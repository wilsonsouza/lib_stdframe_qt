//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.treeview.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
TreeView::TreeView(QWidget * pOwner, std::ustring const & strName):QTreeView(pOwner)
{
   SetName(strName);
   SetNotifyEverthing();
   Update();
}
//-----------------------------------------------------------------------------------------------//
TreeView::~TreeView()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
void const TreeView::Update()
{
   this->show();
}
//-----------------------------------------------------------------------------------------------//
void TreeView::SetNotifyEverthing()
{
   connect(this, &QTreeView::collapsed,[=](QModelIndex const & qIndex)
   { emit OnCollapsed(qIndex, this); });
   connect(this, &QTreeView::expanded,[=](QModelIndex const & qIndex)
   { emit OnExpanded(qIndex, this); });
   connect(this, &QTreeView::activated,[=](QModelIndex const & qIndex)
   { emit OnActivated(qIndex, this); });
   connect(this, &QTreeView::clicked,[=](QModelIndex const & qIndex)
   { emit OnClicked(qIndex, this); });
   connect(this, &QTreeView::entered,[=](QModelIndex const & qIndex)
   { emit OnEntered(qIndex, this); });
   connect(this, &QTreeView::pressed,[=](QModelIndex const & qIndex)
   { emit OnPressed(qIndex, this); });
   connect(this, &QTreeView::viewportEntered,[=]()
   { emit OnViewportEntered(this); });
   connect(this, &QTreeView::customContextMenuRequested,[=](QPoint const & pt)
   { emit OnCustomContextMenuRequested(pt, this); });
}
//-----------------------------------------------------------------------------------------------//
