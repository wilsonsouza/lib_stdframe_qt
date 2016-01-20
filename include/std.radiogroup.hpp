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
#include <std.radiobutton.hpp>
#include <std.layouts.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class RadioGroup: public QVBoxLayout, public QHash<std::ustring, RadioButton *>
   {
      Q_OBJECT
   public:
      typedef QHash<std::ustring, RadioButton *> HashRadioButtons;
      typedef QList<RadioButton *>         ListRadioButton;
   public:
      RadioGroup();
      virtual ~RadioGroup();
      virtual void AddStringList(StringList const & strListItems);
      virtual void SetEnabled(std::ustring const & strName, bool bEnabled, bool bAll = false);
      virtual bool GetEnabled(std::ustring const & strName);
      virtual RadioButton * GetRadioButton(std::ustring const & strName) const;
      virtual ListRadioButton GetRadioButtonsList() const;
      virtual HashRadioButtons const & GetRadioButtonsMapper() const;
      DECLARE_OPERATOR(RadioGroup)
   signals:
      void OnClicked(bool const & bChecked, RadioButton * Sender);
   };
   //-----------------------------------------------------------------------------------------------//
   __inline RadioGroup::RadioGroup():QVBoxLayout(), QHash<std::ustring, RadioButton *>()
   {
   }
   //-----------------------------------------------------------------------------------------------//
   __inline RadioGroup::~RadioGroup()
   {
      for(auto i = begin(); i != end(); i++)
         i.value()->disconnect();

      clear();
   }
   //-----------------------------------------------------------------------------------------------//
   __inline void RadioGroup::AddStringList(StringList const & strListItems)
   {
      for(auto i = strListItems.begin(); i != strListItems.end(); i++)
      {
         std::ustring strName = i.operator*();
         RadioButton * prbPtr = new RadioButton(strName, strName);

         prbPtr->connect(prbPtr, &RadioButton::OnClicked,[=](bool const & bChecked, RadioButton * Sender)
         {
            emit OnClicked(bChecked, Sender);
         });
      }
   }
   //-----------------------------------------------------------------------------------------------//
   __inline void RadioGroup::SetEnabled(std::ustring const & strName, 
                                        bool bEnabled, 
                                        bool bAll)
   {
      if(bAll)
         for(auto i = begin(); i != end(); i++)
            i.value()->setEnabled(bEnabled);
      else
         if(value(strName) != nullptr)
            value(strName)->setEnabled(bEnabled);
   }
   //-----------------------------------------------------------------------------------------------//
   __inline bool RadioGroup::GetEnabled(std::ustring const & strName)
   {
      RadioButton * prbPtr = value(strName);

      if(prbPtr)
         return prbPtr->isEnabled();

      return false;
   }
   //-----------------------------------------------------------------------------------------------//
   __inline RadioButton * RadioGroup::GetRadioButton(std::ustring const & strName) const
   {
      return value(strName);
   }
   //-----------------------------------------------------------------------------------------------//
   __inline RadioGroup::ListRadioButton RadioGroup::GetRadioButtonsList() const
   {
      return values();
   }
   //-----------------------------------------------------------------------------------------------//
   __inline RadioGroup::HashRadioButtons const & RadioGroup::GetRadioButtonsMapper() const
   {
      return *this;
   }
   //-----------------------------------------------------------------------------------------------//
};