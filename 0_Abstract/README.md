# ABSTRACT

* This project "CAR MONITORING" is about protect the car from different issues like finding obstacle and Engine Temperature. 
* In this project, a Temperature is replaced by Poteniometer to show the Engine Temperature. A Fixed Voltage Source is provide to supply constant voltage to the           poteniometer.
* If the temperature of the Car Engine is below 20 degree, LED 1 will glow.
* Similarly, if the temperature of the Car Engine is below 50 and above 20 degree, LED 2 will glow.
* But the temperature is above 50, tha car engine is in danger and the buzzer is ON to provide signal to the driver.
* The ultrasonic sensor is trigged and echoed by atmega328 D0 and D2 pins.
* The LCD connections are given to the atmega328 for displaying the values. 
* Trigger PIN is used to trigger the sensor to measure the distance, the distance is calculated by the pulse. 
* The pulse is changed every time when the ultrasonic sensor is activated. When the sensor has moved the distance that the sensor moved is displayed. 
