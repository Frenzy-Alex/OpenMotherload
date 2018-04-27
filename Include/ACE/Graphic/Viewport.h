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
#include <ACE/Base/Containers/List.h>
#include <ACE/Graphic/Camera.h>
#include <ACE/Math/Vector.h>

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

        const ACE_Vector2i &GetPosition() const;
        const ACE_Vector2i &GetSize() const;

        void SetPosition( const ACE_Vector2i &in_position );
        void SetSize( const ACE_Vector2i &in_size );

        void AttachCamera( ACE_Camera *in_camera );
        void DetachCamera( ACE_Camera *in_camera );
    protected:
        virtual void GraphicUpdate();
    private:
        ACE_GraphicContext *m_graphicContext;

        ACE_Vector2i m_position;
        ACE_Vector2i m_size;

        ACE_List<ACE_Camera *> m_cameras;
    };
}