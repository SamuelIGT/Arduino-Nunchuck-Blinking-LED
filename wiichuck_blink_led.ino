/*
  Nunchuck Blink
  Turns on an LED when z button of the nunchuck is pressed.
 */

#include <Wire.h>
#include "nunchuck_funcs.h"

int loop_cnt = 0; //loop count used to time the data collection

int led = 13; //led on pin 13
byte zbtn; //nunchuck z button

void setup() {
  Serial.begin(19200);
  
  //Sets the power pins
  nunchuck_setpowerpins();

  //Initialize the nunchuck
  nunchuck_init();
  
  //initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

void loop() {
  if(loop_cnt > 100){
    loop_cnt = 0;

    //Reads Nunchucks data
    nunchuck_get_data();

    zbtn = nunchuck_zbutton();

    if((byte)zbtn == 1){
      digitalWrite(led, HIGH);// turn the LED on (HIGH is the voltage level)
    }
    else{
      digitalWrite(led, LOW);// turn the LED off by making the voltage LOW
    }
  }
  loop_cnt++;
  delay(1);
}
