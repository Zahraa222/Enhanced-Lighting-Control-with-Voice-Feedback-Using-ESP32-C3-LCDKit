## ESP32-C3-LCDKit: Enhanced Lighting Control with Voice Feedback 

This project demonstrates the use of the ESP32-C3-LCDKit microcontroller to test and process input from a rotary position sensor (knob). This was built upon the knob example provided.  The system was developed using the ESP-IDF 5.3 framework, emphasizing key operating systems concepts such as concurrency control, task scheduling, and resource management. The rotary position sensor’s data is processed in real time to control a lighting system and provide feedback to the user through voice announcements. This feature will announce the current lighting level whenever the knob is rotated to adjust brightness.

### Features:

* Lighting Control: Adjust brightness using a rotary knob.
* Voice Announcements: Announce current lighting levels in real-time.
* Multitasking: Tasks operate concurrently with robust synchronization mechanisms.

### Deliverables
* Source Code: Located in the /src folder.
* Technical Documentation: Available in PDF format in the /docs folder.
* Demonstration Video: Located in the /videos folder or linked in the README.

### Repository Structure:
* /src: All source code files.
* /docs: Technical documentation (PDF format).
* /media: Media assets used in the project.
* /videos: Demonstration video link or file.

### Software Required:

* The ESP-IDF v5.0 or later is required to use this example. For using the branch of ESP-IDF, the latest branch `release/v5.1` is recommended. For using the tag of ESP-IDF, the tag `v5.1.2` or later is recommended.
* Please follow the [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/index.html) to set up the development environment.

### Hardware Required:

* An ESP32-C3-LCDkit development board with subboard and speaker
* An USB Type-C cable for Power supply and programming

### Build and Flash

* 1. Configure the project: `idf.py menuconfig`

* 2. Build and flash the firmware: `idf.py build` and `idf.py flash`

* 3. Monitor the output: `idf.py monitor`

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

### GUI Control

1. In "Root" page, short press to enter "App" page and long press to restore factory settings.
2. In "App" page, short press to confirm and long press to exit.



## Troubleshooting

* Program upload failure
    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.
    * Error message with `A fatal error occurred: Could not open /dev/ttyACM0, the port doesn't exist`: Please first make sure the development board connected, then make board into "Download Boot" by following steps:
        1. keep press the knob
        2. short press "REST(SW3)" button
        3. release the knob
        4. upload program and reset
* Program runtime failure
    * Error message with `i2s_common: i2s_channel_disable : the channel has not been enabled yet`: This is a normal message, please ignore it.


