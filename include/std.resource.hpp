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
#include <std.defs.hpp>
#include <std.widget.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class _DYNAMICLINK Exception;

   namespace resource
   {
      class _DYNAMICLINK Compiler;
      class _DYNAMICLINK Icon;

      class _DYNAMICLINK Resource : public Widget
      {
         Q_OBJECT
      public:
         Resource();
         Resource(Widget * pwParent, std::ustring const & strName = std::ustring());
         virtual ~Resource();

          virtual void const Process(Compiler const & cCompiler);
          virtual void const Load(Compiler const & cCompiler);
          virtual QPixmap const Find(ustring const & ustrName) const;

          DECLARE_OPERATOR(Resource);
      protected:
         QPixmap m_pxCurrentResource;
         QProgressBar * m_ppbBar;
         QPushButton * m_pbCancel;
         QHBoxLayout * m_pblHBoxLayout;
      };

      class _DYNAMICLINK Icon: public QIcon, public QObject
      {
      public:
         Icon();
         Icon(Icon const & oIcon);
         Icon(const QPixmap & oPixmap);
         Icon(const QIcon & oIcon);
         Icon(const ustring & szFile);
         Icon(QIconEngine * pIConEngine);
         virtual ~Icon();

         __declspec(property(get=cacheKey)) qint64 CacheKey;
         __declspec(property(get=isNull)) bool IsNull;
         __declspec(property(get=name)) std::ustring IconName;
         __declspec(property(put=swap)) QIcon & Swap;

         DECLARE_OPERATOR(Icon);
      };
//-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Header: public QObject
      {
      public:
         enum HeaderID { IDD_EOF = 0xffee, IDD_ID = 0xaaff };
         friend class Compiler;
      public:
         Header();
         Header(ustring const & strName, 
            long long const & llcSize,
            unsigned long const & ulcID,
            QDate const & dcDate);
         bool const Write(QFile const * pfHandle);
         bool const Read(QFile const * pfHandle);

         QDate GetDate() const
         {
            return m_dDate;
         }
         ustring GetName() const
         {
            return m_ustrName;
         }
         unsigned long GetID() const
         {
            return m_ulID;
         }
         long long GetSize() const
         {
            return m_llSize;
         }
         DECLARE_OPERATOR(Header);
      protected:
         unsigned long m_ulID;
         long long m_llSize;
         QDate m_dDate;
         ustring m_ustrName;
      };
//-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Data: public QObject
      {
      public:
         Data();
         Data(QByteArray const * pbaByteArray);
         virtual ~Data();
         void const SetData(QByteArray const * pbaData);
         bool const Write(QFile const & fFile);
         bool const Read(QFile const & fFile, long long const & cllOffset);
         QByteArray const * GetData() const;

         DECLARE_OPERATOR(Data);
      protected:
         struct ItemData
         {
            ItemData(char const * lpszPointer, unsigned int uiOffset):
            m_lpszPointer(const_cast<char *>(lpszPointer)), 
            m_uiOffset(uiOffset)
            {
            }

            char * m_lpszPointer;
            unsigned int m_uiOffset;
         };

         QByteArray * m_pbaBuffer;
      };
//-----------------------------------------------------------------------------------------------//      
      class _DYNAMICLINK Information: public QFileInfo, public QFile
      {
      public:
         Information(){}
         Information(ustring const & ustrFile):QFileInfo(ustrFile), QFile(ustrFile)
         {
         }
         Information(ustring const & ustrPath,
            ustring const & ustrFile,
            ustring const & ustrExtension):QFileInfo(), QFile(),
            m_ustrPath(ustrPath), m_ustrFile(ustrFile), m_ustrExtension(ustrExtension)
         {
         }
         void SetPath(ustring const & ustrName)
         {
            m_ustrPath = ustrName;
         }
         void SetFile(ustring const & ustrFile)
         {
            m_ustrFile = ustrFile;
         }
         void SetExtension(ustring const & ustrExtension)
         {
            m_ustrExtension = ustrExtension;
         }
         ustring const & GetPath() const
         {
            return m_ustrPath;
         }
         ustring const & GetFile() const
         {
            return m_ustrFile;
         }
         ustring const & GetExtension() const
         {
            return m_ustrExtension;
         }

         DECLARE_OPERATOR(Information)
      protected:
         ustring m_ustrPath;
         ustring m_ustrFile;
         ustring m_ustrExtension;
      };
//-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Compiler: 
         public Information, public QMap<ustring, QFileInfo>
      {
         friend class Resource;
      public:
         Compiler();
         Compiler(ustring const & ustrDir,
            ustring const & ustrFile,
            ustring const & ustrExtension);
         virtual ~Compiler(){}

         virtual bool const CreateResourceFile(ustring const & ustrName);
         virtual QMap<ustring, QFileInfo> const * GetImagesMap() const;
         virtual QDataStream const * GetBuffer();

         DECLARE_OPERATOR(Compiler);
      protected:
         QDataStream * m_pdsDataStream;
      };
   };
};
//-----------------------------------------------------------------------------------------------//