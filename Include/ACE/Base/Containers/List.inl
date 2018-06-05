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
    ACE_List<T>::ACE_List( size in_size ) : m_head( nullptr ), m_tail( nullptr )
    {
        if( in_size > 0 )
        {
            m_head = new ACE_ListNode<T>();
            ACE_ListNode<T> *_temp = m_head;
            for( int i = 1; i < in_size; ++i )
            {
                _temp->m_nextNode = new ACE_ListNode<T>( _temp, nullptr );
                _temp = _temp->m_nextNode;
            }
            m_tail = _temp;
        }
    }

    template< typename T >
    ACE_List<T>::ACE_List( size in_size, const T &in_value ) : m_head( nullptr ), m_tail( nullptr )
    {
        if( in_size > 0 )
        {
            m_head = new ACE_ListNode<T>( in_value );
            ACE_ListNode<T> *_temp = m_head;
            for( int i = 1; i < in_size; ++i )
            {
                _temp->m_nextNode = new ACE_ListNode<T>( _temp, nullptr, in_value );
                _temp = _temp->m_nextNode;
            }
            m_tail = _temp;
        }
    }

    template< typename T >
    ACE_List<T>::ACE_List( const ACE_List <T> &in_list ) : m_head( nullptr ), m_tail( nullptr )
    {
        if( !in_list.IsEmpty() )
        {
            m_head = new ACE_ListNode<T>( in_list.m_head->m_data );

            ACE_ListNode<T> *_temp = in_list.m_head;
            ACE_ListNode<T> *_temp2 = m_head;

            while( _temp->m_nextNode )
            {
                _temp = _temp->m_nextNode;
                _temp2->m_nextNode = new ACE_ListNode<T>( _temp2, nullptr, _temp->m_data );
                _temp2 = _temp2->m_nextNode;

            }
            m_tail = _temp2;
        }
    }

    template< typename T >
    ACE_List<T>::ACE_List( ACE_List <T> &&in_list ) noexcept : m_head( in_list.m_head ), m_tail( in_list.m_tail )
    {
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
    size ACE_List<T>::Size() const
    {
        size _size = 0;
        ACE_ListNode<T> *_temp = m_head;
        while( _temp )
        {
            ++_size;
            _temp = _temp->m_nextNode;
        }
        return _size;
    }

    template< typename T >
    void ACE_List<T>::Resize( size in_size )
    {
        size _curSize = 0;
        ACE_ListNode<T> *_temp = m_head;
        while( _temp && _curSize < in_size )
        {
            ++_curSize;
            _temp = _temp->m_nextNode;
        }
        // Not working yet
    }

    template< typename T >
    inline T &ACE_List<T>::Front()
    {
        ACE_Assert( m_head != nullptr );
        return m_head->m_data;
    }

    template< typename T >
    inline T &ACE_List<T>::Back()
    {
        ACE_Assert( m_tail != nullptr );
        return m_tail->m_data;
    }

    template< typename T >
    void ACE_List<T>::Clear()
    {
        ACE_ListNode<T> *_temp = m_head;
        while( _temp->m_nextNode )
        {
            _temp = _temp->m_nextNode;
            delete _temp->m_prevNode;
        }
        delete _temp;
    }

    template< typename T >
    void ACE_List<T>::PopFront()
    {
        ACE_Assert( m_head != nullptr );
        ACE_ListNode<T> *_temp = m_head;
        if( m_head == m_tail )
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else
        {
            m_head = m_head->m_nextNode;
            m_head->m_prevNode = nullptr;
        }
        delete _temp;
    }

    template< typename T >
    void ACE_List<T>::PushFront( const T &in_data )
    {
        ACE_ListNode<T> *_temp = new ACE_ListNode<T>( in_data );
        if( !m_head )
        {
            m_head = _temp;
            m_tail = m_head;
        }
        else
        {
            _temp->m_nextNode = m_head;
            m_head->m_prevNode = _temp;
            m_head = _temp;
        }
    }

    template< typename T >
    void ACE_List<T>::PopBack()
    {
        ACE_Assert( m_tail != nullptr );
        ACE_ListNode<T> *_temp = m_tail;
        if( m_head == m_tail )
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else
        {
            m_tail = m_tail->m_prevNode;
            m_tail->m_nextNode = nullptr;
        }
        delete _temp;
    }

    template< typename T >
    void ACE_List<T>::PushBack( const T &in_data )
    {
        ACE_ListNode<T> *_temp = new ACE_ListNode<T>( in_data );
        if( !m_head )
        {
            m_head = _temp;
            m_tail = m_head;
        }
        else
        {
            _temp->m_prevNode = m_tail;
            m_tail->m_nextNode = _temp;
            m_tail = _temp;
        }
    }

    template< typename T >
    void ACE_List<T>::Remove( const T &in_value )
    {
        ACE_ListNode<T> *_temp = m_head;
        while( _temp )
        {
            if( _temp->m_data == in_value )
            {
                ACE_ListNode<T> *_prev = _temp->m_prevNode;
                ACE_ListNode<T> *_next = _temp->m_nextNode;

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

                delete _temp;
                break;
            }

            _temp = _temp->m_nextNode;
        }
    }

    template< typename T >
    void ACE_List<T>::RemoveAll( const T &in_value )
    {
        ACE_ListNode<T> *_temp = m_head;
        while( _temp != nullptr )
        {
            if( _temp->m_data == in_value )
            {
                ACE_ListNode<T> *_prev = _temp->m_prevNode;
                ACE_ListNode<T> *_next = _temp->m_nextNode;

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

                ACE_ListNode<T> *_delete = _temp;
                _temp = _temp->m_nextNode;
                delete _temp;
                continue;
            }

            _temp = _temp->m_nextNode;
        }
    }

    template< typename T >
    inline ACE_ListIterator <T> ACE_List<T>::Begin() const
    {
        return ACE_ListIterator<T>( m_head );
    }

    template< typename T >
    inline ACE_ListIterator <T> ACE_List<T>::End() const
    {
        return ACE_ListIterator<T>( m_tail );
    }

    template< typename T >
    ACE_ListIterator <T> ACE_List<T>::Insert( const ACE_ListIterator <T> &in_pos, const T &in_value )
    {
        ACE_ListNode<T> *_node = new ACE_ListNode<T>( in_value );
        if( in_pos.m_node )
        {

        }
        return ACE_ListIterator<T>( _node );
    }

    template< typename T >
    ACE_ListIterator <T> ACE_List<T>::Insert( const ACE_ListIterator <T> &in_pos, T &&in_value )
    {
        ACE_ListNode<T> *_node = new ACE_ListNode<T>( in_value );
        return ACE_ListIterator<T>( _node );
    }

    template< typename T >
    ACE_ListIterator <T> ACE_List<T>::Erase( const ACE_ListIterator <T> &in_pos )
    {
        if( in_pos.m_node )
        {

        }
    }

    template< typename T >
    ACE_ListIterator <T> ACE_List<T>::Erase( const ACE_ListIterator <T> &in_first, const ACE_ListIterator <T> &in_last )
    {

    }


    //
    //  List Node
    //
    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode() noexcept : m_prevNode( nullptr ), m_nextNode( nullptr ), m_data()
    {

    }

    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode( ACE_ListNode <T> *in_prevNode, ACE_ListNode <T> *in_nextNode ) noexcept :
            m_prevNode( in_prevNode ), m_nextNode( in_nextNode ), m_data()
    {

    }

    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode( const T &in_data ) noexcept : m_prevNode( nullptr ), m_nextNode( nullptr ), m_data( in_data )
    {
    }

    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode( ACE_ListNode <T> *in_prevNode, ACE_ListNode <T> *in_nextNode, const T &in_data ) noexcept :
            m_prevNode( in_prevNode ), m_nextNode( in_nextNode ), m_data( in_data )
    {
    }

    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode( T &&in_data ) noexcept : m_prevNode( nullptr ), m_nextNode( nullptr ), m_data( in_data )
    {
    }

    template< typename T >
    inline ACE_ListNode<T>::ACE_ListNode( ACE_ListNode <T> *in_prevNode, ACE_ListNode <T> *in_nextNode, T &&in_data ) noexcept :
            m_prevNode( in_prevNode ), m_nextNode( in_nextNode ), m_data( in_data )
    {
    }

    //
    //  List Iterator
    //
    template< typename T >
    ACE_ListIterator<T>::ACE_ListIterator( ACE_ListNode <T> *in_node ) noexcept : m_node( in_node )
    {
    }

    template< typename T >
    bool ACE_ListIterator<T>::IsValid() const noexcept
    {
        return m_node != nullptr;
    }

    //  Assignment operator
    template< typename T >
    ACE_ListIterator <T> &ACE_ListIterator<T>::operator=( const ACE_ListIterator <T> &in_ref ) noexcept
    {
        m_node = in_ref.m_node;
        return *this;
    }

    //  Increment, Decrement operators
    template< typename T >
    ACE_ListIterator <T> &ACE_ListIterator<T>::operator++()
    {
        ACE_Assert( m_node != nullptr );
        m_node = m_node->m_nextNode;
        return *this;
    }

    template< typename T >
    ACE_ListIterator <T> &ACE_ListIterator<T>::operator--()
    {
        ACE_Assert( m_node != nullptr );
        m_node = m_node->m_prevNode;
        return *this;
    }

    //  Comparsion operators
    template< typename T2 >
    bool operator==( const ACE_ListIterator <T2> &in_lhs, const ACE_ListIterator <T2> &in_rhs ) noexcept
    {
        return in_lhs.m_node == in_rhs.m_node;
    }

    template< typename T2 >
    bool operator!=( const ACE_ListIterator <T2> &in_lhs, const ACE_ListIterator <T2> &in_rhs ) noexcept
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