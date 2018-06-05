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

#include <ACE/Base/Misc/Types.h>

namespace ACE
{
    class ACE_ArgumentParser
    {
    public:
        ACE_ArgumentParser( int in_argCount, char **in_args );
        virtual ~ACE_ArgumentParser();

        bool ParseArguments();
    protected:
        virtual bool ParseArgument(u8 &in_argId, const char *in_arg);

        virtual void PrintHelp();

        const int m_argCount;
        char** const m_args;
    private:
    };
}
