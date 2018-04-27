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

#include <ACE/Base/Singleton.h>
#include <ACE/Base/Containers/List.h>
#include <ACE/Core/Object/Object.h>
#include <ACE/RootInitializer.h>

namespace ACE
{
    class ACE_ObjectManager final : public ACE_Singleton<ACE_ObjectManager>
    {
        ACE_ObjectManager();
        virtual ~ACE_ObjectManager() override final;
        friend class ACE_RootInitializer;
        friend class ACE_Object;
    public:
        ACE_Object *Find( uint in_id );
        ACE_Object *Find( const char *in_name );
    protected:
        void RegisterObject( const ACE_Object *in_object );
        void UnregisterObject( const ACE_Object *in_object );
    private:
        ACE_List<const ACE_Object *> m_objects;
        //  Map of objects
    };

    #define ACE_ObjectManagerS      ACE::ACE_ObjectManager::GetInstance()
}