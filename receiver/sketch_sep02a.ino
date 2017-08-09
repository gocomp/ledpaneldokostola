/*
  Example of how to drive a seven segment display using HCF4511 or similar
 
 This sketch drive the display in order to show a number from 0 to 9 everytime a button connected to A0 is pressed.
  
author: Arturo Guadalupi <a.guadalupi@arduino.cc>
 */
#include <RCSwitch.h>
#include <cd4511.h>

CD4511 cd4511(8,7,6,5,true);

RCSwitch mySwitch = RCSwitch();

//Declaration of Arduino pins used as HCF4511 inputs
const int A=13;
const int B=11;
const int C=10;
const int D=9;

 int count = 0;
//GRobotronics 28-5-2014

// Arduino pins connected to the 4511
const uint8_t LedA = 8;
const uint8_t LedB = 7;
const uint8_t LedC = 6;
const uint8_t LedD = 5;




const int transmit_pin = 12;
//  const uint8_t Led4 = 2;
  int i=1,uj=0;
int szam1=0,szam2=0,szam3=0;
  int oszl=1;

  
void setup()
{

  mySwitch.enableReceive(0); 
  // Let the Arduino know which pins go where
   Serial.begin(9600);

  //pinMode(A, OUTPUT);
 // pinMode(B, OUTPUT);
//  pinMode(C, OUTPUT);
//  pinMode(D, OUTPUT);

  
   //   digitalWrite(D, LOW);
    // digitalWrite(A, LOW); //bkapcsol
  
   //  digitalWrite(B, HIGH);
   //     digitalWrite(C, LOW);

       
      
  //    digitalWrite(A, HIGH);
//      digitalWrite(B, LOW); //bkapcsol
//      set_number(szam2);
//      digitalWrite(B, HIGH);
//      digitalWrite(C, LOW); //bkapcsol
//      set_number(szam3);
//      digitalWrite(C, HIGH);
   

  
//  pinMode(LedF, OUTPUT);
  

}

#define T(v,b)  (v & (1<<b) ? HIGH : LOW)

void show( unsigned int value )
{
  
  int v0 = T(value, 0);
  int v1 = T(value, 1);
  int v2 = T(value, 2);
  int v3 = T(value, 3);
  
  if ( value <= 9 )
  {
    // enable the latch so we can write
    //digitalWrite( LATCH_ENABLE, LOW );
  
    digitalWrite(LedA, v0);
    digitalWrite(LedB, v1);
    digitalWrite(LedC, v2);
    digitalWrite(LedD, v3);
   
   
   Serial.print(v0);
   Serial.print(",");
   Serial.print(v1);
   Serial.print(",");
   Serial.print(v2);
   Serial.print(",");
   Serial.print(v3);
   Serial.println();
   
    
  
    // disable the latch now that we're done writing
    //digitalWrite( LATCH_ENABLE, HIGH );
  }
}


  
void loop()
{

//for ( int i = 0; i <= 9; i++ )
 // {
 //   show(i) ;
 //  delay(500) ;  // msec
 // }
  
  for (int i = 0; i < 10; i++) { 
    cd4511.write(i);
    delay(2000);
    Serial.print(i);
  }

 
if (mySwitch.available()) {
    
    Serial.print("Received ");
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
     // Serial.print("Unknown encoding");
    } else {

       if ((value == 555)&&(count!=value) )
     {
        if (count==10) {count=0;}
        kiir(count);
        delay(250);
         count = mySwitch.getReceivedValue(); 
        
     }
else {     
       count = mySwitch.getReceivedValue(); 
}
    }

    mySwitch.resetAvailable();
    
   
  }
    

 // if (Serial.available()) {
 //   delay(100); //allows all serial sent to be received together
 //   while(Serial.available() && i<4) {
//      str[i++] = Serial.read();
//    }
//    str[i++]='\0';
//  }
  

  }



void kiir(int szam )
{


switch (oszl) {
    case 1:  
       szam3=0;
         szam2=0;
         szam1= szam;
         oszl++;
      break;
    case 2:
         szam3=0;
         szam2=szam1;
         szam1=szam;
         oszl++;
      break;
      case 3:
         szam3=szam2;
         szam2=szam1;
         szam1=szam;
         oszl=1;
      break;
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
  

     digitalWrite(6, LOW); //bkapcsol
     set_number(szam1);
    digitalWrite(6, HIGH);
      digitalWrite(7, LOW); //bkapcsol
      set_number(szam2);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW); //bkapcsol
      set_number(szam3);
     digitalWrite(8, HIGH);

    Serial.print(szam3);  
    Serial.print(szam2);  
    Serial.println(szam1);  
      
  }



int my_atoi(char *p) {
    int k = 0;
    while (*p) {
        k = (k<<3)+(k<<1)+(*p)-'0';
        p++;
    }
    return k;
}


void to_BCD()
{
    if (count == 0) //write 0000
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 1) //write 0001
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 2) //write 0010
    {
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 3) //write 0011
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 4) //write 0100
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 5) //write 0101
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 6) //write 0110
    {
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 7) //write 0111
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 8) //write 1000
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    }
     
    if (count == 9) //write 1001
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    } 
}


void set_number(const unsigned n) {
  static const struct number {
    uint8_t d;
    uint8_t c;
    uint8_t b;
    uint8_t a;
  } numbers[] = {
    { LOW,  LOW,  LOW,  LOW}, /* 0 */
    { LOW,  LOW,  LOW, HIGH}, /* 1 */
    { LOW,  LOW, HIGH,  LOW}, /* 2 */
    { LOW,  LOW, HIGH, HIGH}, /* 3 */
    { LOW, HIGH,  LOW,  LOW}, /* 4 */
    { LOW, HIGH,  LOW, HIGH}, /* 5 */
    { LOW, HIGH, HIGH,  LOW}, /* 6 */
    { LOW, HIGH, HIGH, HIGH}, /* 7 */
    {HIGH,  LOW,  LOW,  LOW}, /* 8 */
    {HIGH,  LOW,  LOW, HIGH}, /* 9 */
  };
  
  digitalWrite(LedA, numbers[n%10].a);
  digitalWrite(LedB, numbers[n%10].b);
  digitalWrite(LedC, numbers[n%10].c);
  digitalWrite(LedD, numbers[n%10].d);
}
