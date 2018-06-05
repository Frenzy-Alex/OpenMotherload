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
    template< uint8 S, typename T >
    struct ACE_VectorBase
    {
        static_assert( S == 2 || S == 3 || S == 4 );
    };

    #define ACE_AnonymousStruct( type, ... )    struct{ type __VA_ARGS__; }

    template< typename T >
    struct ACE_VectorBase<2, T>
    {
        union
        {
            ACE_AnonymousStruct( T, x, y );
            ACE_AnonymousStruct( T, r, g );
            T data[2];
        };
    };

    template< typename T >
    struct ACE_VectorBase<3, T>
    {
        union
        {
            ACE_AnonymousStruct( T, x, y, z );
            ACE_AnonymousStruct( T, r, g, b );
            T data[3];
        };
    };

    template< typename T >
    struct ACE_VectorBase<4, T>
    {
        union
        {
            ACE_AnonymousStruct( T, x, y, z, w );
            ACE_AnonymousStruct( T, r, g, b, a );
            T data[4];
        };
    };

    template< uint8 S, typename T >
    struct ACE_Vector : ACE_VectorBase<S, T>
    {
        //
        //  Constructors
        //

        ACE_Vector();

        template< uint8 S2, typename T2 >
        ACE_Vector( const ACE_Vector<S2, T2> &in_vec );

        ACE_Vector( T in_x );
        ACE_Vector( T in_x, T in_y );
        ACE_Vector( T in_x, T in_y, T in_z );
        ACE_Vector( T in_x, T in_y, T in_z, T in_w );

        //
        //  Functions
        //

        //
        //  Assignment operators
        //

        template< uint8 S2, typename T2 >
        ACE_Vector &operator=( const ACE_Vector<S2, T2> &in_vec );

        template< uint8 S2, typename T2 >
        ACE_Vector &operator+=( const ACE_Vector<S2, T2> &in_vec );

        template< uint8 S2, typename T2 >
        ACE_Vector &operator-=( const ACE_Vector<S2, T2> &in_vec );

        template< uint8 S2, typename T2 >
        ACE_Vector &operator*=( const ACE_Vector<S2, T2> &in_vec );

        template< uint8 S2, typename T2 >
        ACE_Vector &operator/=( const ACE_Vector<S2, T2> &in_vec );

        //
        //  Arithmetic operators
        //

        ACE_Vector operator-() const;

        template< uint8 S1, typename T1, uint8 S2, typename T2 >
        friend ACE_Vector<S1, T1> operator+( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs );

        template< uint8 S1, typename T1, uint8 S2, typename T2 >
        friend ACE_Vector<S1, T1> operator-( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs );

        template< uint8 S1, typename T1, uint8 S2, typename T2 >
        friend ACE_Vector<S1, T1> operator*( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs );

        template< uint8 S1, typename T1, uint8 S2, typename T2 >
        friend ACE_Vector<S1, T1> operator/( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs );

        //
        //  Comparison operators
        //

        template< uint8 S1, typename T1, uint8 S2, typename T2 >
        friend bool operator==( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs );

        template< uint8 S1, typename T1, uint8 S2, typename T2 >
        friend bool operator!=( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs );

        //
        //  Member access operators
        //

        T &operator[]( uint8 in_index );
        const T &operator[]( uint8 in_index ) const;

        //
        //  Static data
        //

        static const ACE_Vector<S, T> zero;
        static const ACE_Vector<S, T> one;
    };

    template< typename T > using ACE_Vector2 =  ACE_Vector<2, T>;
    template< typename T > using ACE_Vector3 =  ACE_Vector<3, T>;
    template< typename T > using ACE_Vector4 =  ACE_Vector<4, T>;

    typedef ACE_Vector2<bool> ACE_Vector2b;
    typedef ACE_Vector2<char> ACE_Vector2c;
    typedef ACE_Vector2<uchar> ACE_Vector2uc;
    typedef ACE_Vector2<short> ACE_Vector2s;
    typedef ACE_Vector2<ushort> ACE_Vector2us;
    typedef ACE_Vector2<int> ACE_Vector2i;
    typedef ACE_Vector2<uint> ACE_Vector2ui;
    typedef ACE_Vector2<float> ACE_Vector2f;
    typedef ACE_Vector2<double> ACE_Vector2d;

    typedef ACE_Vector3<bool> ACE_Vector3b;
    typedef ACE_Vector3<char> ACE_Vector3c;
    typedef ACE_Vector3<uchar> ACE_Vector3uc;
    typedef ACE_Vector3<short> ACE_Vector3s;
    typedef ACE_Vector3<ushort> ACE_Vector3us;
    typedef ACE_Vector3<int> ACE_Vector3i;
    typedef ACE_Vector3<uint> ACE_Vector3ui;
    typedef ACE_Vector3<float> ACE_Vector3f;
    typedef ACE_Vector3<double> ACE_Vector3d;

    typedef ACE_Vector4<bool> ACE_Vector4b;
    typedef ACE_Vector4<char> ACE_Vector4c;
    typedef ACE_Vector4<uchar> ACE_Vector4uc;
    typedef ACE_Vector4<short> ACE_Vector4s;
    typedef ACE_Vector4<ushort> ACE_Vector4us;
    typedef ACE_Vector4<int> ACE_Vector4i;
    typedef ACE_Vector4<uint> ACE_Vector4ui;
    typedef ACE_Vector4<float> ACE_Vector4f;
    typedef ACE_Vector4<double> ACE_Vector4d;
}

#include <ACE/Math/Vector.inl>
