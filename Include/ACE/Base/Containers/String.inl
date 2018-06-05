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

#include <ACE/PrecompiledHeader.h>
#include <ACE/Base/Misc/Assert.h>

namespace ACE
{
    /**
     * @brief Test if string is empty
     * @return true if string length is 0, false otherwise
     */
    inline bool ACE_String::IsEmpty() const
    {
        return strlen( m_string ) == 0;
    }

    /**
     * @brief Return length of string
     * @return The number of bytes in the string
     */
    inline size ACE_String::Length() const
    {
        return strlen( m_string );
    }

    /**
     * @brief Get C string
     * @return A pointer to the c string.
     */
    inline const char *ACE_String::CStr() const noexcept
    {
        return m_string;
    }

    //
    //  Member Access Operators
    //
    inline char &ACE_String::operator[]( uint in_pos ) noexcept
    {
        ACE_Assert( Length() < in_pos );
        return m_string[in_pos];
    }

    inline const char &ACE_String::operator[]( uint in_pos ) const noexcept
    {
        ACE_Assert( Length() < in_pos );
        return m_string[in_pos];
    }

    //  String to ...
    template< typename T >
    bool ACE_StringTo( const ACE_String &in_str, T *out_value )
    {
        return T::UnsupportedType;
    }

    template< typename T >
    const ACE_String &ACE_ToString( T in_value )
    {
        return T::UnsupportedType;
    }

    template< typename T >
    bool ACE_CStringTo( char *in_str, T *out_value )
    {
        return T::UnsupportedType;
    }

    template< typename T >
    const char *ACE_ToCString( T in_value )
    {
        return T::UnsupportedType;
    }
}
