/*
 * uifacade.cpp
 *
 *  Created on: 30.12.2022
 *      Author: ian
 */

#include "uifacade.h"
#include "ui/ui.h"
#include <lvgl.h>

ui_facade::ui_facade() {
}

void ui_facade::updateClock(const String &str) {
	lv_label_set_text(ui_S1LabelClock, str.c_str());
}

void ui_facade::updateIP(const String &str) {
	lv_label_set_text(ui_SWifiLabelIPAddr, ("IP: " + str).c_str());
}

void ui_facade::updateSpeed(uint16_t speed) {
	String spdStr(speed/10.0, 1);
	lv_label_set_text(ui_S1LabelSpeed, spdStr.c_str());
	lv_arc_set_value(ui_S1ArcSpeed, speed);
}
