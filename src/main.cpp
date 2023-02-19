#include "SD_MMC.h"
#include "Wire.h"

#include "ui/ui.h"
#include "ui/ui_FL.h"
#include "ui/chart_series.h"

#include "lvgl.h"
#include "pin_config.h"
#include <Arduino.h>

#include <TRGBSuppport.h>
#include "uifacade.h"

#include "freertos/ringbuf.h"

TRGBSuppport trgb;
ui_facade ui;

#include "BLEDevices.h"
BLEDevices bleDevs;



#include <Battery.h>
Battery batt = Battery(3000, 4200, BAT_VOLT_PIN);

#include <WiFi.h>

const char* ntpServer = "pool.ntp.org";
const char* ssid = "IA216oT";
const char* password = "SwieSecurity";

#include <DateTime.h>


void ui_ev_standby(lv_event_t * e)
{
	trgb.deepSleep();
}

void ui_ev_bright(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
	//int sliderValue = ( ( (int)lv_slider_get_value(slider)) << 8 ) / 100 - 1;
	int sliderValue = (int)lv_slider_get_value(slider);

	Serial.printf("New bright value %d.\n", sliderValue);
	if (sliderValue == 255) {
		digitalWrite(EXAMPLE_PIN_NUM_BK_LIGHT, EXAMPLE_LCD_BK_LIGHT_ON_LEVEL);
	}
	analogWrite(EXAMPLE_PIN_NUM_BK_LIGHT, sliderValue);
}


void listDir(const char * dirname, uint8_t levels){
  Serial.printf("📁 Listing directory: %s\n", dirname);

  File root = SD_MMC.open(dirname);
  if(!root){
    Serial.println("Failed to open directory");
    return;
  }
  if(!root.isDirectory()){
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while(file){
    if(file.isDirectory()){
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if(levels){
    	  String dir(dirname);
    	  dir += "/";
    	  dir += file.name();
        listDir(dir.c_str(), levels -1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}


void setup() {
  Serial.begin(115200);
  Serial.setTxTimeoutMs(1);	// workaround to minimize blocking time for output to HWCDCSerial (Serial), if no host is connected.
  Serial.println("Setup Serial");

  trgb.init();
  TRGBSuppport::print_chip_info();
  TRGBSuppport::scan_iic();

  trgb.SD_init();
  batt.begin(3300, 2.0/4.0 * 1.03, &sigmoidal); // divider ratio is 2, but ESP32-S3 has 4096 bit DAC instead of 1024, so an additional division by 4 is needed --> 0.5 ratio  + 3% error correction (individual setting?)

  bleDevs.setup();


  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  configTime(3600, 3600, "pool.ntp.org");

  listDir("/BTTacho", 4);
  ui_init();
  ui_init_ScrFL();
  chart_init();

  ui.updateIP("Connecting..");

  // Glue modules together
  bleDevs.getFlparser().setStateCb([](FLClassicParser::EFLConnState cstate, uint32_t flags) {Serial.printf("FL-FLAGS in main: %x\n", flags);ui_ScrFLUpdateFlags(flags);});
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint32_t Millis;
  static bool wifiInitialized = false;
  static uint16_t ani_counter = 0;

  static uint16_t speedSim = 200;
  static uint8_t bat_level = 0;

  lv_timer_handler();

  bleDevs.loop();

  if (millis() - Millis > 500) {
	ani_counter++;
	Millis=millis();
    //float v = trgb.getBatVoltage();
    uint16_t v_int = batt.voltage();
    float v = v_int / 1000.0;
    uint16_t v_avg = chart_add_voltage(v, bat_level) * 1000;
    bat_level = batt.level(v_avg);

    time_t now;
    time(&now);
	String time_str = DateFormatter::format(DateFormatter::TIME_ONLY,now);
    ui.updateClock(time_str);

    speedSim += (rand() % 20) - 10;
    ui.updateSpeed(speedSim);

    // Handle Wifi
	if (!wifiInitialized) {
		if (WiFi.status() == WL_CONNECTED) {
			wifiInitialized = true;
			ui.updateIP(WiFi.localIP().toString());
			// Setup Web Server
			//setupWebserver();
		} else if (ani_counter > 10 /*5s*/) {
			wifiInitialized = true;
			Serial.println("Not connected to Wifi - disabling it");
			ui.updateIP(String("WiFi disabled"));
			WiFi.mode(WIFI_MODE_NULL);
			WiFi.setSleep(WIFI_PS_MAX_MODEM);
			WiFi.setSleep(true);
		}
	} else if (WiFi.status() == WL_CONNECTION_LOST) {
		ui.updateIP(String("connection lost"));
		Serial.println("Wifi connection lost - disabling it to save power");
		WiFi.mode(WIFI_MODE_NULL);
		WiFi.setSleep(WIFI_PS_MAX_MODEM);
		WiFi.setSleep(true);
	}
  } else {
	  delay(2);
  }
}
