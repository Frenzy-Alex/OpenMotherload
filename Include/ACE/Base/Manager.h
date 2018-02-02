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

#include <ACE/Base/Containers/List.h>
#include <ACE/Base/Misc/Macro.h>
#include <ACE/Base/Initializable.h>
#include <ACE/Base/Object.h>

namespace ACE
{
    class ACE_Application;

    template< bool InThread >
    class ACE_Manager;

    class ACE_IManager : public ACE_Object, public ACE_Initializable
    {
        explicit ACE_IManager( const char *in_objectName, bool in_isInThread );
        virtual ~ACE_IManager() override = default;

        friend class ACE_Application;
        friend class ACE_Manager<false>;
        friend class ACE_Manager<true>;
    public:
        const bool IsInThread() const;
    protected:
        virtual void Initialize();
        virtual void Initialized();

        virtual void Update();

        virtual void Terminate();
        virtual void Terminated();

        void AddChildManager( ACE_IManager *in_manager );
        void RemoveChildManager( ACE_IManager *in_manager );
    private:
        const bool m_isInThread;
        ACE_List<ACE_IManager *> m_childManagers;
        ACE_List<ACE_IManager *> m_childUpdatableManagers;
    };

    template<>
    class ACE_Manager<false> : public ACE_IManager
    {
    public:
        constexpr static bool IsInThread();
    protected:
        explicit ACE_Manager( const char *in_objectName );
        virtual ~ACE_Manager() override = default;
    };

    template<>
    class ACE_Manager<true> : public ACE_IManager
    {
    public:
        constexpr static bool IsInThread();
    protected:
        explicit ACE_Manager( const char *in_objectName );
        virtual ~ACE_Manager() override = default;

        //        virtual void Initialize();
        //        virtual void Initialized();
        //
        //        virtual void Terminate();
        //        virtual void Terminated();
    };

    #define ACE_Manager_Initialize()    ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Terminated );     \
                                        ACE_Manager::Initialize();                                          \
                                        ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Initializing )


    #define ACE_Manager_Terminate()     ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Initialized &&    \
                                                      GetInitializationStatus() != ACE_IS_Error );          \
                                        ACE_Manager::Terminate();                                           \
                                        ACE_ReturnIf( GetInitializationStatus() != ACE_IS_Terminating )

}