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
#include <ACE/Audio/AudioContext.h>

namespace ACE
{
    class ACE_AudioManager;
    class ACE_AudioDevice : public ACE_Object
    {
        friend class ACE_AudioManager;
        friend class ACE_AudioContext;
    public:
        ACE_AudioDevice( const char *in_objectName );
        virtual ~ACE_AudioDevice() override;

        bool Open( const char *in_deviceName = nullptr );
        bool IsOpen() const;
        bool Close();

        void AttachContext( ACE_AudioContext *in_context );
        void DetachContext( ACE_AudioContext *in_context );
    protected:
        virtual void AudioUpdate();
    private:
        ALCdevice *m_device;
        ACE_List<ACE_AudioContext *> m_contexts;
    };
}