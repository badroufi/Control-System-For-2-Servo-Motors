/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo ServoA;  // create servo object to control a servo
Servo ServoB;

int potpin = A3;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int LED = 8;

void setup() {
  ServoA.attach(9);  // attaches the servo A on pin 9 to the servo object
  ServoB.attach(6);  // attaches the servo B on pin 6 to the servo object

  pinMode(LED, OUTPUT);  // we will attach an Led to pin 8 and it will turn on if the servo angle is greter than 90 degrees 
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  ServoA.write(val);                  // sets the servo position according to the scaled value
  ServoB.write(val); 
  
  
  delay(15);  // waits for the servo to get there

  if(val > 90) 
  
   digitalWrite(LED, HIGH);
  
  else 
  
 digitalWrite(LED, LOW);

 delay(15); 
}
