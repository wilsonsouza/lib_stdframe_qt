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
   class _DYNAMICLINK Label: public QLabel
   {
      Q_OBJECT
   public:
      explicit Label(QWidget * pOwner,
         std::ustring const & szTitle,
         std::ustring const & szName = std::ustring(),
         Qt::WindowFlags wf = 0) :QLabel(pOwner, wf)
      {
         setText(szTitle);
         SetName(szName);
      }
      explicit Label(std::ustring const & szTitle,
         std::ustring const & szName = std::ustring(),
         Qt::WindowFlags wf = 0) :QLabel(nullptr, wf)
      {
         setText(szTitle);
         SetName(szName);
      }
      virtual ~Label(){}
      //propertys
      DECLARE_PROPERTYS(1);
      DECLARE_OPERATOR(Label);
      /**/
      __declspec(property(get=text, put=setText)) std::ustring Text;
   signals:
      void OnLinkActivated(std::ustring const & strLink, Label * Sender);
      void OnLinkHovered(std::ustring const & strLink, Label * Sender);

   protected:
      void SetNotifyEverthing(bool const & bOK = true)
      {
         if (bOK)
         {
            connect(this, &QLabel::linkActivated, [=](std::ustring const & strLink)
            {
               emit OnLinkActivated(strLink, this);
            });
            connect(this, &QLabel::linkHovered, [=](std::ustring const & strLink)
            {
               emit OnLinkHovered(strLink, this);
            });
         }
         else
            disconnect();
      }
   };
};
//-----------------------------------------------------------------------------------------------//

