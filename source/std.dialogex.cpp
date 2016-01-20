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
#include <std.dialogex.hpp>
#include <std.application.hpp>
#include <std.timer.hpp>
#include <std.button.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
DialogEx::DialogEx(QWidget * pOwner, Qt::WindowFlags wf, std::ustring const & strName) :
IDialogExImpl(pOwner, Qt::MSWindowsFixedSizeDialogHint)
{
   m_OK = new Button { nullptr, Captions::OK, m_IconsList->GetCommon()->OK };
   m_Cancel = new Button { nullptr, Captions::CANCEL, m_IconsList->GetCommon()->CANCEL, true };
   m_Help = new Button { nullptr, Captions::HELP, m_IconsList->GetCommon()->HELPINDEX };
   m_Timer = shared_ptr<std::Timer>( new std::Timer( this, GetClassName() ) );
   m_Timer->setInterval(0x64);
}
//-----------------------------------------------------------------------------------------------//
DialogEx::~DialogEx()
{
   cancel();
   disconnect();
}
//-----------------------------------------------------------------------------------------------//
int  const __fastcall DialogEx::DoModal()
{
   setModal(true);
   return this->exec();
}
//-----------------------------------------------------------------------------------------------//
void const __fastcall DialogEx::Show()
{
   setModal(false);
   {
      QDialog::show();
   }
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogEx::OnCreate(DialogEx * pDlg)
{
   m_HorizontalLayButtons->addStretch();
   m_HorizontalLayButtons->addWidget(m_OK);
   m_HorizontalLayButtons->addWidget(m_Cancel);
   m_HorizontalLayButtons->addWidget(m_Help);

   connect(m_OK, &Button::OnClicked,[=](bool const &, Button * pSender)
   {
      OnCommand(pSender, nullptr);
   });
   /**/
   connect(m_Cancel, &Button::OnClicked,[=](bool const &, Button * pSender)
   {
      OnCommand(pSender, nullptr);
   });
   /**/
   connect(m_Help, &Button::OnClicked,[=](bool const &, Button * pSender)
   {
      OnCommand(pSender, nullptr);
   });
   /**/
   connect( Timer.get(), &std::Timer::timeout, [=] ()
   {
      run_and_wait( [&]
      {
         OnTimer( this, m_Timer.get() ); 
      } );
   } );
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogEx::OnClose(DialogEx * pDlg)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogEx::OnTimer(DialogEx * pDlg, std::Timer * pTimer)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogEx::OnNotify(QObject * pSender, QEvent * pEvent, void const * pData)
{
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogEx::OnCommand(QObject * pSender, void const * pData)
{
   if(pSender == m_Cancel)
   {
      setResult(IDDCANCEL);
      close();
      return true;
   }
   /**/
   if ( pSender == m_OK )
   {
      setResult( IDDOK );
   }
   /**/
   if ( pSender == m_Help )
   {
      setResult( IDDHELP );
   }
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool DialogEx::event(QEvent * e)
{
   int ID = e->type();

   if(ID == QEvent::Polish)
   {
      run_and_wait( [&]
      {
         if ( OnCreate( this ) )
         {
            e->accept();
            m_Timer->start();
         }
         else
         {
            e->ignore();
         }
      } );
      return e->isAccepted();
   }
   return QDialog::event(e);
}
//-----------------------------------------------------------------------------------------------//
void DialogEx::closeEvent( QCloseEvent * e )
{
   run_and_wait( [&]
   {
      if ( OnClose( this ) )
      {
         e->accept();
         m_Timer->stop();
      }
      else
      {
         e->ignore();
      }
   } );
}
//-----------------------------------------------------------------------------------------------//
void DialogEx::timerEvent(QTimerEvent * e)
{
   if (e->timerId() == Timer->timerId())
   {
      run_and_wait( [&]
      {
         if ( OnTimer( this, Timer.get() ) )
         {
            e->accept();
         }
         else
         {
            e->ignore();
         }
      } );
   }
}
//-----------------------------------------------------------------------------------------------//
