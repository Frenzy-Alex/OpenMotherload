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
    struct ACE_Vector4
    {
        ACE_Vector4();
        ACE_Vector4( const ACE_Vector4<T> &in_vec );

        ACE_Vector4( T in_x, T in_y = 0 );

        static const ACE_Vector4<T> zero;
        static const ACE_Vector4<T> one;
    };

    typedef ACE_Vector4<int>    ACE_Vector4i;
    typedef ACE_Vector4<uint>   ACE_Vector4ui;
    typedef ACE_Vector4<float>  ACE_Vector4f;
    typedef ACE_Vector4<double> ACE_Vector4d;
}

#include <ACE/Math/Vector2.inl>