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

namespace ACE
{
    class ACE_FunctionBase
    {
    public:
        ACE_FunctionBase();
        virtual ~ACE_FunctionBase();

        virtual void Invoke();
    };

    class ACE_Thread final
    {
    public:
        ACE_Thread() noexcept;
        ACE_Thread( const ACE_Thread & ) = delete;
        ACE_Thread( ACE_Thread &&in_thread ) noexcept;

        template< class Func, class ...Args >
        explicit ACE_Thread( Func &&in_func, Args &&... in_args );

        ~ACE_Thread();

        void Create();

        void Join();
        void Detach();

        void Kill();

        ACE_Thread &operator=( ACE_Thread &&in_thread ) noexcept;
    private:
        static void *StartRoutine( void *in_function );

        pthread_t m_thread;
        ACE_FunctionBase *m_function;
    };

    class ACE_Function final : public ACE_FunctionBase
    {
    public:
        ACE_Function() noexcept;
        ACE_Function( const ACE_Function& in_func );
        ACE_Function( ACE_Function && in_func );

        virtual ~ACE_Function() override final;
    private:
    };
}
