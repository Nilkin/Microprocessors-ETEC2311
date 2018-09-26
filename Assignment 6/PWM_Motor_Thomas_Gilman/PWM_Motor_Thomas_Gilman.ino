//Thomas Gilman
//Lab 6
//PWM motor
//ETEM 2311_51

int Motor = 1;
int SW0 = 14, SW1 = 15, SW2 = 16, SW3 = 17;

int SwArray[4] = {SW0, SW1, SW2, SW3};

IntervalTimer myTimer;


void setup()   
{ 
  Serial.begin(9600);
  pinMode(Motor, OUTPUT);
  for(int i=0; i<4 ; i++)
    pinMode(SwArray[i],INPUT);

  myTimer.begin(checkSwitch,1); //checkSwitchPress every microsecond
}

int Switch0Press = 0, Switch1Press = 0, Switch2Press = 0, Switch3Press = 0;
int freq = 0, on = 1;
int Timer = 0;
int Sec = 1000000;

void loop()                     
{;}

void checkSwitch()
{
  if(on)
  {
    if(Timer-- == 0)
    {
      Serial.println("motor on");
      digitalWrite(Motor, digitalRead(Motor)^1);  //toggle Motor
      Timer = freq;                               //reset Timer
    }
  }
  if(Switch0Press)          //check for press on switch0  Decrease low time on Motor
  {
    if(digitalRead(SW0) == LOW)
      Switch0Press = 0;
  }
  else                          //If Switch0 pressed down
  {
   if(digitalRead(SW0) == HIGH)//Did user release switch?
   {
    Switch0Press = 1;
    
    if(freq > 0)              //decreaseFreqeuncy timer
    {
      freq -= 100000; on = 1;
    }
    Serial.print("decreasing off time:");Serial.println(freq);
   }
  }
  if(Switch1Press)          //check for press on switch1  SET MOTOR TO MAX
  {
   if(digitalRead(SW1) == LOW)
     Switch1Press = 0;
  }
  else                           //If Switch1 pressed down
  {
   if(digitalRead(SW1) == HIGH)//Did user release switch?
   {
     Switch1Press = 1;
     if(freq > 0 || on == 0)              //decreaseFreqeuncy timer to Max
     {
       freq = 0; on = 1;
     }
     Serial.print("Max Power:");Serial.println(freq);
   }
  }
  if(Switch2Press)          //check for press on switch2  SET MOTOR TO MIN
  {
    if(digitalRead(SW2) == LOW)
      Switch2Press = 0;
  }
  else                          //If Switch2 pressed down
  {
    if(digitalRead(SW2) == HIGH)//Did user release switch?
    {
      Switch2Press = 1;
      
      if(on == 1)        //decreaseFreqeuncy timer
      {
       freq = Sec; on = 0; 
      }
      Serial.print("forever OFF:");Serial.println(freq);
    }
  }
  if(Switch3Press)          //check for press on switch3  Increase low time on Motor
  {
    if(digitalRead(SW3) == LOW)
      Switch3Press = 0;
  }
  else                           //If Switch3 pressed down
  {
    if(digitalRead(SW3) == HIGH)//Did user release switch?
    {
      Switch3Press = 1;
      if(freq != Sec)              //increase Frequency timer
      {
       freq += 100000; on = 1;
      }
      else
      {
       on = 0;
      }
      Serial.print("increasing off time:");Serial.println(freq);
    }
  }
}
