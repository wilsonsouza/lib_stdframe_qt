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
	class _DYNAMICLINK PuttingIconDataOnResourceFile: public IconData
	{
      Q_OBJECT
	public:
		PuttingIconDataOnResourceFile():IconData(){} /* starter inline object class */
		explicit PuttingIconDataOnResourceFile(ustring const & szResourceName = "icondata.wrr",
			ustring const & szResourcePath = "./");
		virtual ~PuttingIconDataOnResourceFile();
		virtual bool const __stdcall Build();

		DECLARE_OPERATOR(PuttingIconDataOnResourceFile);
   signals:
      void OnNotify(QFileInfo * pFileInfo, QDataStream::Status uStatus);
	};
};