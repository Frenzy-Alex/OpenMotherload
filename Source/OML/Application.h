/********************************************************************************
 *                                                                              *
 *          Copyright (C) 2018 Oleksandr Lynok. All Rights Reserved.            *
 *                                                                              *
 *                  This file is part of OpenMotherload.               			*
 *                                                                              *
 *      OpenMotherload is licensed under GNU Lesser General Public     			*
 *  License (LGPL), version 3.  See file "LICENSE.txt".                         *
 *                                                                              *
 ********************************************************************************/

#pragma once

#include <ACE/ACE.h>

namespace OML
{
    class OML_Application final : public ACE::ACE_Application
    {
    public:
        OML_Application();
        virtual ~OML_Application() override final;
    protected:
        virtual void Initialize() override final;
        virtual void Update() override final;
        virtual void Terminate() override final;
    };
}
