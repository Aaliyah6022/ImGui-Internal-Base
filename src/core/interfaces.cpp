#include "interfaces.h"

template<typename T>
T* interfaces::Capture(const char* name, const char* lib) noexcept
{
	const HINSTANCE handle = GetModuleHandle(lib); 

	if (!handle)
		return nullptr;

	using Function = T * (*)(const char*, int*);
	Function CreateInterface = reinterpret_cast<Function>(GetProcAddress(handle, "CreateInterface"));

	return CreateInterface(name, nullptr);
}


namespace interfaces
{
	IBaseClientDLL* client = nullptr;
	void* clientMode = nullptr;
	IVEngineClient* engine = nullptr;
	IClientEntityList* clientEntityList = nullptr;
	IEngineVGui* engineVGui = nullptr;
	//ISurface* surface = nullptr;
	//CGlobalVarsBase* global_vars_base = nullptr;
	//IPrediction* prediction = nullptr;
	//IMoveHelper* move_helper = nullptr;
	//IGameMovement* game_movement = nullptr;
	//IWeaponSystem* weapon_system = nullptr;
	//IMDLCache* model_cache = nullptr;
	IModelRender* modelRender = nullptr;
	IMaterialSystem* materialSystem = nullptr;
	//IVModelInfo* model_info = nullptr;
	IDebugOverlay* debugOverlay = nullptr;
	IPanel* panel = nullptr;
	IEngineTrace* engineTraceClient = nullptr;
	//IStudioRender* studioRender = nullptr;

	bool Setup()
	{
		client = Capture<IBaseClientDLL>("VClient018", "client.dll");
		clientMode = **reinterpret_cast<void***>((*reinterpret_cast<unsigned int**>(client))[10] + 5);

		clientEntityList = Capture<IClientEntityList>("VClientEntityList003", "client.dll");
		panel = Capture<IPanel>("VGUI_Panel009", "vgui2.dll");
		engineVGui = Capture<IEngineVGui>("VEngineVGui001", "engine.dll");

		if (!engineVGui)
			return false;

		engine = Capture<IVEngineClient>("VEngineClient014", "engine.dll");

		if (!engine)
			return false;

		debugOverlay = Capture<IDebugOverlay>("VDebugOverlay004", "engine.dll");

		if (!debugOverlay)
			return false;

		materialSystem = Capture<IMaterialSystem>("VMaterialSystem080", "materialsystem.dll");

		if (!materialSystem)
			return false;

		modelRender = Capture<IModelRender>("VEngineModel016", "engine.dll");

		if (!modelRender)
			return false;

		engineTraceClient = Capture<IEngineTrace>("EngineTraceClient004", "engine.dll");

		if (!engineTraceClient)
			return false;

		return true;
	}
}