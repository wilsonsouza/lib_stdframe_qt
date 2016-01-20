//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.label.hpp>
#include <std.toolbutton.hpp>
#include <std.groupboxtopbuttoncontrol.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
GroupBoxTopButtonControl::GroupBoxTopButtonControl():Widget(nullptr, 0)
{
   SetName(GetClassName());
   SetCaption(new Label(ustring()));
   SetIconsList(shared_ptr<IconsImplEx<>>(new IconsImplEx<>()));
   SetTopPlus(new ToolButton(ustring(), m_IconsList->GetCommon()->MINUS));
   SetGroup(new GroupBoxImpl<>(nullptr, ustring()));
   SetVerticalLay(new VerticalBox(this));
}
//-----------------------------------------------------------------------------------------------//
GroupBoxTopButtonControl::GroupBoxTopButtonControl(std::ustring const & szCaption, 
   std::ustring const & szName):
Widget(nullptr, 0)
{
   SetName(szName);
   setWindowTitle(szCaption);
   SetCaption(new Label(ustring()));
   SetIconsList(shared_ptr<IconsImplEx<>>(new IconsImplEx<>()));
   SetTopPlus(new ToolButton(ustring(), m_IconsList->GetCommon()->MINUS));
   SetGroup(new GroupBoxImpl<>(nullptr, ustring()));
   SetVerticalLay(new VerticalBox(this));
}
//-----------------------------------------------------------------------------------------------//
GroupBoxTopButtonControl::~GroupBoxTopButtonControl()
{
   m_TopPlus->disconnect();
}
//-----------------------------------------------------------------------------------------------//
void GroupBoxTopButtonControl::Create()
{
   HorizontalBox * pTop = new HorizontalBox();
   {
      m_TopPlus->setFixedSize(0x10, 0x10);
      m_TopPlus->setIcon(m_IconsList->GetCommon()->PLUS);
      /**/
      if (m_TopPlus->isVisible())
         m_TopPlus->setIcon(m_IconsList->GetCommon()->MINUS);
      /**/
      m_TopPlus->setEnabled(true);
      m_TopPlus->setIconSize(QSize(0xe, 0xe));

      pTop->addWidget([this]()->ToolButton *
      {
         connect(m_TopPlus, &ToolButton::OnClicked,[=](Action * pAction, ToolButton * Sender)
         {
            GetTopPlus()->setIcon(GetIconsList()->GetCommon()->PLUS);
            GetTopPlus()->setVisible(!GetGroup()->isVisible());
            /**/
            if (GetTopPlus()->isVisible())
               GetTopPlus()->setIcon(GetIconsList()->GetCommon()->MINUS);
         });
         return m_TopPlus;
      }());
      /**/
      pTop->addWidget(m_Caption);
   }

   VerticalBox * pBody = new VerticalBox();
   {
      pBody->addLayout(pTop);
      pBody->addWidget(m_Group);
   }

   if(m_Caption->text().length() == 0)
      m_Caption->setText(ustring("Opções de Pesquisa..."));

   m_VerticalLay->addLayout(pBody);
}
//-----------------------------------------------------------------------------------------------//
