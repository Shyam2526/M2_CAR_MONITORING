# CAR MONITORING
## ABSTRACT
This project "CAR MONITORING" is about protect the car from different issues like finding obstacle and Engine Temperature. In this project, a Temperature is replaced by Potentiometer to show the Engine Temperature. A Fixed Voltage Source is provide to supply constant voltage to the potentiometer. If the temperature of the Car Engine is below 20 degree, LED 1 will glow. Similarly, if the temperature of the Car Engine is below 50 and above 20 degree, LED 2 will glow. But the temperature is above 50, tha car engine is in danger and the buzzer is ON to provide signal to the driver. The ultrasonic sensor is trigged and echoed by atmega328 D0 and D2 pins. The LCD connections are given to the atmega328 for displaying the values. Trigger PIN is used to trigger the sensor to measure the distance, the distance is calculated by the pulse. The pulse is changed every time when the ultrasonic sensor is activated. When the sensor has moved the distance that the sensor moved is displayed. 


## INTRODUCTION
  * Automation is the technology by which a process or procedure is performed with minimal human interference through the use of technological or mechanical devices. It is the technique of making a process or a system operate automatically.
  * Car Monitoring consists of an electronic device or number of devices installed in a vehicle to monitor driver activities and to avoid accidents, car damages, etc.
  * The Car Engine will be highly used in most of the cars while going for a long journey. So, it is important to monitor the car engine temperature. Thus, by avoid car engines failures.
  * Ultrasonic Sensor is provide for the obstacles which is near to the front of the car to give signal to the user about the obstacles with the clear measured distance.
  * In Ultrasonic, transducer is used to send and receive the pulse to calculate or measure the distance of the obstacles. The measured distance is connected to the display. 

## BLOCK DIAGRAM

![Untitled Diagram drawio (2)](https://user-images.githubusercontent.com/101013448/164976527-8fe343e7-d76e-472c-a440-fda3e82d79f1.png)

## FLOW CHART

 ![Untitled Diagram drawio](https://user-images.githubusercontent.com/101013448/164976417-1c3965a5-d9c5-4222-aa3a-888e99cb06a0.png)

__fig1.1 Behavioural Flowchart__

 ![Untitled Diagram drawio (1)](https://user-images.githubusercontent.com/101013448/164976398-3e08dc4b-893b-43ee-9cf9-30c5e0077d0e.png)

__fig1.2 Structural Flowchart__

## COMPONENTS USED
  1) Atmega328
  2) Poteniometr
  3) Ultrasoic Sensor
  4) LCD Display
  5) LED
  6) BUZZER
  7) Resistor (10k ohm)

## COMPONENTS DESCRIPTION
* ATmega328 is an Advanced Virtual RISC (AVR) microcontroller. It supports 8-bit data processing. ATmega-328 has 32KB internal flash memory. ATmega328 has 1KB Electrically Erasable Programmable Read-Only Memory (EEPROM).
* An ultrasonic sensor is an instrument that measures the distance to an object using ultrasonic sound waves. An ultrasonic sensor uses a transducer to send and receive ultrasonic pulses that relay back information about an object's proximity.
* Potentiometers work by varying the position of a sliding contact across a uniform resistance. In a potentiometer, the entire input voltage is applied across the whole length of the resistor, and the output voltage is the voltage drop between the fixed and sliding contact as shown below.
* LCD (Liquid Crystal Display) is a type of flat panel display which uses liquid crystals in its primary form of operation. LEDs have a large and varying set of use cases for consumers and businesses, as they can be commonly found in smartphones, televisions, computer monitors and instrument panels.
* LEDs are “directional” light sources, which means they emit light in a specific direction, unlike incandescent and CFL, which emit light and heat in all directions. That means LEDs are able to use light and energy more efficiently in a multitude of applications.
## WORKING
* This project is mainly based on monitoring of the vehile, which includes cars, trucks, lorry,etc.
* Main component of any vehicle is Engine, In this project the temperature of the engine is monitored using potentiometer insteat of DHT22.
* The temperature is continously monitored by the sensor to gives constant signal to the user.
* If the temperature of the Car Engine is below 20 degree, LED 1 will glow. 
* Similarly, if the temperature of the Car Engine is below 50 and above 20 degree, LED 2 will glow.
* But the temperature is above 50, tha car engine is in danger and the buzzer is ON to provide signal to the driver.
* Using a transducer, the ultrasonic sensor sends the wave and receives the ultrasonic pulses that relay back information about an object's proximity. 
* The pulses are varied by the object that is near the vehicles. The pulses are divided by some values(52) to get approximate distances.
* It depends on the obstacles, the led will glow, which is connected with the resistor to avoid a short circuit. 
* The connections are made as per the circuit diagram before.
## CIRCUIT DIAGRAM

![m2_new](https://user-images.githubusercontent.com/101013448/164968451-d3fa1d33-2140-4558-9887-6499d54aa151.jpg)

## CONCLUSION
In this project, the car engine is monitored successfully using temperature sensor and also measure the obstacle distance by using ultrasonic sensor.
