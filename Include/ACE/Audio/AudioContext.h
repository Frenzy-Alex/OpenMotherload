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

#include <ACE/PrecompiledHeader.h>
#include <ACE/Base/Object.h>
#include <ACE/Base/Containers/List.h>
#include <ACE/Audio/AudioListener.h>

namespace ACE
{
    class ACE_AudioDevice;
    class ACE_AudioContext : public ACE_Object
    {
        friend class ACE_AudioDevice;
    public:
        ACE_AudioContext( const char *in_objectName );
        virtual ~ACE_AudioContext() override;

        virtual void AudioUpdate();

        ACE_AudioDevice *GetDevice() const;

        bool Create();
        bool MakeCurrent();
        void Destroy();

        void AttachListener( ACE_AudioListener *in_listener );
        void DetachListener( ACE_AudioListener *in_listener );
    private:
        ACE_AudioDevice *m_device;
        ALCcontext *m_context;

        ACE_List<ACE_AudioListener *> m_listeners;
    };
}