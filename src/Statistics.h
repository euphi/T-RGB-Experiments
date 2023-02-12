/*
 * Statistics.h
 *
 *  Created on: 31.12.2022
 *      Author: ian
 */
#pragma once

#include <Arduino.h>

class Statistics {
	enum ESummaryType{
		FL_SUMMARY_AUTO = -1,
		ESP_TOUR = 0,           // Tour Distance as stored locally
		ESP_TRIP,               // Trip Distance as stored locally
		ESP_START,              // Distance as stored locally (since start)
		FL_TOUR,    			// Tour Distance as stored in FL
		FL_TRIP,                // Trip Distance as stored in FL
		ESummaryTypeMax
	};

	enum EDrivingState {	// Various driving states
		NO_CONN,
		BREAK,
		STOP,
		DRIVE_COASTING,
		DRIVE_POWER
	};

	enum EAvgType {
		AVG_ALL,
		AVG_DRIVE,
		AVG_NOBREAK   // but Pause/Stop
	};

	uint16_t speed_max[ESP_START+1] = {0,0,0};

	//time_t timestamp_last;
	uint32_t timestamp_last;

	uint32_t distance[ESummaryTypeMax];


public:
	static constexpr float dist_per_pulse = 2.155 / 14; // Umfang / Polpaare
	static constexpr float hmh_per_pulse = 2.155 / 14 * 3600 * 0.001 * 10; // Umfang / Polpaare * 3600 sec/hour * 0.001 m/km * 10 (100m/km) --> [0,1 km/h]
	static constexpr float m_per_pulse = 2.155 / 14 / 1000; // Umfang / Polpaare / 1000mm/m --> [m]

	Statistics();
	void addSpeed(uint16_t speed);  // in 0,1km/h
	void addDistance(uint16_t dist,ESummaryType type = FL_SUMMARY_AUTO);

	float getAvg(ESummaryType type, EAvgType avgtype) const {
		return 0.0;
		//return dist_total[type] / (10.0 * speed_avg_count);
	};

};

