//Thomas Gilman
//Interrupts 2
//Teensy 3.2
//6th April, 2018

int ledPin0 = 0, ledPin1 = 1, ledPin2 = 2, ledPin3 = 3; //lowerNibble
int ledPin4 = 4, ledPin5 = 5, ledPin6 = 6, ledPin7 = 7; //upperNibble
int ledPinArray[8] = {ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7};

int Button0 = 13, Button1 = 14, Button2 = 15, Button3 = 16;

int toggler = 0;

void setup() {
  //LED Pins
  pinMode(ledPin0, OUTPUT); pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT); pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT); pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT); pinMode(ledPin7, OUTPUT);
  //Button Pins
  pinMode(Button0, INPUT); pinMode(Button1, INPUT);
  pinMode(Button2, INPUT); pinMode(Button3, INPUT);
}

void loop() {
  //pins are pullup so they idle high
  if(digitalRead(Button0) == 0)
  {
    Serial.println(digitalRead(Button0));
    digitalWrite(ledPin0, digitalRead(ledPin0)^1);
  }
    
  delay(20); //20 milliseconds
}
