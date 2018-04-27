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
    class ACE_Queue;

    template< typename T >
    class ACE_QueueNode;

    template< typename T >
    class ACE_Queue final
    {
    public:
        ACE_Queue();
        ACE_Queue( const ACE_Queue<T> &in_ref );
        ACE_Queue( ACE_Queue<T> &&in_ref );
        ~ACE_Queue();

        bool IsEmpty() const noexcept;
        size Size() const noexcept;

        T &Front();
        T &Back();

        void Pop();

        void Push( const T &in_value );
        void Push( T &&in_value );
    private:
        ACE_QueueNode<T> *m_head;
        ACE_QueueNode<T> *m_tail;
    };

    template< typename T >
    class ACE_QueueNode final
    {
        friend class ACE_Queue<T>;
    public:
    protected:
        ACE_QueueNode( ACE_QueueNode<T> *in_nextNode, const T &in_data );
        ~ACE_QueueNode();
    private:
        ACE_QueueNode<T> *m_nextNode;
        T m_data;
    };
}

#include <ACE/Base/Containers/Queue.inl>