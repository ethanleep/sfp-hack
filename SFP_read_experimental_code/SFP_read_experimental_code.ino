const int clockpin = 7;
const int datapin = 6;
int del = 250;

void setup() {
  // put your setup code here, to run once:
pinMode(clockpin, OUTPUT);
digitalWrite(clockpin, HIGH);
pinMode(datapin, OUTPUT);
digitalWrite(datapin, HIGH);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
start();
datahigh();
cloc();
datalow();
cloc();
datahigh();
cloc();
datalow();
cloc();
cloc();
cloc();
cloc();
cloc();
cloc();

//First bit
cloc();
//Second bit
cloc();
//Third bit
cloc();
//Fourth bit
cloc();
//Fifth bit
cloc();
//Sixth bit
cloc();
//Seventh bit
cloc();
//Eight bit
cloc();

datalow();
cloc();
start();
datahigh();
cloc();
datalow();
cloc();
datahigh();
cloc();
datalow();
cloc();
cloc();
cloc();
cloc();
datahigh();
cloc();
datalow();
cloc();
rele();
cloc();
cloc();
cloc();
cloc();
cloc();
cloc();
cloc();
cloc();
tak();
cloc();
delay(500000);
}

void cloc() {
digitalWrite(clockpin, HIGH);
delayMicroseconds(del);
digitalWrite(clockpin, LOW);
delayMicroseconds(del);
}

void datahigh() {
digitalWrite(datapin, HIGH);
delayMicroseconds(del);
}

void datalow() {
  digitalWrite(datapin, LOW);
delayMicroseconds(del);
}

void start() {
  digitalWrite(datapin, HIGH);
  delayMicroseconds(del);
  digitalWrite(clockpin, HIGH);
  delayMicroseconds(del);
  digitalWrite(datapin, LOW);
  delayMicroseconds(del);
  digitalWrite(clockpin, LOW);
  delayMicroseconds(del);
}

void rele() {
  pinMode(datapin, INPUT);
}

void tak() {
  pinMode(datapin, OUTPUT);
  digitalWrite(datapin, LOW);
}

void stap() {
  digitalWrite(clockpin, HIGH);
  delayMicroseconds(del);
  digitalWrite(datapin, HIGH);
}

