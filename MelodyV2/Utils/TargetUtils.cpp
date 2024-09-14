#include "TargetUtils.h"
#include "../Utils/Math.h"
#include "../SDK/GameData.h"
#include <string>
bool TargetUtils::isTargetValid(Actor* target, bool isMob) {
	LocalPlayer* localPlayer = mc.getLocalPlayer();
	if (localPlayer == nullptr) return false;
	if (target == nullptr) return false;
	if (target == localPlayer) return false;
	if (!target->isAlive()) return false;
	int entId = target->getEntityTypeId();
	if (entId == 0) return false;
	if (entId == 64) return false; // item
	if (entId == 66) return false; // falling block
	if (entId == 69) return false; // xp orb
	if (entId == 70) return false; // enderEye
	if (entId == 95) return false; // falling block
	if (entId == 4194372) return false; // exp bottle
	if (entId == 4194390) return false; // potion
	if (entId == 4194405) return false; // still potion
	if (entId == 4194391) return false; // ender pearl
	if (entId == 12582992) return false; // wtf arrow???

	if (!isMob) {
		if (!target->isPlayer()) return false;
		if (entId != 319) return false;
	}
	else {
		//mmb
	}
	return true;
}

bool TargetUtils::sortByDist(Actor* a1, Actor* a2) {
	Vec3<float> lpPos = *mc.getLocalPlayer()->getPosition();
	return ((a1->getPosition()->dist(lpPos)) < (a2->getPosition()->dist(lpPos)));
}