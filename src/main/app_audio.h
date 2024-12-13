
/*
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#pragma once
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"

typedef enum{
    SOUND_TYPE_KNOB,
    SOUND_TYPE_SNORE,
    SOUND_TYPE_WASH_END_CN,
    SOUND_TYPE_WASH_END_EN,
    SOUND_TYPE_FACTORY,
    //EDIT: Add sound for light control
    SOUND_TYPE_LIGHT_OFF,
    SOUND_TYPE_LIGHT_LEVEL_25,
    SOUND_TYPE_LIGHT_LEVEL_50,
    SOUND_TYPE_LIGHT_LEVEL_75,
    SOUND_TYPE_LIGHT_LEVEL_100,
}PDM_SOUND_TYPE;

esp_err_t audio_force_quite(bool ret);

esp_err_t audio_handle_info(PDM_SOUND_TYPE voice);

esp_err_t audio_play_start();

extern EventGroupHandle_t lighting_event_group;
extern SemaphoreHandle_t light_config_mutex;