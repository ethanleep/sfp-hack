
int clockPin = 7;
int dataPin = 6;
byte memory = 0;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(clockPin, OUTPUT);
  digitalWrite(clockPin, HIGH);
  pinMode(dataPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  Serial.begin(115200);
}

void loop() {
  start();
  readData();
  delay(1000);
}
void start() {
  pinMode(dataPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  delayMicroseconds(5);
  digitalWrite(clockPin, LOW);
  delayMicroseconds(5);
}

void writeData() {

}

void readData() {
  shiftOut(dataPin, clockPin, MSBFIRST, 160);
  pinMode(dataPin, INPUT);
  delayMicroseconds(5);
  digitalWrite(clockPin, HIGH);
  delayMicroseconds(5);
  if (digitalRead(dataPin) == 1) {
    Serial.println("Module busy");
  }
  else {
    digitalWrite(clockPin, LOW);
    delayMicroseconds(5);
    pinMode(dataPin, OUTPUT);
    delayMicroseconds(5);
    shiftOut(dataPin, clockPin, MSBFIRST, memory);
    pinMode(dataPin, INPUT);
    delayMicroseconds(5);
    digitalWrite(clockPin, HIGH);
    delayMicroseconds(5);
    if (digitalRead(dataPin) == 1) {
      Serial.println("Module busy");
    }
    else {
      pinMode(dataPin, OUTPUT);
      digitalWrite(clockPin, LOW);
      delayMicroseconds(5);
      digitalWrite(dataPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(clockPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(dataPin, LOW);
      delayMicroseconds(5);
      digitalWrite(clockPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, 161);
      pinMode(dataPin, INPUT);
      delayMicroseconds(5);
      digitalWrite(clockPin, HIGH);
      delayMicroseconds(5);
      if (digitalRead(dataPin) == 1) {
        Serial.println("Module busy");
      }
      else {
        digitalWrite(clockPin, LOW);
        delayMicroseconds(5);
        for (int idek = 0; idek < 255; idek++) {
          byte j = shiftIn(dataPin, clockPin, MSBFIRST);
          delay(1);
          Serial.print("Address ");
          Serial.print(idek);
          Serial.print(" is ");
          Serial.println(j);
          delay(2);
          if(idek == 245) {
            break;
          }
          delayMicroseconds(5);
          pinMode(dataPin, OUTPUT);
          delayMicroseconds(5);
          digitalWrite(dataPin, LOW);
          delayMicroseconds(5);
          digitalWrite(clockPin, HIGH);
          delayMicroseconds(5);
          digitalWrite(clockPin, LOW);
          delayMicroseconds(5);
          pinMode(dataPin, INPUT);
        }
        delayMicroseconds(5);
        pinMode(dataPin, OUTPUT);
        digitalWrite(dataPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(clockPin,  LOW);
        delayMicroseconds(5);
        digitalWrite(dataPin, LOW);
        delayMicroseconds(5);
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(dataPin, HIGH);
      }
    }
  }
}

