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

#include <ACE/Base/Misc/Assert.h>

namespace ACE
{
    template< class T > T *ACE_Singleton<T>::sm_instance = nullptr;

    template< class T >
    inline ACE_Singleton<T>::ACE_Singleton()
    {
        ACE_Assert( sm_instance == nullptr );
        sm_instance = (T*)this;
    }

    template< class T >
    inline ACE_Singleton<T>::~ACE_Singleton()
    {
        ACE_Assert( sm_instance != nullptr );
        sm_instance = nullptr;
    }

    template< class T >
    inline T &ACE_Singleton<T>::GetInstance()
    {
        ACE_Assert( sm_instance != nullptr );
        return *sm_instance;
    }
}