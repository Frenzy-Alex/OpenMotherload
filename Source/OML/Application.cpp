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

        ACE_ReturnIf( !G_AudioDevice->Open( nullptr ), ACE_Initializable_Errored() );
        G_AudioDevice->AttachContext( &G_AudioContext );

        ACE_ReturnIf( !G_AudioContext->Create(), ACE_Initializable_Errored() );
        ACE_ReturnIf( !G_AudioContext->MakeCurrent(), ACE_Initializable_Errored() );

        ACE_ReturnIf( !G_Window->Create(), ACE_Initializable_Errored() );
        G_Window->AttachContext( &G_GraphicContext );

        ACE_ReturnIf( !G_GraphicContext->Create(), ACE_Initializable_Errored() );
        ACE_ReturnIf( !G_GraphicContext->MakeCurrent(), ACE_Initializable_Errored() );
    }

    void OML_Application::Terminate()
    {
        ACE_Application_Terminate();

        G_AudioContext->Destroy();
        G_AudioDevice->Close();

        G_GraphicContext->Destroy();
        G_Window->Destroy();
    }
}