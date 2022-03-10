
#include <RBDdimmer.h>//     

#define outputPin  12  // signal out to dimmer

int sensorPin = A0;
int sensorValue;
int lastSensorVal = 0;
bool onSeat = false;
int threshold = 400;

dimmerLamp dimmer(outputPin); //initialise port for dimmer

int maxDim = 90; // max brightness
int minDim = 20;  // min brightness

int delayBetweenSteps = 100; // delay between steps of brightness  ???

void setup() {
                      // initialize serial communication
  Serial.begin(9600);
  dimmer.begin(NORMAL_MODE, ON); // dimmer initialization
  delay(1000);
   
   
  Serial.println("Dimmer program is starting...");
}

void loop() {
  sensorValue = analogRead(sensorPin);
 
                        // if person on seat occurs:
  if (sensorValue > threshold) {
    if (lastSensorVal <= threshold) {
      onSeat = true;
      Serial.println(onSeat);
      delay(10);
      pinkFadeUp();
    }

  } else {
                        // if person on seat leaves
    if (lastSensorVal > threshold) {
      onSeat = false;      
      Serial.println(onSeat);
      delay(10);
      pinkFadeDown();
    }
  }
   
  lastSensorVal = sensorValue;

}

void pinkFadeUp() {
  for (int i = minDim; i < maxDim; i++) {
    dimmer.setPower(i); // set power
  //  Serial.print("dimmer power: ");
 //   Serial.println(i);
    delay(100);
  }
}

void pinkFadeDown() {
  for (int i = maxDim; i > minDim; i--) {
    dimmer.setPower(i); // set power
  //  Serial.print("dimmer power:  ");
  //  Serial.println(i);
    delay(100);
  }
}
