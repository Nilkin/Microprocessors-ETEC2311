//Thomas Gilman
//Lab 5
//Interrupts 2_6
//ETEM 2311_51

int SPEAKER = 0;
int SW0 = 14, SW1 = 15, SW2 = 16, SW3 = 17, SwArray[4] = {SW0, SW1, SW2, SW3};

IntervalTimer myTimer;
int bUp1 = 3822, bUp2 = 3033, bUp3 = 2407, bUp4 = 2024;
int Freq1 = 3822, Freq2 = 3033, Freq3 = 2407, Freq4 = 2024;

void setup()   
{ 
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  for(int i=0; i<4 ; i++)
    pinMode(SwArray[i],INPUT);

  myTimer.begin(checkSwitch,1); //checkSwitchPress every microsecond
}

void loop()                     
{;}

void checkSwitch()
{
  if(digitalRead(SW0) == LOW)
  {
    if(Freq1 == 0)
    {
      digitalWrite(SPEAKER, digitalRead(SPEAKER)^1);
      Freq1 = bUp1;
    }
    else
      Freq1--;
  }
  if(digitalRead(SW1) == LOW)
  {
    if(Freq2 == 0)
    {
      digitalWrite(SPEAKER, digitalRead(SPEAKER)^1);
      Freq2 = bUp2;
    }
    else
      Freq2--;
  }
  if(digitalRead(SW2) == LOW)
  {
    if(Freq3 == 0)
    {
      digitalWrite(SPEAKER, digitalRead(SPEAKER)^1);
      Freq3 = bUp3;
    }
    else
      Freq3--;
  }
  if(digitalRead(SW3) == LOW)
  {
    if(Freq4 == 0)
    {
      digitalWrite(SPEAKER, digitalRead(SPEAKER)^1);
      Freq4 = bUp1;
    }
    else
      Freq4--;
  }
}
