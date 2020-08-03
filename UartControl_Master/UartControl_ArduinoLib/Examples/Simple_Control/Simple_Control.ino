/*
This is a simple code that shows how to use the UartControl library, and to control the computer's mouse & keyboard easily.
connect 2 buttons to digital pins 2 and 3 and to Gnd.
For more info: http://www.eitanra.022.co.il/BRPortal/br/P100.jsp
*/

#include <UartControl.h>

UartControl pc(9600); //Create an UartControl instance, and set baud rate to 9600

//Set buttons pins
#define leftBtn 2
#define rightBtn 12

void setup() {
  pc.begin(); //Start UartControl
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  Serial.println("Start!");
}

void loop() {
  if(digitalRead(leftBtn) == 0 && digitalRead(rightBtn) == 1) { //Left button click
    while(digitalRead(leftBtn) == 0); //Wait until the button is being released
    pc.click(); //Simulate a mouse-left-button click
  }
  if(digitalRead(rightBtn) == 0 && digitalRead(leftBtn) == 1) {
    while(digitalRead(rightBtn) == 0);
    pc.rightClick(); //Simulate a mouse-right-button click
  }
  if(digitalRead(leftBtn) == 0 && digitalRead(rightBtn) == 0) { //Both of the buttons are pushed
    while(digitalRead(leftBtn) == 1 && digitalRead(rightBtn) == 1);
    pc.keyPress("Hello world!"); //Simulate keyboard keys pressing: H-e-l-l-o-SPACE-w-o-r-l-d-!
    pc.keyPress("{Enter}"); //Simulate Enter key pressing
    pc.moveCursor(100, -50); //Move the cursor 100 pixels right and -50 pixels up
    /* If you want to simulate a key pressing more than one time, use: "{Three 3}". This will write: ThreeThreeThree */
  }
  Serial.println("Cursor position: (" + String(pc.getCursorX()) + ", " + String(pc.getCursorY()) + ")"); //Writing the current cursor's position
  /*
  pc.leftDown(); //Hold down mouse left button
  pc.leftUp(); //Release mouse left button
  pc.rightDown();
  pc.rightUp();
  pc.middleDown();
  pc.middleUp();
  */
}
