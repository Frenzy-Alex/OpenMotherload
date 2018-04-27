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

using namespace OML;

int main( int in_argc, char **in_argv )
{
    OML_GlobalInitialize();
    ACE_RootManagerS.Run( in_argc, in_argv, *G_Application );
    OML_GlobalTerminate();
    return 0;
}
