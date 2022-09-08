#pragma once
#include "util/includes.h"

// interfaces
#include "interfaces/IClientEntityList.h"


class IPanel;
class IClientEntityList;
class IEngineVGui;
class IModelRender;
class IMaterialSystem;
class IDebugOverlay;
class IBaseClientDLL;
class IVEngineClient;
class IStudioRender;
class IEngineTrace;

namespace interfaces
{
	extern IBaseClientDLL* client;
	extern void* clientMode;
	extern IVEngineClient* engine;
	extern IClientEntityList* clientEntityList;
	extern IEngineVGui* engineVGui;
	//extern ISurface* surface;
	//extern CGlobalVarsBase* global_vars_base;
	//extern IPrediction* prediction;
	//extern IMoveHelper* move_helper;
	//extern IGameMovement* game_movement;
	//extern IWeaponSystem* weapon_system;
	//extern IMDLCache* model_cache;
	extern IModelRender* modelRender;
	extern IMaterialSystem* materialSystem;
	//extern IVModelInfo* model_info;
	extern IDebugOverlay* debugOverlay;
	extern IPanel* panel;
	extern IEngineTrace* engineTraceClient;
	//extern IStudioRender* studioRender;

	template <typename T>
	T* Capture(const char* name, const char* lib) noexcept;

	bool Setup();
}


// This is how an interface should look like and params
#if 0 Create Interface

int __cdecl CreateInterface(int a1, int a2)
{
	return sub_980750(a1, a2);
}

#endif

#if 0 PanoramaUIEngine
int __stdcall sub_266160(int(__cdecl* a1)(const char*, _DWORD), int a2)
{
    int v2; // eax
    char* v3; // eax
    char v4; // cl
    FILE* v6; // eax
    char v7[8]; // [esp+8h] [ebp-108h] BYREF
    char Str[256]; // [esp+10h] [ebp-100h] BYREF

    sub_84F820();
    off_D8E8D0 = a2;
    sub_8174E0(&a1);
    sub_98AEE0();
    if (dword_5324024)
        (*(void(__thiscall**)(int, int))(*(_DWORD*)dword_5324024 + 532))(dword_5324024, 1);
    dword_5324028 = a1("PanoramaUIEngine001", 0);
    SteamAPI_InitSafe();
    SteamAPI_SetTryCatchCallbacks(0);
    sub_290E40(&dword_4E1DDD8);
    if (dword_4E1DDE0
        && dword_4E1DDDC
        && dword_4E1DDE4
        && dword_4E1DDFC
        && dword_4E1DDE8
        && (v2 = (*(int(__stdcall**)(char*))(*(_DWORD*)dword_4E1DDDC + 8))(v7), (unsigned __int8)sub_246950(v2)))
    {
        sub_97E400();
        if ((*(unsigned __int8(__thiscall**)(int, char*, int))(*(_DWORD*)dword_4E1DDF4 + 60))(dword_4E1DDF4, Str, 256)
            && strlen(Str)
            && sub_9772F0("public", Str))
        {
            v3 = strstr(Str, "beta");
            v4 = byte_530B160;
            if (v3)
                v4 = 1;
            byte_530B160 = v4;
        }
        return 1;
    }
    else
    {
        v6 = __acrt_iob_func(2u);
        sub_1CCEE0(
            v6,
            "FATAL ERROR: This game requires latest version of Steam to be running!\n"
            "Your Steam Client can be updated using Steam > Check for Steam Client Updates...\n");
        Error(
            "FATAL ERROR: Failed to connect with local Steam Client process!\n"
            "\n"
            "Please make sure that you are running latest version of Steam Client.\n"
            "You can check for Steam Client updates using Steam main menu:\n"
            "             Steam > Check for Steam Client Updates...");
        Plat_ExitProcess(100);
        return 0;
    }
}
#endif

#if 0 Engine
int __userpurge sub_266330@<eax>(int* a1@<ecx>, int a2@<edi>, int(__cdecl* a3)(const char*, _DWORD), int a4)
{
    unsigned __int8(__thiscall * **v5)(_DWORD); // eax
    int v6; // ecx
    void(__thiscall * **v7)(_DWORD, const char*, int*); // eax
    void(__thiscall * **v8)(_DWORD, const char*, int*); // edi
    int (*v9)(void); // edi
    int v10; // eax
    int v11; // eax
    int v12; // eax
    char v13; // cl
    int v14; // eax
    int v15; // ecx
    int v16; // eax
    int v17; // edi
    int v18; // ecx
    int v19; // eax
    int v20; // eax
    int v21; // eax
    int v22; // eax
    int v23; // [esp-Ch] [ebp-18h]
    int v24; // [esp-8h] [ebp-14h]
    int v25; // [esp-4h] [ebp-10h]
    int v26; // [esp-4h] [ebp-10h]

    COM_TimestampedLog("ClientDLL factories - Start");
    dword_530B138 = a3("VEngineClient014", 0);
    if (!dword_530B138)
        return 0;
    dword_530B1EC = a3("VEngineModel016", 0);
    if (!dword_530B1EC)
        return 0;
    dword_530B1DC = a3("VEngineEffects001", 0);
    if (!dword_530B1DC)
        return 0;
    dword_530B1F4 = a3("EngineTraceClient004", 0);
    if (!dword_530B1F4)
        return 0;
    dword_530B1A8 = a3("FileLoggingListener001", 0);
    if (!dword_530B1A8)
        return 0;
    dword_530B1E0 = a3("VEngineRenderView014", 0);
    if (!dword_530B1E0)
        return 0;
    dword_530B1D8 = a3("VDebugOverlay004", 0);
    if (!dword_530B1D8)
        return 0;
    dword_530B1C0 = a3("VDataCache003", 0);
    if (!dword_530B1C0)
        return 0;
    if (!dword_5324008)
        return 0;
    dword_530B134 = a3("VModelInfoClient004", 0);
    if (!dword_530B134)
        return 0;
    dword_530B1B8 = a3("VEngineVGui001", 0);
    if (!dword_530B1B8)
        return 0;
    dword_530B1BC = a3("VEngineClientStringTable001", 0);
    if (!dword_530B1BC)
        return 0;
    dword_530B1E8 = a3("SpatialPartition001", 0);
    if (!dword_530B1E8)
        return 0;
    dword_530B1B4 = a3("VEngineShadowMgr002", 0);
    if (!dword_530B1B4)
        return 0;
    dword_530B1B0 = a3("StaticPropMgrClient005", 0);
    if (!dword_530B1B0)
        return 0;
    dword_530B1D0 = a3("IEngineSoundClient003", 0);
    if (!dword_530B1D0)
        return 0;
    dword_530B1CC = a3("VFileSystem017", 0);
    if (!dword_530B1CC)
        return 0;
    dword_530B200 = a3("VEngineRandom001", 0);
    if (!dword_530B200)
        return 0;
    dword_530B1AC = a3("VENGINE_GAMEUIFUNCS_VERSION005", 0);
    if (!dword_530B1AC)
        return 0;
    dword_530B13C = a3("GAMEEVENTSMANAGER002", 0);
    if (!dword_530B13C)
        return 0;
    dword_530B1A4 = a3("VSoundEmitter003", 0);
    if (!dword_530B1A4)
        return 0;
    dword_530B1F0 = a3("InputSystemVersion001", 0);
    if (!dword_530B1F0)
        return 0;
    dword_530B1A0 = a3("VAvi001", 0);
    if (!dword_530B1A0)
        return 0;
    dword_530B1F8 = a3("SceneFileCache002", 0);
    if (!dword_530B1F8)
        return 0;
    dword_530B1E4 = a3("BlackBoxVersion001", 0);
    if (!dword_530B1E4)
        return 0;
    dword_530B19C = a3("XboxSystemInterface002", 0);
    if (!dword_530B19C)
        return 0;
    v5 = (unsigned __int8(__thiscall***)(_DWORD))a3("RenderToRTHelper001", 0);
    dword_530B194 = (int)v5;
    if (!v5)
        return 0;
    if (!(**v5)(v5))
        return 0;
    off_D96DB0 = (int*)a3("VENGINE_GAMETYPES_VERSION002", 0);
    if (!off_D96DB0)
        return 0;
    if (!dword_532402C)
        return 0;
    if (!dword_5324014)
        return 0;
    sub_237B70(v6);
    if (!dword_5324014)
        return 0;
    v7 = (void(__thiscall***)(_DWORD, const char*, int*))(*(int(__thiscall**)(int, int))(*(_DWORD*)dword_5324014
        + 40))(
            dword_5324014,
            a2);
    v8 = v7;
    if (v7)
    {
        (**v7)(v7, "VClient018", a1);
        (**v8)(v8, "GameUI011", &dword_52403F0);
    }
    v9 = CommandLine;
    v10 = CommandLine();
    if (!(*(int(__thiscall**)(int, const char*, _DWORD))(*(_DWORD*)v10 + 12))(v10, "-noscripting", 0))
        dword_530B18C = a3("VScriptManager009", 0);
    dword_5296090 = (int)a3;
    COM_TimestampedLog("soundemitterbase->Connect");
    if (!(**(unsigned __int8(__thiscall***)(int, int(__cdecl*)(const char*, _DWORD)))dword_530B1A4)(
        dword_530B1A4,
        a3))
        return 0;
    v11 = CommandLine();
    v12 = (*(int(__thiscall**)(int, const char*))(*(_DWORD*)v11 + 44))(v11, "-makedevshots");
    v13 = byte_530B204;
    if (v12)
        v13 = 1;
    byte_530B204 = v13;
    v14 = CommandLine();
    (*(void(__thiscall**)(int, const char*))(*(_DWORD*)v14 + 44))(v14, "-headtracking");
    dword_530B1C4 = a3("VMaterialSystemStub001", 0);
    if (!dword_5324060)
        return 0;
    CGaussianRandomStream::AttachToStream(
        (CGaussianRandomStream*)&unk_4DE8608,
        (struct IUniformRandomStream*)dword_530B200);
    dword_530B164 = (*(int(__thiscall**)(int, const char*))(*(_DWORD*)dword_5324044 + 68))(
        dword_5324044,
        "host_thread_mode");
    COM_TimestampedLog("InitGameSystems");
    if ((*(int(__thiscall**)(int*))(dword_4DE8690 + 52))(&dword_4DE8690))
    {
        if ((*(int(__thiscall**)(_DWORD, int, int))(*g_pMemAlloc + 4))(g_pMemAlloc, 92, v25))
        {
            v26 = v15;
            v16 = sub_26DE30();
            v17 = sub_264F00(v16, v26);
        }
        else
        {
            v17 = 0;
        }
        (*(void(__thiscall**)(_DWORD, int))(*g_pThreadPool + 56))(g_pThreadPool, v17);
        sub_265AB0(a3);
        while (!(unsigned __int8)sub_1D8490(v17))
        {
            (*(void(__thiscall**)(int))(*(_DWORD*)dword_532405C + 592))(dword_532405C);
            ThreadSleep(50);
        }
        (*(void(__thiscall**)(int))(*(_DWORD*)v17 + 4))(v17);
        v9 = CommandLine;
        goto LABEL_52;
    }
    COM_TimestampedLog("ParticleMgr()->Init");
    v23 = v18;
    sub_31F1D0();
    if (!(unsigned __int8)sub_320CC0(v23, v24))
        return 0;
    COM_TimestampedLog("InitGameSystems - Start");
    sub_265AB0(a3);
    COM_TimestampedLog("InitGameSystems - End");
LABEL_52:
    COM_TimestampedLog("C_BaseAnimating::InitBoneSetupThreadPool");
    dword_321B564 = g_pThreadPool;
    a1[21] = sub_2D5C30("CHudCloseCaption");
    (*(void(__thiscall**)(int*, _DWORD))(*off_D96DB0 + 4))(off_D96DB0, 0);
    v19 = v9();
    (*(void(__thiscall**)(int, const char*))(*(_DWORD*)v19 + 44))(v19, "-perfectworld");
    v20 = v9();
    (*(void(__thiscall**)(int, const char*))(*(_DWORD*)v20 + 44))(v20, "-usebanlist");
    sub_1AA9C0();
    if (!dword_5324014
        || !(*(int(__thiscall**)(int))(*(_DWORD*)dword_5324014 + 40))(dword_5324014)
        || (v21 = (*(int(__thiscall**)(int))(*(_DWORD*)dword_5324014 + 40))(dword_5324014),
            (v22 = (*(int(__thiscall**)(int, const char*))(*(_DWORD*)v21 + 8))(v21, "INETSUPPORT_003")) == 0)
        || (unsigned int)((*(int(__thiscall**)(int))(*(_DWORD*)v22 + 36))(v22) - 13839) > 2)
    {
        Error(
            "FATAL ERROR: Game content version mismatch detected!\n"
            "\n"
            "Please make sure that you are running latest version of the game.\n"
            "Verify integrity of game files in Steam Client may be used to re-download corrupt files.");
        Plat_ExitProcess(100);
    }
    sub_3590A0(sub_3594A0);
    COM_TimestampedLog("ClientDLL Init - Finish");
    return 1;
}
#endif