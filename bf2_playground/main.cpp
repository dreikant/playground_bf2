#include <windows.h>
#include <stdlib.h>

#include "Detours.h"

#define _DEBUG_LOG    TRUE
#include "LogFile.h"

#include "bf2Defines.h"

//typedef HRESULT (WINAPI* tPresent)(LPDIRECT3DSWAPCHAIN9 pSwapChain, const RECT *pSourceRect,const RECT *pDestRect,HWND hDestWindowOverride,const RGNDATA *pDirtyRegion,DWORD dwFlags);
//tPresent oPresent;

//typedef HRESULT (WINAPI* tPresent)(IDXGISwapChain* theClass, unsigned int, unsigned int);
//tPresent oPresent;


//HRESULT WINAPI hkPresent(LPDIRECT3DSWAPCHAIN9 pSwapChain, const RECT *pSourceRect,const RECT *pDestRect,HWND hDestWindowOverride,const RGNDATA *pDirtyRegion,DWORD dwFlags)
//HRESULT WINAPI hkPresent(IDXGISwapChain* theclass, unsigned int d, unsigned int e)
//{
//	return oPresent(theclass, d, e);
//}

DWORD CreateDetours()
{
	// init hooks.
	CLogFile logFile = CLogFile("log.txt",true);
	logFile.Write("Create Detours...");
	logFile.Write("Create Detours Finished...");

	// init detours.
	if ( true )
	{
		DWORD dxgi_base = (DWORD)GetModuleHandle("dxgi.dll") + (DWORD)0x2D9D1;

		//oPresent = ( tPresent )DetourCreate( (PBYTE)dxgi_base, (PBYTE)&hkPresent, 5);


		//logFile.Write("Detoured Swapchain Function: %X -> %X ... ", dxgi_base, (DWORD)oPresent);
	}else
	{
		//logFile.Write("Detour failed. Swapchain Invalid. %X ... ", g_dxRenderer->pSwapChain);
	}


	return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
    if(dwReason == DLL_PROCESS_ATTACH) { 
		CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CreateDetours,0,0,0);
    } 
    return TRUE;
}