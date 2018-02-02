#include <OML/Global.h>

using namespace OML;

int main( int in_argc, char **in_argv )
{
    Global::OML_CreateGlobal();
    Global::ApplicationG->Run();
    Global::OML_DestroyGlobal();
    return 0;
}