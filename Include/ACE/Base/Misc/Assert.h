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

#include <ACE/SettingsBase.h>

namespace ACE
{
    [[noreturn]] void ACE_AssertPrint( const char *in_fileName, int in_line, const char *in_functionName, const char *in_condition );

    #if ACE_Setting_Debug == 0
    #   define ACE_Assert( expr )       ((void)0)
    #else
    #   define ACE_Assert( expr )       (( expr ) ? ((void)0) : ACE::ACE_AssertPrint( __FILE__, __LINE__, __func__, #expr ))
    #endif
}