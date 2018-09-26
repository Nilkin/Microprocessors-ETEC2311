//Thomas Gilman
//Lab 5
//Interrupts 2_2
//ETEM 2311_51

int LED0 = 0, LED1 = 1, LED2 = 2, LED3 = 3, LED4 = 4, LED5 = 5, LED6 = 6, LED7 = 7;
int SW0 = 14, SW1 = 15, SW2 = 16, SW3 = 17;

int LedArray[8] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7};
int SwArray[4] = {SW0, SW1, SW2, SW3};

IntervalTimer Led0Timer, Led1Timer, Led2Timer, Led3Timer;

void setup()   
{ 
  Serial.begin(9600);
  for(int i=0; i<8 ; i++)
  {
    pinMode(LedArray[i],OUTPUT);
    if(i<4)
      pinMode(SwArray[i],INPUT);
  }
  Led0Timer.begin(toggleLed0,250000); //blink every 500miliseconds (every half second)
  Led1Timer.begin(toggleLed1,500000); //blink every 1second
  Led2Timer.begin(toggleLed2,2500000); //blink every 5seconds
  Led3Timer.begin(toggleLed3,5000000); //blink every 10seconds
}

void loop()                     
{;}

void toggleLed0()
{
  digitalWrite(LED0, digitalRead(LED0)^1); //xor led
}
void toggleLed1()
{
  digitalWrite(LED1, digitalRead(LED1)^1); //xor led
}
void toggleLed2()
{
  digitalWrite(LED2, digitalRead(LED2)^1); //xor led
}
void toggleLed3()
{
  digitalWrite(LED3, digitalRead(LED3)^1); //xor led
}

