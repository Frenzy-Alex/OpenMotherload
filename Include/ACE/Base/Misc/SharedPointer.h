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
    /*
     *   ACE_SharedPointer for Single Object
     */
    template< typename T >
    class ACE_SharedPointer final
    {
    public:
        ACE_SharedPointer() noexcept;
        explicit ACE_SharedPointer( const ACE_SharedPointer<T> & ) = delete;
        explicit ACE_SharedPointer( ACE_SharedPointer<T> &&in_ref ) noexcept;
        explicit ACE_SharedPointer( T *in_ptr ) noexcept;
        ~ACE_SharedPointer();

        T *Release() noexcept;
        void Reset( T *in_ptr = nullptr ) noexcept;
        void Swap( ACE_SharedPointer<T> &in_ref ) noexcept;

        //  Member access operator
        T &operator*() const;
        T *operator&() const noexcept;
        T *operator->() const noexcept;

        //
        explicit operator bool() const noexcept;
    private:
        uint32 *m_counter;
        T *m_pointer;
    };
}

#include <ACE/Base/Misc/SharedPointer.inl>