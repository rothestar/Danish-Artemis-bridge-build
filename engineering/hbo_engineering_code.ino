/*
  Goal of this project is:
  1. to make it as simple as possible to understand the code.



  there are two reasons why I have left out the 10 presets:
  1. I am out of inputs on the Arduino Pro Micro board
  2. Let the player do all the needed ajustments on the fly, not just press a button job done.

  Artemis engineer panel test code for sliders only,
  setup for screen resolution 1920x1080
  HID-Project.h do not use screen resolution but need an x input from 0 to 32767 (0 to 1920) and y input from 0 to 32767 (0 to 1080)
  Coordinats are located in ms-paint, these values are the calculated in a Excel spreedsheet...

*/
#include "HID-Project.h"
#include <ResponsiveAnalogRead.h>
#include <Keypad.h>

// setup button matrix
const byte rows = 4; //four rows
const byte cols = 4; //four columns
char keys[rows][cols] = {      // rows, columns
  {10, 11, 12, 13},
  {20, 21, 22, 23},
  {30, 31, 32, 33},
  {40, 41, 42, 43}
};
byte colPins[cols] = {0, 1, 2, 3}; //connect to the column pinouts of the keypad
byte rowPins[rows] = {5, 7, 10, 16}; //connect to the row pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );





//const int activate = 3;
//int statusread;
//define min max value coming from potentiometer
int slider_output_min = 2;
int slider_output_max = 1022;

//define the x-coordinats for the coolant buttons
int coolant_1 = 1638;
int coolant_2 = 5685;
int coolant_3 = 9733;
int coolant_4 = 13780;
int coolant_5 = 17827;
int coolant_6 = 21874;
int coolant_7 = 25921;
int coolant_8 = 29968;
int coolant_down = 32100;
int coolant_up = 21936;

//define the x-coordinats for the sliders
int slider_1 = 853;
int slider_2 = 4900;
int slider_3 = 8948;
int slider_4 = 12995;
int slider_5 = 17042;
int slider_6 = 21089;
int slider_7 = 25136;
int slider_8 = 29183;
int slider_max = 21238;
int slider_min = 31857;
//placeholder for potentionmeter output
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue6 = 0;
int sensorValue7 = 0;
int sensorValue8 = 0;
//placeholder for the y-coordinates to move to
int outputValue1 = 0;
int outputValue2 = 0;
int outputValue3 = 0;
int outputValue4 = 0;
int outputValue5 = 0;
int outputValue6 = 0;
int outputValue7 = 0;
int outputValue8 = 0;
//define analog pins
ResponsiveAnalogRead slider1(A0, true);
ResponsiveAnalogRead slider2(A1, true);
ResponsiveAnalogRead slider3(A2, true);
ResponsiveAnalogRead slider4(A3, true);
ResponsiveAnalogRead slider5(A6, true);
ResponsiveAnalogRead slider6(A7, true);
ResponsiveAnalogRead slider7(A8, true);
ResponsiveAnalogRead slider8(A9, true);

void setup() {

  //pinMode(activate, INPUT_PULLUP);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  //int read_analog_next = millis();
  AbsoluteMouse.begin();
}

void loop() {
Serial.println("online");

  slider1.update();
  slider2.update();
  slider3.update();
  slider4.update();
  slider5.update();
  slider6.update();
  slider7.update();
  slider8.update();


  sensorValue1 = (slider1.getValue());
  sensorValue2 = (slider2.getValue());
  sensorValue3 = (slider3.getValue());
  sensorValue4 = (slider4.getValue());
  sensorValue5 = (slider5.getValue());
  sensorValue6 = (slider6.getValue());
  sensorValue2 = (slider7.getValue());
  sensorValue2 = (slider8.getValue());

  // statusread=digitalRead(activate);

  outputValue1 = map(sensorValue1, slider_output_min, slider_output_max, slider_min, slider_max);
  outputValue2 = map(sensorValue2, slider_output_min, slider_output_max, slider_min, slider_max);
  outputValue3 = map(sensorValue3, slider_output_min, slider_output_max, slider_min, slider_max);
  outputValue4 = map(sensorValue4, slider_output_min, slider_output_max, slider_min, slider_max);
  outputValue5 = map(sensorValue5, slider_output_min, slider_output_max, slider_min, slider_max);
  outputValue6 = map(sensorValue6, slider_output_min, slider_output_max, slider_min, slider_max);
  outputValue7 = map(sensorValue7, slider_output_min, slider_output_max, slider_min, slider_max);
  outputValue8 = map(sensorValue8, slider_output_min, slider_output_max, slider_min, slider_max);


  //if (statusread == LOW) {
  //Serial.println("on");


  if (slider1.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_1, outputValue1);
  }


  if (slider2.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_2, outputValue2);
  }


  if (slider3.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_3, outputValue3);
  }

  if (slider4.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_4, outputValue4);
  }

  if (slider5.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_5, outputValue5);
  }

  if (slider6.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_6, outputValue6);
  }

  if (slider7.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_7, outputValue7);
  }

  if (slider8.hasChanged()) {
    AbsoluteMouse.press();
    AbsoluteMouse.moveTo(slider_8, outputValue8);
  }

  AbsoluteMouse.release();
  //Serial.print("\tchanged");

  // If buttons have charged:
  // Press buttons that have are pressed; release buttons that are released

  // Fills keypad.key[ ] array with up-to 10 active keys.
  // Returns true if there are ANY active keys.
  if (keypad.getKeys())
  {
    for (int i = 0; i < LIST_MAX; i++) // Scan the whole key list.
    {
      if ( keypad.key[i].stateChanged )   // Only find keys that have changed state.
      {
        switch (keypad.key[i].kchar) {  // check to see what button has changed and take appropraite action

          //  ***************** coolant ***************************
          case 10:                    // cool1_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_1 , coolant_up);
              AbsoluteMouse.click();
            }
            break;


          case 11:                    // cool3_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_3 , coolant_up);
              AbsoluteMouse.click();
            }
            break;
          case 12:                    // cool5_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_5 , coolant_up);
              AbsoluteMouse.click();
            }
            break;

          case 13:                    // cool7_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_7 , coolant_up);
              AbsoluteMouse.click();
            }
            break;

          case 20:                    // cool1_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_1 , coolant_down);
              AbsoluteMouse.click();
            }
            break;

          case 21:                    // cool3_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_3 , coolant_down);
              AbsoluteMouse.click();
            }
            break;
          case 22:                    // cool5_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_5 , coolant_down);
              AbsoluteMouse.click();
            }
            break;
          case 23:                    // cool7_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_7 , coolant_down);
              AbsoluteMouse.click();
            }
            break;
          case 30:                    // cool2_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_2 , coolant_up);
              AbsoluteMouse.click();
            }
            break;
          case 31:                    // cool4_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_4 , coolant_up);
              AbsoluteMouse.click();
            }
            break;
          case 32:                    // cool6_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_6 , coolant_up);
              AbsoluteMouse.click();
            }
            break;
          case 33:                    // cool8_up
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_8 , coolant_up);
              AbsoluteMouse.click();
            }
            break;
          case 40:                    // cool2_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_2 , coolant_down);
              AbsoluteMouse.click();
            }
            break;
          case 41:                    // cool4_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_4 , coolant_down);
              AbsoluteMouse.click();
            }
            break;
          case 42:                    // cool6_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_6 , coolant_down);
              AbsoluteMouse.click();
            }
            break;
          case 43:                    // cool8_down
            if (keypad.key[i].kstate == PRESSED) {
              AbsoluteMouse.moveTo(coolant_8 , coolant_down);
              AbsoluteMouse.click();
            }
            break;



        }
      }
    }
  }          // end keypad block




}
