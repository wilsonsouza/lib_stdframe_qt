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
#include <std.groupbox.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   template <class T = QVBoxLayout> 
   class GroupBoxImpl: virtual public GroupBox, virtual public T
   {
   public:
      explicit GroupBoxImpl(std::ustring const & szCaption, std::ustring const & szName):
         GroupBox(szCaption, nullptr), T(this)
      {
         SetName(szName);
      }
      explicit GroupBoxImpl(QWidget * pOwner, std::ustring const & szName) :
         GroupBox(szName, pOwner), T(this)
      {
         SetName(szName);
      }
      virtual ~GroupBoxImpl(){}
      /**/
      DECLARE_OPERATOR(GroupBoxImpl);
   };
};
//-----------------------------------------------------------------------------------------------//

