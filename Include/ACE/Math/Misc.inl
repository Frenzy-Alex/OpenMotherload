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
    constexpr T ACE_Min()
    {
        return 0;
    }

    template<>
    constexpr int ACE_Min()
    {
        return INT_MIN;
    }

    template< typename T >
    constexpr T ACE_Max()
    {
        return 0;
    }

    template<>
    constexpr int ACE_Max()
    {
        return INT_MAX;
    }

    template< typename T >
    constexpr const T &ACE_Min( const T &in_lhs, const T &in_rhs )
    {
        return in_lhs < in_rhs ? in_lhs : in_rhs;
    }

    template< typename T >
    constexpr const T &ACE_Max( const T &in_lhs, const T &in_rhs )
    {
        return in_lhs > in_rhs ? in_lhs : in_rhs;
    }

    template< typename T >
    constexpr T ACE_Random()
    {
        return ACE_Min<T>() + rand() % ACE_Max<T>();
    }

    template< typename T >
    constexpr T ACE_Random( const T &in_min, const T &in_max )
    {
        return in_min + rand() % ( in_max - in_min + 1 );
    }
}