/*
 * chart_series.h
 *
 *  Created on: 31.12.2022
 *      Author: ian
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include "ui.h"

void chart_init();
float chart_add_voltage(const float v, uint8_t l);

#ifdef __cplusplus
} /*extern "C"*/
#endif
