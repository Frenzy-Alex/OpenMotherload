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
    class ACE_AudioListener;
    class ACE_Camera;

    class ACE_Scene : public ACE_Object
    {
    public:
        ACE_Scene( const char *in_objectName );
        virtual ~ACE_Scene();

        virtual void AudioUpdate();
        virtual void GameUpdate();
        virtual void GraphicUpdate();
        virtual void NetworkUpdate();
        virtual void PhysicUpdate();
        virtual void ScriptUpdate();

        ACE_AudioListener *GetAudioListener() const;
        ACE_Camera *GetCamera() const;

        void SetAudioListener( ACE_AudioListener *in_audioListener );
        void SetCamera( ACE_Camera *in_camera );
    private:
        ACE_AudioListener *m_audioListener;
        ACE_Camera *m_camera;
    };
}