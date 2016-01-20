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
#include <std.icons.hpp>
#include <std.groupboxtopbuttoncontrol.hpp>
#include <std.widgetimpl.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK ComboBox;
   class _DYNAMICLINK LineEdit;
   class _DYNAMICLINK Button;
   class _DYNAMICLINK SearchWidgetControl: public Widget
   {
      Q_OBJECT
   public:
      typedef std::list<std::pair<std::ustring, std::ustring>> LookInMapper;
      typedef std::list<std::pair<std::ustring, std::ustring>> FindWhatMaskMapper;
   public:
      enum
      {
         IDDMATCHCASE = 1,
         IDDMATCHWHOLEWORD = 2,
         IDDUSE = 4
      };
   public:
      explicit SearchWidgetControl(QWidget * pOwner = nullptr, std::ustring const & strName = std::ustring());
      virtual ~SearchWidgetControl();
      void SetLookInMapper(SearchWidgetControl::LookInMapper const & lmLookIn);
      void SetFindWhatListMask(SearchWidgetControl::FindWhatMaskMapper const & fmFindWhatMask);
      virtual void Create();
      DECLARE_OPERATOR(SearchWidgetControl);
      set_property(std::shared_ptr<std::SearchWidgetControl::LookInMapper>, LookInHasher);
      set_property(std::Button *, OK);
      set_property(std::Button *, Cancel);
      set_property(std::Button *, Help);
      set_property(std::GroupBoxTopButtonControl *, Options);
      set_property(std::LineEdit *, FindWhat);
      set_property(std::ComboBox *, LookIn);
      set_property(std::ComboBox *, RegularExpressions);
      set_property(std::ustring, FilterSelectedName);
      set_property(unsigned int, State);
      set_property(std::shared_ptr<std::SearchWidgetControl::FindWhatMaskMapper>, FindWhatMaskHasher);
      set_property(std::VerticalBox *, VerticalLay);
      set_property(shared_ptr<IconsImplEx<>>, IconsList);
signals:
      void OnFindWhat(std::SearchWidgetControl * pSender);
   };
};
//-----------------------------------------------------------------------------------------------//
