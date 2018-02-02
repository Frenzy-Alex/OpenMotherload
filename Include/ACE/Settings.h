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

#include <ACE/SettingsBase.h>

#include <ACE/Base/Containers/String.h>
#include <ACE/Core/Logging/LoggingCategory.h>
#include <ACE/Core/Logging/LoggingLevel.h>

namespace ACE
{
    #define ACE_Setting_Multithreading      0

    /********************************************************************************
     *  Audio Settings                                                              *
     ********************************************************************************/

    constexpr bool ACE_Setting_Audio_Enable = true;

    //constexpr ACE_Thread* ACE_Setting_Audio_Thread = ACE_Main_Thread;

    /********************************************************************************
     *  Core Settings                                                               *
     ********************************************************************************/

    /*
     *  Default: config.cfg
     */
    extern ACE_String ACE_Setting_Config_ConfigFileName;


    /*
     *  Default: ACE_LL_Debug
     */
    extern ACE_LoggingLevel ACE_Setting_Logging_DefaultLoggingLevel;

    /*
     *  Default: ./Logs/
     */
    extern ACE_String ACE_Setting_Logging_LogFilePath;

    /*
     *  Default: true
     */
    extern bool ACE_Setting_Logging_LogToConsole;

    /*
     *  Default: 1024
     */
    constexpr uint ACE_Setting_Logging_MaxMessageSize = 1024;

    /********************************************************************************
     *  Event Settings                                                              *
     ********************************************************************************/

    constexpr bool ACE_Setting_Event_Enable = true;

    /********************************************************************************
     *  Graphic Settings                                                            *
     ********************************************************************************/

    constexpr bool ACE_Setting_Graphic_Enable = true;

    /********************************************************************************
     *  Math Settings                                                               *
     ********************************************************************************/

    /********************************************************************************
     *  Network Settings                                                            *
     ********************************************************************************/

    constexpr bool ACE_Setting_Network_Enable = true;

    /********************************************************************************
     *  Physic Settings                                                             *
     ********************************************************************************/

    constexpr bool ACE_Setting_Physic_Enable = true;

    /********************************************************************************
     *  Resource Settings                                                           *
     ********************************************************************************/

    constexpr bool ACE_Setting_Resource_Enable = true;

    /********************************************************************************
     *  Script Settings                                                             *
     ********************************************************************************/

    constexpr bool ACE_Setting_Script_Enable = true;
}