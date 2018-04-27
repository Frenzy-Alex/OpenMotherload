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
    template< int R, int C, typename T >
    inline ACE_Matrix<R, C, T>::ACE_Matrix() : matrix { 0 }
    {
    };

    template< int R, int C, typename T >
    template< int R2, int C2, typename T2 >
    inline ACE_Matrix<R, C, T>::ACE_Matrix( const ACE_Matrix <R2, C2, T2> &in_mat )
    {
        matrix[0][0] = in_mat.matrix[0][0];
        matrix[0][1] = in_mat.matrix[0][1];
        matrix[1][0] = in_mat.matrix[1][0];
        matrix[1][1] = in_mat.matrix[1][1];
        if constexpr ( C >= 3 )
        {
            if constexpr ( C2 >= 3 )
            {
                matrix[0][2] = in_mat.matrix[0][2];
                matrix[1][2] = in_mat.matrix[1][2];
            }
            else
            {
                matrix[0][2] = 0;
                matrix[1][2] = 0;
            }

            if constexpr ( C == 4 )
            {
                if constexpr ( C2 == 4 )
                {
                    matrix[0][3] = in_mat.matrix[0][3];
                    matrix[1][3] = in_mat.matrix[1][3];
                }
                else
                {
                    matrix[0][3] = 0;
                    matrix[1][3] = 0;
                }
            }
        }
        //
        //  Add
        //
        if constexpr ( R >= 3 )
        {
            matrix[2][0] = in_mat.matrix[0][0];
            matrix[2][1] = in_mat.matrix[0][0];
            if constexpr ( C >= 3 )
            {
                matrix[2][2] = in_mat.matrix[0][0];
                if constexpr ( C == 4 )
                {
                    matrix[2][3] = in_mat.matrix[0][0];
                }
            }

            if constexpr ( R == 4 )
            {
                matrix[3][0] = in_mat.matrix[0][0];
                matrix[3][1] = in_mat.matrix[0][0];
                if constexpr ( C >= 3 )
                {
                    matrix[3][2] = in_mat.matrix[0][0];
                    if constexpr ( C == 4 )
                    {
                        matrix[3][3] = in_mat.matrix[0][0];
                    }
                }
            }
        }
    };

    template< int R, int C, typename T >
    inline ACE_Matrix<R, C, T>::ACE_Matrix( T in_m11, T in_m12, //
                                            T in_m21, T in_m22 )
    {
        matrix[0][0] = in_m11;
        matrix[0][1] = in_m12;
        matrix[1][0] = in_m21;
        matrix[1][1] = in_m22;
    };

    template< int R, int C, typename T >
    inline ACE_Matrix<R, C, T>::ACE_Matrix( T in_m11, T in_m12, T in_m13, //
                                            T in_m21, T in_m22, T in_m23, //
                                            T in_m31, T in_m32, T in_m33 )
    {
        matrix[0][0] = in_m11;
        matrix[0][1] = in_m12;
        matrix[1][0] = in_m21;
        matrix[1][1] = in_m22;
        if constexpr ( C >= 3 )
        {
            matrix[0][2] = in_m13;
            matrix[1][2] = in_m23;
        }
        if constexpr ( R >= 3 )
        {
            matrix[2][0] = in_m31;
            matrix[2][1] = in_m32;
            if constexpr ( C >= 3 )
            {
                matrix[2][2] = in_m33;
            }
        }
    };

    template< int R, int C, typename T >
    inline ACE_Matrix<R, C, T>::ACE_Matrix( T in_m11, T in_m12, T in_m13, T in_m14, //
                                            T in_m21, T in_m22, T in_m23, T in_m24, //
                                            T in_m31, T in_m32, T in_m33, T in_m34, //
                                            T in_m41, T in_m42, T in_m43, T in_m44 )
    {
        matrix[0][0] = in_m11;
        matrix[0][1] = in_m12;
        matrix[1][0] = in_m21;
        matrix[1][1] = in_m22;
        if constexpr ( C >= 3 )
        {
            matrix[0][2] = in_m13;
            matrix[1][2] = in_m23;
            if constexpr ( C == 4 )
            {
                matrix[0][3] = in_m14;
                matrix[1][3] = in_m24;
            }
        }
        if constexpr ( R >= 3 )
        {
            matrix[2][0] = in_m31;
            matrix[2][1] = in_m32;
            if constexpr ( C >= 3 )
            {
                matrix[2][2] = in_m33;
                if constexpr ( C == 4 )
                {
                    matrix[2][3] = in_m34;
                }
            }

            if constexpr ( R == 4 )
            {
                matrix[3][0] = in_m41;
                matrix[3][1] = in_m42;
                if constexpr ( C >= 3 )
                {
                    matrix[3][2] = in_m43;
                    if constexpr ( C == 4 )
                    {
                        matrix[3][3] = in_m44;
                    }
                }
            }
        }
    };


    //
    //  Static data
    //

    template< int R, int C, typename T > //
    const ACE_Matrix <R, C, T> ACE_Matrix<R, C, T>::zero = ACE_Matrix( 0, 0, 0, 0, //
                                                                       0, 0, 0, 0, //
                                                                       0, 0, 0, 0, //
                                                                       0, 0, 0, 0 );

    template< int R, int C, typename T > //
    const ACE_Matrix <R, C, T> ACE_Matrix<R, C, T>::identity = ACE_Matrix( 1, 0, 0, 0, //
                                                                           0, 1, 0, 0, //
                                                                           0, 0, 1, 0, //
                                                                           0, 0, 0, 1 );
}