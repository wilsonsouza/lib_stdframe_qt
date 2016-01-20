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
#include <std.label.hpp>
#include <std.progressbar.hpp>
#include <std.button.hpp>
#include <std.layouts.hpp>
#include <std.icons.hpp>
#include <std.widgetimpl.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK MDIChildWindow;
   class _DYNAMICLINK MDIFrameWindow;
   class _DYNAMICLINK DisplayProgressBar: 
      virtual public std::Widget, 
      virtual public std::VerticalBox
   {
      Q_OBJECT
   public:
      explicit DisplayProgressBar(std::MDIFrameWindow * pWnd, std::MDIChildWindow * pChildWnd);
      virtual ~DisplayProgressBar();
      virtual DisplayProgressBar * Create( int const & nOfffset = 0, std::ustring const & szCaption = std::ustring() );
      virtual DisplayProgressBar * Update( std::ustring const & szMessage = std::ustring() );
      virtual DisplayProgressBar * Remove();
      virtual DisplayProgressBar * Reset();
      virtual DisplayProgressBar * SetMax( int const & nMax );
      /**/
      CREATE_PROPERTY_READONLY(std::Button *, m_p, Cancel);
      CREATE_PROPERTY_READONLY(std::ProgressBar *, m_p, Progress);
      CREATE_PROPERTY_READONLY(std::Label *, m_p, Caption);
      CREATE_PROPERTY_READONLY(std::Label *, m_p, SubCaption);
      CREATE_PROPERTY_READWRITE(int, m_n, int>, Counter, int>);
      CREATE_PROPERTY_READWRITE(int, m_n, int>, Total, int>);
      CREATE_PROPERTY_READONLY(std::MDIFrameWindow *, m_p, FrameWindow);
      CREATE_PROPERTY_READONLY(std::MDIChildWindow *, m_p, ChildWindow);
      CREATE_PROPERTY_READONLY(VerticalBox *, m_p, VerticalLay);
      set_property(shared_ptr<IconsImplEx < >> , IconList);
   };
};