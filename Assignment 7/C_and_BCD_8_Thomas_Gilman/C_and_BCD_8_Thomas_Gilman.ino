//Thomas Gilman
//Lab 6_7
//C_and_BCD
//ETEM 2311_51


int LED0 = 0, LED1 = 1, LED2 = 2, LED3 = 3, LED4 = 4, LED5 = 5, LED6 = 6, LED7 = 7;
int LedArray[8] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7};
int LowerNib = B0001;
int UpperNib = B00010000;
int halfSecond = 1;
IntervalTimer myTimer;

int num = {0x06,5B,4F,65,6D,7C,7,7F,67}

void setup()   
{ 
  DDRD = 0xff; //ports 0-7
  Serial.begin(9600);
  myTimer.begin(checkSwitch,100000);  //Every 1/2 Second
}

void loop()
{;}

void checkSwitch()
{
  PORTD = LowerNib | UpperNib;
  if(halfSecond-- == 0)
  {
    if(UpperNib == B11110000)
      UpperNib = B00010000;
    else
      UpperNib = UpperNib + B10000; //shift bit in at bit 4 to increment
    halfSecond = 1;                 //reset second timer
  }
  if(LowerNib == B1111)
    LowerNib = B0001;
  else
    LowerNib = LowerNib + B1; //shift bit in at bit 0
} 
