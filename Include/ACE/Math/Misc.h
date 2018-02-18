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
    //
    //  Trigonometric functions
    //

    template< typename T >
    constexpr T ACE_Degrees( const T &in_degrees );

    template< typename T >
    constexpr T ACE_Radians( const T &in_radians );

    template< typename T >
    constexpr T ACE_Cos( const T &in_angle );

    template< typename T >
    constexpr T ACE_Sin( const T &in_angle );

    template< typename T >
    constexpr T ACE_Tan( const T &in_angle );

    //
    //  Exponential and logarithmic functions
    //

    template< typename T >
    constexpr T ACE_Exp( const T &in_x );

    template< typename T >
    constexpr T ACE_Log( const T &in_x );

    //
    //  Power functions
    //

    template< typename T >
    constexpr T ACE_Pow( const T &in_x, const T &in_y );

    template< typename T >
    constexpr T ACE_Sqrt( const T &in_x );

    //
    //  Basic functions
    //

    template< typename T >
    constexpr T ACE_Abs( const T &in_x );

    template< typename T >
    constexpr T ACE_Floor( const T &in_x );

    template< typename T >
    constexpr T ACE_Sign( const T &in_x );

    template< typename T >
    constexpr const T &ACE_Min( const T &in_lhs, const T &in_rhs );

    template< typename T >
    constexpr const T &ACE_Max( const T &in_lhs, const T &in_rhs );

    //
    //  Random functions
    //

    template< typename T >
    constexpr T ACE_Random();

    template< typename T >
    constexpr T ACE_Random( const T &in_min, const T &in_max );
}

#include <ACE/Math/Misc.inl>