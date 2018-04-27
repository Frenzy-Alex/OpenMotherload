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

namespace ACE
{
    template< class T >
    class ACE_Singleton
    {
    public:
        static T &GetInstance();
    protected:
        ACE_Singleton();
        virtual ~ACE_Singleton();
    private:
        static T *sm_instance;
    };
}

#include <ACE/Base/Singleton.inl>