#include <Arduino.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>


const int chipSelect = 10;

MPU6050 mpu6050(Wire);

long timer = 0;


int led = 8;

const byte interruptPin = 3;
volatile byte state = 0;

void blink();
void sound();
File dataFile1, dataFile2, dataFile3;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
  delay(1000);
  
   Wire.begin();
   mpu6050.begin();
   mpu6050.calcGyroOffsets(true);

   
}

 
 
void loop() 
{
  Serial.println(digitalRead(3));
   if (state ==1)
   {  sound();
      dataFile1 = SD.open("walk.txt", FILE_WRITE);
      for (int i = 0; i < 500; i++)
      {
        digitalWrite(led,HIGH);
        mpu6050.update();  
    
        dataFile1.print(mpu6050.getTemp());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getAccX());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getAccY());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getAccZ());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getGyroX());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getGyroY());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getGyroZ());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getAccAngleX());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getAccAngleY());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getGyroAngleX());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getGyroAngleY());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getGyroAngleZ());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getAngleX());
        dataFile1.print("\t");
        dataFile1.print(mpu6050.getAngleY());
        dataFile1.print("\t");
        dataFile1.println(mpu6050.getAngleZ());
        delay(10);
      }
      digitalWrite(led,LOW);
      sound();
      delay(1000);
      dataFile1.close();

      dataFile2 = SD.open("stand.txt", FILE_WRITE);
      for (int i = 0; i < 500; i++)
      {
        digitalWrite(led,HIGH);
        mpu6050.update();  
        dataFile2.print(mpu6050.getTemp());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getAccX());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getAccY());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getAccZ());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getGyroX());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getGyroY());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getGyroZ());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getAccAngleX());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getAccAngleY());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getGyroAngleX());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getGyroAngleY());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getGyroAngleZ());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getAngleX());
        dataFile2.print("\t");
        dataFile2.print(mpu6050.getAngleY());
        dataFile2.print("\t");
        dataFile2.println(mpu6050.getAngleZ());
        delay(10);
      }
      digitalWrite(led,LOW);
      sound();
      delay(1000);
      dataFile2.close();

      dataFile3 = SD.open("jump.txt", FILE_WRITE);
      for (int i = 0; i < 500; i++)
      {
        digitalWrite(led,HIGH);
        mpu6050.update();  
        dataFile3.print(mpu6050.getTemp());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getAccX());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getAccY());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getAccZ());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getGyroX());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getGyroY());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getGyroZ());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getAccAngleX());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getAccAngleY());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getGyroAngleX());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getGyroAngleY());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getGyroAngleZ());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getAngleX());
        dataFile3.print("\t");
        dataFile3.print(mpu6050.getAngleY());
        dataFile3.print("\t");
        dataFile3.println(mpu6050.getAngleZ());
        delay(10);
      }
      digitalWrite(led,LOW);
      sound();
      delay(1000);
      dataFile3.close();
  
    state = 0; 
     }
  else
  {
    
    digitalWrite(led,HIGH);
    delay(200);
    digitalWrite(led,LOW);
    delay(200);

  }
  
}
void blink() 
{
   state = 1;
}

void sound()
{
  tone(9,260,500);
}

