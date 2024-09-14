#include "AutoSprint.h"

AutoSprint::AutoSprint() : Module("AutoSprint", "Sprint for you.", Category::MOVEMENT) {
	addEnumSetting("Mode", "Change sprint modes.", { "Auto" }, &Mode);
}

void AutoSprint::onNormalTick(Actor* actor) {
	if (mc.getLocalPlayer() == nullptr) return;
	if (mc.isKeyDown('W') || mc.isKeyDown('A') || mc.isKeyDown('S') || mc.isKeyDown('D'))
	{
		mc.getLocalPlayer()->setSprinting(true);
	}
	else
	{
		mc.getLocalPlayer()->setSprinting(false);
	}


	
}