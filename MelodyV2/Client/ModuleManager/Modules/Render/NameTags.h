#pragma once
#include "../Module.h"

class NameTags : public Module {
private:
	float opacity = 0.4f;
public:
	NameTags();

	virtual void onImGuiRender(ImDrawList* d) override;
};