//Thomas Gilman
//Lab 5
//Interrupts 2_4
//ETEM 2311_51

int SPEAKER = 0;
int Second = 1000000;
int halfSTimer = 500000;
int Octave = 200;     //.2milliseconds
int freqTimer = 200;
int OctaveIndex = 0;
int waiting = 0;

IntervalTimer SpeakerTimer;

void setup()   
{ 
  pinMode(SPEAKER,OUTPUT);
  SpeakerTimer.begin(toggleSpeaker,1); //go through every microsecond
}

void loop()                     
{;}

void toggleSpeaker()
{
  if( waiting != 1)
  {
    if(Second-- != 0) //has it been a second?
    {
      if(freqTimer-- != 0);//is freqTimer up?
      else
      {
        digitalWrite(SPEAKER, digitalRead(SPEAKER)^1);//toggle speaker
        freqTimer = Octave;  //reset freqTimer
      }
    }
    else
    {
      waiting = 1;  //now waiting
      Second = 1000000; //reset SecondTimer
    }
  }
  else
  {
    if(halfSTimer-- != 0)
    {;}
    else
    {
      halfSTimer = 500000;//resetWaitTimer
      if(OctaveIndex == 7)
      {
        Octave = 200;   //reset octave
        OctaveIndex = 0;
      }
      else
      {
        OctaveIndex++;
        Octave = Octave*2;    //next octave
      }
      freqTimer = Octave;
      waiting = 0;     //not waiting anymore
    }
  } 
}
