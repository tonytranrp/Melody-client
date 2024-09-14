#pragma once
#include "../Module.h"

class ArrayList : public Module {
private:
	int mode = 1;
	float size = 1.f;
	float bgOpacity = 0.2f;
	float spacing = 0.f;
public:
	bool bottom = false;
	ArrayList();

	virtual void onImGuiRender(ImDrawList* drawlist) override;
};