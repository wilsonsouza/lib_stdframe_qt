//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.resource.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
using namespace resource;
//-----------------------------------------------------------------------------------------------//
Compiler::Compiler():m_pdsDataStream(new QDataStream()), Information()
{
}
//-----------------------------------------------------------------------------------------------//
Compiler::Compiler(ustring const & ustrDir, ustring const & ustrFile, ustring const & ustrExtension):
Information(ustrDir, ustrFile, ustrExtension),
m_pdsDataStream(new QDataStream())
{
}
//-----------------------------------------------------------------------------------------------//
bool const Compiler::CreateResourceFile(ustring const & ustrName)
{
   this->setFile(m_ustrFile);
   this->setFileName(m_ustrFile);

   if (this->QFile::exists())
   {
      throw exception(ustring
      {
         "Arquivo %1 de recurso já existe!"
      }.arg(ustrName).toStdString().c_str());
   }

   if (!this->QFile::open(QIODevice::ReadWrite))
   {
      throw exception(ustring
      {
         "Não foi possivel criar o arquivo %1!" 
      }.arg(ustrName).toStdString().c_str());
   }

   Header * pTemp = new Header();
   Header * pHeader = new Header("WR Resource File", pTemp->GetSize(), pTemp->GetID(), QDate());

   try
   {
      pHeader->Write(*this);
   }
   catch(exception & e)
   {
      throw e;
   }

   return true;
}
//-----------------------------------------------------------------------------------------------//
QMap<ustring, QFileInfo> const * Compiler::GetImagesMap() const
{
   return dynamic_cast< QMap<ustring, QFileInfo> const *>(this);
}
//-----------------------------------------------------------------------------------------------//
QDataStream const * Compiler::GetBuffer()
{
   return dynamic_cast<QDataStream *>(m_pdsDataStream);
}
//-----------------------------------------------------------------------------------------------//