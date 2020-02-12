/**
 * 0Copyright (c) 2017 Ehsan Zaery Moghaddam (zaerymoghaddam@gmail.com)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
 
//  Include following libraries to access IR sensor
#include <IRremote.h>
#include <IRremoteInt.h>

const int BLU_LED_PIN = 2;
const int GRN_LED_PIN = 3;
const int YEL_LED_PIN = 4;
const int RED_LED_PIN = 5;

int RECV_PIN = 13;          //  The digital pin that the signal pin of the sensor is connected to
IRrecv receiver(RECV_PIN);  //  Create a new receiver object that would decode signals to key codes
decode_results results;     //  A varuable that would be used by receiver to put the key code into

void setup() {

  //  Setup the pins connected to LEDs as output pin
  pinMode(BLU_LED_PIN, OUTPUT);
  pinMode(GRN_LED_PIN, OUTPUT);
  pinMode(YEL_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  receiver.enableIRIn();    //  Enable receiver so that it would start processing infrared signals
}

//  These variables keep the state of LEDs. 'false' means given LED is off and 'true' means it's on
bool isBlueOn = false;
bool isGreenOn = false;
bool isYellowOn = false;
bool isRedOn = false;

void loop() {
  if (receiver.decode(&results)) {            //  Decode the button code and put it in "results" variable
    
    if (results.value == 0xFF6897) {          //  Key '1' is pressed which belongs to the blue LED
      if (isBlueOn == true) {                 //  Blue LED is on, turn it off and set update corresponding state variable
        digitalWrite(BLU_LED_PIN, LOW);
        isBlueOn = false;
      } else {                                //  Blue LED is off, turn it on and set update corresponding state variable
        digitalWrite(BLU_LED_PIN, HIGH);
        isBlueOn = true;
      }
    }
    if (results.value == 0xFF9867) {          //  Key '2' is pressed which belongs to the green LED
      if (isGreenOn == true) {                //  Green LED is on, turn it off and set update corresponding state variable
        digitalWrite(GRN_LED_PIN, LOW);
        isGreenOn = false;
      } else {                                //  Green LED is off, turn it on and set update corresponding state variable
        digitalWrite(GRN_LED_PIN, HIGH);
        isGreenOn = true;
      }
    }
    if (results.value == 0xFFB04F) {          //  Key '3' is pressed which belongs to the yellow LED
      if (isYellowOn == true) {               //  Yellow LED is on, turn it off and set update corresponding state variable
        digitalWrite(YEL_LED_PIN, LOW);
        isYellowOn = false;
      } else {                                //  Yellow LED is off, turn it on and set update corresponding state variable
        digitalWrite(YEL_LED_PIN, HIGH);
        isYellowOn = true;
      }
    }
    if (results.value == 0xFF30CF) {          //  Key '4' is pressed which belongs to the red LED
      if (isRedOn == true) {                  //  Red LED is on, turn it off and set update corresponding state variable
        digitalWrite(RED_LED_PIN, LOW);
        isRedOn = false;
      } else {                                //  Red LED is off, turn it on and set update corresponding state variable
        digitalWrite(RED_LED_PIN, HIGH);
        isRedOn = true;
      }
    }
    receiver.resume();                        //  Continue listening for new signals
  }
}
