//Thomas Gilman
//Lab 5
//Interrupts 2_5
//ETEM 2311_51

int SPEAKER = 0;
int SW0 = 14, SW1 = 15;

IntervalTimer myTimer;
int Switch2Press = 0, Switch1Press = 0, changeInSwitch2 = 0;
int SwCount = 0, Delay = 30;

void setup()   
{ 
  pinMode(SPEAKER,OUTPUT);
  pinMode(SW0,INPUT); pinMode(SW1,INPUT);
  myTimer.begin(checkSwitch,20000); //checkSwitchPress every 20miliseconds
}

void loop()                     
{;}

void checkSwitch()
{
  if(Switch2Press != 1)         //Not Hitting Speaker
  {
    if(changeInSwitch2 == 0)   //check for press on switch2
    {
      if(digitalRead(SW1) == LOW)
      {
        changeInSwitch2 = 1;
      }
    }
    else                          //If Switch2 pressed down
    {
      if(digitalRead(SW1) == HIGH)//Did user release switch?
      {
        Switch2Press = 1;
        changeInSwitch2 = 0;
      }
    }
    
    if(Switch1Press == 1)
    {
      if(digitalRead(SW0) == HIGH)//switch released
      {
        SwCount++;                //Inc count
        Switch1Press = 0;      //Switch no longer pressed
      }
    }
    else  //Switch not pressed, check if down
    {
      if(digitalRead(SW0) == LOW)
        Switch1Press = 1;     //Switch pressed wait for lift
    }
  }
  else
  {
    if(SwCount != 0)            //Still need to blink
    {
      if(Delay == 0)
      {
        tone(SPEAKER, 3000, 30);
        SwCount--;
        Delay = 30;
      }
      else
        Delay--;
    }
    else                        //done blinking for SwCount times
      Switch2Press = 0;
  }
}
