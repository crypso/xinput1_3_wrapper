#include "stdafx.h"
#include "Common.h"
#include "SWIP.h"
#include "Logger.h"
#include "Utils.h"

#include "SWIP.h"

static const char * legal_notice = {
	"\nBased of code x360ce - XBOX 360 Controller emulator\n"
    "https://code.google.com/p/x360ce/\n\n"
    "Copyright (C) 2014 Vicent Ahuir\n\n"
    "This program is free software you can redistribute it and/or modify it under\n"
    "the terms of the GNU Lesser General Public License as published by the Free\n"
    "Software Foundation, either version 3 of the License, or any later version.\n\n"
};

std::string GetLogFile( const std::string &filename ) {
	SYSTEMTIME systime;
	GetLocalTime( &systime );
	std::string processName;
	ModuleFileName( &processName );

	std::string uniquefilename = filename;
	uniquefilename += "_%s_%02u-%02u-%02u_%08u.log";

	std::string logfile = StringFormat( uniquefilename.c_str( ), processName.c_str( ), systime.wYear,
										systime.wMonth, systime.wDay, GetTickCount( ) );

	return logfile;
}

VOID InitInstance()
{
	std::string path;
	FullPathFromPath( &path, "xinput1_3_wrapper.ini" );

	SWIP ini;
    std::string inipath("xinput1_3_wrapper.ini");

    if ( ini.Load( inipath ) ) {
		bool con;
		bool file;
		int level; 

		ini.Get( "Options", "Console", &con );
		ini.Get( "Options", "Log", &file );
		ini.Get( "Options", "LogLevel", &level );

		Logger::TConsoleInit consoleParameters;
		Logger::TFileInit fileParameters;

		if( con ) {
			consoleParameters.title = "xinput1_3_wrapper";
			consoleParameters.notice = legal_notice;
		}

		if( file ) {
			std::string filename;

			ini.Get( "Options", "LogFile", &filename );

			fileParameters.filename = GetLogFile( filename );			
		}

		Logger::Initialize( con? &consoleParameters : nullptr, file? &fileParameters : nullptr, level );
	}

}

extern "C" BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved);

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);
            InitInstance();
            break;

        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}