/*
 * Statistics.cpp
 *
 *  Created on: 31.12.2022
 *      Author: ian
 */

#include "Statistics.h"

Statistics::Statistics() {
	timestamp_last = millis();
}

void Statistics::addSpeed(uint16_t speed) {
	for (uint_fast8_t i = 0; i<= ESP_START; i++) {

	}

}

void Statistics::addDistance(uint16_t dist, ESummaryType type) {
	bool absolut = (type == FL_TOUR) || (type == FL_TRIP);			// distance update from FL is absolut

	if (absolut) {
		distance[type] = dist;
	} else {
		distance[type] += dist;		//TODO: Care about the units
	}

}
