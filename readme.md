# Smart Chair Prototype

This repository contains the code for a smart chair prototype designed to monitor and evaluate the user's sitting posture using LDT0-028K sensors.

## Contents

- `sensor.ino`: Arduino sketch for data collection and processing.
- `transmit.ino`: Arduino sketch for data upload.
- `ESP8266WIFICLIENT.h`: Library for ESP8266 WiFi client.

## Getting Started

### Prerequisites

- Arduino IDE installed.
- ESP8266 board package installed in Arduino IDE.

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/smart-chair.git
  - Open the Arduino IDE and load the sketches (sensor.ino and transmit.ino).
  - Install the required libraries.

### Usage
-Upload sensor.ino to the microcontroller responsible for data collection.
-Upload transmit.ino to the microcontroller responsible for data upload.
-Ensure that the ESP8266WIFICLIENT library is correctly installed.
### Configuration
- Modify the code to customize parameters such as WiFi credentials, data processing algorithms, and transmission intervals.
### Contributing
-Contributions are welcome! Please follow the contribution guidelines.

### License
This project is licensed under the MIT License.
