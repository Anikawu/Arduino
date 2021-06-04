#include <DigitalTube.h>
const int VOLTAGE_PIN = A0;
const int CDS_PIN = A3;
const int LED_PIN = 7;



int cdsValueThreshold = 500; // 門檻值(小於：燈亮，大於：燈滅)
DigitalTube dis(4, 5, 6);



void setup() {
delay(100);
Serial.begin(9600);
pinMode(LED_PIN, OUTPUT);
dis.begin();
Serial.println("Ready");
}



void loop() {
if(Serial.available() > 0) {
// 取得所輸入的數值, 用來變更 cdsValueThreshold 的內容
  String text =Serial.readString();  //讀取自串資料
  text.trim();//去除空白(含\n\r)
  cdsValueThreshold = text.toInt();//字串轉數字
  Serial.print("text= ");
  Serial.print(text);
  Serial.print(",cdsValueThreshold");
  Serial.print(cdsValueThreshold);
}
int cdsValue = analogRead(CDS_PIN); // 0~1023
Serial.println(cdsValue);
dis.print(cdsValue);
if(cdsValue < cdsValueThreshold) {
digitalWrite(LED_PIN, HIGH);
} else {
digitalWrite(LED_PIN, LOW);
}
delay(500);
}
