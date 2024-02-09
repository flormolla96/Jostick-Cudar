#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>
#include <SPI.h>
const int pinCE = 8;
const int pinCSN = 7;
RF24 radio(pinCE, pinCSN);
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
char data[16],ch,TxData[]="Hola";
void setup(void)
{
   Serial.begin(115200);
   printf_begin();
   radio.begin();
   radio.openReadingPipe(0,pipe);
   radio.openWritingPipe(pipe);
   radio.setAutoAck(false);
   radio.setPALevel(3,0);
   radio.closeReadingPipe(1);
   radio.startListening();
   //radio.stopListening();
   //radio.setChannel(7)
   if(!radio.isChipConnected ())
    Serial.println("Niet");

   radio.printPrettyDetails();
}
 
void loop(void)
{
  int16_t X=0,Y=0;
  uint8_t Bat=0,DIO=0;
   if (radio.available())
   {
      radio.read(data, sizeof data); 
      X=((data[4]<<8)&0xFF00)|(data[5]&0xFF);
      Y=((data[6]<<8)&0xFF00)|(data[7]&0xFF);;
      Bat=data[9];
      DIO=data[8];
      Serial.println("Recivido:");
    
      Serial.println(X);
      Serial.println(Y);
      Serial.println(Bat);
      Serial.println(DIO);
      radio.stopListening();
      delay(300);
      radio.write (TxData, sizeof TxData);
      
      radio.startListening();
      X=0;
      Y=0;
      Bat=0;
      DIO=0;
      
 
   }
}
