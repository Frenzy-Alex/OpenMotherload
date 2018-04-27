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
#include <ACE/RootInitializer.h>
#include <ACE/Graphic/Window.h>

namespace ACE
{
    class ACE_WindowManager final : public ACE_Manager, public ACE_Singleton<ACE_WindowManager>
    {
        ACE_WindowManager();
        virtual ~ACE_WindowManager() override final;
        friend class ACE_RootInitializer;
        friend class ACE_Window;
    public:
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;

        #if ACE_Platform == ACE_Platform_Linux

        Display *GetDisplay() const;
        Window GetDefaultRootWindow() const;

        #endif

        void RegisterWindow( ACE_Window *in_window );
        void UnregisterWindow( ACE_Window *in_window );
    private:
        #if ACE_Platform == ACE_Platform_Linux

        Display *m_display;
        Screen *m_defaultScreen;
        Window m_defaultRootWindow;

        #endif

        ACE_List<ACE_Window *> m_windows;
    };

    #define ACE_WindowManagerS     ACE::ACE_WindowManager::GetInstance()
}