#pragma once
#include "../Module.h"

class PacketMine : public Module {
private:
	float range = 6.f;
	bool silenSwitch = true;
	bool silentBack = true;
	int breakMode = 0;
	int breakKeybind = 0x0;
	Vec3<int> breakPos = Vec3<int>(0, 0, 0);
	uint8_t face = -1;

	std::pair<int, float> getBestPickaxeSlot(Block* block);
	int lastSlot = -1;
	int shouldSwitchBack = false;
public:
	bool isbeingmine = false;
	PacketMine();
	void setBreakPos(const Vec3<int>& bPos, uint8_t f);
	void Reset();

	virtual void onNormalTick(Actor* actor) override;
	virtual void onRender(MinecraftUIRenderContext* ctx) override;
	virtual void onImGuiRender(ImDrawList* drawlist) override;
};