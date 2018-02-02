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
    struct ACE_Vector3
    {
        ACE_Vector3();
        ACE_Vector3( const ACE_Vector3<T> &in_vec );

        explicit ACE_Vector3( T in_x, T in_y = 0, T in_z = 0 );

        T *Data() const;

        ACE_Vector3 &operator=( const ACE_Vector3 &in_ref );

        T x, y, z;

        static const ACE_Vector3<T> zero;
        static const ACE_Vector3<T> one;
    };

    typedef ACE_Vector3<int> ACE_Vector3i;
    typedef ACE_Vector3<uint> ACE_Vector3ui;
    typedef ACE_Vector3<float> ACE_Vector3f;
    typedef ACE_Vector3<double> ACE_Vector3d;
}

#include <ACE/Math/Vector3.inl>