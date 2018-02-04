#pragma once

#include <ACE/ACE.h>

namespace OML
{
    class OML_Application final : public ACE::ACE_Application
    {
    public:
        OML_Application();
        virtual ~OML_Application() override final;
    protected:
        virtual void Initialize() override final;
        virtual void Terminate() override final;
    };
}