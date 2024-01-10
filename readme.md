# Smart Chair Prototype

This repository hosts the code for an innovative smart chair prototype, designed to monitor and correct sitting posture using LDT0-028K sensors. This project aims to mitigate the health risks associated with prolonged sedentary behavior by providing real-time feedback on posture.

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
- You need to connect the sensor to the arduino correctly and power the sensor correctly. Remember not to connect the TX/RX interface in advance when burning code.
- Make sure your sensitive data is stored in separate files, and make sure they are correct.
- Deploy the app.js file on the server. It is best to start it separately through screen for easy management. You can also see the specific work of the js program here.
- Now connect all the components, power them up, and see the results.
### Configuration
- Customize parameters such as WiFi credentials and data processing algorithms in the code.
- Adjust transmission intervals as needed.

### Critical Analysis and Future Directions
- The current prototype faces challenges in continuous pressure measurement sensitivity. Future improvements include advanced sensor integration and enhanced data processing techniques.
- Consider the use of ESP32 for better performance and integrated WiFi, along with FSR402 sensors for improved accuracy.

### Problem solving
- You can use postman to test whether the server's js program is working properly.
### Contributing
-Contributions are welcome! Please follow the contribution guidelines.

### License
This project is licensed under the MIT License.
