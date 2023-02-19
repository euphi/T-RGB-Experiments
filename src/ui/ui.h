// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

extern lv_obj_t * ui_S1Main;
extern lv_obj_t * ui_S1LabelTitle;
extern lv_obj_t * ui_S1ArcSpeed;
extern lv_obj_t * ui_S1ArcAvg;
extern lv_obj_t * ui_S1BarPuls;
extern lv_obj_t * ui_S1BarPulsLabel;
extern lv_obj_t * ui_S1LabelSpeed;
extern lv_obj_t * ui_S1PanelIcons;
void ui_event_S1ImgIconBTClassic(lv_event_t * e);
extern lv_obj_t * ui_S1ImgIconBTClassic;
void ui_event_S1ImgIconBLEhrm(lv_event_t * e);
extern lv_obj_t * ui_S1ImgIconBLEhrm;
void ui_event_S1ImgIconWifi(lv_event_t * e);
extern lv_obj_t * ui_S1ImgIconWifi;
void ui_event_S1RollerStatMode(lv_event_t * e);
extern lv_obj_t * ui_S1RollerStatMode;
void ui_event_S1PanelStat(lv_event_t * e);
extern lv_obj_t * ui_S1PanelStat;
extern lv_obj_t * ui_S1PStatLTitle;
extern lv_obj_t * ui_S1PStatLAvg;
extern lv_obj_t * ui_S1PStatLAvgVar;
extern lv_obj_t * ui_S1PStatImgAvgUnit;
extern lv_obj_t * ui_S1PStatLGradientVar;
extern lv_obj_t * ui_S1PStatLGradient;
extern lv_obj_t * ui_S1PStatLspdMax;
extern lv_obj_t * ui_S1PStatLspdMaxVar;
extern lv_obj_t * ui_S1PStatImgSpdMaxUnit;
extern lv_obj_t * ui_S1PStatLDist;
extern lv_obj_t * ui_S1PStatLDistVar;
extern lv_obj_t * ui_S1PStatLTime;
extern lv_obj_t * ui_S1PStatLTimeVar;
extern lv_obj_t * ui_S1BarPowerMode;
extern lv_obj_t * ui_S1BarBatt;
extern lv_obj_t * ui_S1LabelClock;
void ui_event_ScreenWifi(lv_event_t * e);
extern lv_obj_t * ui_ScreenWifi;
extern lv_obj_t * ui_SWifiLabelIPAddr;
void ui_event_ScreenWifi_Slider1(lv_event_t * e);
extern lv_obj_t * ui_ScreenWifi_Slider1;
extern lv_obj_t * ui_ScreenWifi_Label8;
void ui_event_SWifiButtonStandby(lv_event_t * e);
extern lv_obj_t * ui_SWifiButtonStandby;
extern lv_obj_t * ui_ScreenWifiButtonLabelStandby;
void ui_event_ScreenChart(lv_event_t * e);
extern lv_obj_t * ui_ScreenChart;
extern lv_obj_t * ui_ScreenSettings_Panel2;
extern lv_obj_t * ui_ScreenChart_Chart1;
extern lv_obj_t * ui_ScreenChart_LabelV;

void ui_ev_bright(lv_event_t * e);
void ui_ev_standby(lv_event_t * e);

LV_IMG_DECLARE(ui_img_1672049344351_png);    // assets/1672049344351.png
LV_IMG_DECLARE(ui_img_1672052474193_png);    // assets/1672052474193.png
LV_IMG_DECLARE(ui_img_1672050212073_png);    // assets/1672050212073.png
LV_IMG_DECLARE(ui_img_1719627537);    // assets/equation (1).png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
