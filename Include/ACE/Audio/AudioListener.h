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

namespace ACE
{
    struct ACE_Orientation
    {
        ACE_Orientation()
        {
        }

        ACE_Orientation( const ACE_Vector3f &in_at, const ACE_Vector3f &in_up ) : at( in_at ), up( in_up )
        {
        }

        float *Data() const
        {
            return (float *)this;
        }

        ACE_Orientation &operator=( const ACE_Orientation &in_orientation )
        {
            at = in_orientation.at;
            up = in_orientation.up;
            return *this;
        }

        ACE_Vector3f at;
        ACE_Vector3f up;
    };

    class ACE_AudioListener : public ACE_Object
    {
    public:
        explicit ACE_AudioListener( const char *in_objectName );
        virtual ~ACE_AudioListener() override;

        virtual void AudioUpdate();

        float GetGain() const;
        const ACE_Orientation &GetOrientation() const;
        const ACE_Vector3f &GetPosition() const;
        const ACE_Vector3f &GetVelocity() const;

        void SetGain( float in_gain );
        void SetOrientation( const ACE_Orientation &in_orientation );
        void SetPosition( const ACE_Vector3f &in_position );
        void SetVelocity( const ACE_Vector3f &in_velocity );
    private:
        float m_gain;
        ACE_Orientation m_orientation;
        ACE_Vector3f m_position;
        ACE_Vector3f m_velocity;
    };
}