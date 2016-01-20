//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#include <std.dialogsearch.hpp>
#include <std.button.hpp>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
DialogSearch::DialogSearch(QWidget * pOwner, std::ustring const & strName):
DialogEx(pOwner, 0, strName)
{
   setWindowIcon(m_IconsList->GetEdit()->FIND_REPLACE);
}
//-----------------------------------------------------------------------------------------------//
DialogSearch::~DialogSearch()
{
   m_OK->disconnect();
}
//-----------------------------------------------------------------------------------------------//
bool const __fastcall DialogSearch::OnCreate(DialogEx * pDlg)
{
   //mount buttons on layout staker
   return DialogEx::OnCreate(pDlg);
}
//-----------------------------------------------------------------------------------------------//

