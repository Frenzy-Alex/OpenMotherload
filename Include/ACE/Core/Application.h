/********************************************************************************
 *                                                                              *
 *          Copyright (C) 2018 Oleksandr Lynok. All Rights Reserved.            *
 *                                                                              *
 *                  This file is part of Advanced Crystal Engine.               *
 *                                                                              *
 *      Advanced Crystal Engine is licensed under GNU Lesser General Public     *
 *  License (LGPL), version 3.  See file "LICENSE.txt".                         *
 *                                                                              *
 ********************************************************************************/

#pragma once

#include <ACE/Core/Object/Object.h>
#include <ACE/Base/Initializable.h>

namespace ACE
{
    class ACE_RootManager;
    class ACE_Application : public ACE_Object, public ACE_Initializable
    {
        friend class ACE_RootManager;
    public:
        explicit ACE_Application( const char *in_objectName );
        virtual ~ACE_Application() override;
    protected:
        virtual void ParseArgs( int in_argc, char **in_argv );

        virtual void Initialize() override;
        virtual void Update();
        virtual void Terminate() override;
    };

    #define ACE_Application_Initialize()        ACE_Initializable_Initialize( ACE::ACE_Application )

    #define ACE_Application_Terminate()         ACE_Initializable_Terminate( ACE::ACE_Application )
}