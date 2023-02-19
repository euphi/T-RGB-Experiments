/*
 * FLClassicParser.h
 *
 *  Created on: 19.02.2023
 *      Author: ian
 */


#pragma once
#include <functional>
#include <Arduino.h>

class FLClassicParser {
public:
	typedef enum {
		FL_STATE_UNKNOWN = -1,
		FL_STATE_INIT = 0,
		FL_STATE_LOST,
		FL_STATE_CONNECTING,
		FL_STATE_CONNECTED
	} EFLConnState;

	typedef enum {
		FL_FLAG_BALANCE1       =  23 , // (1 << 7) << 16,
		FL_FLAG_BALANCE2       =  22  , // (1 << 6) << 16,
		FL_FLAG_BALANCE3       =  21  , // (1 << 5) << 16,
		FL_FLAG_SHORTCIRCUIT   =  20  , // (1 << 4) << 16,
		FL_FLAG_DISCHARGE_OVR  =  19  , // (1 << 3) << 16,
		FL_FLAG_CHARGE_OVR     =  18  , // (1 << 2) << 16,
		FL_FLAG_DISCHARGE_HGH  =  17  , // (1 << 1) << 16,
		FL_FLAG_CHARGE_HGH     =  16  , // (1 << 0) << 16,

		FL_FLAG_OVPWRRED       =  15  , // (1 << 7) << 8,
		FL_FLAG_OVERLOAD       =  14  , // (1 << 6) << 8, --> 2
		FL_FLAG_IN_DUVR        =  13  , // (1 << 5) << 8,
		FL_FLAG_CHARGE_INH     =  12  , // (1 << 4) << 8,
		FL_FLAG_DISCHARGE_INH  =  11  , // (1 << 3) << 8,
		FL_FLAG_FULL_DISCHARGE =  10  , // (1 << 2) << 8,
		FL_FLAG_CAPACITY_ACC   =  9   , // (1 << 1) << 8,
		FL_FLAG_DISCHARGE      =  8   , // (1 << 0) << 8,

		FL_ERR_CRITICAL        =  7  , // (1 << 7),
		FL_ERR_CELL_TEMP_LOW   =  6  , // (1 << 6),
		FL_ERR_CELL_TEMP_HIGH  =  5  , // (1 << 5),
		FL_ERR_VOLTAGE_LOW     =  4  , // (1 << 4),
		FL_ERR_VOLTAGE_HIGH    =  3  , // (1 << 3),
		FL_ERR_CHARGE_PROT     =  2  , // (1 << 2),
		FL_ERR_CHECKSUM        =  1  , // (1 << 1),
		FL_ERR_SYSTEM_IRQ      =  0  , // (1 << 0)
	} EFLFlags;


	//Types
	typedef std::function<void(uint8_t idx, bool state)> FLSpeedDistUpdateHandler;
	typedef std::function<void(uint8_t idx, bool state)> FLBatUpdateHandler;
	typedef std::function<void(uint8_t idx, bool state)> FLEnvUpdateHandler;

	typedef std::function<void(EFLConnState cstate, EFLFlags flags)> FLStateUpdateHandler;

	//Methods
	FLClassicParser(uint8_t polePair, uint16_t circum_mm);

	void setConnState(EFLConnState state) {cstate = state;}
	void updateFromString(const String& flStr);

	void setBatCb(const FLBatUpdateHandler &batCb) {batCB = batCb;}
	void setEnvCb(const FLEnvUpdateHandler &envCb) {envCB = envCb;}
	void setSpeedCb(const FLSpeedDistUpdateHandler &speedCb) {speedCB = speedCb;}

private:
	// Fields
	EFLConnState cstate = FL_STATE_UNKNOWN;

	const float dist_m_per_pulse, kmh_per_pulse_per_s;

	FLSpeedDistUpdateHandler speedCB = nullptr;
	FLBatUpdateHandler batCB = nullptr;
	FLEnvUpdateHandler envCB = nullptr;
	FLStateUpdateHandler stateCB = nullptr;

	unsigned long lastUpdate;

	// Methods


	static constexpr float dist_per_pulse = 2.155 / 14; // Umfang / Polpaare
	static constexpr float hmh_per_pulse = 2.155 / 14 * 3600 * 0.001 * 10; // Umfang / Polpaare * 3600 sec/hour * 0.001 m/km * 10 (100m/km) --> [0,1 km/h]
	static constexpr float m_per_pulse = 2.155 / 14 / 1000; // Umfang / Polpaare / 1000mm/m --> [m]


};

