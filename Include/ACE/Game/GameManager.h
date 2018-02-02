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

#include <ACE/Base/Manager.h>
#include <ACE/Base/Singleton.h>

namespace ACE
{
    class ACE_GameManager final : public ACE_Manager<false>, public ACE_Singleton<ACE_GameManager>
    {
        ACE_GameManager();
        virtual ~ACE_GameManager() override final;
        ACE_SingletonFriend( ACE_GameManager );
    public:
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;
    };

    #define ACE_GameManagerS        ACE::ACE_GameManager::GetInstance()
}