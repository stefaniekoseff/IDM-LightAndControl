 /// Alternating blink pattern (2 on / 2 off) 4 white LEDs x4 then xfade up/down 1 pink and 1 green LED //
// rinse & repeat // 
// ideas for the for-loop from Moreware blog
// https://www.moreware.org/wp/blog/2020/04/02/arduino-ide-rgb-led-for-while-do-while-loops-7/


const int white1 = 2;
const int white2 = 4;
const int white3 = 7;
const int white4 = 8;

const int green = 10;
const int pink = 9;
 
int ledState = LOW;
int ledStateReverse = HIGH;

unsigned long prevMillis = 0;

const long interval = 750;

int count = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(white1, OUTPUT);
  pinMode(white2, OUTPUT);
  pinMode(white3, OUTPUT);
  pinMode(white4, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pink, OUTPUT);
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

    if (count >= 6) {
      count = 0;
    }
  }

if (count <= 4) {
  whiteBlink();
}

if (count == 4) {
     digitalWrite(white1, LOW);
    digitalWrite(white4, LOW);
    digitalWrite(white2, LOW);
    digitalWrite(white3, LOW); 
}

if (count >=5 && count <6) {
  greenPinkFade();
 delay (100);
}
  else 
  digitalWrite(pink, LOW);
  digitalWrite(green, LOW);
}
 
void whiteBlink() {

    digitalWrite(white1, ledState);
    digitalWrite(white4, ledState);
    digitalWrite(white2, ledStateReverse);
    digitalWrite(white3, ledStateReverse);
}

void greenPinkFade() {
  digitalWrite(pink, HIGH);
  
 for (int i = 0; i <256; i+= 2) {
  analogWrite(green, i);
  analogWrite(pink, -i);
  delay(10);
 }
 for (int i=255; i >=0; i -=2) {
  analogWrite(green, i);
  analogWrite(pink, -i);
 delay(10);
 }  
}
 
