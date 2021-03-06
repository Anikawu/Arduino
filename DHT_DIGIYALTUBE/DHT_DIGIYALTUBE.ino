
#include "DHT.h"
#define DHT_TYPE DHT11
#include <TridentTD_7Segs74HC595.h>


//DigitalTube dis(4, 5, 6);
const int CDS_PIN = A3;
const int DHT_PIN = 2; //使用數位腳2
const int DHT_DELTA = -5; //設一個調整值


#define SCLK        4
#define RCLK        5
#define DIO         6

DHT dht(DHT_PIN, DHT_TYPE); //初始化 dht
TridentTD_7Segs74HC595  tube( SCLK, RCLK, DIO);//初始化


void setup() {
  delay(100);
  Serial.begin(9600);
  //dis.begin();
  dht.begin();//啟動 dht
  tube.init();  //啟動tube
  tube.setTextScroll("READY...");
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
  Serial.print(h,1);
  Serial.print("% T:");
  Serial.print(t,2);
  Serial.println("。C:");
  tube.setTextScroll("H."+String(h,1)+" "+"t."+String(t)+ "c");

  delay(1000);
}
