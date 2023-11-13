# GSM Based Relay Control System with Call and SMS Switching and Whitelisting

This project demonstrates a GSM-based relay control system with call and SMS switching, featuring a whitelisting mechanism to control access. The system allows you to remotely control a relay using incoming calls or SMS from predefined whitelisted phone numbers.

## Components Used
- Arduino UNO
- SIM900 GSM Sheild
- Relay Module
- Power Supply
- Jumper Wires

## Features

- **Swsitching SMS**: Sends an SMS to the whitelisted number with the current relay status after toggling.
- **Call Switching**: Accepts calls from whitelisted numbers to toggle the relay status.
- **SMS Switching**: Accepts SMS commands from whitelisted numbers to toggle the relay status.
- **Whitelisting**: Allows only predefined phone numbers to control the relay.


## Circuit 

Components and Connections
Arduino Board:
Connect the VCC and GND pins of the Arduino to the respective pins on the breadboard or power supply.

SIM900 GSM Shield:

Connect the VCC and GND pins of the SIM800L module to the power supply.
Connect the TX pin of the SIM800L module to the Arduino's RX pin (pin 8).
Connect the RX pin of the SIM800L module to the Arduino's TX pin (pin 7).
Relay Module:

Connect the VCC and GND pins of the relay module to the power supply.
Connect the IN (or signal) pin of the relay module to a digital pin on the Arduino (e.g., pin 4).
Connect the GSM Antenna:
Attach the GSM antenna to the designated port on the SIM900 GSM shield.

Power Supply:
Suplly the GSM shield with 12V, 2/3A power adapter
Connect the positive (+) and negative (-) terminals of the power supply to the breadboard or respective components.

Jumper Wires:
Use jumper wires to make the necessary connections between components on the breadboard.

## Installation
1. Connect the components as per the circuit diagram.
2. Upload the provided Arduino sketch to your Arduino board.

## Usage
1. Set the `phone` variable to the phone number you want to whitelist. Include the country code (e.g., +91 for India).
2. Upload the code to your Arduino.
3. Power on the GSM shield with 12V, 2/3A power adapter and ensure the GSM module is connected to the network.
4. Call the system from a whitelisted number to toggle the relay.

## Code Explanation
- The Arduino code uses the SoftwareSerial library to communicate with the GSM module.
- The system initializes by setting up the GSM module and configuring it for call and SMS handling.
- Incoming calls are accepted only from whitelisted numbers.
- The relay status is toggled on valid call or SMS commands.

