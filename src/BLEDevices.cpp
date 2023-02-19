/*
 * BLEDevices.cpp
 *
 *  Created on: 18.02.2023
 *      Author: ian
 */

#include <BLEDevices.h>
#include <BLEDevice.h>

#include <Arduino.h>

// HRM, CSC, FL
const BLEUUID BLEDevices::serviceUUID[3] = { BLEUUID((uint16_t)0x180D), BLEUUID((uint16_t)0x1816), BLEUUID("e62efa94-afa8-11ed-afa1-0242ac120002")};
const BLEUUID BLEDevices::charUUID[3] = { BLEUUID((uint16_t)0x2A37), BLEUUID((uint16_t)0x2A5B), BLEUUID("e62efe40-afa8-11ed-afa1-0242ac120002")};

const char* BLEDevices::DEV_EMOJI[DEV_COUNT] = {"❤️","🚴","⚡"};


BLEDevices::BLEDevices():
		flparser(14, 2155)
{

}

void BLEDevices::onResult(BLEAdvertisedDevice advertisedDevice) {
//	sdl.logf(SDLogger::Log_Debug, SDLogger::TAG_HR, "🔵 Advertised Device: %s ", advertisedDevice.toString().c_str());
	Serial.printf("🔵 Advertised Device: %s \n", advertisedDevice.toString().c_str());
	Serial.printf("\tServiceDataCount: %d ServiceDataUUIDCount: %d ServiceUUIDCount: %d\n", advertisedDevice.getServiceDataCount(), advertisedDevice.getServiceDataUUIDCount(), advertisedDevice.getServiceUUIDCount());
	for (uint8_t c=0; c < advertisedDevice.getServiceDataCount(); c++) {
		std::string servStr = advertisedDevice.getServiceData(c);
		Serial.printf("\tServiceData: %s\n", servStr.c_str());
	}
	for (uint8_t c=0; c < advertisedDevice.getServiceDataUUIDCount(); c++) {
		BLEUUID uuid = advertisedDevice.getServiceDataUUID(c);
		Serial.printf("\tServiceData-UUID: %s\n", uuid.toString().c_str());
	}
	for (uint8_t c=0; c < advertisedDevice.getServiceUUIDCount(); c++) {
		BLEUUID uuid = advertisedDevice.getServiceUUID(c);
		if (uuid.equals(serviceUUID[DEV_CSC])) {
			Serial.println("\t🚴 Found CSC Device");
			pServerAddress[DEV_CSC] = new BLEAddress(advertisedDevice.getAddress());
			doConnect[DEV_CSC] = true;
			connState[DEV_CSC] = CONN_ADVERTISED;
		}
		if (uuid.equals(serviceUUID[DEV_HRM])) {
			Serial.println("\t❤️ Found HRM Device");
			pServerAddress[DEV_HRM] = new BLEAddress(advertisedDevice.getAddress());
			doConnect[DEV_HRM] = true;
			connState[DEV_HRM] = CONN_ADVERTISED;
		}
		Serial.printf("\tService-UUID: %s\n", uuid.toString().c_str());
	}
	if (advertisedDevice.getName().find("ForumsLader") != std::string::npos) {
		Serial.println("\t⚡ Found FL Device");
		pServerAddress[DEV_FL] = new BLEAddress(advertisedDevice.getAddress());
		doConnect[DEV_FL]=true;
		connState[DEV_FL] = CONN_ADVERTISED;
	}
}


bool BLEDevices::connectToServer(EDevType ctype) {
	doConnect[ctype] = false;
	if (!pClient[ctype]) {
		pClient[ctype] = new BLEClient();
	} else {
		Serial.printf("Client already exists for %s %d - reusing it", DEV_EMOJI[ctype], ctype);
	}
	Serial.printf("%s Connecting to address %s\n", DEV_EMOJI[ctype], pServerAddress[ctype]->toString().c_str());
	//Serial.printf("Client:\n%s\n", pClient[ctype]->toString().c_str());
	if (pClient[ctype]->connect(*pServerAddress[ctype], (ctype == DEV_CSC) ? BLE_ADDR_TYPE_RANDOM : BLE_ADDR_TYPE_PUBLIC)) {
		Serial.printf("Client %d connected\n", ctype);
		connState[ctype] = CONN_CONNECTED;

	} else {
		Serial.println("🔵⚠️ Cannot connect");
		return false;
	}

	BLEUUID uuid = serviceUUID[ctype];
	BLERemoteService* pRemoteService = pClient[ctype]->getService(uuid);
	if (pRemoteService == nullptr) {
		Serial.printf("🔵⚠️ Cannot find remote service %s\n", uuid.toString().c_str());
		return false;
	}
	BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID[ctype]);
	if (pRemoteCharacteristic == nullptr) {
		Serial.println("🔵⚠️ Cannot find remote characteristic");
		return false;
	}
	pRemoteCharacteristic->registerForNotify([&, ctype](BLERemoteCharacteristic* pBLERemoteCharacteristic, uint8_t* pData, size_t length, bool isNotify) {notifyCallbackCSC(pBLERemoteCharacteristic, pData, length, isNotify, ctype);});
	return true;
}


void BLEDevices::setup() {
	  BLEDevice::init("TRGB_BTTacho BLE");
	  pBLEScan = BLEDevice::getScan(); //create new scan
	  pBLEScan->setAdvertisedDeviceCallbacks(this);
	  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
	  pBLEScan->setInterval(100);
	  pBLEScan->setWindow(99);  // less or equal setInterval value
	  pBLEScan->start(scanTime, [](BLEScanResults result) {Serial.printf("🔵 ✔️ BLE scan completed: %d devices found.\n", result.getCount());}); // Non-Blocking
	  scanning = true;
}

void BLEDevices::notifyCallbackCSC(BLERemoteCharacteristic *pBLERemoteCharacteristic, uint8_t *pData, size_t length, bool isNotify, EDevType ctype) {
	uint8_t flags;
	uint16_t crank_rev, crank_time, hr;

	switch (ctype) {
	case DEV_FL:
		//Serial.printf("Received %d bytes\n", length);
		bufferFL.concat(pData, length);
		//Serial.println(bufferFL);
		if (bufferFL.indexOf('\n') >0) {
			Serial.println(bufferFL);
			flparser.updateFromString(bufferFL);
			bufferFL.clear();
		}
		break;
	case DEV_CSC:
		Serial.printf("Received from CSC %d bytes: 0x", length);
		for (uint8_t c = 0; c<length; c++) {
			Serial.print(*(pData+c), 16);
		}
		if (length < 1) {
			return;
		}
		flags = pData[0];
		Serial.printf(" - Flag %x: Wheel: [%c] Crank: [%c]\n", flags, (flags & 1) ? 'x':' ', (flags & 2) ? 'x':' ');
		if (length < 5) return;
		crank_rev = (pData[2] << 8 )+ pData[1];		// LSB first
		crank_time = (pData[4] << 8 )+ pData[3];	// LSB first
		//Serial.printf("%d revs at %d. Delta: %d at %d\n", crank_rev, crank_time, (crank_rev - crank_rev_last), (crank_time - crank_time_last));
		if ((crank_time - crank_time_last) > 0) {
			cadence = ( (crank_rev - crank_rev_last) * 1024 * 60 ) / (crank_time - crank_time_last);
		} else {
			//TODO: Handle 0 BPM correctly
		}
		crank_rev_last = crank_rev;
		crank_time_last = crank_time;
		Serial.println(cadence);
		break;
	case DEV_HRM:
		//uint32_t* pData32 = (uint32_t*)pData;
		if (length < 2)
			return;
		flags = pData[0];
		hr = pData[1];
		Serial.printf("HR Data with length %d. HR 8bit: %x FLAG: %X\n", length,	hr, flags);
//		uint8_t contact = (pData[0] >> 1) & 3; // Bit 1&2 --> Contact
//			if (debug) {
//				switch (contact) {
//				case 2:
//					sdl.log(SDLogger::Log_Debug, SDLogger::TAG_HR, F("No contact"));
//					break;
//				case 3:
//					sdl.log(SDLogger::Log_Debug, SDLogger::TAG_HR, F("Contact"));
//					break;
//				default:
//					sdl.logf(SDLogger::Log_Debug, SDLogger::TAG_HR, "Contact not supported [%x]\n", contact);
//				}
//			}
//		  bool ee_status =  ((pData[0] >> 3) & 1) == 1;  // Bit 3 --> EE
//		  bool rr_interval = ((pData[0] >> 4) & 1) == 1;  // Bit 4 --> RR

		if ((pData[0] & 1)) {		// LSB flag = 16 bit or 8bit
			hr |= (pData[2] << 8);
		}
		Serial.printf("❤️ Heart rate: %d bpm\n", hr);
//		  sdl.logf(SDLogger::Log_Info, SDLogger::TAG_HR, "%sbit Data HR: %d bpm - EE: %s - RR: %s\n", data8Bit?"8":"16", hr, ee_status?"true":"false", rr_interval?"true":"false");
		break;

	default:
		Serial.println(pBLERemoteCharacteristic->toString().c_str());
		Serial.printf("Notify Callback for %d\n", ctype);
	}

}

void BLEDevices::loop() {
	if (millis() < 6000) return;
	for (uint16_t c = 0; c < DEV_COUNT; c++) {
		if (doConnect[c]) connectToServer(static_cast<EDevType>(c));
		if (connState[c] == CONN_CONNECTED && !pClient[c]->isConnected()) {
			connState[c] = CONN_LOST;
			Serial.print(DEV_EMOJI[c]);
			Serial.println("⚠️ Lost connection.");
		}
	}
}
