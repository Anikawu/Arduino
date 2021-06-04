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
  
//show text
//HELLO跑馬燈
dis.show(' ',' ',' ',' ');
delay(500);
dis.show(' ',' ',' ','H');
delay(500);
dis.show(' ',' ','H','E');
delay(500);
dis.show(' ','H','E','L');
delay(500);
dis.show('H','E','L','L');
delay(500);
dis.show('L','L','O',' ');
delay(500);
dis.show('L','O',' ',' ');
delay(500);
dis.show('O',' ',' ',' ');
delay(500);
dis.show(' ',' ',' ',' ');
delay(500);
 for(int i=9;i>0;i--)
 {
  dis.print(i);
  delay(500);
  }
  dis.show('S','T','O','P');
  delay(300);
  dis.show(' ',' ',' ',' ');
  delay(300);
   dis.show('S','T','O','P');
  delay(300);
  dis.show(' ',' ',' ',' ');
  delay(300);
   dis.show('S','T','O','P');
  delay(300);
  dis.show(' ',' ',' ',' ');
  delay(2000);
}
