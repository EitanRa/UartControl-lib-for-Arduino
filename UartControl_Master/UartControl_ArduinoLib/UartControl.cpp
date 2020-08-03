/*
  UartControl.cpp - Library for controlling mouse and keyboard in Windows computers using Uart communication.
  Created by Eitan Rabinovitch, July 14, 2020.
  Released into the public domain.
  http://www.eitanra.022.co.il/BRPortal/br/P100.jsp
*/
#include "Arduino.h"
#include "UartControl.h"

UartControl::UartControl(int baudRate) {
    _br = baudRate;
}

void UartControl::begin() {
    Serial.begin(_br);
}

void UartControl::click() {
    Serial.println("m ld");
    Serial.println("m lu");
}

void UartControl::rightClick() {
    Serial.println("m rd");
    Serial.println("m ru");
}

void UartControl::leftDown() {
    Serial.println("m ld");
}

void UartControl::leftUp() {
    Serial.println("m lu");
}

void UartControl::rightDown() {
    Serial.println("m rd");
}

void UartControl::rightUp() {
    Serial.println("m ru");
}

void UartControl::middleDown() {
    Serial.println("m md");
}

void UartControl::middleUp() {
    Serial.println("m mu");
}

void UartControl::moveCursor(int xsteps, int ysteps) {
    if(xsteps > -1) {
        Serial.println("x+" + String(xsteps));
    }
    else {
        Serial.println("x-" + String(xsteps*-1));
    }
    if(ysteps > -1) {
        Serial.println("y+" + String(ysteps));
    }
    else {
        Serial.println("y-" + String(ysteps*-1));
    }
}

int UartControl::getCursorX() {
    Serial.println("gx");
    int x = -1;
    if(Serial.available() > 0) {
        x = Serial.parseInt();
    }
    return x;
}

int UartControl::getCursorY() {
    Serial.println("gy");
    int y = -1;
    if(Serial.available() > 0) {
        y = Serial.parseInt();
    }
    return y;
}

void UartControl::keyPress(String key) {
    Serial.println("k " + key);
}
