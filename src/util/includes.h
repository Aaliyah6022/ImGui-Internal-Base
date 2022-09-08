#pragma once
#include <Windows.h>
#include <thread>
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

// Globals
#include "globals.h"


#include "xorstr.h"
#include "keybinds.h"

#include "../ext/kiero/kiero.h"
#include "../ext/minhook/MinHook.h"
#include "../ext/imgui/imgui.h"
#include "../ext/imgui/imgui_impl_win32.h"
#include "../ext/imgui/imgui_impl_dx9.h"

#include "core/classes/LunaEngine.h"

#define WINDOW_NAME "Aaliyah"
typedef long(__stdcall* EndScene)(LPDIRECT3DDEVICE9);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);