# Swamp Cooler Project

## Overview
This project demonstrates an evaporative cooling system (swamp cooler) implemented using an Arduino Mega 2560. The system efficiently manages temperature and humidity through real-time monitoring and control. It features state transitions, error handling, and logging functionalities.

## Features
- **Temperature and Humidity Monitoring**: Uses a DHT11 sensor to measure environmental conditions.
- **Water Level Monitoring**: Detects low water levels using a water sensor.
- **Fan Motor Control**: Activates or deactivates the fan based on temperature thresholds.
- **Error Handling**: Handles low water conditions and other potential errors with clear alerts.
- **State Machine Implementation**: Operates across four states (DISABLED, IDLE, RUNNING, ERROR).
- **Event Logging**: Logs all state transitions with timestamps using an RTC module.
- **Serial Monitor Output**: Displays system stats and logs for testing and demonstration.

## Components
1. **Arduino Mega 2560**
2. **DHT11 Sensor**: For temperature and humidity readings.
3. **Water Level Sensor**: Monitors water reservoir levels.
4. **Fan Motor**: Controlled based on the temperature.
5. **RTC Module (DS1307)**: Logs events with timestamps.
6. **16x2 LCD Display**: For displaying stats (LCD non-functional in this project; serial monitor used as a substitute).
7. **LEDs**: Indicate the current system state.
8. **Push Buttons**: For START, STOP, and RESET operations.

## System States
1. **DISABLED**: Initial state, no sensors active; transitions to IDLE with the START button.
2. **IDLE**: Monitors environmental conditions; transitions to RUNNING or ERROR based on conditions.
3. **RUNNING**: Fan motor active; transitions to IDLE or ERROR based on temperature or water level.
4. **ERROR**: Indicates system issues (e.g., low water level); requires RESET to recover.

## How to Use
1. Connect all components as described in the [schematic](#).
2. Upload the code from this repository to the Arduino Mega 2560.
3. Power on the system and use the START button to enable it.
4. Monitor stats and logs via the serial monitor.

## Project Files
- **Code**: [swamp_cooler.ino](https://github.com/1103-Morris-Johnnie/CPE-FINAL/blob/main/final.ino)
- **Technical Documentation**: [Link to PDF](https://github.com/1103-Morris-Johnnie/CPE-FINAL/blob/main/Swamp%20Cooler%20Project_%20Technical%20Documentation.pdf)
- **Demonstration Video**: UPLOAD THROUGH WEBCAMPUS
- **Schematic and Images**: [IMAGE 1](https://github.com/1103-Morris-Johnnie/CPE-FINAL/blob/main/image%201.jpg)  [IMAGE 2](https://github.com/1103-Morris-Johnnie/CPE-FINAL/blob/main/image%202.png)

## Notes
- Due to a damaged LCD, all outputs are redirected to the serial monitor for this project.
- The project has been thoroughly tested, and all features (except LCD output) function as intended.

## Lessons Learned
- Importance of handling hardware failures.
- Effective use of a state machine for robust system design.
- Leveraging serial communication for debugging and as a fallback solution.

## Contributors
- Johnnie Morris
