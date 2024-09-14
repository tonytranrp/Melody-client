#include "ArrayList.h"
#include "../../../Client.h"

ArrayList::ArrayList() : Module("ArrayList", "Display enabled modules list.", Category::CLIENT) {
	addBoolCheck("Bottom", "Make your arraylist at bottom.", &bottom);
	addSlider<float>("Size", "Changes arraylist size.", ValueType::FLOAT_T, &size, 0.5f, 1.5f);
	addSlider<float>("BG Opacity", "Changes background opacitys.", ValueType::FLOAT_T, &bgOpacity, 0.f, 1.f);
	addSlider<float>("Spacing", "NULL", ValueType::FLOAT_T, &spacing, 0.f, 5.f);
}

bool sortByLength(Module* lhs, Module* rhs) {
	float textWidth1 = ImGuiUtils::getTextWidth(lhs->getModuleName());
	if (lhs->getModName() != "NULL") textWidth1 += ImGuiUtils::getTextWidth(std::string(" " + lhs->getModName()));
	float textWidth2 = ImGuiUtils::getTextWidth(rhs->getModuleName());
	if (rhs->getModName() != "NULL") textWidth2 += ImGuiUtils::getTextWidth(std::string(" " + rhs->getModName()));

	return (textWidth1 > textWidth2);
}

void ArrayList::onImGuiRender(ImDrawList* drawlist) {
	float textSize = 1.f * size;
	float textPadding = 1.f * textSize;
	float textHeight = ImGuiUtils::getTextHeight(textSize) - 2.f; // riel textHeight
	textHeight += spacing;
	ImGuiIO& io = ImGui::GetIO();
	float xPos = io.DisplaySize.x - 1.f;
	float yPos = 0.f;
	if (bottom) yPos = io.DisplaySize.y;

	static std::vector<Module*> moduleList = *client->moduleMgr->getModuleList();
	std::sort(moduleList.begin(), moduleList.end(), sortByLength);

	static Colors* colorsMod = (Colors*)client->moduleMgr->getModule("Colors");

	int index = 0;
	for (Module* module : moduleList) {
		std::string moduleName = module->getModuleName();
		std::string modName = module->getModName();

		module->ArrayListDuration = Math::lerp((module->isEnabled() && module->isVisible()) ? 1.f : 0.f, module->ArrayListDuration, 0.2f);
		
		if (module->ArrayListDuration < 0.01f) continue;
		float textWidth = ImGuiUtils::getTextWidth(moduleName, textSize);
		if (modName != "NULL") textWidth += ImGuiUtils::getTextWidth(std::string(" " + modName), textSize);

		Vec2<float> textPos(xPos - (textWidth + textPadding) * module->ArrayListDuration, yPos);
		if (bottom) textPos.y -= textHeight + textPadding;
		Vec4<float> rectPos(textPos.x - textPadding * 3.f, textPos.y, textPos.x + textWidth + textPadding + 1.f, textPos.y + textHeight + textPadding);
		UIColor textColor = colorsMod->getColor(-index * colorsMod->getSeperationValue());
		ImGuiUtils::fillRectangle(rectPos, UIColor(0, 0, 0, int(255.f * bgOpacity)));
		ImGuiUtils::drawText(textPos, moduleName, textColor, textSize);
		if (modName != "NULL") ImGuiUtils::drawText(Vec2<float>(textPos.x + ImGuiUtils::getTextWidth(std::string(moduleName + " "), textSize), textPos.y), modName, UIColor(255, 255, 255, 255), textSize);

		++index;
		if (bottom) yPos -= (textHeight + textPadding) * module->ArrayListDuration;
		else yPos += (textHeight + textPadding) * module->ArrayListDuration;
	}
}
