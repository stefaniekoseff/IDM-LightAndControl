 /// Alternating blink pattern (2 on / 2 off) 4 white LEDs x6 and then an RGB LED fades from orange to pink // 
// rinse & repeat // 


const int white1 = 2;
const int white2 = 4;
const int white3 = 7;
const int white4 = 8;

const int color1R = 3;
const int color1G = 5;
const int color1B = 6;
  

int ledState = LOW;
int ledStateReverse = HIGH;

unsigned long prevMillis = 0;

const long interval = 1000;

int count = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(white1, OUTPUT);
  pinMode(white2, OUTPUT);
  pinMode(white3, OUTPUT);
  pinMode(white4, OUTPUT);
  pinMode(color1R, OUTPUT);
  pinMode(color1G, OUTPUT);
  pinMode(color1B, OUTPUT);

}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
     
    } else {
      ledState = LOW;
    }

    if (ledStateReverse == HIGH) {
      ledStateReverse = LOW;
    } else {
      ledStateReverse = HIGH;
    }
      count += 1;
      Serial.println(count);

    if (count >= 7) {
      count = 0;
    }
  }

 if (count <= 5) {
  whiteBlink();
}

if (count == 5) {
    digitalWrite(white1, LOW);
    digitalWrite(white4, LOW);
    digitalWrite(white2, LOW);
    digitalWrite(white3, LOW); 
}

if (count >=6 && count <7) {
  changeColors1();

}
  else 
  analogWrite(color1R, 255);
  analogWrite(color1G, 255);
  analogWrite(color1B, 255);
}


void whiteBlink() {
    digitalWrite(white1, ledState);
    digitalWrite(white4, ledState);
    digitalWrite(white2, ledStateReverse);
    digitalWrite(white3, ledStateReverse);
}

void changeColors1() {

int red = 0;
int green = 220;
int blue = 255;

  analogWrite(color1R, red);

  for (int i = 220; i <=255; i+= 2) {
    analogWrite(color1G, i);
    delay(100);
  }
    for (int i = 255; i >=200; i-= 2) {
      analogWrite(color1B, i);
      delay(100);
  }
}
