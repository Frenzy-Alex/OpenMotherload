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

#include <ACE/Base/InitializationStatus.h>
#include <ACE/Base/Misc/Macro.h>

namespace ACE
{
    class ACE_Initializable
    {
    public:
        ACE_InitializationStatus GetInitializationStatus() const;
    protected:
        ACE_Initializable();
        virtual ~ACE_Initializable() = default;

        void SetInitializationStatus( ACE_InitializationStatus in_initializationStatus );

        virtual void Initialize();
        virtual void Initialized();

        virtual void Terminate();
        virtual void Terminated();
    private:
        ACE_InitializationStatus m_initializationStatus;
    };

    #define ACE_Initializable_Initialize( B )   ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Terminated );     \
                                                B::Initialize();                                                    \
                                                ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Initializing )

    #define ACE_Initializable_Initialized( B )  ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Initializing );   \
                                                B::Initialized()

    #define ACE_Initializable_Terminate( B )    ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Initialized &&    \
                                                              GetInitializationStatus() != ACE_IS_Error );          \
                                                B::Terminate();                                                     \
                                                ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Terminating )

    #define ACE_Initializable_Terminated( B )   ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Terminating );    \
                                                B::Terminated()

    #define ACE_Initializable_Errored()         SetInitializationStatus( ACE_IS_Error )
}