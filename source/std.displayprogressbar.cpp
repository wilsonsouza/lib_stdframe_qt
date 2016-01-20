//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.layouts.hpp>
#include <std.mdichildwindow.hpp>
#include <std.mdiframewindow.hpp>
#include <std.mdiframewindowarea.hpp>
#include <std.displayprogressbar.hpp>
#include <std.statusbar.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
DisplayProgressBar::DisplayProgressBar(std::MDIFrameWindow * pWnd, std::MDIChildWindow * pChildWnd):
std::Widget(nullptr)
{
   SetVerticalLay(new VerticalBox(this));
   SetIconList( shared_ptr<IconsImplEx<>>( new IconsImplEx<>() ) );
   //
   SetFrameWindow(reinterpret_cast<MDIFrameWindow *>(pWnd));
   SetChildWindow(reinterpret_cast<MDIChildWindow *>(pChildWnd));
   //
   SetCaption(new Label(this, "Aguarde..."));
   SetSubCaption(new Label(this, std::ustring()));
   SetProgress(new ProgressBar(this));
   SetCancel(new Button
   {
      this, Captions::CANCEL, m_IconList->GetCommon()->CANCEL
   });
   //
   HorizontalBox * pHBoxBtn = new HorizontalBox();
   {
      pHBoxBtn->addWidget(Cancel);
      pHBoxBtn->addStretch();
   }
   //
   VerticalLay->addWidget(Caption);
   VerticalLay->addWidget(SubCaption);
   VerticalLay->addWidget(Progress);
   VerticalLay->addLayout(pHBoxBtn);
   //
   Progress->setMaximum(0x64);
   Progress->setMinimum(0);
   /**/
   Counter = 0;
   Total = 0;
   //
   Cancel->setEnabled(ChildWindow != nullptr);
   /**/
   QObject::connect(Cancel, &Button::OnClicked,[=](bool const &, Button * Sender)
   {
      ChildWindow->OnNotify(ChildWindow, long(WM_CLOSE), Sender);
   });
   /**/
   Cancel->setEnabled( false );
   std::Widget::update();
}
//-----------------------------------------------------------------------------------------------//
DisplayProgressBar::~DisplayProgressBar()
{
   Remove();
}
//-----------------------------------------------------------------------------------------------//
DisplayProgressBar * DisplayProgressBar::Create( int const & nOffset, std::ustring const & szCaption )
{
   QWidget::setObjectName( szCaption );
   /**/
   if ( FrameWindow->statusBar()->findChild<QWidget *>( szCaption ) )
   {
      Remove();
   }
   /**/
   FrameWindow->statusBar()->addWidget(this);
   SetMax( nOffset <= 0? 1: nOffset );
   Progress->setMaximum( 0x64 );
   Progress->setMinimum( 0 );
   show();
   /**/
   Cancel->setToolTip(tr("Clique aqui para <b>finalizar<\b> o processo!"));
   FrameWindow->statusBar()->update();
   Caption->setText(szCaption);
   Caption->update();
   /**/
   std::Widget::update();
   return this;
}
//-----------------------------------------------------------------------------------------------//
DisplayProgressBar * DisplayProgressBar::Remove()
{
   FrameWindow->statusBar()->removeWidget(this);
   Reset();
   std::Widget::update();
   FrameWindow->statusBar()->update();
   return this;
}
//-----------------------------------------------------------------------------------------------//
DisplayProgressBar * DisplayProgressBar::SetMax( int const & nMax )
{
   Reset();
   Total = nMax;
   return this;
}
//-----------------------------------------------------------------------------------------------//
DisplayProgressBar * DisplayProgressBar::Update( std::ustring const & szMessage )
{
   int n = ++m_Counter;
   int nResult = int(n * 0x64) / m_Total;
   /**/
   if(!szMessage.empty)
   {
      Progress->setValue(nResult);
      std::ustring szFmt = std::ustring().sprintf("%d %", Progress->value());
      /**/
      Progress->setFormat(szFmt);
      Progress->setToolTip(ustring("Operação em andamento.\n"
         "Para finalizar clique no botão <b>Cancelar<\b>.\n"
                                          "%1").arg(szFmt));
      Caption->setText(szMessage);
   }
   else
      Progress->setValue(nResult);

   //process all events on queue and exclude user input events
   FrameWindow->statusBar()->update();
   Progress->update();
   Caption->update();
   SubCaption->update();
   std::Widget::update();
   return this;
}
//-----------------------------------------------------------------------------------------------//
DisplayProgressBar * DisplayProgressBar::Reset()
{
   Progress->reset();
   Counter = 0;
   Total = 0;
   FrameWindow->statusBar()->update();
   std::Widget::update();
   return this;
}
//-----------------------------------------------------------------------------------------------//