/*
Arduino Turn LED On/Off using Serial Commands
Created April 22, 2015

It's a simple sketch which waits for a character on serial
and in case of a desirable character, it turns an LED on/off.

Possible string values:
a (to turn the LED on)
b (tor turn the LED off)
*/
#include <Servo.h>
char junk;
String inputString="";
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;   

void setup()                    // run once, when the sketch starts
{
Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
pinMode(7, OUTPUT);
 myservo.attach(9);
}

void loop()
{
if(Serial.available()){
while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
inputString += inChar;        //make a string of the characters coming on serial
    }
Serial.println(inputString);
    while (Serial.available() > 0)  
{ junk = Serial.read() ; }      // clear the serial buffer
if(inputString == "a"){         //in case of 'a' turn the LED on
 myservo.write(180); 
}else if(inputString == "b"){   //incase of 'b' turn the LED off
 myservo.write(0);
    }
inputString = "";
  }
}
