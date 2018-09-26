//Thomas Gilman
//Lab 5
//Interrupts 2_3
//ETEM 2311_51

int SPEAKER = 0;

IntervalTimer SpeakerTimer;

void setup()   
{ 
  pinMode(SPEAKER,OUTPUT);
  SpeakerTimer.begin(toggleSpeaker,3000); //go through every 3milliseconds (1/300 = 3.333milliseconds)
}

void loop()                     
{;}

void toggleSpeaker()
{
  digitalWrite(SPEAKER,digitalRead(SPEAKER)^1);
}
