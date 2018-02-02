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
#include <ACE/Math/Vector3.h>
#include <ACE/Audio/AudioSourceState.h>

namespace ACE
{
    class ACE_AudioSource : public ACE_Object
    {
    public:
        explicit ACE_AudioSource( const char *in_objectName );
        virtual ~ACE_AudioSource() override;

        virtual void AudioUpdate();

        virtual void Create();
        virtual void Destroy();

        void Pause();
        void Play();
        void Stop();

        float GetGain() const;
        float GetPitch() const;
        const ACE_Vector3f &GetPosition() const;
        const ACE_Vector3f &GetVelocity() const;

        ACE_AudioSourceState GetState() const;

        void SetBuffer( ALuint in_buffer );
        void SetGain( float in_gain );
        void SetPitch( float in_pitch );
        void SetPosition( const ACE_Vector3f &in_position );
        void SetVelocity( const ACE_Vector3f &in_velocity );
    private:
        ALuint m_source;
        float m_gain;
        float m_pitch;
        ACE_Vector3f m_position;
        ACE_Vector3f m_velocity;
        ACE_AudioSourceState m_state;
    };
}