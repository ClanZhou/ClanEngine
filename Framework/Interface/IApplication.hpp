#pragma once

#include <cstdint>

#include "Interface.hpp"

namespace clan
{

_Interface_ IApplication
{
public:
	virtual ~IApplication() = default;

	virtual void SetCommandLineParameters(int argc, char** argv) = 0;
	[[nodiscard]] virtual int GetCommandLineArgumentsCount() const = 0;
	[[nodiscard]] virtual const char* GetCommandLineArgument(int index) const = 0;

	virtual int Initialize() = 0;
	virtual void Tick() = 0;
	virtual void Finalize() = 0;

	[[nodiscard]] virtual bool IsQuit() const = 0;
	virtual void RequestQuit() = 0;

	virtual void CreateMainWindow() = 0;
	virtual void* GetMainWindowHandler() = 0;

	virtual void GetFramebufferSize(uint32_t& width, uint32_t& height) = 0;

	virtual void RegisterAllRuntimeModules() = 0;
};

}