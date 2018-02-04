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

#include <ACE/Base/Containers/List.h>
#include <ACE/Base/Object.h>
#include <ACE/Graphic/GraphicContext.h>

namespace ACE
{
    class ACE_Window : public ACE_Object
    {
    public:
        explicit ACE_Window( const char *in_objectName );
        virtual ~ACE_Window();

        bool Create();
        void Destroy();

        void SetIcon();
        void SetPosition();
        void SetSize();
        void SetTitle( const char *in_title );

        void AttachContext( ACE_GraphicContext *in_context );
        void DetachContext( ACE_GraphicContext *in_context );
    protected:
        virtual void GraphicUpdate();
    private:
        ACE_List<ACE_GraphicContext *> m_graphicContexts;
    };
}