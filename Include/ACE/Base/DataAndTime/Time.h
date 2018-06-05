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
    struct ACE_Time
    {
        ACE_Time();
        ACE_Time( const ACE_Time &in_ref );

        int hour;
        int minute;
        int second;
    };
}
