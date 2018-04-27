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

#include <ACE/Core/Object/Object.h>
#include <ACE/Game/Scene.h>

namespace ACE
{
    class ACE_Viewport;
    class ACE_Camera : public ACE_Object
    {
        friend class ACE_Viewport;
        friend class ACE_Scene;
    public:
        ACE_Camera( const char *in_objectName );
        virtual ~ACE_Camera() override;

        ACE_Viewport *GetViewport() const;

        ACE_Scene *GetScene() const;
    protected:
        virtual void GraphicUpdate();
    private:
        ACE_Viewport *m_viewport;

        ACE_Scene *m_scene;
    };
}