//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.gettingicondataonresourcefile.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
GettingIconDataOnResourceFile::GettingIconDataOnResourceFile(
	ustring const & szResourceName, ustring const & szResourcePath):
IconData(szResourceName, szResourcePath)
{
}
//-----------------------------------------------------------------------------------------------//
GettingIconDataOnResourceFile::~GettingIconDataOnResourceFile()
{
}
//-----------------------------------------------------------------------------------------------//
bool const __stdcall GettingIconDataOnResourceFile::Build()
{
	ustring szName = ustring("%1/%2").arg(m_szResourcePath).arg(m_szResourceName);

	/* abort process if variables empty */
	if(m_szResourceName.isEmpty() || m_szResourcePath.isEmpty())
		return false;

	/* verify archive */
	shared_ptr<QFileInfo> lpFileInfo(new QFileInfo());
	shared_ptr<QDir> lpDir(new QDir(m_szResourcePath));

	lpFileInfo->setFile(*lpDir, m_szResourceName);

	/* file already exists abort process */
	if(!lpFileInfo->exists())
		return false;

	lpDir->setPath(m_szResourcePath);
	lpDir->setFilter(QDir::Files);

	m_lpFileHandle = shared_ptr<QFile>(new QFile(szName));
	m_lpDataStreamHandle = shared_ptr<QDataStream>(new QDataStream(m_lpFileHandle.operator->()));

	/* open resource file */
	if(!m_lpFileHandle->open(QIODevice::ReadOnly))
		return false;

	m_lpData = shared_ptr<RESOURCEDATA>(new RESOURCEDATA);
	m_lpHeader = shared_ptr<RESOURCEHEADER>(new RESOURCEHEADER);

	m_lpData->lcbOffset = 0;
	m_lpHeader->lcbOffset = 0;

	while(m_lpDataStreamHandle->atEnd())
	{
		if(m_lpHeader->lcbOffset == 0)
		{
			m_lpDataStreamHandle->readRawData(reinterpret_cast<char *>(&m_lpHeader->lcbOffset), sizeof(m_lpHeader->lcbOffset));
			m_lpDataStreamHandle->readRawData(reinterpret_cast<char *>(&m_lpHeader->wcbId), sizeof(m_lpHeader->wcbId));
			m_lpDataStreamHandle->readRawData(reinterpret_cast<char *>(&m_lpHeader->lcbSize), sizeof(m_lpHeader->lcbSize));
			
			/* get string buffer */
			ustring szBuffer;
			*m_lpDataStreamHandle >> szBuffer;
			/* assign buffer on list */
			*m_lpListResourceNames = szBuffer.split("/");

			/* notify client */
			emit OnNotify(nullptr, m_lpDataStreamHandle->status());
		}

		/**/
		m_lpDataStreamHandle->readRawData(reinterpret_cast<char *>(&m_lpData->lcbOffset), sizeof(m_lpData->lcbOffset));
		ustring szName;
		*m_lpDataStreamHandle >> szName;

		m_lpDataStreamHandle->readRawData(reinterpret_cast<char *>(&m_lpData->lcbSize), sizeof(m_lpData->lcbSize));
		
		ustring szBuffer;
		*m_lpDataStreamHandle >> szBuffer;

		shared_ptr<QFile> f(new QFile(szName));

		if(!f->exists())
		{
			if(!f->open(QIODevice::ReadWrite))
			{
				emit OnNotify(nullptr, QDataStream::WriteFailed);
				continue;
			}

			/* write icon on disk */
			shared_ptr<QDataStream> d(new QDataStream(f.operator->()));
			*d << szBuffer;

			/* notify */
			emit OnNotify(nullptr, d->status());
		}
	}

	return true;
}
//-----------------------------------------------------------------------------------------------//
