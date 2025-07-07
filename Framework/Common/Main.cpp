#include <iostream>

#include "IApplication.hpp"
#include <GLFW/glfw3.h>

namespace clan
{
	extern IApplication* g_pApp;
}

int main(int argc, char** argv) 
{
	using clan::g_pApp;
	
	g_pApp->SetCommandLineParameters(argc, argv);

        g_pApp->RegisterAllRuntimeModules();

        if (int ret = g_pApp->Initialize(); ret != 0)
        {
                std::cerr << "App Initialize Failed! \n";
                return ret;
        }

        g_pApp->CreateMainWindow();
        auto* window = static_cast<GLFWwindow*>(g_pApp->GetMainWindowHandler());

        while (!g_pApp->IsQuit() && window && !glfwWindowShouldClose(window))
        {
                g_pApp->Tick();
                glfwPollEvents();
        }

	g_pApp->Finalize();

	delete g_pApp;

	return 0;
}

