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

#include <ACE/Base/Misc/Macro.h>
#include <ACE/Core/Object/Object.h>
#include <ACE/Base/Initializable.h>

namespace ACE
{
    class ACE_RootManager;

    class ACE_Manager : public ACE_Object, public ACE_Initializable
    {
        friend class ACE_RootManager;
    protected:
        explicit ACE_Manager( const char *in_objectName );
        virtual ~ACE_Manager() override = default;

        virtual void Initialize();
        virtual void Initialized();

        virtual void Update();

        virtual void Terminate();
        virtual void Terminated();
    };

    #define ACE_Manager_Initialize()    ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Terminated );     \
                                        ACE_Manager::Initialize();                                          \
                                        ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Initializing )


    #define ACE_Manager_Terminate()     ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Initialized &&    \
                                                      GetInitializationStatus() != ACE_IS_Error );          \
                                        ACE_Manager::Terminate();                                           \
                                        ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Terminating )

}