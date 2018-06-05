/********************************************************************************
 *                                                                              *
 *          Copyright (C) 2018 Oleksandr Lynok. All Rights Reserved.            *
 *                                                                              *
 *                  This file is part of OpenMotherload.               			*
 *                                                                              *
 *      OpenMotherload is licensed under GNU Lesser General Public     			*
 *  License (LGPL), version 3.  See file "LICENSE.txt".                         *
 *                                                                              *
 ********************************************************************************/

#include <OML/Global.h>

using namespace ACE;
using namespace OML;

int main( int in_argc, char **in_argv )
{
    //  Parse Input Arguments
    ACE_ArgumentParser _argumentParser( in_argc, in_argv );
    ACE_ReturnIf( !_argumentParser.ParseArguments(), -1 );

    //  Initialize Global Variables
    OML_GlobalInitialize();

    //  Initialize & Start Engine and Application
    ACE_RootManagerS.Run( *G_Application );

    //  Terminate Global Variables
    OML_GlobalTerminate();
    return 0;
}
