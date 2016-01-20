//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.button.hpp>
#include <std.widgetimpl.hpp>
#include <std.label.hpp>
#include <std.aboutdialog.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
AboutDialog::AboutDialog(QWidget * pOwner, std::ustring const & strCaption):
DialogEx(pOwner, 0, strCaption)
{
}
//-----------------------------------------------------------------------------------------------//
AboutDialog::~AboutDialog()
{
   m_OK->disconnect();
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall AboutDialog::OnCreate(DialogEx * pDlg)
{
   std::WidgetImpl<> * pQueue = new std::WidgetImpl<>();
   std::ustring strAppName = qApp->applicationDisplayName();
   std::ustring strVersion = qApp->applicationVersion();
   std::ustring strCopy    = qApp->organizationName();
   std::ustring strDomain  = std::ustring("Created by Wilson Souza");
   /**/
   QObject::connect(m_OK, &Button::OnClicked, [=](bool const &, Button * pOwner)
   { 
      close();  
   });
   /**/
   pQueue->addWidget(new std::Label(strAppName + " " + strVersion), 0, Qt::AlignCenter);
   pQueue->addWidget(new std::Label(strCopy), 0, Qt::AlignCenter);
   pQueue->addWidget(new std::Label(strDomain), 0, Qt::AlignCenter);
   pQueue->addStretch();
   pQueue->addStretch();
   pQueue->addWidget(m_OK, 0, Qt::AlignCenter);
   setMaximumSize(strDomain.length() * 15, 250);
   m_VerticalLay->addWidget(pQueue->operator QWidget *());
   m_OK->setEnabled(true);
   setLayout(m_VerticalLay);
   return true;
}
//-----------------------------------------------------------------------------------------------//

