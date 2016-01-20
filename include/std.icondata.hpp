//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013, 2014
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013, 2014
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
	struct RESOURCEHEADER
	{
		LONG   lcbOffset;
		WCHAR  wcbId;
		LONG   lcbSize;
		LPVOID lpData;
	};

	struct RESOURCEDATA
	{
		LONG   lcbOffset;
		LPSTR  lpName;
		LONG   lcbSize;
		LPVOID lpBuffer;
	};

	/* abstract class to resource icon data object  icondata */
	class _DYNAMICLINK IconData: public QObject
	{
	public:
      explicit IconData(); /**/
		explicit IconData(ustring const & szResourceName, ustring const & szResourcePath);
		virtual ~IconData(){}
		virtual bool const __stdcall Build() = 0;

		DECLARE_OPERATOR(IconData); /**/
	protected:
		shared_ptr<RESOURCEHEADER> m_lpHeader;
		shared_ptr<RESOURCEDATA> m_lpData;
		shared_ptr<QFile> m_lpFileHandle;
		shared_ptr<QDataStream> m_lpDataStreamHandle;
      ustring m_szResourceName;
      ustring m_szResourcePath;
      shared_ptr<StringList> m_lpListResourceNames;
	};
};