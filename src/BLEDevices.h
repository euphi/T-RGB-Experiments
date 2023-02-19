/*
 * BLEDevices.h
 *
 *  Created on: 18.02.2023
 *      Author: ian
 */

#pragma once

#include <vector> // Arduino BLE somehow misses this include. So add it here.
#include <BLEScan.h>
#include <BLEUtils.h>
#include <Arduino.h>
#include <FLClassicParser.h>

class BLEDevices: public BLEAdvertisedDeviceCallbacks {

typedef enum {
	DEV_HRM,
	DEV_CSC,
	DEV_FL,
	DEV_COUNT
} EDevType;

typedef enum {
	CONN_DEV_NOTFOUND,
	CONN_ADVERTISED,
	CONN_CONNECTED,
	CONN_LOST
} EBLEConnState;

static const char* DEV_EMOJI[DEV_COUNT];

private:
	BLEScan* pBLEScan;
	BLEAddress *pServerAddress[DEV_COUNT];
	BLEClient  *pClient[DEV_COUNT];

	bool scanning=false;
	bool doConnect[DEV_COUNT] = {false, false, false};
	EBLEConnState connState[DEV_COUNT] = {CONN_DEV_NOTFOUND, CONN_DEV_NOTFOUND, CONN_DEV_NOTFOUND};

	static const int scanTime = 5; //In seconds
	bool connectToServer(EDevType ctype);

	String bufferFL;
	FLClassicParser flparser;

    // CSC related
	uint16_t crank_rev_last, crank_time_last = 0;
	uint16_t cadence;


public:
	BLEDevices();

	static const BLEUUID serviceUUID[DEV_COUNT];
	static const BLEUUID charUUID[DEV_COUNT];


	// Interface BLEAdvertisedDeviceCallbacks
	void onResult(BLEAdvertisedDevice advertisedDevice);

	// helper functions called from lambda
	void notifyCallbackCSC( BLERemoteCharacteristic* pBLERemoteCharacteristic, uint8_t* pData, size_t length, bool isNotify, EDevType ctype);

	void setup();
	void loop();

};
