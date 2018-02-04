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
#include <ACE/Base/Containers/List.h>
#include <ACE/Graphic/Viewport.h>

namespace ACE
{
    enum class ACE_GraphicContextFlags
    {
        GCF_No,
        GCF_Debug,
        GCF_ForwardCompatible
    };

    enum class ACE_GraphicContextProfile
    {
        GCP_CoreProfile,
        GCP_CompatibilityProfile
    };

    #define ACE_GCP_CoreProfile             ACE::ACE_GraphicContextProfile::GCP_CoreProfile
    #define ACE_GCP_CompatibilityProfile    ACE::ACE_GraphicContextProfile::GCP_CompatibilityProfile

    class ACE_Window;
    class ACE_GraphicContext : public ACE_Object
    {
        friend class ACE_Window;
    public:
        ACE_GraphicContext( const char *in_objectName );
        virtual ~ACE_GraphicContext() override;

        ACE_Window *GetWindow() const;

        bool Create();
        bool IsCreated() const;
        bool MakeCurrent();
        void Destroy();

        void AddViewport( ACE_Viewport *in_viewport );
        void RemoveViewport( ACE_Viewport *in_viewport );
    protected:
        virtual void GraphicUpdate();
    private:
        ACE_Window *m_window;

        int m_majorVer;
        int m_minorVer;
        ACE_GraphicContextFlags m_flags;
        ACE_GraphicContextProfile m_profile;

        ACE_List<ACE_Viewport *> m_viewports;
    };
}