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
    ACE_TConfigParam<T>::ACE_TConfigParam( const char *in_paramName, const T &in_defaultValue ) : ACE_IConfigParam( in_paramName ), m_defaultValue( in_defaultValue ), m_value( m_defaultValue )
    {

    }

    template< typename T >
    T ACE_TConfigParam<T>::GetValue() const
    {
        return m_value;
    }

    template< typename T >
    const T &ACE_TConfigParam<T>::GetDefaultValue() const
    {
        return m_defaultValue;
    }

    template< typename T >
    void ACE_TConfigParam<T>::SetValue( const T &in_value )
    {
        m_value = in_value;
    }

    template< typename T >
    void ACE_TConfigParam<T>::Reset()
    {
        m_value = m_defaultValue;
    }

    template< typename T >
    ACE_String ACE_TConfigParam<T>::ValueToStr() const
    {
        return ACE_ToString( m_value );
    }

    template< typename T >
    bool ACE_TConfigParam<T>::StrToValue( const ACE_String &in_str )
    {
        bool _result = false;
        T _temp = ACE_StringTo<T>( in_str, &_result );
        if( _result )
        {
            m_value = _temp;
        }
        return _result;
    }
}