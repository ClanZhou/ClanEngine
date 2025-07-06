#include <cassert>

#include "BaseApplication.hpp"

namespace clan
{

int BaseApplication::Initialize() {
    int ret = 0;

    std::cout << m_Config;

    for (auto& module : m_RuntimeModules)
    {
        if ((ret = module->Initialize()) != 0)
        {
            std::cerr << "Module initialize failed!\n";
            break;
        }
    }

    return ret;
}

void BaseApplication::Tick() 
{
    for (auto& module : m_RuntimeModules)
    {
        module->Tick();
    }
}

void BaseApplication::Finalize()
{
    for (auto& module : m_RuntimeModules)
    {
        module->Finalize();
    }
}

void BaseApplication::SetCommandLineParameters(int argc, char** argv) 
{
    m_nArgC = argc;
    m_ppArgV = argv;
}

const char* BaseApplication::GetCommandLineArgument(int index) const 
{
    assert(index < m_nArgC);
    return m_ppArgV[index];
}

void BaseApplication::RegisterAllRuntimeModules()
{

}

}