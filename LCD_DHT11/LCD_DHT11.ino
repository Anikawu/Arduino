/*
   接線
   LCD i2c 接線
   GND -GND
   VCC - 5V
   SDA - A4
   SCL - A5
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
const int LED_PIN = 7;
const int BUZEER_PIN = 3;
const int BUTTIN_PIN = 8;

DHT dht(DHT_PIN, DHT_TYPE); // 初始化 dht
TridentTD_7Segs74HC595  tube( SCLK, RCLK, DIO); // 初始化 tube
Timer timer1, timer2, timer3; // 宣告 Timer 物件

float humiValue    = 0.0; // 濕度資料
float tempValue    = 0.0; // 溫度資料
int buttonCount    =0;
int perButtonState = 0;


#include<Wire.h>
#include<LCD.h>
#include<LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27 //0x27 或0x3F 定義 i2c的 Address位置(PCF8574T)

LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup() {
  delay(10);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTIN_PIN, INPUT);
  pinMode(BUZEER_PIN, OUTPUT);
  dht.begin(); // 啟動 dht
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH); //HIGH/LOW 控制LCD的背光
  lcd.clear();
  /*
   * LCD 佈局
   * -------------
   * H:00.0%
   * T:00.0*C
   * ------------
   */
  lcd.setCursor(0,0);
  lcd.print("H:00.0 %");
  lcd.setCursor(0,1);
  lcd.print("T:00.00 *C");


  // 配置排程
  timer1.every(100,  listenerButton); // 每100ms監聽Button狀態乙次
  timer2.every(1000, playLCD);        // 每100ms執行LCD乙次
  timer3.every(1000, setDHT);         // 每1000ms取得最新溫濕度乙次
  Serial.println("Ready");


}

// 監聽 button
void listenerButton() {
   int curButtonState = digitalRead(BUTTIN_PIN); // 目前 Button 的狀態
  if(curButtonState == LOW) {
    tone(BUZEER_PIN, 2000, 100);
    delay(300);
  }
  if (curButtonState != perButtonState) {
    if (curButtonState == LOW) { // LOW = 0, HIGH = 1
      buttonCount++;
      if(buttonCount% 2 ==1){
        lcd.setBacklight(LOW);
        }else{
          lcd.setBacklight(HIGH);
          }
    }
    perButtonState = curButtonState; // 狀態交換
  }

}

void playLCD() {
  lcd.clear();
  lcd.setCursor(0, 0); //(欄0-15,列0-1)
  //印字
  lcd.print("H:");
  //設定cursor
  lcd.setCursor(0, 1); //(欄0-15,列0-1)
  //印字
  lcd.print("T:");
  lcd.setCursor(6,0);
  lcd.print(humiValue);
  lcd.setCursor(12, 0); //(欄0-15,列0-1)
  lcd.print("%");
  lcd.setCursor(6,1);
  lcd.print(tempValue);
  lcd.setCursor(12, 1); //(欄0-15,列0-1)
  lcd.print("*C");
  delay(500);
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
 
  delay(200);
}


  void loop() {
  timer1.update();
  timer2.update();
  timer3.update();

}
