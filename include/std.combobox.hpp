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
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK ComboBox: public QComboBox
   {
      Q_OBJECT
   public:
      explicit ComboBox(std::ustring const & strName = std::ustring(), bool const & bEnabled = true);
      explicit ComboBox(QWidget * pOwner, std::ustring const & strName = std::ustring());
      virtual ~ComboBox();

      struct Item;
      ComboBox & __fastcall operator + (ComboBox::Item & items);
      ComboBox & __fastcall operator + (StringList const & list);
      ComboBox::Item operator[](int index);
      DECLARE_OPERATOR(ComboBox);

      struct Item
      {
         std::ustring strItem;
         Variant vData;
         QIcon qIcon;

         Item(std::ustring const & strItem, QIcon qIcon = QIcon(), Variant const & vData = Variant())
         {
            this->strItem = strItem;
            this->vData = vData;
            this->qIcon = qIcon;
         }
      };
   signals:
      void OnCurrentIndexChanged(int const & nIndex, ComboBox * Sender);
      void OnEditTextChanged(std::ustring const & strText, ComboBox * Sender);
      void OnActivated(int const & nIndex, ComboBox * Sender);
      void OnUpdateCurrentData(ComboBox * Sender, std::ustring const & strData);

   protected:
      void slot_OnCurrentIndexChanged(int nIndex);
      void slot_OnEditTextChanged(std::ustring const & str);
      void slot_OnActivated(int nIndex);
      void SetNotifyEverthing();

   private:
      int m_index;
      std::ustring m_strData;
   };
};
//-----------------------------------------------------------------------------------------------//

