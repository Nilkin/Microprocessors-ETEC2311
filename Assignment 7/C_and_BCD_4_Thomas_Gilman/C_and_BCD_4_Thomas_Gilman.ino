//Thomas Gilman
//Lab 7_4
//C and BCD Lab
//ETEM 2311_51

int LED0 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(LED0, OUTPUT);
}

void loop() {
  tone(LED0, 20); //freq = 20HZ
}
