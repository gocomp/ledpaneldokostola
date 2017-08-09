int ArduinoPins_Row_OUTPUT[] = {9,10,11,12};
int ArduinoPins_Col_INPUT[] = {5,6,7,8};
int Row_1_Data[] = {1,4,7,999};
int Row_2_Data[] = {2,5,8,888};
int Row_3_Data[] = {3,6,9,444};
int Row_4_Data[] = {111,10,777,10}; //111=* 777=napocska
int *Matrix[] ={Row_1_Data,Row_2_Data,Row_3_Data,Row_4_Data} ;
const int transmit_pin = 2;


#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup()
{
 // Initialise the IO and ISR
  mySwitch.enableTransmit(transmit_pin);
  
//Serial.begin(9600);
for (int i = 0; i<=3;i++)
{
pinMode(ArduinoPins_Row_OUTPUT[i],OUTPUT);
digitalWrite(ArduinoPins_Row_OUTPUT[i],HIGH);
pinMode(ArduinoPins_Col_INPUT[i],INPUT);
digitalWrite(ArduinoPins_Col_INPUT[i],HIGH);//pull up resistor
}
}



void loop()
{ 

for (int row = 0; row<=3;row++)
{
for (int col = 0; col<=3;col++)
{
digitalWrite(ArduinoPins_Row_OUTPUT[row],LOW);
if (digitalRead(ArduinoPins_Col_INPUT[col]) == LOW)
{
   mySwitch.send(Matrix[col] [row], 24);
   mySwitch.send(555, 24);
 //  Serial.println(Matrix[col] [row]);
   //delay(50);
}
digitalWrite(ArduinoPins_Row_OUTPUT[row],HIGH);
}
}

}


