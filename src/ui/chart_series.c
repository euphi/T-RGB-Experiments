/*
 * chart_series.c
 *
 *  Created on: 31.12.2022
 *      Author: ian
 */

#include "chart_series.h"

static lv_chart_series_t * ser_v;
static lv_chart_series_t * ser_v_minute;
static lv_chart_series_t * ser_per_minute;

void chart_init() {
	lv_obj_t* chart = ui_ScreenChart_Chart1;
	lv_chart_set_point_count(chart, 384);		// Size 384 data points (Size of Chart area)
	lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_SHIFT);
	lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 350, 450);
	lv_chart_set_range(chart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
	lv_chart_set_axis_tick(chart, LV_CHART_AXIS_PRIMARY_Y, 10, 2, 4, 2, true, 60);
	ser_v = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
	ser_v_minute = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
	ser_per_minute = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_SECONDARY_Y);
	//lv_obj_set_style_outline_width(chart, 1, LV_STATE_DEFAULT);
}

float chart_add_voltage(const float v, uint8_t l) {
	static uint32_t count = 0;
	static float avg = 0.0;
	lv_obj_t * chart = ui_ScreenChart_Chart1;
	lv_chart_set_next_value(chart, ser_v, (int16_t) (v * 100));
	if (++count % 60 == 0) {
		avg = 0.0;
		int16_t cur_point = ser_v->start_point;
		for (uint8_t c=0 ; c<60; c++) {
			if (--cur_point < 0) cur_point = ((lv_chart_t *)chart)->point_cnt - 1;
			float v1 = ser_v->y_points[cur_point] / 100.0;
			avg += v1;
			printf("%.2f - %d - %.2f\t", v1,c, avg);
		}
		printf("\nSum: %.2f\n", avg);
		avg = avg/60.0;
		printf("\nAvg: %.2f\n", avg);
		lv_chart_set_next_value(chart, ser_v_minute, (int16_t) (avg * 100));
		lv_chart_set_next_value(chart, ser_per_minute, l);
	}
    lv_chart_refresh(chart);
    char str[32];
    sprintf(str, "%.2fV - Avg %.2fV\n%d%%", v, avg, l);
    lv_label_set_text(ui_ScreenChart_LabelV, str);
    return avg;
}
