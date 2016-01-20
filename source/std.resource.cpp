//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.defsx.hpp>
#include <std.resource.hpp>
#include <std.layouts.hpp>
#include <std.button.hpp>
#include <std.progressbar.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
using namespace resource;
//-----------------------------------------------------------------------------------------------//
Resource::Resource():Widget(nullptr)
{
   Name = GetClassName();
   m_pblHBoxLayout = new QHBoxLayout(this);
   m_ppbBar = new ProgressBar(this);
   m_pbCancel = new Button(this, Captions::CANCEL, Icons::Common().CANCEL);

   m_pblHBoxLayout->addWidget(m_pbCancel);
   m_pblHBoxLayout->addWidget(m_ppbBar);
}
//-----------------------------------------------------------------------------------------------//
Resource::Resource(Widget * pwParent, std::ustring const & strName):Widget(pwParent, 0)
{
   SetName(strName);
   m_pblHBoxLayout = new QHBoxLayout(this);
   m_ppbBar = new ProgressBar(this);
   m_pbCancel = new Button(this, Captions::CANCEL, Icons::Common().CANCEL);

   m_pblHBoxLayout->addWidget(m_pbCancel);
   m_pblHBoxLayout->addWidget(m_ppbBar);
}
//-----------------------------------------------------------------------------------------------//
Resource::~Resource()
{
}
//-----------------------------------------------------------------------------------------------//
void const Resource::Process(Compiler const & cCompiler)
{
   Compiler * pcPtr = dynamic_cast<Compiler *>(&const_cast<Compiler &>(cCompiler));

   if (pcPtr->QFile::fileName().isEmpty())
      throw exception("Identificação do arquivo de recurso indefinada!");

   QDir * pdDir = &QDir(pcPtr->m_ustrPath, pcPtr->m_ustrExtension);
   QFileInfoList * pfilPtr = &pdDir->entryInfoList();

   for(QList<QFileInfo>::iterator i = pfilPtr->begin(); i != pfilPtr->end(); i++)
   {
      QFileInfo * pfiPtr = &i.operator*();
      ustring _CurrentName = pfiPtr->filePath() + "/" + pfiPtr->fileName();
      QFile fIn(_CurrentName);

      if (fIn.open(QIODevice::ReadOnly))
      {
         QByteArray * pbaByte = &fIn.read(pfiPtr->size());

         if (pbaByte->length())
         {
            Data * pdData = &Data(pbaByte);
            pdData->Write(*pcPtr);
         }
      }
      else
      {
         throw exception(ustring
         {
            "Impossivel acessar o arquivo %1!"
         }.arg(pfiPtr->fileName()).toStdString().c_str());
      }
   }
}
//-----------------------------------------------------------------------------------------------//
void const Resource::Load(Compiler const & _Compiler)
{
   Compiler * pcPtr = dynamic_cast<Compiler *>(&const_cast<Compiler &>(_Compiler));

   pcPtr->setFileName(pcPtr->m_ustrFile);
   pcPtr->setFile(pcPtr->m_ustrFile);

   if (!pcPtr->QFile::exists())
   {
      throw exception(ustring("Arquivo %1 não existe!").arg(pcPtr->m_ustrFile).toStdString().c_str());
   }

   if (!pcPtr->open(QIODevice::ReadWrite))
   {
      throw exception(ustring
      {
         "Erro, impossivel acessar o arquivo %1!" 
      }.arg(pcPtr->m_ustrFile).toStdString().c_str());
   }

   pcPtr->clear();
   Header * phResult = &Header();
   {
      try
      {
         phResult->Read(*pcPtr);
      }
      catch (exception const & e)
      {
         throw e;
      }
   }
}
//-----------------------------------------------------------------------------------------------//
QPixmap const Resource::Find(ustring const & strName) const
{
   return QPixmap();
}
//-----------------------------------------------------------------------------------------------//