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

namespace ACE
{
    class ACE_AudioListener;
    class ACE_Camera;

    class ACE_Scene : public ACE_Object
    {
        friend class ACE_AudioListener;
        friend class ACE_Camera;
    public:
        ACE_Scene( const char *in_objectName );
        virtual ~ACE_Scene();

        ACE_AudioListener *GetAudioListener() const;
        ACE_Camera *GetCamera() const;

        void SetAudioListener( ACE_AudioListener *in_audioListener );
        void SetCamera( ACE_Camera *in_camera );

    protected:
        virtual void AudioUpdate();
        virtual void GameUpdate();
        virtual void GraphicUpdate();
        virtual void NetworkUpdate();
        virtual void PhysicUpdate();
        virtual void ScriptUpdate();
    private:
        ACE_AudioListener *m_audioListener;
        ACE_Camera *m_camera;
    };
}