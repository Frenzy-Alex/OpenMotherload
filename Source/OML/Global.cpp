#include <OML/Global.h>

namespace OML
{
    void OML_Global::ResetAll()
    {
        Application.Reset( new OML_Application() );

        //  Audio
        AudioDevice.Reset( new ACE_AudioDevice( "OML_AudioDevice" ) );

        //  Graphic
        Window.Reset( new ACE_Window( "OML_Window" ) );
    }
}