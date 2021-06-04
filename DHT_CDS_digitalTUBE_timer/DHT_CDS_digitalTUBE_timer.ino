/*
 * 將CDS與DHT11(溫濕度)都可以顯示在Tube上
 * 可以利用 Timer 來實現
 * 閃爍顯示
 * 0321 H50.0 26.2C
*/
#include <Timer.h>
#include <DHT.h>
#include <TridentTD_7Segs74HC595.h>

#define DHT_TYPE DHT11
#define SCLK 4
#define RCLK 5
#define DIO  6

const int DHT_PIN = 2; // 使用數位腳 2
const int DHT_DELTA = -5;
const int CDS_PIN = A3;
const int LED_PIN = 7;

DHT dht(DHT_PIN, DHT_TYPE); // 初始化 dht
TridentTD_7Segs74HC595  tube( SCLK, RCLK, DIO); // 初始化 tube
Timer timer; // 宣告 Timer 物件

int   cdsValueThreshold = 500; // 門檻值(小於：燈亮，大於：燈滅)
int   cdsValue    = 0; // CDS資料
float humiValue = 0.0; // 濕度資料
float tempValue = 0.0; // 溫度資料

void setup() {
  delay(100);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  dht.begin(); // 啟動 dht
  tube.init();  // 啟動 tube
  
  // 配置排程
  timer.every(1000, setCDS);   // 每1000ms取得CDS資料乙次
  timer.every(1000, checkLED); // 每1000ms檢查是否要開燈
  timer.every(1000, setDHT);   // 每1000ms取得最新溫濕度乙次
  timer.every(10,   playTube); // 每10ms執行Tube顯示乙次

  Serial.println("Ready");

}

void checkLED() {
  if(cdsValue < cdsValueThreshold) {
    digitalWrite(LED_PIN, HIGH);  
  } else {
    digitalWrite(LED_PIN, LOW);  
  }  
}

void setCDS() {
  cdsValue = analogRead(CDS_PIN); // 0~1023
  Serial.print("CDS: ");
  Serial.println(cdsValue);  
}

// 取得最新溫濕度
void setDHT() {
  humiValue = dht.readHumidity(); // 濕度
  tempValue = dht.readTemperature(false); // 溫度 true: 華氏, false(預設): 攝氏
  if (isnan(humiValue) || isnan(tempValue)) { // nan -> not a number
    Serial.println("No dht data !!");
    delay(1000);
    return;
  }
  // 溫度 delta 調整
  tempValue = tempValue + DHT_DELTA;
  Serial.print("H:");
  Serial.print(humiValue, 1);
  Serial.print("% T:");
  Serial.print(tempValue, 2);
  Serial.println("*C");
}

// 執行Tube
void playTube() {
  tube.setText(String(cdsValue));
  delay(500);
  tube.setText("H" + String(humiValue, 1));
  delay(500);
  tube.setText(String(tempValue) + "C");
  delay(500);
}

void loop() {
  timer.update();
}
