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
#include <std.icondata.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
	class _DYNAMICLINK GettingIconDataOnResourceFile: public IconData
	{
      Q_OBJECT
	public:
		GettingIconDataOnResourceFile():IconData(){} /* starter inline object class */
		explicit GettingIconDataOnResourceFile(ustring const & szResourceName = "icondata.wrr",
			ustring const & szResourcePath = "./");
		virtual ~GettingIconDataOnResourceFile();
		virtual bool const __stdcall Build();

		DECLARE_OPERATOR(GettingIconDataOnResourceFile);/**/
   signals:
      void OnNotify(QFileInfo * pFileInfo, QDataStream::Status uStatus);
	};
};