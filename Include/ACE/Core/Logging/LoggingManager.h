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

#include <ACE/RootInitializer.h>
#include <ACE/Base/Singleton.h>
#include <ACE/Base/Misc/Mutex.h>
#include <ACE/Core/Logging/LoggingCategory.h>
#include <ACE/Core/Logging/LoggingLevel.h>

namespace ACE
{
    class ACE_LoggingManager final : public ACE_Singleton<ACE_LoggingManager>
    {
        ACE_LoggingManager();
        virtual ~ACE_LoggingManager() override final;
        friend class ACE_RootInitializer;
    public:
        void Log( ACE_LoggingCategory in_logCategory, ACE_LoggingLevel in_logLevel, const char *in_msgSenderName, const char *in_msgStringFormat, ... );
        void SetLoggingLevel( ACE_LoggingCategory in_logCategory, ACE_LoggingLevel in_logLevel );
    private:
        ACE_Mutex m_mutex;
        ACE_LoggingLevel m_loggingLevel[(int)__ACE_LC_Last] {};
        //        static ACE_File sm_logFile[(int)__ACE_LC_Last];
    };

    #define ACE_LoggingManagerS                         ACE::ACE_LoggingManager::GetInstance()

    #define ACE_Log( cat, lvl, sndr, ... )              ACE_LoggingManagerS.Log( cat, lvl, sndr, __VA_ARGS__ )
    #define ACE_LogO( cat, lvl, ... )                   ACE_Log( cat, lvl, GetObjectName(), __VA_ARGS__ )

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

    /*
     *  Graphic Log Macro
     */

    #define ACE_Log_Graphic( lvl, sndr, ... )           ACE_Log( ACE_LC_Graphic, lvl, sndr, __VA_ARGS__ )
    #define ACE_Log_GraphicO( lvl, ... )                ACE_LogO( ACE_LC_Graphic, lvl, __VA_ARGS__ )

    #define ACE_Log_Graphic_Fatal( sndr, ... )          ACE_Log_Graphic( ACE_LL_Fatal,   sndr, __VA_ARGS__ )
    #define ACE_Log_Graphic_Error( sndr, ... )          ACE_Log_Graphic( ACE_LL_Error,   sndr, __VA_ARGS__ )
    #define ACE_Log_Graphic_Warning( sndr, ... )        ACE_Log_Graphic( ACE_LL_Warning, sndr, __VA_ARGS__ )
    #define ACE_Log_Graphic_Info( sndr, ... )           ACE_Log_Graphic( ACE_LL_Info,    sndr, __VA_ARGS__ )

    #define ACE_Log_Graphic_FatalO( ... )               ACE_Log_GraphicO( ACE_LL_Fatal,  __VA_ARGS__ )
    #define ACE_Log_Graphic_ErrorO( ... )               ACE_Log_GraphicO( ACE_LL_Error,  __VA_ARGS__ )
    #define ACE_Log_Graphic_WarningO( ... )             ACE_Log_GraphicO( ACE_LL_Warning, __VA_ARGS__ )
    #define ACE_Log_Graphic_InfoO( ... )                ACE_Log_GraphicO( ACE_LL_Info,   __VA_ARGS__ )

    #if ACE_Setting_Debug
    #   define ACE_Log_Graphic_Debug( sndr, ... )       ACE_Log_Graphic( ACE_LL_Debug,   sndr, __VA_ARGS__ )
    #   define ACE_Log_Graphic_DebugO( ... )            ACE_Log_GraphicO( ACE_LL_Debug, __VA_ARGS__ )
    #else
    #   define ACE_Log_Graphic_Debug( sndr, ... )
    #   define ACE_Log_Graphic_DebugO( ... )
    #endif
}