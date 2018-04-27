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

#include <OML/Application.h>

#include <OML/Global.h>

namespace OML
{
    OML_Application::OML_Application() : ACE_Application( "OML_Application" )
    {
    }

    OML_Application::~OML_Application()
    {
    }

    void OML_Application::Initialize()
    {
        ACE_Application_Initialize();

        //  Audio
        ACE_ReturnIf( !G_AudioDevice->Open( nullptr ), ACE_Initializable_Errored() );
        G_AudioDevice->AttachContext( &G_AudioContext );

        ACE_ReturnIf( !G_AudioContext->Create(), ACE_Initializable_Errored() );
        G_AudioContext->AttachListener( &G_AudioListener );

        //  Graphic
        ACE_ReturnIf( !G_Window->Create(), ACE_Initializable_Errored() );
        G_Window->SetTitle("OpenMotherload");
        G_Window->AttachContext( &G_GraphicContext );

        ACE_ReturnIf( !G_GraphicContext->Create(), ACE_Initializable_Errored() );
        ACE_ReturnIf( !G_GraphicContext->MakeCurrent(), ACE_Initializable_Errored() );

        //  Game
    }

    void OML_Application::Update()
    {

    }

    void OML_Application::Terminate()
	{
		G_AudioContext->Destroy();
		G_AudioDevice->Close();

		G_GraphicContext->Destroy();
		G_Window->Destroy();

		ACE_Application_Terminate();
	}
}
