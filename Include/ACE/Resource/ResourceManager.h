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
#include <ACE/Base/Manager.h>
#include <ACE/Base/Singleton.h>

namespace ACE
{
    class ACE_ResourceManager final : public ACE_Manager, public ACE_Singleton<ACE_ResourceManager>
    {
        ACE_ResourceManager();
        virtual ~ACE_ResourceManager() override final;
        friend class ACE_RootInitializer;
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;
    };

    #define ACE_ResourceManagerS        ACE::ACE_ResourceManager::GetInstance()
}