/*
 * chart_series.c
 *
 *  Created on: 31.12.2022
 *      Author: ian
 */

#include "chart_series.h"

static lv_chart_series_t * ser_v;

void chart_init() {
	lv_obj_t* chart = ui_ScreenChart_Chart1;
	lv_chart_set_point_count(chart, 120);		// Size 120 data points (1 per 30sec)
	lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_SHIFT);
	lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 400, 500);
	ser_v = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
}

void chart_add_voltage(const float v) {
	lv_obj_t* chart = ui_ScreenChart_Chart1;
	lv_chart_set_next_value(chart, ser_v, (int16_t) (v * 100));
    lv_chart_refresh(chart);
}
