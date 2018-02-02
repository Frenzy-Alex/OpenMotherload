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
    /*
     *   ACE_UniquePointer for Single Object
     */
    template< typename T >
    class ACE_UniquePointer final
    {
    public:
        ACE_UniquePointer() noexcept;
        explicit ACE_UniquePointer( const ACE_UniquePointer<T> & ) = delete;
        explicit ACE_UniquePointer( ACE_UniquePointer<T> &&in_ref ) noexcept;
        explicit ACE_UniquePointer( T *in_ptr ) noexcept;
        ~ACE_UniquePointer();

        T *Release() noexcept;
        void Reset( T *in_ptr ) noexcept;
        void Swap( ACE_UniquePointer<T> &in_ref ) noexcept;

        //  Member access operator
        T &operator*() const;
        T *operator&() const noexcept;
        T *operator->() const noexcept;

        //
        explicit operator bool() const noexcept;
    private:
        T *m_pointer;
    };

    /*
     *   ACE_UniquePointer for Array
     */
    template< typename T >
    class ACE_UniquePointer<T[]> final
    {
    public:
        ACE_UniquePointer() noexcept;
        explicit ACE_UniquePointer( const ACE_UniquePointer<T> & ) = delete;
        explicit ACE_UniquePointer( ACE_UniquePointer<T> &&in_ref ) noexcept;
        explicit ACE_UniquePointer( T *in_ptr = nullptr ) noexcept;
        ~ACE_UniquePointer();

        T *Release() noexcept;
        void Reset( T *in_ptr ) noexcept;
        void Swap( ACE_UniquePointer<T> &in_ref ) noexcept;

        //  Member access operator
        T &operator*() const;
        T *operator->() const noexcept;

        //
        explicit operator bool() const noexcept;
    private:
        T *m_pointer;
    };
}

#include <ACE/Base/Misc/UniquePointer.inl>