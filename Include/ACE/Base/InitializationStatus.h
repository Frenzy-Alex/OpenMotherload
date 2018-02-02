/********************************************************************************
 *                                                                              *
 *          Copyright (C) 2017 Oleksandr Lynok. All Rights Reserved.            *
 *                                                                              *
 *                  This file is part of Advanced Crystal Engine.               *
 *                                                                              *
 *      Advanced Crystal Engine is licensed under GNU Lesser General Public     *
 *  License (LGPL), version 3.  See file "LICENSE.txt".                         *
 *                                                                              *
 ********************************************************************************/

#pragma once

#include <ACE/Base/Containers/String.h>

namespace ACE
{
    enum class ACE_InitializationStatus
    {
        IS_Initializing,
        IS_Initialized,
        IS_Terminating,
        IS_Terminated,
        IS_Error,
        __IS_Last
    };

    template<>
    const char *ACE_ToCString( ACE_InitializationStatus in_initializationStatus );

    #define ACE_IS_Initializing     ACE::ACE_InitializationStatus::IS_Initializing
    #define ACE_IS_Initialized      ACE::ACE_InitializationStatus::IS_Initialized
    #define ACE_IS_Terminating      ACE::ACE_InitializationStatus::IS_Terminating
    #define ACE_IS_Terminated       ACE::ACE_InitializationStatus::IS_Terminated
    #define ACE_IS_Error            ACE::ACE_InitializationStatus::IS_Error
    #define __ACE_IS_Last           ACE::ACE_InitializationStatus::__IS_Last

}