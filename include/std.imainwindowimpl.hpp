#pragma once
#include <std.defs.hpp>
#include <std.popup.hpp>

namespace std
{
   class _DYNAMICLINK MenuItemData;
   class _DYNAMICLINK Action;
   class IMainWindowImpl :
      public QMainWindow, public task_group, public shared_ptr < Popup >
   {
   public:
      explicit IMainWindowImpl(QWidget * lpOwner, ustring const & szName, Qt::WindowFlags f) :
         QMainWindow(lpOwner, f), 
         task_group(), 
         shared_ptr<Popup>(new Popup())
      {
         SetName(szName);
      }
      virtual ~IMainWindowImpl(){}
      virtual bool const __fastcall OnCommand(bool const & bChecked, Action * pAction) = 0;
      virtual bool const __fastcall OnCreate(QWidget * pWnd) = 0;
      virtual bool const __fastcall OnClose(QWidget * pWnd) = 0;
      virtual bool const __fastcall OnActivate(QWidget * pWnd) = 0;
      virtual bool const __fastcall OnDeactivate(QWidget * pWnd) = 0;
      virtual bool const __fastcall OnShow(QWidget * pWnd, unsigned int const & uMode) = 0;
      virtual bool const __fastcall OnUpdateUI(QWidget * pWnd, MenuItemData * pUI, bool const & bEnabled) = 0;
      virtual bool const __fastcall OnNotify(QObject * pWnd, unsigned long ulMsg, void const * pData) = 0;
      /**/
      DECLARE_OPERATOR(IMainWindowImpl);
      DECLARE_PROPERTYS(0);
   };
};