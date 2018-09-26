//Thomas Gilman
//Lab 7_1
//C and BCD Lab
//ETEM 2311_51

int LED0 = 0, LED1 = 1, LED2 = 2, LED3 = 3, LED4 = 4, LED5 = 5, LED6 = 6, LED7 = 7;
int SW0 = 14, SW1 = 15, SW2 = 16, SW3 = 17;

int LedArray[8] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7};
int SwArray[4] = {SW0, SW1, SW2, SW3};

IntervalTimer myTimer;
int Switch0Press = 0, Switch1Press = 0, Switch2Press = 0, Switch3Press = 0;
void setup()   
{ 
  Serial.begin(9600);
  for(int i=0; i<8 ; i++)
  {
    pinMode(LedArray[i],OUTPUT);
    if(i<4)
      pinMode(SwArray[i],INPUT);
  }
}

void loop()                     
{
  for(int index = 0; index <  8; index++)
  {  
    digitalWrite(LedArray[index], digitalRead(LedArray[index])^1);  //xor the port
    delay(200);  //20milisecond Delay
  }
}

