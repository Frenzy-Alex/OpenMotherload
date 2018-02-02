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

#include <ACE/Base/Misc/Types.h>

namespace ACE
{
    template< typename T >
    class ACE_List;

    template< typename T >
    class ACE_ListNode;

    template< typename T >
    class ACE_ListIterator;

    template< typename T >
    class ACE_List final
    {
    public:
        /**
         * @brief Default constructor
         */
        ACE_List() noexcept;

        /**
         * @brief Fill constructor
         * @param in_size
         */
        ACE_List( size in_size );
        ACE_List( size in_size, const T &in_value );

        /**
         * @brief Copy constructor
         */
        ACE_List( const ACE_List<T> &in_list );

        /**
         * @brief Move constructor
         */
        ACE_List( ACE_List<T> &&in_list ) noexcept;

        /**
         * @brief Destructor
         */
        ~ACE_List();

        bool IsEmpty() const noexcept;
        uint Size() const;
        void Resize( uint in_size );

        T &Front();
        T &Back();

        void Clear();

        void PopFront();
        void PushFront( const T &in_data );

        void PopBack();
        void PushBack( const T &in_data );

        void Remove( const T &in_value );
        void RemoveAll( const T &in_value );

        void Reverse();

        void Sort();

        void Unique();

        ACE_ListIterator<T> Begin() const;
        ACE_ListIterator<T> End() const;

        ACE_ListIterator<T> Insert( const ACE_ListIterator<T> &in_pos, const T &in_value );
        ACE_ListIterator<T> Insert( const ACE_ListIterator<T> &in_pos, T &&in_value );

        ACE_ListIterator<T> Erase( const ACE_ListIterator<T> &in_pos );
        ACE_ListIterator<T> Erase( const ACE_ListIterator<T> &in_first, const ACE_ListIterator<T> &in_last );

        ACE_List &operator=( const ACE_List &in_list );
        ACE_List &operator=( ACE_List &&in_list );
    private:
        ACE_ListNode<T> *m_head;
        ACE_ListNode<T> *m_tail;
    };

    template< typename T >
    class ACE_ListNode final
    {
        friend class ACE_List<T>;
        friend class ACE_ListIterator<T>;
    protected:
        explicit ACE_ListNode( const T &in_data ) noexcept;
        explicit ACE_ListNode( T &&in_data ) noexcept;
        ~ACE_ListNode() = default;
    private:
        ACE_ListNode<T> *m_prevNode;
        ACE_ListNode<T> *m_nextNode;
        T m_data;
    };

    template< typename T >
    class ACE_ListIterator final
    {
        friend class ACE_List<T>;
    public:
        ~ACE_ListIterator() = default;

        bool IsValid() const noexcept;

        //  Assignment operator
        ACE_ListIterator<T> &operator=( const ACE_ListIterator<T> &in_ref ) noexcept;

        //  Increment, Decrement operators
        ACE_ListIterator<T> &operator++();
        ACE_ListIterator<T> &operator--();

        //  Comparsion operators
        template< typename T2 >
        friend bool operator==( const ACE_ListIterator<T2> &in_lhs, const ACE_ListIterator<T2> &in_rhs ) noexcept;
        template< typename T2 >
        friend bool operator!=( const ACE_ListIterator<T2> &in_lhs, const ACE_ListIterator<T2> &in_rhs ) noexcept;

        //  Member access operator
        T &operator*() const;
        T *operator->() const noexcept;

        explicit operator bool() const noexcept;
    protected:
        explicit ACE_ListIterator( ACE_ListNode<T> *in_node ) noexcept;
    private:
        ACE_ListNode<T> *m_node;
    };
}

#include <ACE/Base/Containers/List.inl>
