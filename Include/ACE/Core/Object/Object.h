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
#include <ACE/Base/Misc/Types.h>

namespace ACE
{
    class ACE_Object
    {
    public:
        const uint GetObjectID() const;
        const char *GetObjectName() const;
    protected:
        explicit ACE_Object( const char *in_objectName );
        virtual ~ACE_Object();
    private:
        static uint sm_latestObjectId;

        const uint m_objectId;
        const char *m_objectName;
    };
}