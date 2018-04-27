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

#include <ACE/Base/Manager.h>
#include <ACE/Base/Singleton.h>
#include <ACE/RootInitializer.h>

namespace ACE
{
    class ACE_EventManager final : public ACE_Manager, public ACE_Singleton<ACE_EventManager>
    {
        ACE_EventManager();
        virtual ~ACE_EventManager() override final;
        friend class ACE_RootInitializer;
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;
    };

    #define ACE_EventManagerS       ACE::ACE_EventManager::GetInstance()
}