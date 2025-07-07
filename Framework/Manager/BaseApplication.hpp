#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "IApplication.hpp"
#include "IRuntimeModule.hpp"

struct GLFWwindow;

namespace clan
{

struct ApplicationConfiguration
{
	uint32_t screenWidth{ 1280 };
	uint32_t screenHeight{ 720 };
	std::string appName{ "BaseApplication" };

	explicit ApplicationConfiguration(uint32_t           width = 1280, 
									  uint32_t           height = 720,
									  const std::string& name = "BaseApplication")
		: screenWidth(width), screenHeight(height), appName(name)
	{ }

	friend std::ostream& operator<<(std::ostream& out, const ApplicationConfiguration& config)
	{
		out << "App Name: " << config.appName << '\n'
			<< "Configurations:\n"
			<< "ScreenWidth: " << config.screenWidth << '\n'
			<< "ScreenHeight: " << config.screenHeight << std::endl;

		return out;
	}
};

class BaseApplication : _implements_ IApplication
{
public:
	BaseApplication() = default;
	explicit BaseApplication(const ApplicationConfiguration& config) : m_Config(config) {}
	virtual ~BaseApplication() = default;

	int Initialize() override;
	void Tick() override;
	void Finalize() override;

	void SetCommandLineParameters(int argc, char** argv) override;
	[[nodiscard]] int GetCommandLineArgumentsCount() const override { return m_nArgC; };
	[[nodiscard]] const char* GetCommandLineArgument(int index) const override;

	[[nodiscard]] bool IsQuit() const override { return m_bQuit; };
	void RequestQuit() override { m_bQuit = true; }

	[[nodiscard]] const ApplicationConfiguration& GetConfiguration() const { return m_Config; }

        void CreateMainWindow() override;
        void* GetMainWindowHandler() override;

	void GetFramebufferSize(uint32_t& width, uint32_t& height) override { }

	void RegisterAllRuntimeModules() override;

protected:
	bool m_bQuit{ false };
	ApplicationConfiguration m_Config{};

	int    m_nArgC{ 0 };
	char** m_ppArgV{ nullptr };

private:
        std::vector<std::unique_ptr<IRuntimeModule>> m_RuntimeModules{};
        GLFWwindow* m_pWindow{ nullptr };
};

}