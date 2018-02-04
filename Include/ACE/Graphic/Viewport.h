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
    class ACE_GraphicContext;
    class ACE_Viewport : public ACE_Object
    {
        friend class ACE_GraphicContext;
    public:
        ACE_Viewport( const char *in_objectName );
        virtual ~ACE_Viewport();

        ACE_GraphicContext *GetGraphicContext() const;
    protected:
        virtual void GraphicUpdate();
    private:
        ACE_GraphicContext *m_graphicContext;
    };
}