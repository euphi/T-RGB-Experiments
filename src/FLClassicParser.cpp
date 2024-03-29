/*
 * FLClassicParser.cpp
 *
 *  Created on: 19.02.2023
 *      Author: ian
 */

#include <FLClassicParser.h>

FLClassicParser::FLClassicParser(uint8_t polePair, uint16_t circum_mm):
dist_m_per_pulse((float)circum_mm/(float)polePair / 1000.0),
kmh_per_pulse_per_s(dist_m_per_pulse * 3600 / 1000.0),
lastUpdate(millis())
{

}

void FLClassicParser::updateFromString(const String &flStr) {
	lastUpdate = millis();
	//sdl.logf(SDLogger::Log_Debug, SDLogger::TAG_FL, "ℹ️ Rvcd string from BT: %s", bufferSerial);

//	Serial.printf("Received string:\n%s\n", flStr.c_str());
//	Serial.printf("First chars: '%x' '%x' '%x' \n", flStr[0], flStr[1], flStr[2]);
//	Serial.printf("First chars: '%c' '%c' '%c' \n", flStr[0], flStr[1], flStr[2]);
//	Serial.printf("Substring: '%s'\n", flStr.substring(0,3));
	int8_t scanCt = 0;
	float speed_f = NAN;
	uint8_t scanFLC_id;
	uint32_t scanFLC_buffer[5];

	if (flStr.startsWith("$FL")) {
		uint16_t pulses_per_s, temperature, pressure, height, gradient;

		int8_t cons_on_off;
		int8_t	stufe;			// -1: Dauer-Aus, 0: aus, 1-4: nach Geschwindigkeit

		int32_t timecounter;
		int32_t pulsecounter;
		int32_t micropulsecounter;
		uint16_t batterie[3];	// in mV

		int16_t  batt_current;	// in mA
		int16_t  cons_current;  // in mA
		uint8_t  batt_perc;		// in %
		int16_t int_temp;		// in 1/10°C (or K?)
		int16_t timeout;

		uint32_t flags;
		uint32_t hm_total;

		//Forumslader V5 uses $FL5, $FLB and $FLC only
		switch(flStr.charAt(3)) { //                                                                                                                 Strom in mA? // Verbraucherstrom int. Temp Verbraucher Timeout
		case '5':  // $FL5,08c800,0,0,4158,4161,4162,-18,0,294,1,233,3679,13231,25897;                        $FL5,08c800,     0,        0,       4158,        4161,        4162,       -18,         0,           294,        1,          233,        3679,             13231,         25897;
			scanCt = sscanf(flStr.c_str(), "$FL5,%lx,%hhd,%hd,%hd,%hd,%hd,%hd,%hd,%hd,%hhd,%hd,%d,%d,%d\n", &flags, &stufe, &pulses_per_s, &batterie[0],&batterie[1],&batterie[2],&batt_current,&cons_current,&int_temp,&cons_on_off,&timeout,&micropulsecounter,&pulsecounter,&timecounter);
			if (scanCt != 14) Serial.println("❌ Not all fields scanned");
			Serial.printf("[%x] Batteries: %dmV %dmV %dmV\n", scanCt, batterie[0], batterie[1], batterie[2]);
			Serial.printf("Flags: %x\n", flags);
			if (stateCB) stateCB(FL_STATE_CONNECTED, flags);
			speed_f = pulses_per_s * hmh_per_pulse;
			//FIXME: stats.updateDistance(ceil((pulsecounter * 4096 + micropulsecounter) * m_per_pulse));
			//FIXME: speed = static_cast<uint16_t>(speed_f);
			//FIXME: stats.updateSpeed(speed/10.0);
			//Serial.printf("Speed: %.1f - %d ", speed_f, speed);
			break;
		case 'B': // $FLB,850,98591,2731,0;
			scanCt = sscanf(flStr.c_str(), "$FLB,%hd,%d,%hd,%hd\n", &temperature, &pressure,&height,&gradient);
			if (scanCt != 4) Serial.println("❌ Not all fields scanned");
			Serial.printf("[%x] Temp: %.02f\tPressure: %.01f\tHeight: %.01f\tGradient: %d\n", scanCt, temperature/10.0, pressure/100.0, height/10.0, gradient);
			break;
		case 'C':
			scanCt = sscanf(flStr.c_str(), "$FLC,%hhd,%d,%d,%d,%d,%d\n", &scanFLC_id, &scanFLC_buffer[0],&scanFLC_buffer[1],&scanFLC_buffer[2],&scanFLC_buffer[3],&scanFLC_buffer[4]);
			switch (scanFLC_id) {
			case 0: // $FLC,0,0,0,200,3798,26;
				//Tour
				//FIXME: stats.updateFLStoredDistance(sumType, scanFLC_buffer[4]);
				break;
			case 1: // $FLC,1,0,0,200,3798,26;
				//Trip
				//FIXME: stats.updateFLStoredDistance(sumType, scanFLC_buffer[4]);
				break;
			case 2: // $FLC,2,478561,0,200,0,200;
				break;
			case 3: // $FLC,3,8126,0,0,1799,0;
				break;
			case 4: // $FLC,4,48,48,0,0,0;
				break;
			case 5: // $FLC,5,1870,100,1667,36,73053775;   $FLC,5,1921,99,1667,37,74684176;  // StartCounter, Batt%, fullCap, CycleCount, Acc
				batt_perc = scanFLC_buffer[1];
				break;

			}
			// Ignore for now (Total data)
			break;
		default:
			Serial.printf("❌ Unknown FL-ID '%c'\n", flStr.charAt(3));
		}
		//sdl.log(SDLogger::Log_Info, SDLogger::TAG_RAW_NMEA, bufferSerial);

	} else {
		Serial.println("❌ Unknown String identifier");
	}
}
