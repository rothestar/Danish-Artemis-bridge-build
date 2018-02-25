/*
********************************************
*                  Artemis                 *
*             Fighter jystick v1.1         *
*          modifyed By Rothestar           *
*     to work with my hardware design      *
* see my build blog at http://seosalle.dk  *
********************************************
*/


#include "Joystick.h"

Joystick_ Joystick;

void setup() {

Joystick.begin();
Joystick.setXAxis(0);
Joystick.setYAxis(0);
Joystick.setZAxis(0);
pinMode(3, INPUT_PULLUP);//button 0 Beam 
pinMode(4, INPUT_PULLUP);//button 1 Boost
pinMode(5, INPUT_PULLUP);//button 2 Brake
pinMode(6, INPUT_PULLUP);//button 3 Missiles
pinMode(7, INPUT_PULLUP);//button 4 Request Dock
//pinMode(8, INPUT_PULLUP);
//pinMode(9, INPUT_PULLUP);
//pinMode(10, INPUT_PULLUP);
int lastButtonState = 0;
}

void loop() {

int button0Val =digitalRead(3); 
int button1Val =digitalRead(4);
int button2Val =digitalRead(5);
int button3Val =digitalRead(6);
int button4Val =digitalRead(7);
//int button5Val =digitalRead(8);
//int button6Val =digitalRead(9);
//int button7Val =digitalRead(10);


int xAxis = analogRead(A1);//switch due to fact that the joystick is turned 90 degrees to fit into the hardware design (original it should be A0).
int yAxis = analogRead(A0);//switch due to fact that the joystick is turned 90 degrees to fit into the hardware design (original it should be A1).
yAxis = map(yAxis,0,1023,1023,0);//to reverse the y-axes

int zAxis = analogRead(A2); YAW

Joystick.setXAxis(xAxis);
Joystick.setYAxis(yAxis);
Joystick.setZAxis(zAxis);
Joystick.setButton(0, !button0Val);
Joystick.setButton(1, !button1Val);
Joystick.setButton(2, !button2Val);
Joystick.setButton(3, !button3Val);
Joystick.setButton(4, !button4Val);
//Joystick.setButton(5, !button5Val);
//Joystick.setButton(6, !button6Val);
//Joystick.setButton(7, !button7Val);
}

