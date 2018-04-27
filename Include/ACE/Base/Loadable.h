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

#include <ACE/Base/LoadingStatus.h>

namespace ACE
{
    class ACE_Loadable
    {
    public:
    protected:
        ACE_Loadable();
        virtual ~ACE_Loadable();
    private:
        ACE_LoadingStatus m_loadingStatus;
    };
}