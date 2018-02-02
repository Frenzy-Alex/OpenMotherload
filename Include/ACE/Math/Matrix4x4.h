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
    template< typename T >
    struct ACE_Matrix4x4
    {
        ACE_Matrix4x4();
        ACE_Matrix4x4( const ACE_Matrix4x4<T> &in_vec );

        ACE_Matrix4x4( T in_x, T in_y = 0 );

        static const ACE_Matrix4x4<T> zero;
        static const ACE_Matrix4x4<T> one;
    };

    typedef ACE_Matrix4x4<float>  ACE_Matrix4x4f;
    typedef ACE_Matrix4x4<double> ACE_Matrix4x4d;
}

#include <ACE/Math/Vector2.inl>