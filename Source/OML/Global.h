#pragma once

#include <ACE/ACE.h>
#include <OML/Application.h>

using namespace ACE;

namespace OML
{
    void OML_GlobalInitialize();
    void OML_GlobalTerminate();

    extern ACE_UniquePointer<OML_Application> G_Application;

    //  Audio
    extern ACE_UniquePointer<ACE_AudioDevice> G_AudioDevice;
    extern ACE_UniquePointer<ACE_AudioContext> G_AudioContext;
    extern ACE_UniquePointer<ACE_AudioListener> G_AudioListener;

    //  Graphic
    extern ACE_UniquePointer<ACE_Window> G_Window;
    extern ACE_UniquePointer<ACE_GraphicContext> G_GraphicContext;
    extern ACE_UniquePointer<ACE_Viewport> G_Viewport;

    //  Game
//    extern ACE_UniquePointer<ACE_Scene> G_Scene;
}