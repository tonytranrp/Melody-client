// Created by Tony on 2024-10-10 10:01:54

#pragma once
#include "../Module.h"

class FastEat : public Module {
private:
	int duration = 20;
public:
	FastEat();

	virtual void onDisable() override;
	virtual void onNormalTick(Actor* actor) override;
};
