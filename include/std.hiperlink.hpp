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
#include <std.label.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK HiperLink: public Label
   {
   public:
      explicit HiperLink(QWidget * pOwner, ustring const & szUrl,
         ustring const & szCaption, ustring const & szName = std::ustring());
      virtual ~HiperLink(){}

      DECLARE_OPERATOR(HiperLink);

      void OnLinkUrl(HiperLink * pSender);
      void OnClicked(HiperLink * pSender);

   protected:
      virtual void mouseMoveEvent(QMouseEvent * e);
      virtual void mouseDoubleClickEvent(QMouseEvent * e);
      virtual void mousePressEvent(QMouseEvent * e);
      virtual void mouseReleaseEvent(QMouseEvent * e);
   };
};
//-----------------------------------------------------------------------------------------------//

