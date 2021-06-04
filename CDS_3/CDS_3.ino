//透過 PC 輸入 STOP 顯示 STOP
//透過 PC 輸入 1234 顯示1234
//接線方式
/*
   GND:GND
   dio:6
   rc:5
   sc:4
   vcc:5v
*/
#include<DigitalTube.h>
DigitalTube dis(4, 5, 6); //sclk,rclk,dio
const int VOLTAGE_PIN =A0;
const int CDS_PIN = A3;
const int LED_PIN =7;


void setup() {
  delay(100);
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  dis.begin();
  Serial.print("Ready");

}

void loop() {
  
    int cdsvalue = analogRead(CDS_PIN);//0-1023
    Serial.print(cdsvalue);
    dis.print(cdsvalue);
    if (cdsvalue <500)
    {
      digitalWrite(LED_PIN,HIGH);
      }else{
        digitalWrite(LED_PIN,LOW);
        }
    delay(500);

  }
