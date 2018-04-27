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
    class ACE_RootInitializer
    {
    public:
        ACE_RootInitializer();
        virtual ~ACE_RootInitializer();
    private:
        static bool sm_isInstantiated;
    };

    #define ACE_FRIEND_ROOT_INITIALIZER     friend class ACE::ACE_RootInitializer;
}