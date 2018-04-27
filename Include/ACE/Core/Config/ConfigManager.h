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

#include <ACE/Core/Object/Object.h>
#include <ACE/Base/Singleton.h>

#include <ACE/Base/Containers/String.h>
#include <ACE/RootInitializer.h>
#include <ACE/Settings.h>

#include <ACE/Base/Containers/List.h>
#include <ACE/Core/Config/IConfigParam.h>

namespace ACE
{
    class ACE_ConfigManager final : public ACE_Object, public ACE_Singleton<ACE_ConfigManager>
    {
        ACE_ConfigManager();
        virtual ~ACE_ConfigManager() override final;
        friend class ACE_RootInitializer;
        friend class ACE_IConfigParam;
    public:
        bool Load( const ACE_String &in_fileName = ACE_Setting_Config_ConfigFileName );
        bool Save( const ACE_String &in_fileName = ACE_Setting_Config_ConfigFileName );
    protected:
        void RegisterConfigParam( ACE_IConfigParam *in_configParam );
        void UnregisterConfigParam( ACE_IConfigParam *in_configParam );
    private:
        ACE_List<ACE_IConfigParam *> m_configParams;
    };

    #define ACE_ConfigManagerS      ACE::ACE_ConfigManager::GetInstance()
}