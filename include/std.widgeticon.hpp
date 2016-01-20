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
#include <std.defsx.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK WidgetIcon: public Widget, public QIcon
   {
   public:
      WidgetIcon();
      explicit WidgetIcon(Widget * _Parent, QIcon const & _Icon, QSize const & _Size = QSize(0x20, 0x20));
      explicit WidgetIcon(Widget * _Parent, std::ustring const & _strIconName, QSize const & _Size = QSize(0x40, 0x40));
      virtual ~WidgetIcon();

      virtual void const SetIconFile(QString const & _strIconName);
      virtual void const SetIcon(QIcon const & _Icon);
      virtual void paintEvent(QPaintEvent * _PEvent);
      virtual void OnClicked(bool const & bChecked, WidgetIcon * pWidgetIcon);

   protected:
      virtual void mousePressEvent(QMouseEvent * pMouseEvent);

   protected:
      bool m_bPressed;
      QSize m_sSize;
   };
};
//-----------------------------------------------------------------------------------------------//

