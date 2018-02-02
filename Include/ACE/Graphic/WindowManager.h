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
    class ACE_GraphicManager;
    class ACE_WindowManager final : public ACE_Manager<false>, public ACE_Singleton<ACE_WindowManager>
    {
        ACE_WindowManager();
        virtual ~ACE_WindowManager() override final;
        ACE_SingletonFriend( ACE_WindowManager );
        friend class ACE_GraphicManager;
    public:
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;
    private:
    };

    #define ACE_WindowManagerS     ACE::ACE_WindowManager::GetInstance()
}