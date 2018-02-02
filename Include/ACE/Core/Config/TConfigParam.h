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

#include <ACE/Core/Config/IConfigParam.h>

namespace ACE
{
    template< typename T >
    class ACE_TConfigParam final : public ACE_IConfigParam
    {
    public:
        ACE_TConfigParam( const char *in_paramName, const T &in_defaultValue );
        virtual ~ACE_TConfigParam() final = default;

        T GetValue() const;
        const T &GetDefaultValue() const;

        void SetValue( const T &in_value );

        void Reset();
    protected:
        virtual ACE_String ValueToStr() const override final;
        virtual bool StrToValue( const ACE_String &in_str ) override final;
    private:
        const T m_defaultValue;
        T m_value;
    };

    typedef ACE_TConfigParam<bool> ACE_ConfigParamBool;
    typedef ACE_TConfigParam<int> ACE_ConfigParamInt;
    typedef ACE_TConfigParam<uint> ACE_ConfigParamUint;
}

#include <ACE/Core/Config/TConfigParam.inl>