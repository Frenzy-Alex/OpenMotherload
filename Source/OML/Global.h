#include <ACE/ACE.h>
#include <OML/Application.h>

using namespace ACE;

namespace OML
{
    class OML_Global : public ACE_Singleton<OML_Global>
    {
    public:
        void ResetAll();

        ACE_UniquePointer<OML_Application> Application;

        //  Audio
        ACE_UniquePointer<ACE_AudioDevice> AudioDevice;

        //  Graphic
        ACE_UniquePointer<ACE_Window> Window;
    };

    #define OML_GlobalS     OML::OML_Global::GetInstance()

    namespace Global
    {
        void OML_CreateGlobal();
        void OML_DestroyGlobal();

        extern ACE_UniquePointer<OML_Application> OML_ApplicationG;

        //  Audio
        extern ACE_UniquePointer<ACE_AudioDevice> OML_AudioDeviceG;

        //  Graphic
        extern ACE_UniquePointer<ACE_Window> OML_WindowG;
    }
}