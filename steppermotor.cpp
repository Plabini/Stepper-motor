/** @file steppermotor.cpp
 *  @brief Code to drive Stepper Motors with RPI 4 over using GPIO.
 * 
 *  @author Plabini Jibanjyoti Nayak 
 *  @bug    File not tested since there is error while binding.
 */

/**-------------------------------------------------------------------------------
                        ## Function Description ## 
*--------------------------------------------------------------------------------
* drive_stepper() - Function to drive stepper motor by 360 degree in forward 
* direction.
* main() - Main function.
*-----------------------------------------------------------------------------------
*/

/* --- Standard Includes --- */
#include <stdio.h>
#include <shunyaInterfaces.h>

/**
 * @macro Defines GPIO PINS 17,18,27,22
 */

#define Output_pin1 17
#define Output_pin2 18
#define Output_pin3 27
#define Output_pin4 22

/**
 *
 *  @brief: drive_stepper() - Function to drive stepper motor by 360 degree in forward direction.
 *  Half Stepping is a technique where instead of energizing a single phase at a time, a combination of one phase and two phase energizing is used. 
 *  So at each step, the phase (output pins) are changes to provide complete rotation at the end.
 *  Step| Output_pin1| Output_pin2| Output_pin3| Output_pin4
 *  1   | 1          | 0          | 0          | 0
 *  2   | 1          | 1          | 0          | 0
 *  3   | 0          | 1          | 0          | 0
 *  4   | 1          | 0          | 0          | 0
 *  5   | 0          | 0          | 1          | 0
 *  6   | 0          | 0          | 1          | 1
 *  7   | 0          | 0          | 0          | 1
 *  8   | 1          | 0          | 0          | 1
 */
public void drive_stepper(){

    //Digital value of the GPIO pin is set
    digitalWrite(Output_pin1, LOW);
    digitalWrite(Output_pin2, LOW);
    digitalWrite(Output_pin3, LOW);
    digitalWrite(Output_pin4, LOW);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 1
    digitalWrite(Output_pin1, HIGH);
    digitalWrite(Output_pin2, LOW);
    digitalWrite(Output_pin3, LOW);
    digitalWrite(Output_pin4, LOW);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 2
    digitalWrite(Output_pin1, HIGH);
    digitalWrite(Output_pin2, HIGH);
    digitalWrite(Output_pin3, LOW);
    digitalWrite(Output_pin4, LOW);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 3
    digitalWrite(Output_pin1, LOW);
    digitalWrite(Output_pin2, HIGH);
    digitalWrite(Output_pin3, LOW);
    digitalWrite(Output_pin4, LOW);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 4
    digitalWrite(Output_pin1, LOW);
    digitalWrite(Output_pin2, HIGH);
    digitalWrite(Output_pin3, HIGH);
    digitalWrite(Output_pin4, LOW);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 5
    digitalWrite(Output_pin1, LOW);
    digitalWrite(Output_pin2, LOW);
    digitalWrite(Output_pin3, HIGH);
    digitalWrite(Output_pin4, LOW);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 6
    digitalWrite(Output_pin1, LOW);
    digitalWrite(Output_pin2, LOW);
    digitalWrite(Output_pin3, HIGH);
    digitalWrite(Output_pin4, HIGH;
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 7
    digitalWrite(Output_pin1, LOW);
    digitalWrite(Output_pin2, LOW);
    digitalWrite(Output_pin3, LOW);
    digitalWrite(Output_pin4, HIGH);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.

    //Step 8
    digitalWrite(Output_pin1, HIGH);
    digitalWrite(Output_pin2, LOW);
    digitalWrite(Output_pin3, LOW);
    digitalWrite(Output_pin4, HIGH);
    delayMicroseconds(50);// Provides a delay of 50 microsecond tp complete the step.
}

/** 
 *  @brief Main function.
 */
public void main(){
    initLib();
    //The direction of the GPIO pin is set to OUTPUT.
    pinmode(Output_pin1, OUTPUT);
    pinmode(Output_pin2, OUTPUT);
    pinmode(Output_pin3, OUTPUT);
    pinmode(Output_pin4, OUTPUT);
    while (1)
    {
        drive_stepper();// Fucntion called.
        delay(30);// Delay of 30ms
    }
    
}
