//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013, 2014
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013, 2014
//-----------------------------------------------------------------------------------------------//
#include <std.icondata.hpp>
using namespace std;
//-----------------------------------------------------------------------------------------------//
IconData::IconData()
{
   m_lpHeader = nullptr;
   m_lpData = nullptr;
   m_lpFileHandle = nullptr;
   m_lpDataStreamHandle = nullptr;
   m_szResourceName = ustring();
   m_szResourcePath = ustring();
   m_lpListResourceNames = nullptr;
}
//-----------------------------------------------------------------------------------------------//
IconData::IconData(ustring const & szResourceName, ustring const & szResourcePath)
{
   m_szResourceName = szResourceName;
   m_szResourcePath = szResourcePath;
	m_lpHeader = shared_ptr<RESOURCEHEADER>(new RESOURCEHEADER);
	m_lpData = shared_ptr<RESOURCEDATA>(new RESOURCEDATA);
	m_lpListResourceNames = shared_ptr<StringList>(new StringList());
}
//-----------------------------------------------------------------------------------------------//