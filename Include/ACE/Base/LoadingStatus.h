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

#include <ACE/Base/Containers/String.h>

namespace ACE
{
    enum class ACE_LoadingStatus
    {
        LS_Loading,
        LS_LoadingWait,
        LS_Loaded,
        LS_Releasing,
        LS_ReleasingWait,
        LS_Released,
        LS_Error,
        __LS_Last
    };

    template<>
    const char *ACE_ToCString( ACE_LoadingStatus in_loadingStatus );

    #define ACE_LS_Loading          ACE::ACE_LoadingStatus::LS_Loading
    #define ACE_LS_LoadingWait      ACE::ACE_LoadingStatus::LS_LoadingWait
    #define ACE_LS_Loaded           ACE::ACE_LoadingStatus::LS_Loaded
    #define ACE_LS_Releasing        ACE::ACE_LoadingStatus::LS_Releasing
    #define ACE_LS_ReleasingWait    ACE::ACE_LoadingStatus::LS_ReleasingWait
    #define ACE_LS_Released         ACE::ACE_LoadingStatus::LS_Released
    #define ACE_LS_Error            ACE::ACE_LoadingStatus::LS_Error
    #define __ACE_LS_Last           ACE::ACE_LoadingStatus::__LS_Last
}