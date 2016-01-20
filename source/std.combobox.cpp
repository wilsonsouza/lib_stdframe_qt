//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.combobox.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
ComboBox::ComboBox(std::ustring const & strName, bool const & bEnabled):QComboBox(nullptr)
{
   SetName(strName);
   setEditable(false);
   SetNotifyEverthing();
   setEnabled(bEnabled);
}
//-----------------------------------------------------------------------------------------------//
ComboBox::ComboBox(QWidget * pOwner, std::ustring const & strName):
QComboBox(pOwner)
{
   SetName(strName);
   setEditable(false);
   SetNotifyEverthing();
}
//-----------------------------------------------------------------------------------------------//
ComboBox::~ComboBox()
{
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
ComboBox & __fastcall ComboBox::operator + (ComboBox::Item & items)
{
   if(items.qIcon.isNull())
      addItem(items.strItem, items.vData);

   if(!items.qIcon.isNull())
      addItem(items.qIcon, items.strItem, items.vData);

   return *this;
}
//-----------------------------------------------------------------------------------------------//
ComboBox & __fastcall ComboBox::operator + (StringList const & list)
{
   addItems(list);
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ComboBox::Item ComboBox::operator[](int index)
{
   if(index < 0 && index > count())
      return ComboBox::Item(std::ustring());

   return ComboBox::Item(itemText(index), itemIcon(index), itemData(index));
}
//-----------------------------------------------------------------------------------------------//
void ComboBox::slot_OnCurrentIndexChanged(int nIndex)
{
   emit OnCurrentIndexChanged(nIndex, this);
}
//-----------------------------------------------------------------------------------------------//
void ComboBox::slot_OnEditTextChanged(std::ustring const & str)
{
   emit OnEditTextChanged(str, this);
}
//-----------------------------------------------------------------------------------------------//
void ComboBox::slot_OnActivated(int nIndex)
{
   emit OnActivated(nIndex, this);
}
//-----------------------------------------------------------------------------------------------//
void ComboBox::SetNotifyEverthing()
{
   QObject::connect(this, SIGNAL(QComboBox::currentIndexChanged(int)), this, SLOT(slot_OnCurrentIndexChanged(int)));
   QObject::connect(this, SIGNAL(QComboBox::editTextChanged(std::ustring const &)), this, SLOT(slot_OnEditTextChanged(std::ustring const &)));
   QObject::connect(this, SIGNAL(QComboBox::activated(int)), this, SLOT(slot_OnActivated(int)));
}
//-----------------------------------------------------------------------------------------------//


