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

#include <ACE/Base/Containers/String.h>

namespace ACE
{
    enum class ACE_AudioSourceState
    {
        ASS_Initial,
        ASS_Playing,
        ASS_Paused,
        ASS_Stopped,
        __ASS_Last
    };

    template<>
    const char *ACE_ToCString( ACE_AudioSourceState in_audioSourceState );

    #define ACE_ASS_Initial     ACE::ACE_AudioSourceState::ASS_Initial
    #define ACE_ASS_Playing     ACE::ACE_AudioSourceState::ASS_Playing
    #define ACE_ASS_Paused      ACE::ACE_AudioSourceState::ASS_Paused
    #define ACE_ASS_Stopped     ACE::ACE_AudioSourceState::ASS_Stopped
    #define __ACE_ASS_Last      ACE::ACE_AudioSourceState::__ASS_Last
}