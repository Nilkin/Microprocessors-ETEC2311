//Thomas Gilman
//Lab 6_7
//C_and_BCD
//ETEM 2311_51

IntervalTimer myTimer;

void setup()   
{ 
  Serial.begin(9600);
  myTimer.begin(checkSwitch,1000000); //checkSwitchPress every second
}

void loop()                     
{;}

void checkSwitch()
{
  Serial.println("Hello");
}
