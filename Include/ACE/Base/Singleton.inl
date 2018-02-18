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

namespace ACE
{
    template< class T > T *ACE_Singleton<T>::sm_instance = nullptr;

    template< class T >
    void ACE_Singleton<T>::CreateInstance()
    {
        ACE_Assert( sm_instance == nullptr );
        sm_instance = new T();
        //        sm_instance = (T *)malloc( sizeof( T ) );
        //        new( sm_instance ) T();
        ACE_Assert( sm_instance != nullptr );
    }

    template< class T >
    void ACE_Singleton<T>::DestroyInstance()
    {
        ACE_Assert( sm_instance != nullptr );
        delete sm_instance;
        //        sm_instance->~T();
        //        free( sm_instance );
        sm_instance = nullptr;
    }

    template< class T >
    T &ACE_Singleton<T>::GetInstance()
    {
        ACE_Assert( sm_instance != nullptr );
        return *sm_instance;
    }
}