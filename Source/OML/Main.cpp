#include <OML/Global.h>

using namespace OML;

int main( int in_argc, char **in_argv )
{
    OML_GlobalInitialize();
    G_Application->Run();
    OML_GlobalTerminate();
    return 0;
}