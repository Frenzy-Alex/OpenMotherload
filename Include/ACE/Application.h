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

#include <ACE/Base/Object.h>
#include <ACE/Base/Initializable.h>
#include <ACE/Base/Containers/List.h>
#include <ACE/Base/Manager.h>

namespace ACE
{
    class ACE_ApplicationInitializer
    {
        ACE_ApplicationInitializer();
        virtual ~ACE_ApplicationInitializer();
        friend class ACE_Application;
    };

    class ACE_Application : public ACE_ApplicationInitializer, public ACE_Object, public ACE_Initializable
    {
    public:
        static void Exit();

        void Run();
    protected:
        explicit ACE_Application( const char *in_objectName );
        virtual ~ACE_Application() override;

        void AddManager( ACE_Manager *in_manager );

        virtual void Initialize() override;

        virtual void Update();

        virtual void Terminate() override;
    private:
        static bool sm_isExit;
        ACE_List<ACE_Manager *> m_managers;
    };

    #define ACE_Exit()      ACE::ACE_Application::Exit()

    #define ACE_Application_Initialize()        ACE_Initializable_Initialize( ACE::ACE_Application )

    #define ACE_Application_Terminate()         ACE_Initializable_Terminate( ACE::ACE_Application )
}