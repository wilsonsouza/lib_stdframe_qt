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
#include <std.linedate.hpp>
#include <std.combobox.hpp>
#include <std.checkbox.hpp>
#include <std.textedit.hpp>
#include <std.treewidget.hpp>
#include <std.lcdnumber.hpp>
#include <std.generatecontainermapper.hpp>
#include <std.searchinternalcontainermapper.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   template <class F =  sql::FieldListMapper, class W = QWidget> 
   class _DYNAMICLINK UpdateControlsByMapper: public F, public W
   {
   public:
      UpdateControlsByMapper(F const & fMapper, W const * pWidgetT);
      virtual void const Update(bool const & bEnabled);
      virtual void const SetEnabled(bool const & bEnabled);

      DECLARE_OPERATOR(UpdateControlsByMapper);
   protected:
      std::shared_ptr<std::GenerateContainerMapper<>> m_lpContainer;
   };
   //-----------------------------------------------------------------------------------------------//
   template < class F, class W > __inline 
   UpdateControlsByMapper<F, W>::UpdateControlsByMapper(F const & fMapper, W const * pWidgetT):
   F(const_cast<F &>(fMapper)),
   W(const_cast<W *>(pWidgetT))
   {
      m_lpContainer = std::shared_ptr<GenerateContainerMapper<>>(new GenerateContainerMapper<>(const_cast<W *>(pWidgetT)));
   }
   //-----------------------------------------------------------------------------------------------//
   template < class F, class W > __inline
   void const UpdateControlsByMapper<F, W>::Update(bool const & bEnabled)
   {
      for(auto & i = begin(); i != end(); i++)
      {
         std::ustring strName = i->first;
         sql::shared_field_ptr f = i->second;
         Widget * pWidgetT = m_lpContainer->GetMapper()->value(strName);

         if(pWidgetT)
         {
            std::wstring szName = std::ustring(pWidgetT->objectName());
            /**/
            if(pWidgetT->inherits("std::LineEdit") && szName == f->Name)
            {
               LineEdit * ptr = reinterpret_cast<LineEdit *>(pWidgetT);
               {
                  ptr->setMaxLength(f->Size);
                  ptr->setText(std::ustring(f->Text));
                  ptr->setEnabled(bEnabled);
               }
            }

            if(pWidgetT->inherits("std::LineDate") && szName == f->Name)
            {
               LineDate * ptr = reinterpret_cast<LineDate *>(pWidgetT);
               {
                  ptr->setText(std::ustring(f->Text));
                  ptr->setEnabled(bEnabled);
               }
            }

            if(pWidgetT->inherits("std::TextEdit") && szName == f->Name)
            {
               TextEdit * ptr = reinterpret_cast<TextEdit *>(pWidgetT);
               {
                  ptr->setText(std::ustring(f->Text));
                  ptr->setEnabled(bEnabled);
               }
            }

            if(pWidgetT->inherits("std::CheckBox") && szName == f->Name)
            {
               CheckBox * ptr = reinterpret_cast<CheckBox *>(pWidgetT);
               QChar * pcMode = std::ustring(f->Text).data();

               switch(pcMode->digitValue())
               {
               case Qt::Key_S:
               case Qt::Key_1:
                  ptr->setChecked(true);
                  break;
               case Qt::Key_N:
               case Qt::Key_0:
                  ptr->setChecked(false);
                  break;
               default:
                  ptr->setChecked(f->Bool);
               }

               ptr->setEnabled(bEnabled); 
            }

            if(pWidgetT->inherits("std::ComboBox") && szName == f->Name)
            {
               ComboBox * ptr = reinterpret_cast<ComboBox *>(pWidgetT);
               {
                  emit ptr->OnUpdateCurrentData(ptr, std::ustring(f->Text));
                  ptr->setEnabled(bEnabled);
               }
            }

            if(pWidgetT->inherits("std::TreeWidget") && szName == f->Name)
            {
               TreeWidget * ptr = reinterpret_cast<TreeWidget *>(pWidgetT);
               {
                  /* generate event call */
                  emit ptr->OnNotify(ptr, WM_TREEWIDGET_UPDATEITEMS, f);
               }
            }

            if(pWidgetT->inherits("std::LCDNumber") && szName == f->Name)
            {
               LCDNumber * ptr = reinterpret_cast<LCDNumber *>(pWidgetT);
               {
                  ptr->display(f->Integer);
                  ptr->setEnabled(bEnabled);
               }
            }
         }
      }
   }
   //-----------------------------------------------------------------------------------------------//
   template <class F, class W> __inline 
   void const UpdateControlsByMapper<F, W>::SetEnabled(bool const & bEnabled)
   {
      for(auto & i = begin(); i != end(); i++)
      {
         std::ustring strName = i->first;
         Widget * pWidgetT = m_lpContainer->Mapper->value(strName);

         if(pWidgetT)
            pWidgetT->setEnabled(bEnabled);
      }
   }
   //-----------------------------------------------------------------------------------------------//
};