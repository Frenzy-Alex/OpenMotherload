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
#include <ACE/Base/Containers/List.h>
#include <ACE/Audio/AudioDevice.h>

namespace ACE
{
    class ACE_AudioManager final : public ACE_Manager, public ACE_Singleton<ACE_AudioManager>
    {
        ACE_AudioManager();
        virtual ~ACE_AudioManager() override final;
        ACE_SingletonFriend( ACE_AudioManager );
    public:
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;
    private:
        ACE_List<ACE_AudioDevice *> m_audioDevices;
    };

//    extern ACE_UniquePointer<ACE_AudioManager> ACE_AudioManagerS;

    #define ACE_AudioManagerS       ACE::ACE_AudioManager::GetInstance()
}