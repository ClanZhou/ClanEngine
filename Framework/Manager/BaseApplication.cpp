#include <cassert>
#include <GLFW/glfw3.h>

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
    glfwPollEvents();
}

void BaseApplication::Finalize()
{
    for (auto& module : m_RuntimeModules)
    {
        module->Finalize();
    }

    if (m_pWindow)
    {
        glfwDestroyWindow(m_pWindow);
        m_pWindow = nullptr;
    }
    glfwTerminate();
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

void BaseApplication::CreateMainWindow()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW!\n";
        return;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_pWindow = glfwCreateWindow(m_Config.screenWidth, m_Config.screenHeight,
                                m_Config.appName.c_str(), nullptr, nullptr);
    if (!m_pWindow)
    {
        std::cerr << "Failed to create GLFW window!\n";
        glfwTerminate();
    }
}

void* BaseApplication::GetMainWindowHandler()
{
    return m_pWindow;
}

bool BaseApplication::IsQuit() const
{
    return m_bQuit || !m_pWindow || glfwWindowShouldClose(m_pWindow);
}

}

