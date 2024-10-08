#include "GlintColor.h"

GlintColor::GlintColor() : Module("GlintColor", "GlintColor.", Category::CLIENT) {
	addSlider<float>("intensity", "NULL", ValueType::FLOAT_T, &intensity, 0.01f, 0.1f);
	addBoolCheck("night", "NULL", &night);
	addBoolCheck("custom", "NULL", &custom);
	addColorPicker("Color", "NULL", &color);
}