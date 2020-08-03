/*
  UartControl.h - Library for controlling mouse and keyboard input in Windows computers using Uart communication.
  Created by Eitan Rabinovitch, July 14, 2020.
  Released into the public domain.
  http://www.eitanra.022.co.il/BRPortal/br/P100.jsp
*/
#ifndef UartControl_h
#define UartControl_h

#include "Arduino.h"

class UartControl {
    public:
        UartControl(int baudRate);
		void begin();
        void moveCursor(int xsteps, int ysteps);
        void click();
        void rightClick();
        void leftDown();
        void leftUp();
        void rightDown();
        void rightUp();
        void middleDown();
        void middleUp();
        int getCursorX();
        int getCursorY();

        void keyPress(String key);
    private:
		int _br;
};

#endif