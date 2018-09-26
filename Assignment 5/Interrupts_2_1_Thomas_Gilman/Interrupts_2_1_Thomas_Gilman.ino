//Thomas Gilman
//Lab 5
//Interrupts 2_1
//ETEM 2311_51

int LED0 = 0, LED1 = 1, LED2 = 2, LED3 = 3, LED4 = 4, LED5 = 5, LED6 = 6, LED7 = 7;
int SW0 = 14, SW1 = 15, SW2 = 16, SW3 = 17;

int LedArray[8] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7};
int SwArray[4] = {SW0, SW1, SW2, SW3};

IntervalTimer myTimer;
int Switch2Press = 0, Switch1Press = 0, changeInSwitch2 = 0;
int SwCount = 0, Delay = 30;

void setup()   
{ 
  Serial.begin(9600);
  for(int i=0; i<8 ; i++)
  {
    pinMode(LedArray[i],OUTPUT);
    if(i<4)
      pinMode(SwArray[i],INPUT);
  }
  myTimer.begin(checkSwitch,20000); //checkSwitchPress every 20miliseconds
}

void loop()                     
{;}

void checkSwitch()
{
  if(Switch2Press != 1)         //Not Blinking
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
        if(digitalRead(LED0) != HIGH)
          digitalWrite(LED0, HIGH);
        else
        {
          digitalWrite(LED0, LOW);
          Serial.println(SwCount);
          SwCount--;
        }
        Delay = 30;
      }
      else
        Delay--;
    }
    else                        //done blinking for SwCount times
      Switch2Press = 0;
  }
}
