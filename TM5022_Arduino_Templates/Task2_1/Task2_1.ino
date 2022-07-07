/*
 * Autor: Summer Lo
 * Updated date: 05/07/2022
 * Description: Design for counting the traveling time between Front sensor (Virtual) 
 * and Loading and Unloading Station Sensor (Virtual)
 * GPIO Output read status LOW = 0 
 * GPIO Output read status HIGH = 1
 */
#include "stopper.h"
#include <neotimer.h>
#include "sensor.h"

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

int state = 0;
int deliver = 0;
char message;
char store;
unsigned long timer1;
unsigned long timer2;
unsigned long timeDiff;

void setup() {
    Serial.begin(9600);
    t0.reset();
    t2.reset();
    //t0.start();
    t2.start();

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
        if(t2.done())
        {   
            // Begin: Write your code here

            // End: Write your code here
            {
                timer1 = millis();
                //Serial.println(timer1);
                state = 1;
                //Serial.println("Change to State 1!");
            }  
        }
    }
    else if (state == 1)
    {
        // Begin: Write your code here

        // End: Write your code here
        {
            // Begin: Write your code here

            // End: Write your code here
            state = 0;
            //Serial.println("Change to State 0");
            t2.start();
        }
    }
}
