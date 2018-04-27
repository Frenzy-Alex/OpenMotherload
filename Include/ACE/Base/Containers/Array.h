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
    template< typename T >
    class ACE_Array final
    {
    public:
        ACE_Array();
        ACE_Array( const ACE_Array &in_arr );
        ACE_Array( ACE_Array &&in_arr );
        ~ACE_Array();
    private:
        //        T *m_data;
    };
}

#include <ACE/Base/Containers/Array.inl>