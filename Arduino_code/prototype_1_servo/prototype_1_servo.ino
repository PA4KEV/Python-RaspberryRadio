/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo.write(54);  //46 CC slow / 54 C slow
} 
 
void loop() 
{    } 

