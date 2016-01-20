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
Data::Data():m_pbaBuffer(new QByteArray())
{
}
//-----------------------------------------------------------------------------------------------//
Data::Data(QByteArray const * pbaByteArray):m_pbaBuffer(new QByteArray())
{
   ItemData * pID = new ItemData(pbaByteArray->data(), pbaByteArray->length());
   m_pbaBuffer->append(reinterpret_cast<char *>(pID));
}
//-----------------------------------------------------------------------------------------------//
Data::~Data()
{
   delete m_pbaBuffer;
}
//-----------------------------------------------------------------------------------------------//
void const Data::SetData(QByteArray const * pbaData)
{
   ItemData * pID = new ItemData(pbaData->data(), pbaData->length());
   m_pbaBuffer->clear();
   m_pbaBuffer->append(reinterpret_cast<char *>(pID));
}
//-----------------------------------------------------------------------------------------------//
bool const Data::Write(QFile const & fFile)
{
   long long llResult = const_cast<QFile &>(fFile).write(*m_pbaBuffer);

   if (llResult != long long(m_pbaBuffer->length()))
   {
      throw exception("Erro de gravação de dados!");
   }
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const Data::Read(QFile const & fFile, long long const & cllOffset)
{
   QByteArray baBuffer = const_cast<QFile &>(fFile).read(cllOffset);
   {
      if (long long(cllOffset) != long long(baBuffer.length()))
      {
         throw exception(ustring
         {
            "Tamanho de arquivo %1 invalido!" 
         }.arg(fFile.fileName()).toStdString().c_str());
      }
   }
   return true;
}
//-----------------------------------------------------------------------------------------------//
QByteArray const * Data::GetData() const
{
   return reinterpret_cast<QByteArray const *>(m_pbaBuffer);
}
//-----------------------------------------------------------------------------------------------//
