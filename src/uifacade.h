/*
 * uifacade.h
 *
 *  Created on: 30.12.2022
 *      Author: ian
 */

#pragma once
#include <Arduino.h>

class ui_facade {
public:
	ui_facade();

	void updateClock(const String& str);
	void updateIP(const String& str);
	void updateSpeed(uint16_t speed);  // speed in 0,1 km/h


};
