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
    enum class ACE_LoggingLevel
    {
        LL_Debug,
        LL_Info,
        LL_Warning,
        LL_Error,
        LL_Fatal,
        __LL_Last
    };

    template<>
    const char *ACE_ToCString( ACE_LoggingLevel in_loggingLevel );

    #define ACE_LL_Debug        ACE::ACE_LoggingLevel::LL_Debug
    #define ACE_LL_Info         ACE::ACE_LoggingLevel::LL_Info
    #define ACE_LL_Warning      ACE::ACE_LoggingLevel::LL_Warning
    #define ACE_LL_Error        ACE::ACE_LoggingLevel::LL_Error
    #define ACE_LL_Fatal        ACE::ACE_LoggingLevel::LL_Fatal
    #define __ACE_LL_Last       ACE::ACE_LoggingLevel::__LL_Last
}