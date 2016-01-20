//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.widget.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
Widget::Widget(QWidget * pOwner, Qt::WindowFlags f):IWidgetImpl(pOwner, ustring(), f), m_Menu(nullptr)
{
   SetName(GetClassName());
   setContextMenuPolicy(Qt::CustomContextMenu);
}
//-----------------------------------------------------------------------------------------------//
Widget::~Widget()
{
}
//-----------------------------------------------------------------------------------------------//
Widget::operator QWidget *()
{
   return static_cast<QWidget *>(this);
}
//-----------------------------------------------------------------------------------------------//
void Widget::mousePressEvent(QMouseEvent * e)
{
   if (e->button() == Qt::RightButton && childAt(e->pos()) == this)
   {
      OnContextMenuRequested(e->pos(), this);
      return;
   }
   QWidget::mousePressEvent(e);
}
//-----------------------------------------------------------------------------------------------//
void Widget::OnContextMenuRequested(QPoint const & point, IWidgetImpl * lpOwner)
{
   //
}
//-----------------------------------------------------------------------------------------------//
