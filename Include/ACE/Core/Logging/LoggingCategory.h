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
    enum class ACE_LoggingCategory
    {
        LC_Audio,
        LC_Base,
        LC_Core,
        LC_Event,
        LC_Game,
        LC_Graphic,
        LC_Network,
        LC_Physic,
        LC_Resource,
        LC_Script,
        __LC_Last
    };

    template<>
    const char *ACE_ToCString( ACE_LoggingCategory in_loggingCategory );

    #define ACE_LC_Audio        ACE::ACE_LoggingCategory::LC_Audio
    #define ACE_LC_Base         ACE::ACE_LoggingCategory::LC_Base
    #define ACE_LC_Core         ACE::ACE_LoggingCategory::LC_Core
    #define ACE_LC_Event        ACE::ACE_LoggingCategory::LC_Event
    #define ACE_LC_Game         ACE::ACE_LoggingCategory::LC_Game
    #define ACE_LC_Graphic      ACE::ACE_LoggingCategory::LC_Graphic
    #define ACE_LC_Network      ACE::ACE_LoggingCategory::LC_Network
    #define ACE_LC_Physic       ACE::ACE_LoggingCategory::LC_Physic
    #define ACE_LC_Resource     ACE::ACE_LoggingCategory::LC_Resource
    #define ACE_LC_Script       ACE::ACE_LoggingCategory::LC_Script
    #define __ACE_LC_Last       ACE::ACE_LoggingCategory::__LC_Last
}