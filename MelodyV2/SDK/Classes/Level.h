#pragma once
#include "../../Utils/Math.h"
#include "../../Utils/MemoryUtils.h"

class Actor;

class Level {
public:
	Vec3<float> getPointingBlockPos() {
		Vec3<float> pos;
		pos.x = *reinterpret_cast<float*>((uintptr_t)(this) + 0xAE4);
		pos.y = *reinterpret_cast<float*>((uintptr_t)(this) + 0xAE8);
		pos.z = *reinterpret_cast<float*>((uintptr_t)(this) + 0xAEC);
		return pos;
	}

	std::vector<Actor*> getRuntimeActorList() {
		std::vector<Actor*> listOut;
		MemoryUtils::CallVFunc<294, decltype(&listOut)>(this, &listOut);
		return listOut;
	}
};
