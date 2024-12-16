# Swamp Cooler Project Schematic

## Arduino Mega 2560 Connections
The Arduino Mega is the central controller for the project.

| **Pin**       | **Connection Description**                  |
|---------------|---------------------------------------------|
| **5V**        | Connect to the positive power rail on the breadboard. |
| **GND**       | Connect to the ground rail on the breadboard. |

## LCD (16x2 Display) Connections
| **LCD Pin** | **Function**        | **Connection**             |
|-------------|---------------------|----------------------------|
| **1 (VSS)** | Ground              | Connect to GND.            |
| **2 (VDD)** | Power               | Connect to 5V.             |
| **3 (VO)**  | Contrast Control    | Middle pin of a potentiometer (other pins to 5V and GND). |
| **4 (RS)**  | Register Select     | Connect to Arduino pin `12`. |
| **5 (RW)**  | Read/Write          | Connect to GND (write-only mode). |
| **6 (E)**   | Enable              | Connect to Arduino pin `11`. |
| **11 (D4)** | Data Bit 4          | Connect to Arduino pin `5`. |
| **12 (D5)** | Data Bit 5          | Connect to Arduino pin `4`. |
| **13 (D6)** | Data Bit 6          | Connect to Arduino pin `3`. |
| **14 (D7)** | Data Bit 7          | Connect to Arduino pin `2`. |
| **15 (A)**  | Backlight Power     | Connect to 5V via a 220Ω resistor. |
| **16 (K)**  | Backlight Ground    | Connect to GND.             |

## DHT11 Sensor (Temperature and Humidity)
| **DHT11 Pin** | **Function**       | **Connection**             |
|---------------|--------------------|----------------------------|
| **1 (VCC)**   | Power              | Connect to 5V.             |
| **2 (DATA)**  | Data Signal        | Connect to Arduino pin `2`.|
| **3 (NC)**    | Not Connected      | Leave unconnected.         |
| **4 (GND)**   | Ground             | Connect to GND.            |

## RTC Module (Real-Time Clock)
| **RTC Pin** | **Function**       | **Connection**             |
|-------------|--------------------|----------------------------|
| **VCC**     | Power              | Connect to 5V.             |
| **GND**     | Ground             | Connect to GND.            |
| **SDA**     | I2C Data Line      | Connect to Arduino pin `20` (SDA). |
| **SCL**     | I2C Clock Line     | Connect to Arduino pin `21` (SCL). |

## Fan Motor
| **Motor Driver Pin** | **Function**       | **Connection**             |
|-----------------------|--------------------|----------------------------|
| **VCC**              | Power              | Connect to an external power source (e.g., 9V battery or adapter). |
| **GND**              | Ground             | Connect to GND and share a common ground with Arduino. |
| **OUT1 & OUT2**      | Motor Terminals    | Connect to the fan motor terminals. |
| **IN1**              | Speed Control PWM  | Connect to Arduino pin `9`.          |

## Stepper Motor for Vent Control
| **Stepper Driver Pin** | **Function**      | **Connection**             |
|-------------------------|-------------------|----------------------------|
| **VCC**                | Power             | Connect to 5V.             |
| **GND**                | Ground            | Connect to GND.            |
| **IN1**                | Stepper Phase 1   | Connect to Arduino pin `5`. |
| **IN2**                | Stepper Phase 2   | Connect to Arduino pin `6`. |
| **IN3**                | Stepper Phase 3   | Connect to Arduino pin `7`. |
| **IN4**                | Stepper Phase 4   | Connect to Arduino pin `8`. |

## Buttons
### Start Button
| **Button Terminal** | **Connection**             |
|----------------------|----------------------------|
| **1**               | Connect to GND.            |
| **2**               | Connect to Arduino pin `3`.|

### Reset Button
| **Button Terminal** | **Connection**             |
|----------------------|----------------------------|
| **1**               | Connect to GND.            |
| **2**               | Connect to Arduino pin `4`.|

## Water Level Sensor
| **Water Sensor Pin** | **Function**       | **Connection**             |
|-----------------------|--------------------|----------------------------|
| **VCC**              | Power              | Connect to 5V.             |
| **GND**              | Ground             | Connect to GND.            |
| **OUT**              | Analog Output      | Connect to Arduino analog pin `A0`. |

## LED Indicators
### LED States
| **LED Color** | **State**   | **Arduino Pin** | **Connection**             |
|---------------|-------------|-----------------|----------------------------|
| **Yellow**    | DISABLED    | `10`            | Connect via a 220Ω resistor to GND. |
| **Green**     | IDLE        | `11`            | Connect via a 220Ω resistor to GND. |
| **Red**       | ERROR       | `12`            | Connect via a 220Ω resistor to GND. |
| **Blue**      | RUNNING     | `13`            | Connect via a 220Ω resistor to GND. |

## Power Rails
- Use the breadboard’s **positive rail** for 5V connections and **ground rail** for GND connections.
- For components like the **fan motor**, make sure to connect a separate external power source to Arduino to avoid overloading the Arduino.
