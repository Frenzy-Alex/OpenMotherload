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
#include <ACE/Base/Containers/List.h>
#include <ACE/Core/Application.h>
#include <ACE/RootInitializer.h>

namespace ACE
{
    class ACE_RootManager final : public ACE_Manager, public ACE_Singleton<ACE_RootManager>
    {
        ACE_RootManager();
        virtual ~ACE_RootManager() override final;
        friend class ACE_RootInitializer;
    public:
        void AttachManager( ACE_Manager *in_manager );
        void DetachManager( ACE_Manager *in_manager );

        void Run( int in_argc, char **in_argv, ACE_Application &in_application );
        void Exit();
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;
    private:
        bool m_isExit;
        ACE_List<ACE_Manager *> m_managers;
    };

    #define ACE_RootManagerS       ACE::ACE_RootManager::GetInstance()
}