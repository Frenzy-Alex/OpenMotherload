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
    /*
     *   ACE_UniquePointer for Single Object
     */
    template< typename T >
    ACE_UniquePointer<T>::ACE_UniquePointer() noexcept : m_pointer( nullptr )
    {
    }

    template< typename T >
    ACE_UniquePointer<T>::ACE_UniquePointer( ACE_UniquePointer <T> &&in_ref ) noexcept
    {
        m_pointer = in_ref.m_pointer;
        in_ref.m_pointer = nullptr;
    }

    template< typename T >
    ACE_UniquePointer<T>::ACE_UniquePointer( T *in_ptr ) noexcept : m_pointer( in_ptr )
    {
    }

    template< typename T >
    ACE_UniquePointer<T>::~ACE_UniquePointer()
    {
        if( m_pointer )
        {
            delete m_pointer;
        }
    }

    template< typename T >
    T *ACE_UniquePointer<T>::Release() noexcept
    {
        T *_temp = m_pointer;
        m_pointer = nullptr;
        return _temp;
    }

    template< typename T >
    void ACE_UniquePointer<T>::Reset( T *in_ptr ) noexcept
    {
        if( m_pointer )
        {
            delete m_pointer;
        }
        m_pointer = in_ptr;
    }

    template< typename T >
    void ACE_UniquePointer<T>::Swap( ACE_UniquePointer <T> &in_ref ) noexcept
    {
        T *_temp = m_pointer;
        m_pointer = in_ref.m_pointer;
        in_ref.m_pointer = _temp;
    }

    template< typename T >
    T &ACE_UniquePointer<T>::operator*() const
    {
        ACE_Assert( m_pointer != nullptr );
        return *m_pointer;
    }

    template< typename T >
    T *ACE_UniquePointer<T>::operator&() const noexcept
    {
        ACE_Assert( m_pointer != nullptr );
        return m_pointer;
    }

    template< typename T >
    T *ACE_UniquePointer<T>::operator->() const noexcept
    {
        ACE_Assert( m_pointer != nullptr );
        return m_pointer;
    }

    template< typename T >
    ACE_UniquePointer<T>::operator bool() const noexcept
    {
        return m_pointer != nullptr;
    }

    /*
     *   ACE_UniquePointer for Array
     */
    template< typename T >
    ACE_UniquePointer<T[]>::ACE_UniquePointer() noexcept : m_pointer( nullptr )
    {
    }

    template< typename T >
    ACE_UniquePointer<T[]>::ACE_UniquePointer( ACE_UniquePointer <T> &&in_ref ) noexcept
    {
        m_pointer = in_ref.m_pointer;
        in_ref.m_pointer = nullptr;
    }

    template< typename T >
    ACE_UniquePointer<T[]>::ACE_UniquePointer( T *in_ptr ) noexcept : m_pointer( in_ptr )
    {
    }

    template< typename T >
    ACE_UniquePointer<T[]>::~ACE_UniquePointer()
    {
        if( m_pointer )
        {
            delete[] m_pointer;
        }
    }

    template< typename T >
    T *ACE_UniquePointer<T[]>::Release() noexcept
    {
        T *_temp = m_pointer;
        m_pointer = nullptr;
        return _temp;
    }

    template< typename T >
    void ACE_UniquePointer<T[]>::Reset( T *in_ptr ) noexcept
    {
        if( m_pointer )
        {
            delete[] m_pointer;
        }
        m_pointer = in_ptr;
    }

    template< typename T >
    void ACE_UniquePointer<T[]>::Swap( ACE_UniquePointer <T> &in_ref ) noexcept
    {
        T *_temp = m_pointer;
        m_pointer = in_ref.m_pointer;
        in_ref.m_pointer = _temp;
    }

    template< typename T >
    T &ACE_UniquePointer<T[]>::operator*() const
    {
        ACE_Assert( m_pointer != nullptr );
        return *m_pointer;
    }

    template< typename T >
    T *ACE_UniquePointer<T[]>::operator->() const noexcept
    {
        ACE_Assert( m_pointer != nullptr );
        return m_pointer;
    }

    template< typename T >
    ACE_UniquePointer<T[]>::operator bool() const noexcept
    {
        return m_pointer != nullptr;
    }
}