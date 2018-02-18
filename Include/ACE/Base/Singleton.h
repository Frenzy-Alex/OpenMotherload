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

#include <ACE/Base/Misc/UniquePointer.h>

namespace ACE
{
    template< class T >
    class ACE_Singleton
    {
    public:
        static void CreateInstance();
        static void DestroyInstance();

        static T &GetInstance();
    protected:
        ACE_Singleton() = default;
        virtual ~ACE_Singleton() = default;
    private:
        static T *sm_instance;
    };

    #define ACE_SingletonFriend( obj )      friend class ACE_Singleton< obj >
}

#include <ACE/Base/Singleton.inl>