/*#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/Actor.h"
#include "../../../../SDK/Classes/BaseActorRenderContext.h"

#include "../../../Client.h"

class GlintColorHook {
protected:
	using func_t = __int64(__fastcall*)(ScreenContext*, BaseActorRenderContext*, Actor*, MC_Color, MC_Color, MC_Color, MC_Color, float, float, float, float, BaseActorRenderContext**, Vec4<float>*, float, unsigned __int8*);
	static inline func_t func;

	static __int64 GlintColorFunc(ScreenContext* screenContext, BaseActorRenderContext* entityContext, Actor* entity, MC_Color overlay, MC_Color changeColor, MC_Color changeColor2, MC_Color glintColor, float uvOffset1, float uvOffset2, float uvRot1, float uvRot2, BaseActorRenderContext** glintUVScale, Vec4<float>* uvAnim, float br, unsigned __int8* lightEmission) { // sub_1428200A0
		__int64 result = func(a1, a2, a3);
		static NoHurtcam* noHurtcamMod = (NoHurtcam*)client->moduleMgr->getModule("NoHurtcam");
		if (noHurtcamMod->isEnabled() && a1 == mc.getLocalPlayer() && a2 == 2) {
			uintptr_t* v5 = *(uintptr_t**)((__int64)a1 + 0x630);
			if (v5 != nullptr) {
				*v5 = 0;
			}
		}

		return result;
	}
public:
	static void init() {
		uintptr_t address = findSig(Sigs::hook::GlintColorHook);
		MemoryUtils::CreateHook("GlintColorHook", address, (void*)&GlintColorHook::GlintColorFunc, (void*)&func);
	}
};
*/