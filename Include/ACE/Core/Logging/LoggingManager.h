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

#include <ACE/Base/Misc/Mutex.h>
#include <ACE/Core/Logging/LoggingCategory.h>
#include <ACE/Core/Logging/LoggingLevel.h>
#include <ACE/Settings.h>

namespace ACE
{
    class ACE_LoggingManager final
    {
        ACE_LoggingManager() = delete;
        ~ACE_LoggingManager() = delete;
        struct ACE_LoggingManagerInitializer
        {
            ACE_LoggingManagerInitializer();
            ~ACE_LoggingManagerInitializer();
        };
    public:
        static void Log( ACE_LoggingCategory in_logCategory, ACE_LoggingLevel in_logLevel, const char *in_msgSenderName, const char *in_msgStringFormat, ... );
        static void SetLoggingLevel( ACE_LoggingCategory in_logCategory, ACE_LoggingLevel in_logLevel );
    private:
        static ACE_LoggingManagerInitializer sm_loggingManagerInitializer;
        static ACE_Mutex sm_mutex;
        static ACE_LoggingLevel sm_loggingLevel[(int)__ACE_LC_Last];
        //        static ACE_File sm_logFile[(int)__ACE_LC_Last];
    };

    #define ACE_Log( cat, lvl, sndr, ... )          ACE_LoggingManager::Log( cat, lvl, sndr, __VA_ARGS__ )
    #define ACE_LogO( cat, lvl, ... )               ACE_Log( cat, lvl, GetObjectName(), __VA_ARGS__ )

    /*
     *  Base Log Macro
     */

    #define ACE_Log_Base( lvl, sndr, ... )              ACE_Log( ACE_LC_Base, lvl, sndr, __VA_ARGS__ )
    #define ACE_Log_BaseO( lvl, ... )                   ACE_LogO( ACE_LC_Base, lvl, __VA_ARGS__ )

    #define ACE_Log_Base_Fatal( sndr, ... )             ACE_Log_Base( ACE_LL_Fatal,   sndr, __VA_ARGS__ )
    #define ACE_Log_Base_Error( sndr, ... )             ACE_Log_Base( ACE_LL_Error,   sndr, __VA_ARGS__ )
    #define ACE_Log_Base_Warning( sndr, ... )           ACE_Log_Base( ACE_LL_Warning, sndr, __VA_ARGS__ )
    #define ACE_Log_Base_Info( sndr, ... )              ACE_Log_Base( ACE_LL_Info,    sndr, __VA_ARGS__ )

    #define ACE_Log_Base_FatalO( ... )                  ACE_Log_BaseO( ACE_LL_Fatal,  __VA_ARGS__ )
    #define ACE_Log_Base_ErrorO( ... )                  ACE_Log_BaseO( ACE_LL_Error,  __VA_ARGS__ )
    #define ACE_Log_Base_WarningO( ... )                ACE_Log_BaseO( ACE_LL_Warning, __VA_ARGS__ )
    #define ACE_Log_Base_InfoO( ... )                   ACE_Log_BaseO( ACE_LL_Info,   __VA_ARGS__ )

    #if ACE_Setting_Debug
    #   define ACE_Log_Base_Debug( sndr, ... )          ACE_Log_Base( ACE_LL_Debug,   sndr, __VA_ARGS__ )
    #   define ACE_Log_Base_DebugO( ... )               ACE_Log_BaseO( ACE_LL_Debug, __VA_ARGS__ )
    #else
    #   define ACE_Log_Base_Debug( sndr, ... )
    #   define ACE_Log_Base_DebugO( ... )
    #endif

    /*
     *  Core Log Macro
     */

    #define ACE_Log_Core( lvl, sndr, ... )              ACE_Log( ACE_LC_Core, lvl, sndr, __VA_ARGS__ )
    #define ACE_Log_CoreO( lvl, ... )                   ACE_LogO( ACE_LC_Core, lvl, __VA_ARGS__ )

    #define ACE_Log_Core_Fatal( sndr, ... )             ACE_Log_Core( ACE_LL_Fatal,   sndr, __VA_ARGS__ )
    #define ACE_Log_Core_Error( sndr, ... )             ACE_Log_Core( ACE_LL_Error,   sndr, __VA_ARGS__ )
    #define ACE_Log_Core_Warning( sndr, ... )           ACE_Log_Core( ACE_LL_Warning, sndr, __VA_ARGS__ )
    #define ACE_Log_Core_Info( sndr, ... )              ACE_Log_Core( ACE_LL_Info,    sndr, __VA_ARGS__ )

    #define ACE_Log_Core_FatalO( ... )                  ACE_Log_CoreO( ACE_LL_Fatal,  __VA_ARGS__ )
    #define ACE_Log_Core_ErrorO( ... )                  ACE_Log_CoreO( ACE_LL_Error,  __VA_ARGS__ )
    #define ACE_Log_Core_WarningO( ... )                ACE_Log_CoreO( ACE_LL_Warning, __VA_ARGS__ )
    #define ACE_Log_Core_InfoO( ... )                   ACE_Log_CoreO( ACE_LL_Info,   __VA_ARGS__ )

    #if ACE_Setting_Debug
    #   define ACE_Log_Core_Debug( sndr, ... )          ACE_Log_Core( ACE_LL_Debug,   sndr, __VA_ARGS__ )
    #   define ACE_Log_Core_DebugO( ... )               ACE_Log_CoreO( ACE_LL_Debug, __VA_ARGS__ )
    #else
    #   define ACE_Log_Core_Debug( sndr, ... )
    #   define ACE_Log_Core_DebugO( ... )
    #endif
}