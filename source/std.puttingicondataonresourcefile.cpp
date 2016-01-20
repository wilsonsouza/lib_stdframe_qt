//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#include <std.puttingicondataonresourcefile.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
PuttingIconDataOnResourceFile::PuttingIconDataOnResourceFile(
	ustring const & szResourceName, ustring const & szResourcePath):
IconData(szResourceName, szResourcePath)
{
}
//-----------------------------------------------------------------------------------------------//
PuttingIconDataOnResourceFile::~PuttingIconDataOnResourceFile()
{
}
//-----------------------------------------------------------------------------------------------//
bool const __stdcall PuttingIconDataOnResourceFile::Build()
{
	/* abort process if variables empty */
	if(m_szResourceName.isEmpty() || m_szResourcePath.isEmpty())
		return false;

	/* verify archive */
	shared_ptr<QFileInfo> lpFileInfo(new QFileInfo());
	shared_ptr<QDir> lpDir(new QDir(m_szResourcePath));

	lpFileInfo->setFile(*lpDir, m_szResourceName);

	/* file already exists abort process */
	if(lpFileInfo->exists())
		return false;

	lpDir->setPath(m_szResourcePath);
	lpDir->setFilter(QDir::Files);

	QFileInfoList hFileList = lpDir->entryInfoList(QDir::Files, QDir::Name);
	ustring szName = ustring("%1/%2").arg(m_szResourcePath).arg(m_szResourceName);

	m_lpFileHandle = shared_ptr<QFile>(new QFile(szName));
	m_lpDataStreamHandle = shared_ptr<QDataStream>(new QDataStream(m_lpFileHandle.operator->()));

	/* create resource file */
	if(!m_lpFileHandle->open(QIODevice::ReadWrite))
		return false;

	/* get file list */
	shared_ptr<StringList> lpListNames(new StringList());

	if(hFileList.count() == 0)
		return false;

	/* set data */
	m_lpHeader->wcbId = QDataStream::Qt_1_0|0|QDataStream::Qt_1_0|0;

	/*set file version */
	m_lpDataStreamHandle->setVersion(QDataStream::Qt_5_1);

	for(QFileInfoList::Iterator f = hFileList.begin(); f != hFileList.end(); f++)
		lpListNames->append(f.operator->()->fileName());

	ustring szNames = lpListNames->join("/");
	m_lpHeader->lcbOffset = sizeof(*m_lpHeader);
	m_lpHeader->lcbSize = szNames.length();
	/**/
	*m_lpDataStreamHandle 
		<< m_lpHeader->lcbOffset
		<< m_lpHeader->wcbId
		<< m_lpHeader->lcbSize
		<< szNames
		<< "\n";

	if(m_lpDataStreamHandle->status() == QDataStream::WriteFailed)
		return false;

	/**/
	for(QFileInfoList::Iterator f = hFileList.begin(); f != hFileList.end(); f++)
	{
		QFileInfo * p = f.operator->();
		shared_ptr<QFile> in(new QFile(p->fileName()));

		if(in->open(QIODevice::ReadOnly))
		{
			*m_lpDataStreamHandle 
				<< LONG(sizeof(*m_lpData))
				<< p->fileName()
				<< LONG(p->size())
				<< in->readAll().data()
				<< "\n";

			/* notify */
			emit OnNotify(p, m_lpDataStreamHandle->status());
		}
	}
	return true;
}
//-----------------------------------------------------------------------------------------------//
