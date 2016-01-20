//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.dialogex.hpp>
#include <std.lineedit.hpp>
#include <std.combobox.hpp>
#include <std.sspi.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   namespace Captions
   {
      namespace Logon
      {
         static const std::ustring USERNAME = std::ustring("Usuário");
         static const std::ustring PASSWORD = std::ustring("Senha  ");
         static const std::ustring DOMAINID = std::ustring("Dominio");
      };
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK DialogLogin: public DialogEx
   {
      Q_OBJECT
   public:
      explicit DialogLogin(QWidget * pOwner, std::ustring const & strCaption);
      virtual ~DialogLogin();
      virtual bool const __fastcall OnCreate(DialogEx * pDlg);
      virtual bool const __fastcall OnCommand(QObject * lpOwner, void const * pData);

      DECLARE_OPERATOR(DialogLogin);
      CREATE_PROPERTY_READONLY(LineEdit *, m_ple, User);
      CREATE_PROPERTY_READONLY(LineEdit *, m_ple, Password);
      CREATE_PROPERTY_READONLY(ComboBox *, m_pcb, DomainList);

   protected:
      shared_ptr<sspi> m_pAuthenticate;
      shared_ptr<StringList> m_pStringList;
      shared_ptr<DNS_DEVICE_INFO> m_pDNSDeviceInfo;
   };
};