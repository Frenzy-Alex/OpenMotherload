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

#include <ACE/Base/Object.h>

namespace ACE
{
    class ACE_GraphicContext : public ACE_Object
    {
    public:
        ACE_GraphicContext( const char *in_objectName );
        virtual ~ACE_GraphicContext() override;
    private:
    };
}