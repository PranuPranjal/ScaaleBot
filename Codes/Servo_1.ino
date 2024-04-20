#include <Servo.h>
#include <EEPROM.h>

// Define servo objects
Servo servo1;
Servo servo2;
Servo servo3;

// Define variables to store incoming data
char command;
int angle1 = 90; // Initial angle for servo 1
int angle2 = 90; // Initial angle for servo 2
int angle3 = 90; // Initial angle for servo 3

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Attach servos to pins
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    command = Serial.read();

    // Move servo 1
    if (command == '1') {
      angle1 = constrain(angle1 + 5, 0, 180); // Increment angle by 5 degrees
      servo1.write(angle1);
    }
    else if (command == '2') {
      angle1 = constrain(angle1 - 5, 0, 180); // Decrement angle by 5 degrees
      servo1.write(angle1);
    }

    // Move servo 2
    else if (command == '3') {
      angle2 = constrain(angle2 + 5, 0, 180); // Increment angle by 5 degrees
      servo2.write(angle2);
    }
    else if (command == '4') {
      angle2 = constrain(angle2 - 5, 0, 180); // Decrement angle by 5 degrees
      servo2.write(angle2);
    }

    // Move servo 3
    else if (command == '5') {
      angle3 = constrain(angle3 + 5, 0, 180); // Increment angle by 5 degrees
      servo3.write(angle3);
    }
    else if (command == '6') {
      angle3 = constrain(angle3 - 5, 0, 180); // Decrement angle by 5 degrees
      servo3.write(angle3);
    }
  }
}
