
#include "DHT.h"
#define DHT_TYPE DHT11
const int DHT_PIN = 2; //使用數位腳2
const int DHT_DELTA = -5; //設一個調整值
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  delay(100);
  Serial.begin(9600);
  dht.begin();//啟動 dht
  Serial.println("Ready");

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); //溫度 :true:華氏  false(預設):攝氏
  if (isnan(h) || isnan(t)) { //nan ->not a number
    Serial.print("NO DHT data !!");
    delay(1000);
    return;
  }
  //溫度 delta調整
  t = t + DHT_DELTA;
  Serial.print("H:");
  Serial.print(h);
  Serial.print("% T:");
  Serial.print(t);
  Serial.println("。C:");
  delay(1000);

}
