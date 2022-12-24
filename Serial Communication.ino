// 1- Miran Member
// 2- Serial Communication
// 3- Description - Two buttons are connected to each other using a serial connection. 
// 4- Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular Arduino versions, etc... : I assumed what the lab wanted was that a button signal would be sent to a software serial connection and the otherway around and thats
// what the code does. I made sure I understood the lab, so I got it checked by the TA Anjani, and she gave me all good. 
// 5- References - https://create.arduino.cc/projecthub/masteruan/communication-between-arduino-uno-c1caa5
#include <SoftwareSerial.h>


SoftwareSerial portOne(10, 11);

void setup() { // set up the buttons as input and the led as outputs. Also set up the software serial.
  Serial.begin(9600);
  portOne.begin(9600);
  pinMode(6, INPUT);
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}



void loop() {
  if(portOne.available() > 0) { // when the hardware serial sends a signal to the software turn it on.
    byte incomingByte1 = 0;
    incomingByte1 = portOne.read();
    if (incomingByte1 != -1) {
      digitalWrite(3, incomingByte1);
    }
  }

  if(Serial.available() > 0) { // when the software serial sends the signal the hardare turns it on.
    byte incomingByte2 = 0;
    incomingByte2 = Serial.read();
    if (incomingByte2 != -1) {
      digitalWrite(5, incomingByte2);
    }
  }

  portOne.write(digitalRead(4));
  Serial.write(digitalRead(6));
  delay(250);
}
