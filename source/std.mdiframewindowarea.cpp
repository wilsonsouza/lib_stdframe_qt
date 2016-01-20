//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.mdiframewindow.hpp>
#include <std.mdichildwindow.hpp>
#include <std.mdiframewindowarea.hpp>
#include <std.application.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
MDIFrameWindowArea::MDIFrameWindowArea(QWidget * pOwner, std::ustring const & strName):
QMdiArea(pOwner),
task_group()
{
   SetName(strName);
   SetFrameWindow(reinterpret_cast<MDIFrameWindow *>(pOwner));
   setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

   //QObject::connect(this, &QMdiArea::subWindowActivated,[=](QMdiSubWindow * pWnd)
   //{
   //   QList<QMdiSubWindow *> pList = subWindowList();
   //   /**/
   //   if(pWnd != nullptr)
   //      reinterpret_cast<MDIChildWindow *>(pWnd)->
   //      OnActivate(reinterpret_cast<MDIChildWindow *>(pWnd));
   //   /**/
   //   if(pList.empty())
   //      return;
   //   /**/
   //   for(QList<QMdiSubWindow *>::Iterator n = pList.begin(); n != pList.end(); n++)
   //   {
   //      QMdiSubWindow * pSubWnd = n.operator*();

   //      if(pSubWnd != pWnd && pSubWnd != nullptr)
   //         reinterpret_cast<MDIChildWindow *>(pSubWnd)->
   //         OnDeactivate(reinterpret_cast<MDIChildWindow *>(pSubWnd));
   //   }
   //});
}
//-----------------------------------------------------------------------------------------------//
MDIFrameWindowArea::~MDIFrameWindowArea()
{
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindowArea::childEvent(QChildEvent * e)
{
   if (e->polished())
   {
      QObject * o = e->child();
      /**/
      if (o->isWindowType())
      {
         std::MDIChildWindow * pWnd = dynamic_cast<std::MDIChildWindow *>(o);
         /**/
         run_and_wait([this, pWnd, e]
         {
            if (!pWnd->OnCreate(pWnd))
               e->ignore();
            else
               e->accept();
         });
      }
   }
}
//-----------------------------------------------------------------------------------------------//
bool MDIFrameWindowArea::event(QEvent * e)
{
   QEvent::Type uId = e->type();
   /**/
   if (uId == QEvent::WindowActivate)
   {
      std::MDIChildWindow * pWnd = this->GetActiveMDIChildWindow();
      /**/
      if (pWnd != nullptr)
      {
         run_and_wait([this, &e, &pWnd]
         {
            if (pWnd->OnActivate(pWnd))
               e->accept();
            else
               e->ignore();
         });
      }
      return e->isAccepted();
   }
   else if (uId == QEvent::WindowDeactivate)
   {
      std::MDIChildWindow * pWnd = this->GetActiveMDIChildWindow();
      /**/
      if (pWnd)
      {
         run_and_wait([this, &pWnd, &e]
         {
            if (pWnd->OnDeactivate(pWnd))
               e->accept();
            else
               e->ignore();
         });
      }
      return e->isAccepted();
   }
   return QMdiArea::event(e);
}
//-----------------------------------------------------------------------------------------------//
QList<QMdiSubWindow *> __fastcall MDIFrameWindowArea::GetListMDIChildWindow() const
{
   return subWindowList();
}
//-----------------------------------------------------------------------------------------------//
MDIChildWindow * __fastcall MDIFrameWindowArea::GetActiveMDIChildWindow() const
{
   return reinterpret_cast<MDIChildWindow *>(currentSubWindow());
}
//-----------------------------------------------------------------------------------------------//
void MDIFrameWindowArea::AddScrollBar(QWidget * pScrollbar, Qt::Alignment halign)
{
}
//-----------------------------------------------------------------------------------------------//
MDIChildWindow * __fastcall MDIFrameWindowArea::operator [](unsigned int uIndex)
{
   QList<QMdiSubWindow *> pSubWindowList = subWindowList();
   unsigned int uLength = pSubWindowList.count();

   if(uIndex < uLength)
      return reinterpret_cast<MDIChildWindow *>(pSubWindowList.operator[](uIndex));

   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
MDIChildWindow * __fastcall MDIFrameWindowArea::operator [](std::ustring const & strName)
{
   QList<QMdiSubWindow *> pSubWindowList = subWindowList();
   /**/
   if(pSubWindowList.empty())
      return nullptr;
   /**/
   for(auto p = pSubWindowList.begin(); p != pSubWindowList.end(); p++)
   {
      MDIChildWindow * pWnd = reinterpret_cast<MDIChildWindow *>(p.operator*());
      ustring strObjectName = pWnd->GetName();
      /**/
      if(strObjectName == strName)
         return pWnd;
   }

   return nullptr;
}
//-----------------------------------------------------------------------------------------------//
