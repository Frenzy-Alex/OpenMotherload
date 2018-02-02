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

#include <ACE/Base/Singleton.h>
#include <ACE/Base/Containers/List.h>
#include <ACE/Base/Containers/String.h>
#include <ACE/Core/Config/IConfigParam.h>
#include <ACE/Settings.h>

namespace ACE
{
    class ACE_ConfigManager final : public ACE_Singleton<ACE_ConfigManager>
    {
        ACE_ConfigManager() = default;
        virtual ~ACE_ConfigManager() = default;
        friend class ACE_Singleton<ACE_ConfigManager>;
        friend class ACE_IConfigParam;
    public:
        static bool Load( const ACE_String &in_fileName = ACE_Setting_Config_ConfigFileName );
        static bool Save( const ACE_String &in_fileName = ACE_Setting_Config_ConfigFileName );
    protected:
        static void RegisterConfigParam( ACE_IConfigParam *in_configParam );
        static void UnregisterConfigParam( ACE_IConfigParam *in_configParam );
    private:
        static ACE_List<ACE_IConfigParam *> m_configParams;
    };

    #define ACE_ConfigManagerS      ACE::ACE_ConfigManager::GetInstance()
}