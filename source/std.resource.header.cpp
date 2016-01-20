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
Header::Header()
{
   m_dDate = (new QDate())->currentDate();
   m_ustrName = ustring();
   m_ulID   = IDD_ID;
   m_llSize = sizeof(*this);
}
//-----------------------------------------------------------------------------------------------//
Header::Header(ustring const & ustrName, 
               long long const & llcSize,
               unsigned long const & ulcID,
               QDate const & dcDate)
{
   m_ustrName = ustrName;
   m_llSize = llcSize;
   m_ulID   = ulcID;
   m_dDate = dcDate;
}
//-----------------------------------------------------------------------------------------------//
bool const Header::Write(QFile const * pfHandle)
{
   QFile * pfFile = const_cast<QFile *>(pfHandle);
   QByteArray obABuffer = reinterpret_cast<char *>(this);
   {
      obABuffer.append(IDD_EOF);
   }
   long long llSuccess = pfFile->write(obABuffer);
   {
      if (llSuccess != long long(obABuffer.length()))
      {
         throw exception(ustring
         {
            "Erro de gravação do arquivo %1!"
         }.arg(pfFile->fileName()).toStdString().c_str());
      }
   }
   return true;
}
//-----------------------------------------------------------------------------------------------//
bool const Header::Read(QFile const * pfHandle)
{
   QFile * pfFile = const_cast<QFile *>(pfHandle);

   QByteArray baResult = pfFile->read(sizeof(*this));

   if (baResult.length() != sizeof(*this))
   {
      throw exception(ustring
      {
         "Arquivo %1 com tamanho invalido!"
      }.bind(pfFile->fileName()).to_string().c_str());
   }

   if (m_ulID != unsigned long(IDD_ID))
   {
      throw exception(ustring
      {
         "Arquivo %1 invalido!" 
      }.bind(pfFile->fileName()).to_string().c_str());
   }

   return true;
}
//-----------------------------------------------------------------------------------------------//
