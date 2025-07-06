#pragma once

#include "IApplication.hpp"

namespace clan
{

_Interface_ IRuntimeModule
{
public:
	explicit IRuntimeModule(IApplication* pApp) : m_pApp(pApp) { }
	virtual ~IRuntimeModule() = default;

	virtual int Initialize() = 0;
	virtual void Tick() = 0;
	virtual void Finalize() = 0;

private:
	IApplication* m_pApp;
};

}