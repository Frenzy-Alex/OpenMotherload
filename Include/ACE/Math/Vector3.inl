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
    ACE_Vector3<T>::ACE_Vector3()
    {

    }

    template< typename T >
    ACE_Vector3<T>::ACE_Vector3( const ACE_Vector3 <T> &in_vec ) : x( in_vec.x ), y( in_vec.y ), z( in_vec.z )
    {

    }

    template< typename T >
    ACE_Vector3<T>::ACE_Vector3( T in_x, T in_y, T in_z ) : x( in_x ), y( in_y ), z( in_z )
    {

    }

    template< typename T >
    T *ACE_Vector3<T>::Data() const
    {
        return (T *)this;
    }

    template< typename T >
    ACE_Vector3 <T> &ACE_Vector3<T>::operator=( const ACE_Vector3 &in_ref )
    {
        x = in_ref.x;
        y = in_ref.y;
        z = in_ref.z;
        return *this;
    }


}