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
#include <ACE/Graphic/Viewport.h>

namespace ACE
{
    class ACE_Window : public ACE_Object
    {
    public:
        explicit ACE_Window( const char *in_objectName );
        virtual ~ACE_Window();

        void Create();
        void Destroy();

        void AddViewport( ACE_Viewport *in_viewport );
        void RemoveViewport( ACE_Viewport *in_viewport );
    protected:
        virtual void GraphicUpdate();
    private:
        ACE_List<ACE_Viewport *> m_viewports;
    };
}