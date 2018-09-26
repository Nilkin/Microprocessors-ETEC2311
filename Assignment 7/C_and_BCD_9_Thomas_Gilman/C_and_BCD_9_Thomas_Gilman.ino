//Thomas Gilman
//Lab 6_9
//C_and_BCD
//ETEM 2311_51


int LED0 = 0, LED1 = 1, LED2 = 2, LED3 = 3, LED4 = 4, LED5 = 5, LED6 = 6, LED7 = 7;
int BCD0 = 8, BCD1 = 9;
int SW0 = 14, SW1 = 15, SW2 = 16, SW3 = 17;

int LedArray[8] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7};
int SwArray[4] = {SW0, SW1, SW2, SW3};
IntervalTimer myTimer;

int num[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67}; //0,1,2,3,4,5,6,7,8,9
int indexBCD0 = 1, indexBCD1 = 6; //Index locations for numbers to display
int secondTimer = 1000000, BCD_DelayTimer = 1000;
int switch0Press = 0, countDown = 0;

void setup()   
{ 
  Serial.begin(9600);
  DDRD = 0xff; //ports 0-7                      //LEDS
  for(int index = 0; index < 4; index++)        //Switches
    pinMode(SwArray[index], INPUT);
  pinMode(BCD0, OUTPUT); pinMode(BCD1, OUTPUT); //BCD togglers
  
  myTimer.begin(checkSwitch,1);                 //Every milliSecond
}
void loop()
{;}
void checkSwitch()
{
  if(countDown)
  {
    if(indexBCD1 == 0 && indexBCD0 == 0)
    {
      indexBCD0 = 1; indexBCD1 = 6;     //reset timer
      countDown = 0;                    //wait till next switch press
      PORTD = 0x00;
    }
    if(indexBCD1 == 0) //9 seconds left
    {
      --indexBCD0;
      indexBCD1 = 9;
    }
    if(secondTimer-- == 0) //SECONDS BCD
    {
      indexBCD1--;      //decrement second
      secondTimer = 100000;
      
    }
    if(BCD_DelayTimer-- >= 500)
    {
      digitalWrite(BCD1, HIGH);
      PORTD = num[indexBCD1];
      digitalWrite(BCD1, LOW);
    }
    else if(BCD_DelayTimer-- < 500 && BCD_DelayTimer > 0)
    {
      //TEN SECONDS BCD
      digitalWrite(BCD0, HIGH);
      PORTD = num[indexBCD0];
      digitalWrite(BCD0, LOW);
    }
    else
      BCD_DelayTimer = 1000;
  }
  else
  {
    if(switch0Press)
    {
      if(digitalRead(SW0) == HIGH)
      {
        switch0Press = 0;       //reset SwitchCheck
        countDown = 1;          //begin countDown
      }
    }
    else
    {
      if(digitalRead(SW0) == LOW)
        switch0Press = 1;
    }
  }
} 
