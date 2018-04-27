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

#include <ACE/PrecompiledHeader.h>

namespace ACE
{
    class ACE_Mutex final
    {
    public:
        ACE_Mutex();
        ACE_Mutex( const ACE_Mutex & ) = delete;
        ~ACE_Mutex();

        void Lock();
        bool TryLock();
        void Unlock();

        ACE_Mutex &operator=( const ACE_Mutex & ) = delete;
    private:
        pthread_mutex_t m_mutex;
    };
}