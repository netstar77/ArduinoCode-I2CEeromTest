/********************
 * 8K I2C memory test
 * writhing all of the cells of memory with a number
 * than read them and display via serial
 */
#include <Wire.h>

#define ADDR 0x50           //(0xA0) default I2C EEPROM address


void setup() {
  int i;

  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();

  
  for( int i = 0; i < 1024; i++){   // This loop writes every one of 1024 cell of EEPROM with a number
    writeI2CByte(i, (/*i &*/ 0x0FF));
  }


  for( int i = 0; i < 1024; i++){   // This loop reads memory cells and displays value via serial
    if( !(i%16) )
      Serial.print("\n\r");         // print new line and carriage return every 16 elements
    Serial.print("0x");
    Serial.print(readI2CByte(i), HEX);
    Serial.print(", ");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void writeI2CByte(word reg_addr, byte data)
{
  Wire.beginTransmission(ADDR | ((byte)((reg_addr&0x0300)>>8)));     // Start transmittion and send I2C address (7-bit format)(eeprom addres is 0xA0 -> 7-bit is 0x50)
  Wire.write((byte)(reg_addr & 0x00FF));
  Wire.write(data);
  Wire.endTransmission();
  delay(5);                         // after I2C write eeprom require 5ms delay to finish physical write
}

byte readI2CByte(word reg_addr)
{
  byte data;
  byte dev_addr = ADDR | ((byte)((reg_addr&0x0300)>>8));
  Wire.beginTransmission(dev_addr);
  Wire.write((byte)(reg_addr & 0x00FF));
  Wire.endTransmission();
  Wire.requestFrom(dev_addr, 1); //retrieve 1 returned byte
  delay(1);
  if(Wire.available()){
    data = Wire.read();
  }
  return data;
}
