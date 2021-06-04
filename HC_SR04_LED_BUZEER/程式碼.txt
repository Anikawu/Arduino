/*
偵測距離在10cm~5cm之間亮紅燈發出長音bee~~~bee~~ ...
偵測距離在 < 5cm 亮黃燈連續短音bee~bee~ ...
偵測距離 > 10cm 不亮燈不發音
距離請顯示在 DigitalTube
*/

#include <Ultrasonic.h>
#include <Timer.h>
#include <DHT.h>
#include <TridentTD_7Segs74HC595.h>

#define DHT_TYPE DHT11
#define SCLK 4
#define RCLK 5
#define DIO  6
Ultrasonic ultrasonic(12, 11);//trig pin:12 , echo pin:11
int distance;
const int LED_RED_PIN = 9;
const int LED_YELLOW_PIN = 10;
const int BUZEER_PIN = 3;

TridentTD_7Segs74HC595  tube( SCLK, RCLK, DIO); // 初始化 tube
Timer timer1, timer2, timer3, timer4, timer5, timer6; // 宣告 Timer 物件

void setup() {
  delay(10);
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);//< 5cm 亮黃燈連續短音bee~bee~ ...
  pinMode(BUZEER_PIN, OUTPUT);
  tube.init();  // 啟動 tube


  //timer2.every(1000, setCDS);         // 每1000ms取得距離資料乙次
  //timer3.every(1000, checkLED);       // 每1000ms檢查是否要開燈
  Serial.println("Ready");
}

void loop() {
  
  distance = ultrasonic.read(); //不加參數就是輸出CM，可用read(INC)輸出英寸
  if(distance < 5)
  {
    digitalWrite(LED_YELLOW_PIN, HIGH);
    digitalWrite(LED_RED_PIN, LOW);
    tone(BUZEER_PIN, 2000, 100);
    Serial.print("Distance in CM: ");
    Serial.println(distance);
    tube.setText(String(distance));
    delay(300);
  }else if (distance >5 && distance < 10){
    digitalWrite(LED_RED_PIN, HIGH);
    digitalWrite(LED_YELLOW_PIN, LOW);
    tone(BUZEER_PIN, 2000);
    Serial.print("Distance in CM: ");
    Serial.println(distance);
    tube.setText(String(distance));
    delay(300);
    
   }else {
       LEDoff();
       Serial.print("Distance in CM: ");
       Serial.println(distance);
       tube.setText(String(distance));
    }
  
  delay(200); //每次間格0.2秒
}



void LEDoff(){
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(LED_RED_PIN, LOW);
  
  }
