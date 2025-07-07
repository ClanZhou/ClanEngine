#include <iostream>

#include "IApplication.hpp"

namespace clan
{
	extern IApplication* g_pApp;
}

int main(int argc, char** argv) 
{
	using clan::g_pApp;
	
    g_pApp->SetCommandLineParameters(argc, argv);

    g_pApp->CreateMainWindow();

    g_pApp->RegisterAllRuntimeModules();

    if (int ret = g_pApp->Initialize(); ret != 0)
    {
        std::cerr << "App Initialize Failed! \n";
        return ret;
    }

    while (!g_pApp->IsQuit())
    {
        g_pApp->Tick();
    }

	g_pApp->Finalize();

	return 0;
}

