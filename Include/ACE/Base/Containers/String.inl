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

#include <ACE/Base/Misc/Assert.h>

namespace ACE
{
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

    template< typename T >
    T ACE_StringTo( const ACE_String &in_str, bool *out_result )
    {
        return T::UnsupportedType;
    }

    template< typename T >
    const ACE_String &ACE_ToString( T in_value )
    {
        return T::UnsupportedType;
    }

    template< typename T >
    const char *ACE_ToCString( T in_value )
    {
        return T::UnsupportedType;
    }
}