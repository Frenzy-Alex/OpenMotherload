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

#include <ACE/Event/EventType.h>

namespace ACE
{
    class ACE_Event
    {
    public:
        ACE_EventType GetEventType() const;
    protected:
        ACE_Event( ACE_EventType in_eventType );
        virtual ~ACE_Event();
    private:
        ACE_EventType m_eventType;
    };
}