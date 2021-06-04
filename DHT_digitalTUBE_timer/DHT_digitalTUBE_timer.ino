/*
跑馬燈顯示
H50.0 26.28C
*/
#include <Timer.h>
#include <DHT.h>
#include <TridentTD_7Segs74HC595.h>



#define DHT_TYPE DHT11
#define SCLK 4
#define RCLK 5
#define DIO 6



const int DHT_PIN = 2; // 使用數位腳 2
const int DHT_DELTA = -5;



DHT dht(DHT_PIN, DHT_TYPE); // 初始化 dht
TridentTD_7Segs74HC595 tube( SCLK, RCLK, DIO); // 初始化 tube
Timer timer; // 宣告 Timer 物件
float h = 0.0; // 濕度資料
float t = 0.0; // 溫度資料



void setup() {
delay(100);
Serial.begin(9600);
dht.begin(); // 啟動 dht
tube.init(); // 啟動 tube
tube.setTextScroll("READY...");
// 配置排程
timer.every(1000, setDHT); // 每1000ms取得最新溫濕度乙次
timer.every(1000, playScroll); // 每1000ms執行跑馬燈乙次
Serial.println("Ready");
}



// 取得最新溫濕度
void setDHT() {
h = dht.readHumidity(); // 濕度
t = dht.readTemperature(false); // 溫度 true: 華氏, false(預設): 攝氏
if (isnan(h) || isnan(t)) { // nan -> not a number
Serial.println("No dht data !!");
delay(1000);
return;
}
// 溫度 delta 調整
t = t + DHT_DELTA;
Serial.print("H:");
Serial.print(h, 1);
Serial.print("% T:");
Serial.print(t, 2);
Serial.println("*C");
}

// 執行跑馬燈
void playScroll() {
tube.setTextScroll("H" + String(h, 1) + " " + String(t) + "C");
}



void loop() {
timer.update();
}
