#include "LunaEngine.h"

DWORD Global_GameModule;
DWORD Global_EngineModule;

bool LunaEngine::Init()
{
	Global_GameModule = GameModule();
	Global_EngineModule = EngineModule();
	if (Global_GameModule && Global_EngineModule)
		return true;
	return false;
}

DWORD LunaEngine::GameModule()
{
	return (DWORD)GetModuleHandle("client.dll");
}

DWORD LunaEngine::EngineModule()
{
	return (DWORD)GetModuleHandle("engine.dll");
}
