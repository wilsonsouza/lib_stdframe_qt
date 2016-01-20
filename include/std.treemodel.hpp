//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defs.hpp>
#include <std.controls.hpp>
#include <std.icons.hpp>
#include <sql.table.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK TreeWidget;
   class _DYNAMICLINK MDIChildWindow;
   class _DYNAMICLINK DisplayProgressBar;
   //-----------------------------------------------------------------------------------------------//
   namespace Captions
   {
      namespace TreeModel
      {
         static std::ustring const HEADER  = "m_header";
         static std::ustring const FIELDS  = "m_fields";
         static std::ustring const TABLE   = "m_table";
         static std::ustring const WHERE   = "m_where";
      };
   };
   //-----------------------------------------------------------------------------------------------//
   namespace sqlcmd
   {
      static unsigned int SQL_AS   = 1;
      static unsigned int SQL_NONE = 2;
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Direction
   {
      static unsigned int const TOP    = 0x1000;
      static unsigned int const BOTTOM = 0x2000;
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK TreeModel: 
      public QObject,
      public shared_ptr<QMap<ustring, ustring>>
   {
      Q_OBJECT
   public:
      enum ITEMDIRECTION
      {
         GOTOP  = 0x1000,
         BOTTOM = 0x2000
      };
   public:
      TreeModel(MDIChildWindow * pChildWnd);
      virtual ~TreeModel();
      virtual bool const Build(unsigned int uMode = 0, std::ustring const & strParameters = std::ustring()) = 0;
      virtual bool const Load() = 0;
      //
      virtual StringList __fastcall GetModelHeaderList();
      virtual StringList __fastcall GetModelFieldList();
      virtual std::ustring     __fastcall GetModelFormattedFields();
      //get Tree item
      virtual QTreeWidgetItem * GetItemDirection(ITEMDIRECTION ID) const;
      DECLARE_OPERATOR(TreeModel);
      set_property(MDIChildWindow *, ChildWnd);
      set_property(TreeWidget *, TreeWidgetHandle);
      set_property(shared_ptr<DisplayProgressBar>, DisplayHandle);
      set_property(unsigned int, Rows);
      set_property(shared_ptr<QCursor>, OldCursor);
      set_property(bool, Enabled);
      set_property(unsigned int, IndexKey);
      set_property(std::ustring, TableName);
      set_property(std::ustring, WhereConstraint);
      set_property(unsigned int, SingleQueryLanguageMode); //defined sql format mode
      set_property(shared_ptr<sql::Table>, TableHandle);

   protected:
      virtual unsigned int const __fastcall Execute(std::ustring strFields, std::ustring strTable, std::ustring strConstraint = "");
      virtual void const __fastcall Update();
      virtual void const __fastcall Refresh(StringList const & strListQueue = StringList());
   };
};
//-----------------------------------------------------------------------------------------------//
