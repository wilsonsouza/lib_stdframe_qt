//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//
// Last update 5-2015
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.hiperlink.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
HiperLink::HiperLink(QWidget * lpOwner, 
   ustring const & szUrl, ustring const & szCaption, ustring const & szName):
Label(lpOwner, szCaption, szName)
{
   shared_ptr<QPalette> pPalette(new QPalette());
   shared_ptr<QColor> pColor(new QColor(Qt::blue));
   /**/
   setAutoFillBackground(true);
   pPalette->setColor(QPalette::Foreground, *pColor);
   setPalette(*pPalette);
   setText(ustring("<a href=\"%1\">%2</a>").arg(szUrl).arg(szCaption));
}
//-----------------------------------------------------------------------------------------------//
void HiperLink::mouseMoveEvent(QMouseEvent * e)
{
   if (childAt(e->pos()) == this)
   {
      setCursor(Qt::PointingHandCursor);
      e->accept();
      return;
   }
   else
   {
      Label::mouseMoveEvent(e);
   }
}
//-----------------------------------------------------------------------------------------------//
void HiperLink::mouseDoubleClickEvent(QMouseEvent * e)
{

}
//-----------------------------------------------------------------------------------------------//
void HiperLink::mousePressEvent(QMouseEvent * e)
{

}
//-----------------------------------------------------------------------------------------------//
void HiperLink::mouseReleaseEvent(QMouseEvent * e)
{

}
//-----------------------------------------------------------------------------------------------//
