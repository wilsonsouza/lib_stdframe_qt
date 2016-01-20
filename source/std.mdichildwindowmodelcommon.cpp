//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.mdichildwindowmodelcommon.hpp>
#include <sql.table.hpp>
#include <std.mdiframewindow.hpp>
#include <sql.query.hpp>
#include <std.icons.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MDIChildWindowModelCommon::MDIChildWindowModelCommon(QWidget * pOwner, std::ustring const & strCaption):
MDIChildWindow(pOwner, strCaption, 0),
LabelModels<>()
{
   SetStartYearFilter(QDate().currentDate().year());
   SetManagerId(MWC_SEARCH|MWC_VIEWED);
   SetTabbedWidget(new TabbedWidgetImpl<>(strCaption));
   SetSearchWidget(new SearchWidgetControl(this));
   SetVerticalBody(new WidgetImpl<std::VerticalBox>());
   SetTable(std::shared_ptr<sql::Table>(new sql::Table
   {
      GetFrameWindow()->GetSingleQueryLanguageHandle()->ConnectParameters
   }));
   /**/
   GetTabbedWidget()->setTabsClosable(false);
   /* start tasks */
}
//-----------------------------------------------------------------------------------------------//
MDIChildWindowModelCommon::~MDIChildWindowModelCommon()
{
   disconnect();
   OnDeactivate(this);
}
//-----------------------------------------------------------------------------------------------//
void const MDIChildWindowModelCommon::OnPrepareWidgets()
{
   StringList strLabelNames = LabelNames;

   if(strLabelNames.count() > 0)
      GetTabbedWidget()->GetControl()->setHeaderLabels(strLabelNames);
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall MDIChildWindowModelCommon::OnCreate(MDIChildWindow * pWnd)
{
   if(pWnd != nullptr)
   {
      GetHorizontalBox()->addWidget(GetTabbedWidget());
      /**/
      GetTabbedWidget()->addTab(GetVerticalBody(), Shared::DETAILS);
      GetTabbedWidget()->addTab(GetSearchWidget(), Shared::SEARCHED);
      /**/
      GetSearchWidget()->Create();
      GetTabbedWidget()->setTabIcon(TAB_DETAILS, windowIcon());
      GetTabbedWidget()->setTabIcon(TAB_SEARCH, IconsImplEx<>().GetEdit()->FIND_REPLACE);
      /**/
      GetVerticalBox()->addWidget(GetHorizontalBox());
   }
   /* trigger to process tasks */
   run_and_wait([&]
   {
      OnCreateFilter();
      OnPrepareWidgets();
      OnCreateWidgets();
      OnLoad();
      OnInitialize();
   });
   /**/
   return true;   
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall MDIChildWindowModelCommon::OnCreateNoAttached(MDIChildWindow * pWnd)
{
   if(pWnd != nullptr)
      GetVerticalBox()->addWidget(GetTabbedWidget());

   /**/
   GetTabbedWidget()->setTabIcon(TAB_DETAILS, windowIcon());
   GetSearchWidget()->Create();
   /* trigger to process tasks */
   emit OnInitialize();
   /**/
}
//-----------------------------------------------------------------------------------------------//

