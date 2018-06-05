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

#include <ACE/Base/Containers/List.h>
#include <ACE/Core/Object/Object.h>
#include <ACE/Graphic/GraphicContext.h>
#include <ACE/Math/Vector.h>

namespace ACE
{
    class ACE_WindowManager;
    class ACE_Window : public ACE_Object
    {
        friend class ACE_WindowManager;
    public:
        explicit ACE_Window( const char *in_objectName );
        virtual ~ACE_Window();

        bool Create();
        bool IsCreated() const;
        void Destroy();

        const ACE_Vector2i &GetPosition() const;
        const ACE_Vector2ui &GetSize() const;

        void SetIcon();
        void SetPosition( const ACE_Vector2i &in_position );
        void SetSize( const ACE_Vector2ui &in_size );
        void SetTitle( const char *in_title );

        void AttachContext( ACE_GraphicContext *in_context );
        void DetachContext( ACE_GraphicContext *in_context );
    protected:
        virtual void GraphicUpdate();
    private:
        #if ACE_Platform == ACE_Platform_Linux

        XVisualInfo *m_visualInfo;
        Colormap m_colorMap;
        Window m_window;

        #endif

        //icon
        ACE_Vector2i m_position;
        ACE_Vector2ui m_size;
        //title

        ACE_List<ACE_GraphicContext *> m_graphicContexts;
    };
}