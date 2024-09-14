#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../Utils/RenderUtils.h"
#include "../../../../SDK/Classes/ScreenView.h"
#include "../../../../SDK/Classes/UILayer.h"
#include "../../../../SDK/Classes/MinecraftUIRenderContext.h"
#include "../../../../SDK/GameData.h"

#include "../MinecraftUIRenderContext/DrawImageHook.h"
#include "../MinecraftUIRenderContext/DrawTextHook.h"
#include "../Others/SendPacketHook.h"

#include "../../../Client.h"

class SetUpAndRenderHook {
protected:
	using func_t = __int64(__fastcall*)(ScreenView*, MinecraftUIRenderContext*);
	static inline func_t func;

	static __int64 SetUpAndRender(ScreenView* _this, MinecraftUIRenderContext* renderCtx) {
		mc.setClientInstance(renderCtx->clientInstance);
		RenderUtils::SetUp(_this, renderCtx);
		static bool hooked = false;
		if (!hooked) {
			uintptr_t* CtxVTable = *(uintptr_t**)renderCtx;
			uintptr_t* loopbackPacketSenderVTable = *(uintptr_t**)(renderCtx->clientInstance->loopbackPacketSender);
			DrawTextHook::init(CtxVTable[5]);
			DrawImageHook::init(CtxVTable[7]);
			SendPacketHook::init(loopbackPacketSenderVTable[1]);
			hooked = true;
		}
		__int64 result = func(_this, renderCtx);
		if (_this->visualTree->root->GetName() == UILayer::Debug_DebugScreen) {
			client->moduleMgr->onRender(renderCtx);
		}
		return result;
	}
public:
	static void init() {
		uintptr_t address = findSig(Sigs::hook::SetupAndRenderHook);
		MemoryUtils::CreateHook("SetUpAndRenderHook", address, (void*)&SetUpAndRenderHook::SetUpAndRender, (void*)&func);
	}
};