/*
參考資料來源：
https://www.hobbyist.co.nz/?q=documentations/wiring-up-dht11-temp-humidity-sensor-to-your-arduino
*/

#include <dht.h>
#define DHT_PIN A1  //dht 類比腳位 A1
dht DHT;
void setup() {
  delay(10);
  Serial.begin(9600);
  DHT.read11(DHT_PIN);
  Serial.println("Ready");
}
void loop() {
// 讀取溫濕度
float h = DHT.humidity;
float t = DHT.temperature;
Serial.print("H:");
Serial.print(h, 1);
Serial.print("% T:");
Serial.print(t, 1);
Serial.println("*C");
delay(1000);
}
