//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.dialoglogin.hpp>
#include <std.label.hpp>
#include <std.button.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
DialogLogin::DialogLogin(QWidget * pOwner, std::ustring const & strCaption):
DialogEx(pOwner, 0, strCaption)
{
   setWindowIcon(m_IconsList->GetCommon()->PASSWORD);
   /**/
   m_User = new LineEdit(Captions::Logon::USERNAME);
   m_Password = new LineEdit(Captions::Logon::PASSWORD);
   m_DomainList = new ComboBox(Captions::Logon::DOMAINID);
   m_pAuthenticate = shared_ptr<sspi>(new sspi());
   m_pStringList = shared_ptr<StringList>(new StringList());
}
//-----------------------------------------------------------------------------------------------//
DialogLogin::~DialogLogin()
{
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogLogin::OnCreate(DialogEx * pDlg)
{
   /* call super and create buttons */
   DialogEx::OnCreate(pDlg);

   FormBox * fb = new FormBox();
   {
      /**/
      fb->addRow(new Label(Captions::Logon::USERNAME), m_User);
      fb->addRow(new Label(Captions::Logon::PASSWORD), m_Password);
      fb->addRow(new Label(Captions::Logon::DOMAINID), m_DomainList);
      /**/
      m_VerticalLay->addLayout(fb);
      m_VerticalLay->addLayout(m_HorizontalLayButtons);
   };

   m_pDNSDeviceInfo = make_shared<DNS_DEVICE_INFO>(m_pAuthenticate->GetComputerDomain());
   /**/
   for(int i = 0; i < ComputerNameMax; ++i)
   {
      ustring s = ustring(m_pDNSDeviceInfo->szName[i]);
      /**/
      if(s.isEmpty())
         continue;

      if(m_pStringList->empty())
         m_pStringList->append(s);
      else
      {
         if(m_pStringList->indexOf(s) == -1)
            m_pStringList->append(s);
      }
   }
   /**/
   m_DomainList->addItems(m_pStringList.operator*());
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogLogin::OnCommand(QObject * lpOwner, void const * pData)
{
   if(lpOwner->objectName() == GetOK()->GetName())
   {
      ustring strDomain = ustring();
      /**/
      if(m_DomainList->currentText().isEmpty())
      {
         if(wstring(m_pDNSDeviceInfo->szName[m_pDNSDeviceInfo->DNS_DOMAIN]).empty())
            strDomain = ustring(m_pDNSDeviceInfo->szName[m_pDNSDeviceInfo->NETBIOS]);
         else
            strDomain = ustring(m_pDNSDeviceInfo->szName[m_pDNSDeviceInfo->DNS_DOMAIN]);
      }
      else
         strDomain = m_DomainList->currentText();
      /**/
      if(m_pAuthenticate->Authenticate(strDomain, std::ustring(m_User->text()), std::ustring(m_Password->text())))
      {
         setResult(Accepted);
         close();
      }
   }
   else if(lpOwner->objectName() == GetCancel()->GetName())
   {
      setResult(Rejected);
      close();
   }
   return true;
}
//-----------------------------------------------------------------------------------------------//
