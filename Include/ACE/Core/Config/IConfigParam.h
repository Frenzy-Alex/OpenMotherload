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

#include <ACE/Base/Containers/String.h>

namespace ACE
{
    class ACE_ConfigManager;

    class ACE_IConfigParam
    {
        friend class ACE_ConfigManager;
    public:
        const char *GetParamName() const;
    protected:
        ACE_IConfigParam( const char *in_paramName );
        virtual ~ACE_IConfigParam();

        virtual ACE_String ValueToStr() const = 0;
        virtual bool StrToValue( const ACE_String &in_str ) = 0;
    private:
        const char *m_paramName;
    };
}