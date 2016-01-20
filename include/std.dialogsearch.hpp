//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.dialogex.hpp>
#include <std.lineedit.hpp>
#include <std.groupbox.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace Captions
   {
      namespace Find
      {
         static const std::ustring SELECT_MODE = std::ustring("Selecione a chave de pesquisa");
         static const std::ustring PESQUISAR   = std::ustring("Pesquisar");
         static const std::ustring NAME        = std::ustring("Pesquisar");
         static const std::ustring ITEMS       = std::ustring("items");
         static const std::ustring DATA        = std::ustring("data");
         static const std::ustring TIMER       = std::ustring("find_dlg_item_timer");
      };
   };
   //----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK DialogSearch: public DialogEx
   {
      Q_OBJECT
   public:
      DialogSearch(QWidget * pOwner, std::ustring const & strName);
      virtual ~DialogSearch();
      virtual bool const __fastcall OnCreate(DialogEx * pDlg);

      DECLARE_OPERATOR(DialogSearch);
      CREATE_PROPERTY_READONLY(LineEdit *, m_ple, FindWhat)
      CREATE_PROPERTY_READONLY(GroupBox *, m_pgb, Options)
   };
};