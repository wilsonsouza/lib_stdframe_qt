//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.widgeticon.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
WidgetIcon::WidgetIcon():QIcon(), Widget()
{
   SetName(GetClassName());
}
//-----------------------------------------------------------------------------------------------//
WidgetIcon::WidgetIcon(Widget * _PWidget, QIcon const & _Icon, QSize const & _Size):
QIcon(_Icon), Widget(_PWidget, 0)
{
   SetName(GetClassName());
   m_sSize = _Size;
   m_bPressed = false;
}
//-----------------------------------------------------------------------------------------------//
WidgetIcon::WidgetIcon(Widget * _PWidget, ustring const & _strIconName, QSize const & _Size):
QIcon(_strIconName), Widget(_PWidget, 0)
{
   SetName(GetClassName());
   m_sSize = _Size;
   m_bPressed = false;
}
//-----------------------------------------------------------------------------------------------//
WidgetIcon::~WidgetIcon()
{
}
//-----------------------------------------------------------------------------------------------//
void const WidgetIcon::SetIconFile(QString const & _strIconName)
{
   QIcon _Icon(_strIconName);
   dynamic_cast<QIcon &>(*this) = _Icon;
}
//-----------------------------------------------------------------------------------------------//
void const WidgetIcon::SetIcon(QIcon const & _Icon)
{
   dynamic_cast<QIcon &>(*this) = _Icon;
}
//-----------------------------------------------------------------------------------------------//
void WidgetIcon::paintEvent(QPaintEvent * _PPaintEvent)
{
   QRect _rAreaPoint = _PPaintEvent->rect();
   QPainter _pPainter(this);
   QBrush _bBrush(Qt::cyan);
   QPainterPath _ppPainterPathIcon;

   _ppPainterPathIcon.addRect(0, 0, m_sSize.width(), m_sSize.height());
   _pPainter.drawPath(_ppPainterPathIcon);
   _pPainter.fillPath(_ppPainterPathIcon, _bBrush);

   if(m_bPressed)
      _bBrush.setColor(Qt::red);
}
//-----------------------------------------------------------------------------------------------//
void WidgetIcon::mousePressEvent(QMouseEvent * _PMouseEvent)
{
   m_bPressed = true;
   update();
   emit OnClicked(m_bPressed, this);
   QWidget::mousePressEvent(_PMouseEvent);
}
//-----------------------------------------------------------------------------------------------//
