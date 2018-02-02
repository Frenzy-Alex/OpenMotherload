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
    struct ACE_Vector2
    {
        ACE_Vector2();
        ACE_Vector2( const ACE_Vector2<T> &in_vec );

        ACE_Vector2( T in_x, T in_y = 0 );

        static const ACE_Vector2<T> zero;
        static const ACE_Vector2<T> one;
    };

    typedef ACE_Vector2<int>    ACE_Vector2i;
    typedef ACE_Vector2<uint>   ACE_Vector2ui;
    typedef ACE_Vector2<float>  ACE_Vector2f;
    typedef ACE_Vector2<double> ACE_Vector2d;
}

#include <ACE/Math/Vector2.inl>