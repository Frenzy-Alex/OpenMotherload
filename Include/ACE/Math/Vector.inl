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

#include <ACE/Math/Misc.h>

namespace ACE
{
    //
    //  Constructors
    //

    template< int S, typename T >
    inline ACE_Vector<S, T>::ACE_Vector()
    {
        this->x = T( 0 );
        this->y = T( 0 );
        if constexpr ( S >= 3 )
        {
            this->z = T( 0 );
            if constexpr ( S >= 4 )
            {
                this->w = T( 0 );
            }
        }
    };

    template< int S, typename T >
    template< int S2, typename T2 >
    inline ACE_Vector<S, T>::ACE_Vector( const ACE_Vector<S2, T2> &in_vec )
    {
        this->x = T( in_vec.x );
        this->y = T( in_vec.y );
        if constexpr ( S >= 3 )
        {
            if constexpr ( S2 >= 3 )
            {
                this->z = T( in_vec.z );
            }
            else
            {
                this->z = T( 0 );
            }

            if constexpr ( S >= 4 )
            {
                if constexpr ( S2 >= 4 )
                {
                    this->w = T( in_vec.w );
                }
                else
                {
                    this->w = T( 0 );
                }
            }
        }
    };

    template< int S, typename T >
    inline ACE_Vector<S, T>::ACE_Vector( T in_x )
    {
        this->x = in_x;
        this->y = T( 0 );
        if constexpr ( S >= 3 )
        {
            this->z = T( 0 );
            if constexpr ( S >= 4 )
            {
                this->w = T( 0 );
            }
        }
    };

    template< int S, typename T >
    inline ACE_Vector<S, T>::ACE_Vector( T in_x, T in_y )
    {
        this->x = in_x;
        this->y = in_y;
        if constexpr ( S >= 3 )
        {
            this->z = T( 0 );
            if constexpr ( S >= 4 )
            {
                this->w = T( 0 );
            }
        }
    };

    template< int S, typename T >
    inline ACE_Vector<S, T>::ACE_Vector( T in_x, T in_y, T in_z )
    {
        this->x = in_x;
        this->y = in_y;
        if constexpr ( S >= 3 )
        {
            this->z = in_z;
            if constexpr ( S >= 4 )
            {
                this->w = T( 0 );
            }
        }
    };

    template< int S, typename T >
    inline ACE_Vector<S, T>::ACE_Vector( T in_x, T in_y, T in_z, T in_w )
    {
        this->x = in_x;
        this->y = in_y;
        if constexpr ( S >= 3 )
        {
            this->z = in_z;
            if constexpr ( S >= 4 )
            {
                this->w = in_w;
            }
        }
    };

    //
    //  Assignment operators
    //

    template< int S, typename T >
    template< int S2, typename T2 >
    inline ACE_Vector<S, T> &ACE_Vector<S, T>::operator=( const ACE_Vector<S2, T2> &in_vec )
    {
        this->x = in_vec.x;
        this->y = in_vec.y;
        if constexpr ( S >= 3 && S2 >= 3 )
        {
            this->z = in_vec.z;
            if constexpr ( S == 4 && S2 == 4 )
            {
                this->w = in_vec.w;
            }
        }
        return *this;
    };

    template< int S, typename T >
    template< int S2, typename T2 >
    inline ACE_Vector<S, T> &ACE_Vector<S, T>::operator+=( const ACE_Vector<S2, T2> &in_vec )
    {
        this->x += in_vec.x;
        this->y += in_vec.y;
        if constexpr ( S >= 3 && S2 >= 3 )
        {
            this->z += in_vec.z;
            if constexpr ( S == 4 && S2 == 4 )
            {
                this->w += in_vec.w;
            }
        }
        return *this;
    };

    template< int S, typename T >
    template< int S2, typename T2 >
    inline ACE_Vector<S, T> &ACE_Vector<S, T>::operator-=( const ACE_Vector<S2, T2> &in_vec )
    {
        this->x -= in_vec.x;
        this->y -= in_vec.y;
        if constexpr ( S >= 3 && S2 >= 3 )
        {
            this->z -= in_vec.z;
            if constexpr ( S == 4 && S2 == 4 )
            {
                this->w -= in_vec.w;
            }
        }
        return *this;
    };

    template< int S, typename T >
    template< int S2, typename T2 >
    inline ACE_Vector<S, T> &ACE_Vector<S, T>::operator*=( const ACE_Vector<S2, T2> &in_vec )
    {
        this->x *= in_vec.x;
        this->y *= in_vec.y;
        if constexpr ( S >= 3 && S2 >= 3 )
        {
            this->z *= in_vec.z;
            if constexpr ( S == 4 && S2 == 4 )
            {
                this->w *= in_vec.w;
            }
        }
        return *this;
    };

    template< int S, typename T >
    template< int S2, typename T2 >
    inline ACE_Vector<S, T> &ACE_Vector<S, T>::operator/=( const ACE_Vector<S2, T2> &in_vec )
    {
        ACE_Assert( in_vec.x != T( 0 ) );
        this->x /= in_vec.x;
        ACE_Assert( in_vec.y != T( 0 ) );
        this->y /= in_vec.y;
        if constexpr ( S >= 3 && S2 >= 3 )
        {
            ACE_Assert( in_vec.z != T( 0 ) );
            this->z /= in_vec.z;
            if constexpr ( S == 4 && S2 == 4 )
            {
                ACE_Assert( in_vec.w != T( 0 ) );
                this->w /= in_vec.w;
            }
        }
        return *this;
    };

    //
    //  Arithmetic operators
    //

    template< int S, typename T >
    inline ACE_Vector<S, T> ACE_Vector<S, T>::operator-() const
    {
        if constexpr ( S == 2 )
        {
            return ACE_Vector( -this->x, -this->y );
        }
        else if constexpr ( S == 3 )
        {
            return ACE_Vector( -this->x, -this->y, -this->z );
        }
        return ACE_Vector( -this->x, -this->y, -this->z, -this->w );
    };

    template< int S1, typename T1, int S2, typename T2 >
    inline ACE_Vector<S1, T1> operator+( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs )
    {
        T1 _x = in_lhs.x + in_rhs.x;
        T1 _y = in_lhs.y + in_rhs.y;
        if constexpr ( S1 >= 3 )
        {
            T1 _z = in_lhs.z;

            if constexpr ( S2 >= 3 )
            {
                _z += in_rhs.z;
            }

            if constexpr ( S1 == 4 )
            {
                T1 _w = in_lhs.w;

                if constexpr ( S2 == 4 )
                {
                    _w += in_rhs.w;
                }

                return ACE_Vector<S1, T1>( _x, _y, _z, _w );
            }
            return ACE_Vector<S1, T1>( _x, _y, _z );
        }
        return ACE_Vector<S1, T1>( _x, _y );
    };

    template< int S1, typename T1, int S2, typename T2 >
    inline ACE_Vector<S1, T1> operator-( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs )
    {
        T1 _x = in_lhs.x - in_rhs.x;
        T1 _y = in_lhs.y - in_rhs.y;
        if constexpr ( S1 >= 3 )
        {
            T1 _z = in_lhs.z;

            if constexpr ( S2 >= 3 )
            {
                _z -= in_rhs.z;
            }

            if constexpr ( S1 == 4 )
            {
                T1 _w = in_lhs.w;

                if constexpr ( S2 == 4 )
                {
                    _w -= in_rhs.w;
                }

                return ACE_Vector<S1, T1>( _x, _y, _z, _w );
            }
            return ACE_Vector<S1, T1>( _x, _y, _z );
        }
        return ACE_Vector<S1, T1>( _x, _y );
    };

    template< int S1, typename T1, int S2, typename T2 >
    inline ACE_Vector<S1, T1> operator*( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs )
    {
        T1 _x = in_lhs.x * in_rhs.x;
        T1 _y = in_lhs.y * in_rhs.y;
        if constexpr ( S1 >= 3 )
        {
            T1 _z = in_lhs.z;

            if constexpr ( S2 >= 3 )
            {
                _z *= in_rhs.z;
            }

            if constexpr ( S1 == 4 )
            {
                T1 _w = in_lhs.w;

                if constexpr ( S2 == 4 )
                {
                    _w *= in_rhs.w;
                }

                return ACE_Vector<S1, T1>( _x, _y, _z, _w );
            }
            return ACE_Vector<S1, T1>( _x, _y, _z );
        }
        return ACE_Vector<S1, T1>( _x, _y );
    };

    template< int S1, typename T1, int S2, typename T2 >
    inline ACE_Vector<S1, T1> operator/( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs )
    {
        ACE_Assert( in_rhs.x != T1( 0 ) && in_rhs.y != T1( 0 ) );
        T1 _x = in_lhs.x / in_rhs.x;
        T1 _y = in_lhs.y / in_rhs.y;
        if constexpr ( S1 >= 3 )
        {
            T1 _z = in_lhs.z;

            if constexpr ( S2 >= 3 )
            {
                ACE_Assert( in_rhs.z != T1( 0 ) );
                _z /= in_rhs.z;
            }

            if constexpr ( S1 == 4 )
            {
                T1 _w = in_lhs.w;

                if constexpr ( S2 == 4 )
                {
                    ACE_Assert( in_rhs.w != T1( 0 ) );
                    _w /= in_rhs.w;
                }

                return ACE_Vector<S1, T1>( _x, _y, _z, _w );
            }
            return ACE_Vector<S1, T1>( _x, _y, _z );
        }
        return ACE_Vector<S1, T1>( _x, _y );
    };

    //
    //  Comparison operators
    //

    template< int S1, typename T1, int S2, typename T2 >
    inline bool operator==( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs )
    {
        bool _x = in_lhs.x == in_rhs.x;
        bool _y = in_lhs.x == in_rhs.y;
        if constexpr ( S1 >= 3 || S2 >= 3 )
        {
            bool _z;
            if constexpr ( S1 >= 3 && S2 >= 3 )
            {
                _z = in_lhs.z == in_rhs.z;
            }
            else if constexpr ( S1 >= 3 )
            {
                _z = in_lhs.z == T1( 0 );
            }
            else
            {
                _z = in_rhs.z == T2( 0 );
            }
            if constexpr ( S1 == 4 || S2 == 4 )
            {
                bool _w;
                if constexpr ( S1 == 4 && S2 == 4 )
                {
                    _w = in_lhs.w == in_rhs.w;
                }
                else if constexpr ( S1 == 4 )
                {
                    _w = in_lhs.w == T1( 0 );
                }
                else
                {
                    _w = in_rhs.w == T2( 0 );
                }
                return _x && _y && _z && _w;
            }
            return _x && _y && _z;
        }
        return _x && _y;
    };

    template< int S1, typename T1, int S2, typename T2 >
    inline bool operator!=( const ACE_Vector<S1, T1> &in_lhs, const ACE_Vector<S2, T2> &in_rhs )
    {
        bool _x = in_lhs.x != in_rhs.x;
        bool _y = in_lhs.x != in_rhs.y;
        if constexpr ( S1 >= 3 || S2 >= 3 )
        {
            bool _z;
            if constexpr ( S1 >= 3 && S2 >= 3 )
            {
                _z = in_lhs.z != in_rhs.z;
            }
            else if constexpr ( S1 >= 3 )
            {
                _z = in_lhs.z != T1( 0 );
            }
            else
            {
                _z = in_rhs.z != T2( 0 );
            }
            if constexpr ( S1 == 4 || S2 == 4 )
            {
                bool _w;
                if constexpr ( S1 == 4 && S2 == 4 )
                {
                    _w = in_lhs.w != in_rhs.w;
                }
                else if constexpr ( S1 == 4 )
                {
                    _w = in_lhs.w != T1( 0 );
                }
                else
                {
                    _w = in_rhs.w != T2( 0 );
                }
                return _x || _y || _z || _w;
            }
            return _x || _y || _z;
        }
        return _x || _y;
    };

    //
    //  Member access operators
    //

    template< int S, typename T >
    inline T &ACE_Vector<S, T>::operator[]( int in_index )
    {
        ACE_Assert( in_index >= 0 && in_index < S );
        return this->data[in_index];
    };


    template< int S, typename T >
    inline const T &ACE_Vector<S, T>::operator[]( int in_index ) const
    {
        ACE_Assert( in_index >= 0 && in_index < S );
        return this->data[in_index];
    };

    //
    //  Static data
    //

    template< int S, typename T > //
    const ACE_Vector<S, T> ACE_Vector<S, T>::zero = ACE_Vector( 0, 0, 0, 0 );

    template< int S, typename T > //
    const ACE_Vector<S, T> ACE_Vector<S, T>::one = ACE_Vector( 1, 1, 1, 1 );
}