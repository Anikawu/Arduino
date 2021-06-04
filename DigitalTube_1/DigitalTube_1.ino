/*
* lib:https://github.com/artronshop/DigitalTube
* 接線方式:
* GND: GND
* DIO: 6
* RCLK: 5
* SCLK: 4
* VCC: 5V
*/
#include <DigitalTube.h>
DigitalTube dis(4,5,6);

int i=6000;//1分鐘倒數計時
void setup() {
  Serial.begin(9600);
  dis.begin();
  Serial.println("Ready");

}

void loop() {
  dis.print(i);
  if(i<0){i=6000;}
  i--;
  delay(10);

}
