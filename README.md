# Enhanced Lighting Control Panel with Voice Announcements

This project enhances the functionality of the Knob Panel Example for the ESP32-C3-LCDKit by adding voice announcements and robust concurrency control. The system is designed to provide auditory feedback for lighting level changes while ensuring responsive user interaction through multitasking.

## Features

1. **Voice Announcements**:
   - Audible feedback for lighting levels (0%, 25%, 50%, 75%, 100%).
   - Audio files are played from SPIFFS storage.

2. **Concurrent Task Management**:
   - Separate tasks for lighting control and voice announcements using FreeRTOS.
   - Ensures smooth operation and responsiveness.

3. **Concurrency Control**:
   - Mutex (`light_config_mutex`) protects shared resources.
   - Event Groups enable signaling between tasks for lighting level changes.

4. **User Interaction**:
   - Intuitive knob-based brightness adjustment.
   - Responsive LED panel reflecting the current brightness level.

## System Architecture

The system is divided into the following key components:

1. **Lighting Control Task**:
   - Adjusts brightness levels based on user input.
   - Sets event bits in the `lighting_event_group` to trigger voice announcements.

2. **Voice Announcement Task**:
   - Waits for event bits and plays corresponding audio files.
   - Runs independently, ensuring responsiveness.

3. **Concurrency Mechanisms**:
   - `xSemaphoreCreateMutex`: Ensures safe access to `light_set_conf`.
   - `xEventGroupSetBits` and `xEventGroupWaitBits`: Handle communication between tasks.

### Architecture Diagram

![image](https://github.com/user-attachments/assets/77ec455c-d885-433f-84ad-c07ee499062c)

### Flowchart Diagram

![image](https://github.com/user-attachments/assets/ae4136d0-ac61-469d-b349-a3452f273d77)


## Setup Instructions
### Hardware
* ESP32-C3-LCDKit
* Compatible LCD Display
* Knob Panel
* LEDs for Brightness Control
* Speaker for Audio Playback
### Software
* ESP-IDF (v5.3.1 or later)
* Knob Panel Example from ESP32-C3-LCDKit repository

## Usage
### Building and Flashing:

* Clone the repository and navigate to the project directory.
* Configure the project using idf.py menuconfig to set SPIFFS storage paths and audio settings.
* Build and flash the project:
   - idf.py build
   - idf.py flash
### Running the System:

* Rotate the knob to adjust brightness.
* Observe the LED panel brightness changes and listen for corresponding voice announcements.

## Code Walkthrough
### Lighting Control
The light_2color_layer_timer_cb function in ui_light_2color.c adjusts brightness and sets event bits:
```
xSemaphoreTake(light_config_mutex, portMAX_DELAY);

switch (light_set_conf.light_pwm) {
    case 0:
        xEventGroupSetBits(lighting_event_group, BIT0);
        break;

    case 25:
        xEventGroupSetBits(lighting_event_group, BIT1);
        break;

    // Additional cases for other levels
}
xSemaphoreGive(light_config_mutex);
```
### Voice Announcements
The voice_announcement_task function in app_audio.c waits for event bits and plays audio:
```
EventBits_t bits = xEventGroupWaitBits(
    lighting_event_group,
    (BIT0 | BIT1 | BIT2 | BIT3 | BIT4),
    pdTRUE,
    pdFALSE,
    portMAX_DELAY
);

if (bits & BIT0) audio_handle_info(SOUND_TYPE_LIGHT_OFF);
if (bits & BIT1) audio_handle_info(SOUND_TYPE_LIGHT_LEVEL_25);
```
### Concurrency Control
Mutex ensures safe access to shared resources:
```
light_config_mutex = xSemaphoreCreateMutex();
if (light_config_mutex == NULL) {
    ESP_LOGE("Light", "Failed to create light_config_mutex");
    abort();
}
```
## Demonstration Video
[Watch the demo on YouTube](https://www.youtube.com/watch?v=Gphw5YrJCwE)

## Acknowledgments
* Based on the Knob Panel Example from the ESP32-C3-LCDKit repository.
* Built using ESP-IDF.
For further details, refer to the documentation in the /docs folder.
