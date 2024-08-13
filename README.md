# Sensiboo-DEV

Arduino BLE 33 sense code for gesture recognition 

## Overview

This project involves the development of a gesture recognition device using the Arduino Nano 33 BLE Sense. The device leverages the onboard sensors, particularly the 9-axis IMU, to detect and recognize gestures. The recognized gestures can be used to trigger various actions or send commands wirelessly via Bluetooth Low Energy (BLE).

## Features

- **Gesture Recognition:** Utilizes the onboard IMU to detect and classify gestures.
- **Bluetooth Communication:** Sends recognized gestures to a paired device via BLE.
- **Real-time Processing:** Provides near-instantaneous gesture recognition and response.
- **Low Power Consumption:** Optimized to run efficiently on battery power.

## Components

- **Arduino Nano 33 BLE Sense:** The core microcontroller with built-in IMU and BLE capabilities.
- **Power Source:** Typically a USB power supply or a battery pack.
- **Optional:** Additional sensors or actuators depending on your specific application.

## Installation

### Hardware Setup

1. **Connect the Arduino Nano 33 BLE Sense to your computer** via a USB cable.
2. **Optional:** Connect any additional sensors or actuators as needed.

### Software Setup

1. **Install the Arduino IDE** from the official [Arduino website](https://www.arduino.cc/en/software).
2. **Install the necessary libraries**:
    - **Arduino_LSM9DS1:** For interfacing with the IMU.
    - **ArduinoBLE:** For Bluetooth communication.
    - Any other libraries required for your specific implementation.
3. **Clone this repository** to your local machine:
    ```bash
    git clone https://github.com/yourusername/gesture-recognition-device.git
    ```
4. **Open the project in Arduino IDE** and upload the code to your Arduino Nano 33 BLE Sense.

## Usage

1. **Power on the device** by connecting it to a power source.
2. **Pair the device** with your smartphone or other BLE-enabled device.
3. **Perform gestures** in front of the IMU sensor.
4. The device will **recognize and classify the gesture** and send the corresponding data via BLE.

## Customization

### Modifying Gestures

You can modify the set of recognized gestures by adjusting the algorithms in the main sketch file. Depending on your needs, you may implement custom gesture recognition logic or use machine learning models.

### Adding New Features

You can extend the functionality by adding new sensors or actuators. For instance, you could add haptic feedback or LED indicators to provide immediate feedback for recognized gestures.

## Troubleshooting

- **Device not recognized by computer**: Ensure the drivers for the Arduino Nano 33 BLE Sense are installed correctly.
- **Gesture not recognized correctly**: Adjust the sensitivity or fine-tune the recognition algorithm.
- **BLE connection issues**: Make sure the BLE device is within range and not connected to another device.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request if you have any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Arduino](https://www.arduino.cc/) for their amazing platform and community.
- Any other contributors, libraries, or resources that helped in the development of this project.


