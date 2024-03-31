# Household-Fridge-Data-Logging-Project
## Overview
This assignment aims to measure the current and power consumption of a typical household refrigerator using an Arduino UNO. By logging and analyzing this data, it becomes possible to evaluate the energy usage of the appliance and identify ways to reduce consumption levels for energy conservation.

### Goals:
- Gather sensor data
- Save data on an SD card
- Evaluate the data
- Provide suggestions/advice on reducing power consumption

## Bill of Materials (BOM)
| BOM level | Part name           | Description                                                       | Quantity | Cost  |
|-----------|---------------------|-------------------------------------------------------------------|----------|-------|
| 1         | Arduino Uno Rev3    | [Arduino Uno Rev3 with USB Cable](https://eph.com.pk/product/arduino-uno-r3-with-usb-cable/) | 1        | 2000  |
| 2         | CT Sensor ACS712 30A | [CT Sensor ACS712 30A](https://images.app.goo.gl/7JVoST5DhPwy8Hgb9) | 1        | 450   |
|           | DS3231 RTC Module  | [DS3231 RTC Module](https://epro.pk/product/ds3231-rtc-real-time-clock-in-pakistan/) | 1        | 900   |
|           | Micro SD Card Module | [Micro SD Card Module](https://www.daraz.pk/products/microsd-card-module-for-arduino-i235815995.html) | 1        | 180   |
| 4         | USB Cable Adapter (for Arduino) | [Adapter for Arduino](https://www.amazon.com/Adapter-Arduino-Elliptical-Recumbent-Positive/dp/B07ZM46WKF) | 1        | 300   |
|           | SD Card (SanDisk Ultra microSDXC UHS-1 16GB) | [SD Card](https://images.app.goo.gl/8wJooapdbi4AFwBK8) | 1        | 800   |
|           | RTC Cell            | [RTC Cell](https://images.app.goo.gl/teUgJfZ9HRS5sY4W7)            | 1        | 300   |
| 5         | Extension Cable (Female-Male) | [Extension Cable](https://images.app.goo.gl/4f8qJwKkoipEBQbCA)    | 1        | 300   |
|           | Wire Cutter and Stripper | [Wire Cutter and Stripper](https://images.app.goo.gl/ZixNc27nAmEd2aUb6) | 1        | 600   |
|           | Jumper wires (Male-Female and Female-Male) | [Jumper wires](https://www.embededstudio.com/product/jumper-wires-male-female/) | 8        | 140   |
|           | **Total Price**           |                                                                   |          | **5970** |

## Arduino UNO
The Arduino UNO has various digital and analog pins used for different purposes. It is the main microcontroller board used in this data logging system.

## Schematic
Proteus software was used to create the schematic for the data logging system. The schematic includes modules for RTC, SD card, and ACS712 CT sensor. Hardware connections are made according to this schematic.

## Construction
### Connections:
- DS3231 RTC Module: VCC, GND, SDA, SCL connected to Arduino UNO
- Micro SD Card Module: VCC, GND, MISO, MOSI, SCK, CS connected to Arduino UNO
- CT Sensor ACS712 30A: Vout, GND, VCC connected to Arduino UNO

## Working
The Arduino UNO serves as the brain of the data logging system. The DS3231 RTC module tracks the current date and time, connected to the Arduino UNO via I2C communication. The MicroSD Card module stores the data, connected to the Arduino UNO via SPI communication. The ACS712 30A current sensor measures the current, connected to the Arduino UNO analog pin A1. The data (current and power consumption) is logged to a CSV file on the SD card every hour at 20-minute intervals. The file includes values for current, voltage, date, time, and power. After 24 hours, the data logging stops.

## Power Solutions
The system can be powered by household electricity. In case of load shedding, alternative power sources like rechargeable batteries, power banks, or solar panels can be used.

### Note:
The total power consumption of the system can be calculated to determine the battery capacity needed for field deployable systems.
