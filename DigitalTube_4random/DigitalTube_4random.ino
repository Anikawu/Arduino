
#include<DigitalTube.h>
DigitalTube dis(4, 5, 6);
const int v_pin = A0;
void setup() {
  Serial.begin(9600);
  dis.begin();
  Serial.print("Ready");

}
/*
  void loop() {

  float temp =random(230,259)/10.0;
  int tempInt =(int)(temp*10);//234

  dis.show(tempInt/100,tempInt/10%10+10,tempInt%10,'C');//23.4c
  delay(2000);

  }*/

//顯示電池電壓   A0接正極 GND接負極
void loop() {
  float data = analogRead(v_pin);//類比資料讀取(0-1023)

  int volatge = data / 1024.0 * 5.0;
  int volatgeInt = (int)(volatge * 100);
  Serial.print("data= ");
  Serial.print(data);
  Serial.print(", volatge= ");
  Serial.println(volatge);
  Serial.print(", volatgeInt= ");
  Serial.println(volatgeInt);


  dis.show(volatgeInt / 1000, volatgeInt / 100 % 10, volatgeInt / 10 % 10, volatgeInt % 10); //
  delay(1000);
}
