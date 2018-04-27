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

#include <OML/Global.h>

namespace OML
{
    void OML_GlobalInitialize()
    {
    	G_RootInitializer.Reset( new ACE_RootInitializer() );

        G_Application.Reset( new OML_Application() );

        //  Audio
        G_AudioDevice.Reset( new ACE_AudioDevice( "OML_AudioDevice" ) );
        G_AudioContext.Reset( new ACE_AudioContext( "OML_AudioContext" ) );
        G_AudioListener.Reset( new ACE_AudioListener( "OML_AudioListener" ) );

        //  Graphic
        G_Window.Reset( new ACE_Window( "OML_Window" ) );
        G_GraphicContext.Reset( new ACE_GraphicContext( "OML_GraphicContext" ) );
        G_Viewport.Reset( new ACE_Viewport( "OML_Viewport" ) );
    }

    void OML_GlobalTerminate()
    {
        //  Audio
        G_AudioDevice.Reset();
        G_AudioContext.Reset();
        G_AudioListener.Reset();

        //  Graphic
        G_Window.Reset();
        G_GraphicContext.Reset();
        G_Viewport.Reset();

        G_Application.Reset();

        G_RootInitializer.Reset();
    }

    ACE_UniquePointer<ACE_RootInitializer>  G_RootInitializer;

    ACE_UniquePointer<OML_Application> G_Application;

    ACE_UniquePointer<ACE_AudioDevice> G_AudioDevice;
    ACE_UniquePointer<ACE_AudioContext> G_AudioContext;
    ACE_UniquePointer<ACE_AudioListener> G_AudioListener;

    ACE_UniquePointer<ACE_Window> G_Window;
    ACE_UniquePointer<ACE_GraphicContext> G_GraphicContext;
    ACE_UniquePointer<ACE_Viewport> G_Viewport;
}
