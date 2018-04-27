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
#include <ACE/Base/Singleton.h>

namespace ACE
{
    class ACE_CoreManager final : public ACE_Object, public ACE_Singleton<ACE_CoreManager>
    {
        ACE_CoreManager();
        virtual ~ACE_CoreManager() override final;
        friend class ACE_RootInitializer;
    public:
    protected:
    private:
    };

    #define ACE_CoreManagerS      ACE::ACE_CoreManager::GetInstance()
}