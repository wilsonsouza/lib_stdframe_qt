//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.groupboxbuttonscontrol.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
GroupBoxButtonsControl::GroupBoxButtonsControl(std::ustring const & szCaption, 
   int const & nCols, 
   int const & nOffset):
GroupBoxImpl<VerticalBox>(szCaption, szCaption)
{
   SetCols(nCols);
   SetOffset(nOffset);
   SetName(szCaption);
   SetFontSize(0xc);
   SetFontStyle(QFont::Bold);
   SetButtonSize(shared_ptr<QPoint>(new QPoint{ 0xc, 0xc }));
}
//-----------------------------------------------------------------------------------------------//
GroupBoxButtonsControl::~GroupBoxButtonsControl()
{
   for(auto i = m_Queue->begin(); i != m_Queue->end(); i++)
      i.operator->()->second->disconnect();
}
//-----------------------------------------------------------------------------------------------//
Button * GroupBoxButtonsControl::GetButton(int const nId)
{
   auto p = m_Queue->find(nId);

   if(p != m_Queue->end())
      return p.operator->()->second;

   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
GroupBoxButtonsControl * GroupBoxButtonsControl::Create()
{
   for(int i = 0; i <= m_Offset; ++i)
   {
      WidgetImpl<> * w = new WidgetImpl<>();

      for(int n = 0; n < m_Cols; ++n, ++i)
      {
         Button * b = new Button
         {
            std::ustring(), QIcon(), std::ustring().sprintf("%d", i), true
         };
         QFont f = b->font();
         {
            b->setFixedSize(m_ButtonSize->x(), m_ButtonSize->y());
            f.setPixelSize(m_FontSize);
            f.setStyle(QFont::Style(m_FontStyle));
         }
         w->addWidget(b);
      }

      addWidget(w);
   }
   return this;
}
//-----------------------------------------------------------------------------------------------//
