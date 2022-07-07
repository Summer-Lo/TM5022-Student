/*
 * Autor: Summer Lo
 * Updated date: 05/07/2022
 * Description: Design for counting the traveling time between Dispatch Sensor (Physical) 
 * and Loading and Unloading Station Sensor (Physical)
 * GPIO Output read status LOW = 0
 * GPIO Output read status HIGH = 1
 */
#include "stopper.h"
#include <neotimer.h>
#include "sensor.h"
int numBlinks=0;
int count = 0;
int state = 0;
unsigned long timer1;
unsigned long timer2;
unsigned long timeDiff;

//GPIO SetUp (Stopper)
stopper leftStopper(0);
stopper rightStopper(1);
stopper bottomConveyor(2);
stopper dispatchCargo(3);
stopper resetCargo(4);

//GPIO SetUp (Sensor)
sensor cargoDetector(0);
sensor statusButton(1);
sensor locationSensor(2);
sensor homeSensor(3);
sensor resetSensor(4);
sensor palletDetector(5);

// Timer Setup
Neotimer t0 = Neotimer(3000);   // 3 second timer
Neotimer t1 = Neotimer(3000);   // 3 second timer
Neotimer t2 = Neotimer(5000);   // 5 second timer

void setup() {
    Serial.begin(9600);
    t0.reset();
    t2.reset();
    //t0.start();
    //t2.start();

    // Original Position
    bottomConveyor.start();
    delay(200);
    dispatchCargo.start();
    delay(200);
    resetCargo.start();
    delay(200);

    Serial.println("Start\n");
}



void loop() {
    if (state == 0)
    {
        Serial.println("Please input the number of message which you want to send to raspberry pi?"); //Prompt User for Input
        numBlinks = Serial.parseInt();                                                                //Read the data the user has input
        Serial.println("NumBlinks is:"+numBlinks);
        while (Serial.available() == 0) {
            count++;
        }
        switch (numBlinks) {
            case 1:
                state = 1;
                Serial.println("Change to state 1!");
                break;
            case 2:
                state = 2;
                Serial.println("Change to state 2!");
                break;
         }  
    }
    
    // Begin: Write your code here

    // End: Write your code here
}