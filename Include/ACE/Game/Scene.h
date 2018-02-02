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
#include <ACE/Audio/AudioListener.h>

namespace ACE
{
    class ACE_Scene : public ACE_Object
    {
    public:
        ACE_Scene( const char *in_objectName );
        virtual ~ACE_Scene();

        ACE_AudioListener *GetAudioListener() const;

        void SetAudioListener( ACE_AudioListener *in_audioListener );
    private:
        ACE_AudioListener *m_audioListener;
    };
}