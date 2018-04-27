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
    enum class ACE_EventType
    {
        ET_Audio,
        ET_Core,
        ET_Game,
        ET_Graphic,
        ET_Keyboard,
        ET_Network,
        ET_Pointer,
        ET_Physic,
        ET_Resource,
        ET_Script,
        ET_Window
    };

    #define ACE_ET_Keyboard     ACE::ACE_EventType::ET_Keyboard
    #define ACE_ET_Pointer      ACE::ACE_EventType::ET_Pointer
    #define ACE_ET_Window       ACE::ACE_EventType::ET_Window
}