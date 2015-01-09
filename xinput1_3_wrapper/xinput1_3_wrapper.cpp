#include "stdafx.h"
#include "Common.h"

#include "xinput_module_manager.h"

extern "C" DWORD WINAPI XInputGetState(DWORD dwUserIndex, XINPUT_STATE* pState)
{
	PrintDebug(__FUNCTION__);

	if (!pState)
		return ERROR_BAD_ARGUMENTS;

	return XInputModuleManager::Get().XInputGetState(dwUserIndex, pState);
}

extern "C" DWORD WINAPI XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration)
{
	PrintDebug(__FUNCTION__);

	if (!pVibration)
		return ERROR_BAD_ARGUMENTS;

	return XInputModuleManager::Get().XInputSetState(dwUserIndex, pVibration);
}

extern "C" DWORD WINAPI XInputGetCapabilities(DWORD dwUserIndex, DWORD dwFlags, XINPUT_CAPABILITIES* pCapabilities)
{
	PrintDebug(__FUNCTION__);

	if (!pCapabilities || dwFlags != XINPUT_FLAG_GAMEPAD)
		return ERROR_BAD_ARGUMENTS;

	return XInputModuleManager::Get().XInputGetCapabilities(dwUserIndex, dwFlags, pCapabilities);
}

extern "C" VOID WINAPI XInputEnable(BOOL enable)
{
	PrintDebug(__FUNCTION__);

	XInputModuleManager::Get().XInputEnable(enable);
}

extern "C" DWORD WINAPI XInputGetDSoundAudioDeviceGuids(DWORD dwUserIndex, GUID* pDSoundRenderGuid, GUID* pDSoundCaptureGuid)
{
	PrintDebug(__FUNCTION__);

	if (!pDSoundRenderGuid || !pDSoundCaptureGuid)
		return ERROR_BAD_ARGUMENTS;

	return XInputModuleManager::Get().XInputGetDSoundAudioDeviceGuids(dwUserIndex, pDSoundRenderGuid, pDSoundCaptureGuid);
}

extern "C" DWORD WINAPI XInputGetBatteryInformation(DWORD dwUserIndex, BYTE devType, XINPUT_BATTERY_INFORMATION* pBatteryInformation)
{
	PrintDebug(__FUNCTION__);

	if (!pBatteryInformation)
		return ERROR_BAD_ARGUMENTS;

	return XInputModuleManager::Get().XInputGetBatteryInformation(dwUserIndex, devType, pBatteryInformation);
}

extern "C" DWORD WINAPI XInputGetKeystroke(DWORD dwUserIndex, DWORD dwReserved, XINPUT_KEYSTROKE* pKeystroke)
{
	PrintDebug(__FUNCTION__);

	if (!pKeystroke)
		return ERROR_BAD_ARGUMENTS;

	return XInputModuleManager::Get().XInputGetKeystroke(dwUserIndex, dwReserved, pKeystroke);
}

//undocumented
extern "C" DWORD WINAPI XInputGetStateEx(DWORD dwUserIndex, XINPUT_STATE *pState)
{
	PrintDebug(__FUNCTION__);

	if (!pState)
		return ERROR_BAD_ARGUMENTS;

	return XInputModuleManager::Get( ).XInputGetStateEx( dwUserIndex, pState );
}

extern "C" DWORD WINAPI XInputWaitForGuideButton(DWORD dwUserIndex, DWORD dwFlag, LPVOID pVoid)
{
	PrintDebug(__FUNCTION__);

	return XInputModuleManager::Get().XInputWaitForGuideButton(dwUserIndex, dwFlag, pVoid);
}

extern "C" DWORD WINAPI XInputCancelGuideButtonWait(DWORD dwUserIndex)
{
	PrintDebug(__FUNCTION__);

	return XInputModuleManager::Get().XInputCancelGuideButtonWait(dwUserIndex);
}

extern "C" DWORD WINAPI XInputPowerOffController(DWORD dwUserIndex)
{
	PrintDebug(__FUNCTION__);

	return XInputModuleManager::Get().XInputPowerOffController(dwUserIndex);
}

extern "C" DWORD WINAPI XInputGetAudioDeviceIds(DWORD dwUserIndex, LPWSTR pRenderDeviceId, UINT* pRenderCount, LPWSTR pCaptureDeviceId, UINT* pCaptureCount)
{
	PrintDebug(__FUNCTION__);

	return XInputModuleManager::Get( ).XInputGetAudioDeviceIds( dwUserIndex, pRenderDeviceId, pRenderCount, pCaptureDeviceId, pCaptureCount );
}

extern "C" DWORD WINAPI XInputGetBaseBusInformation(DWORD dwUserIndex, struct XINPUT_BUSINFO* pBusinfo)
{
	PrintDebug(__FUNCTION__);

	return XInputModuleManager::Get( ).XInputGetBaseBusInformation( dwUserIndex, pBusinfo );
}

// XInput 1.4 uses this in XInputGetCapabilities and calls memcpy(pCapabilities, &CapabilitiesEx, 20u);
// so XINPUT_CAPABILITIES is first 20 bytes of XINPUT_CAPABILITIESEX
extern "C" DWORD WINAPI XInputGetCapabilitiesEx(DWORD unk1 /*seems that only 1 is valid*/, DWORD dwUserIndex, DWORD dwFlags, struct XINPUT_CAPABILITIESEX* pCapabilitiesEx)
{
	PrintDebug(__FUNCTION__);

	return XInputModuleManager::Get( ).XInputGetCapabilitiesEx( unk1, dwUserIndex, dwFlags, pCapabilitiesEx );
}
