
#include <Gtech_IRremote.h>

Gtech_IRremote com1; 
long int value=0;
long int buffer;
char operator1;
byte button;

void setup() 
{
  Serial.begin(9600);
  Serial.println("IR remote calculator");
  com1.setup();
}
void loop() 
{
  button=com1.getIR();
  if(button>0)
  {
    //Serial.println(button,HEX);
    if(button<0x3a)  // Number 0-9
    {
      if(value!=0)		
        value*=10;		
      value+=button-48;	
      Serial.println(value);
    }
    else if(button==0x3c)  // Vol- for operator '-'
    {
      buffer=value;
      value=0; 
      operator1='-';
      Serial.println("-");
    }
    else if(button==0x3d)  // Vol+ for operator '+'
    {
      buffer=value;
      value=0; 
      operator1='+';
      Serial.println("+");
    }
    else if(button==0x3e)   // EQ for Equal
    {
      if(operator1)
      {
        if(operator1=='-')
          buffer-=value;
        else if(operator1=='+')
          buffer+=value;
        Serial.println(buffer);
      }
      value = buffer = 0;
    }
    delay(100);
  }

}

