#include <OML/Application.h>

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

    }

    void OML_Application::Terminate()
    {
        ACE_Application_Terminate();
    }
}