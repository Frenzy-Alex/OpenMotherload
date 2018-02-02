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
    //  ACE_List
    //
    template< typename T >
    inline ACE_List<T>::ACE_List() noexcept : m_head( nullptr ), m_tail( nullptr )
    {
    }

    template< typename T >
    ACE_List<T>::ACE_List( size in_size )
    {
        ACE_Assert( in_size > 0 );

        ACE_ListNode<T> *_listNodeArr[in_size];

        for( int i = 0; i < in_size; ++i )
        {
            _listNodeArr[i] = new ACE_ListNode<T>();
        }

        for( int i = 1; i < in_size - 1; ++i )
        {
            _listNodeArr[i]->m_prevNode = _listNodeArr[i - 1];
            _listNodeArr[i]->m_nextNode = _listNodeArr[i + 1];
        }

        m_head = _listNodeArr[0];
        m_tail = _listNodeArr[in_size - 1];
    }

    template< typename T >
    ACE_List<T>::ACE_List( size in_size, const T &in_value )
    {
        ACE_Assert( in_size > 0 );

        ACE_ListNode<T> *_listNodeArr[in_size];

        for( int i = 0; i < in_size; ++i )
        {
            _listNodeArr[i] = new ACE_ListNode<T>( in_value );
        }

        for( int i = 1; i < in_size - 1; ++i )
        {
            _listNodeArr[i]->m_prevNode = _listNodeArr[i - 1];
            _listNodeArr[i]->m_nextNode = _listNodeArr[i + 1];
        }

        m_head = _listNodeArr[0];
        m_tail = _listNodeArr[in_size - 1];
    }

    template< typename T >
    ACE_List<T>::ACE_List( const ACE_List<T> &in_list )
    {
        if( !in_list.IsEmpty() )
        {
            m_head = new ACE_ListNode<T>( in_list.m_head->m_data );
            if( in_list.m_head == in_list.m_tail )
            {
                m_tail = m_head;
            }
            else
            {
                ACE_ListNode<T> *_temp = in_list.m_head;
                while( _temp )
                {

                    _temp = _temp->m_nextNode;
                }
            }
        }
        else
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
    }

    template< typename T >
    ACE_List<T>::ACE_List( ACE_List<T> &&in_list ) noexcept
    {
        m_head = in_list.m_head;
        m_tail = in_list.m_tail;
        in_list.m_head = nullptr;
        in_list.m_tail = nullptr;
    }

    template< typename T >
    ACE_List<T>::~ACE_List()
    {
        Clear();
    }

    template< typename T >
    inline bool ACE_List<T>::IsEmpty() const noexcept
    {
        return m_head == nullptr;
    }

    template< typename T >
    uint ACE_List<T>::Size() const
    {
        uint _size = 0;
        ACE_ListNode<T> *_temp = m_head;
        while( _temp != nullptr )
        {
            ++_size;
            _temp = _temp->m_nextNode;
        }
        return _size;
    }

    template< typename T >
    inline T &ACE_List<T>::Front()
    {
        ACE_Assert( m_head != nullptr );
        return m_head->m_data();
    }

    template< typename T >
    inline T &ACE_List<T>::Back()
    {
        ACE_Assert( m_tail != nullptr );
        return m_tail->m_data();
    }

    template< typename T >
    void ACE_List<T>::Clear()
    {
        ACE_ListNode<T> *_temp = m_head;
        ACE_ListNode<T> *_temp2;
        while( _temp != nullptr )
        {
            _temp2 = _temp->m_nextNode;
            delete _temp;
            _temp = _temp2;
        }
    }

    template< typename T >
    void ACE_List<T>::PopFront()
    {
        ACE_Assert( m_head != nullptr );
        if( m_head == m_tail )
        {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
        }
        else
        {
            m_head = m_head->m_nextNode;
            delete m_head->m_prevNode;
            m_head->m_prevNode = nullptr;
        }
    }

    template< typename T >
    void ACE_List<T>::PushFront( const T &in_data )
    {
        ACE_ListNode<T> *_tmp = new ACE_ListNode<T>( in_data );
        if( !m_head )
        {
            m_head = _tmp;
            m_tail = m_head;
        }
        else
        {
            _tmp->m_nextNode = m_head;
            m_head->m_prevNode = _tmp;
            m_head = _tmp;
        }
    }

    template< typename T >
    void ACE_List<T>::PopBack()
    {
        ACE_Assert( m_head != nullptr );
        if( m_head )
        {
            if( m_head == m_tail )
            {
                delete m_head;
                m_head = nullptr;
                m_tail = nullptr;
            }
            else
            {
                m_tail = m_tail->m_prevNode;
                delete m_tail->m_nextNode;
                m_tail->m_nextNode = nullptr;
            }
        }
    }

    template< typename T >
    void ACE_List<T>::PushBack( const T &in_data )
    {
        ACE_ListNode<T> *_tmp = new ACE_ListNode<T>( in_data );
        if( !m_head )
        {
            m_head = _tmp;
            m_tail = m_head;
        }
        else
        {
            _tmp->m_prevNode = m_tail;
            m_tail->m_nextNode = _tmp;
            m_tail = _tmp;
        }
    }

    template< typename T >
    void ACE_List<T>::Remove( const T &in_value )
    {
        ACE_ListNode<T> *_tmp = m_head;
        while( _tmp != nullptr )
        {
            if( _tmp->m_data == in_value )
            {
                ACE_ListNode<T> *_prev = _tmp->m_prevNode;
                ACE_ListNode<T> *_next = _tmp->m_nextNode;

                if( !_prev && !_next )
                {
                    m_head = nullptr;
                    m_tail = nullptr;
                }
                else if( !_prev )
                {
                    m_head = m_head->m_nextNode;
                    m_head->m_prevNode = nullptr;
                }
                else if( !_next )
                {
                    m_tail = m_tail->m_prevNode;
                    m_tail->m_nextNode = nullptr;
                }
                else
                {
                    _prev->m_nextNode = _next;
                    _next->m_prevNode = _prev;
                }

                delete _tmp;

                break;
            }

            _tmp = _tmp->m_nextNode;
        }
    }

    template< typename T >
    void ACE_List<T>::RemoveAll( const T &in_value )
    {

    }

    template< typename T >
    inline ACE_ListIterator<T> ACE_List<T>::Begin() const
    {
        return ACE_ListIterator<T>( m_head );
    }

    template< typename T >
    inline ACE_ListIterator<T> ACE_List<T>::End() const
    {
        return ACE_ListIterator<T>( m_tail );
    }

    template< typename T >
    ACE_ListIterator<T> ACE_List<T>::Insert( const ACE_ListIterator<T> &in_pos, const T &in_value )
    {
        ACE_ListNode<T> *_node = new ACE_ListNode<T>( in_value );
        if( in_pos.m_node )
        {

        }
    }

    template< typename T >
    ACE_ListIterator<T> ACE_List<T>::Insert( const ACE_ListIterator<T> &in_pos, T &&in_value )
    {
        ACE_ListNode<T> *_node = new ACE_ListNode<T>( in_value );
    }

    template< typename T >
    ACE_ListIterator<T> ACE_List<T>::Erase( const ACE_ListIterator<T> &in_pos )
    {
        if( in_pos.m_node )
        {

        }
    }

    template< typename T >
    ACE_ListIterator<T> ACE_List<T>::Erase( const ACE_ListIterator<T> &in_first, const ACE_ListIterator<T> &in_last )
    {

    }


    //
    //  List Node
    //
    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode( const T &in_data ) noexcept : m_prevNode( nullptr ), m_nextNode( nullptr ), m_data( in_data )
    {
    }

    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode( T &&in_data ) noexcept : m_prevNode( nullptr ), m_nextNode( nullptr ), m_data( in_data )
    {
    }

    //
    //  List Iterator
    //
    template< typename T >
    ACE_ListIterator<T>::ACE_ListIterator( ACE_ListNode<T> *in_node ) noexcept : m_node( in_node )
    {
    }

    template< typename T >
    bool ACE_ListIterator<T>::IsValid() const noexcept
    {
        return m_node != nullptr;
    }

    //  Assignment operator
    template< typename T >
    ACE_ListIterator<T> &ACE_ListIterator<T>::operator=( const ACE_ListIterator<T> &in_ref ) noexcept
    {
        m_node = in_ref.m_node;
        return *this;
    }

    //  Increment, Decrement operators
    template< typename T >
    ACE_ListIterator<T> &ACE_ListIterator<T>::operator++()
    {
        ACE_Assert( m_node != nullptr );
        m_node = m_node->m_nextNode;
        return *this;
    }

    template< typename T >
    ACE_ListIterator<T> &ACE_ListIterator<T>::operator--()
    {
        ACE_Assert( m_node != nullptr );
        m_node = m_node->m_prevNode;
        return *this;
    }

    //  Comparsion operators
    template< typename T2 >
    bool operator==( const ACE_ListIterator<T2> &in_lhs, const ACE_ListIterator<T2> &in_rhs ) noexcept
    {
        return in_lhs.m_node == in_rhs.m_node;
    }

    template< typename T2 >
    bool operator!=( const ACE_ListIterator<T2> &in_lhs, const ACE_ListIterator<T2> &in_rhs ) noexcept
    {
        return in_lhs.m_node != in_rhs.m_node;
    }

    //  Member access operator
    template< typename T >
    T &ACE_ListIterator<T>::operator*() const
    {
        ACE_Assert( m_node != nullptr );
        return m_node->m_data;
    }

    template< typename T >
    T *ACE_ListIterator<T>::operator->() const noexcept
    {
        ACE_Assert( m_node != nullptr );
        return m_node;
    }

    template< typename T >
    ACE_ListIterator<T>::operator bool() const noexcept
    {
        return m_node != nullptr;
    }
}