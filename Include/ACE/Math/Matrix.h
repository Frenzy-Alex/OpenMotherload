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

#include <ACE/Math/Vector.h>

namespace ACE
{
    template< int R, int C, typename T >
    struct ACE_Matrix
    {
        ACE_Matrix();

        template< int R2, int C2, typename T2 >
        ACE_Matrix( const ACE_Matrix<R2, C2, T2> &in_mat );

        ACE_Matrix( T in_m11, T in_m12, //
                    T in_m21, T in_m22 );

        ACE_Matrix( T in_m11, T in_m12, T in_m13, //
                    T in_m21, T in_m22, T in_m23, //
                    T in_m31, T in_m32, T in_m33 );

        ACE_Matrix( T in_m11, T in_m12, T in_m13, T in_m14, //
                    T in_m21, T in_m22, T in_m23, T in_m24, //
                    T in_m31, T in_m32, T in_m33, T in_m34, //
                    T in_m41, T in_m42, T in_m43, T in_m44 );

        //
        //  Arithmetic operators
        //

        template< int R1, int C1, typename T1, int R2, int C2, typename T2 >
        friend ACE_Matrix<R1, C1, T1> operator+( const ACE_Matrix<R1, C1, T1> &in_lhs, const ACE_Matrix<R2, C2, T2> &in_rhs );

        template< int R1, int C1, typename T1, int R2, int C2, typename T2 >
        friend ACE_Matrix<R1, C1, T1> operator-( const ACE_Matrix<R1, C1, T1> &in_lhs, const ACE_Matrix<R2, C2, T2> &in_rhs );

        //
        //  Member access operators
        //

        T &operator[]( int in_index );
        const T &operator[]( int in_index ) const;


        //
        //  Data
        //

        union
        {
            ACE_Vector<C, T> vector[R];
            T matrix[R][C];
            T data[R * C];
        };

        //
        //  Static data
        //

        static const ACE_Matrix<R, C, T> zero;
        static const ACE_Matrix<R, C, T> identity;
    };

    template< typename T > using ACE_Matrix2x2 =  ACE_Matrix<2, 2, T>;
    template< typename T > using ACE_Matrix3x3 =  ACE_Matrix<3, 3, T>;
    template< typename T > using ACE_Matrix4x4 =  ACE_Matrix<4, 4, T>;

    typedef ACE_Matrix2x2<float> ACE_Matrix2x2f;
    typedef ACE_Matrix2x2<double> ACE_Matrix2x2d;

    typedef ACE_Matrix3x3<float> ACE_Matrix3x3f;
    typedef ACE_Matrix3x3<double> ACE_Matrix3x3d;

    typedef ACE_Matrix4x4<float> ACE_Matrix4x4f;
    typedef ACE_Matrix4x4<double> ACE_Matrix4x4d;
}

#include <ACE/Math/Matrix.inl>