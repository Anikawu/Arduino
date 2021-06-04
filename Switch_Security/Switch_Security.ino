/*
  1.Button 按下
  防盜模式啟動(On)/關閉(Off)
  2.LCD 顯示
  Security: On/Off
  3.LED(紅色)
  在防盜模式啟動(On) = HIGH
  在防盜模式啟動(Off) = LOW
  4.Switch
  在防盜模式啟動(On) + Switch(偵測到開門) = Buzzer 響起
  按下 Button 關閉防盜模式, Buzzer 停止響
  在防盜模式啟動(Off) + Switch(一樣可進行偵測) 但 Buzzer 不響
*/
#include <Timer.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define SWITCH_PIN 13
#define BUZEER_PIN 3
#define BUTTIN_PIN 8
#define LED_RED_PIN  9
#define I2C_ADDR   0x27

Timer timer1, timer2, timer3, timer4, timer5, timer6; // 宣告 Timer 物件

int securityValue  = 0; // Security 是否啟動(1:ON 2:OFF)
int switchValue    = 0; // Switch 是否開啟(1:ON 2:OFF)
int buttonCount    = 0; // 計數 button 按下的次數
int perButtonState = 0; // 前一次 button 的狀態
int dangerValue    = 0; // 1:Security啟動&Switch啟動
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  delay(10);
  Serial.begin(9600);

  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUTTIN_PIN, INPUT);
  pinMode(BUZEER_PIN, OUTPUT);

  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Security: OFF");
  lcd.setCursor(0, 1);
  lcd.print("Switch: CLOSE");

  // 配置排程
  timer1.every(100, listenerButton); // 每100ms監聽 Button 狀態乙次
  timer2.every(100, detectSwitch);   // 每100ms偵測 Switch 狀態乙次
  timer3.every(100, detectSecurity); // 每100ms偵測 Security 狀態乙次
  timer4.every(100, playLED);        // 每100ms檢查 是否要開燈乙次
  timer5.every(500, playLCD);        // 每500ms更新 LCD 內容乙次
  timer6.every(500, printLog);       // 每500ms印出 Log 內容乙次

  Serial.println("Ready");
}

// 監聽 button
void listenerButton() {
  int curButtonState = digitalRead(BUTTIN_PIN); // 目前 Button 的狀態
  if (curButtonState == LOW) {
    tone(BUZEER_PIN, 2000, 100);
    delay(300);
  }
  if (curButtonState != perButtonState) {
    if (curButtonState == LOW) { // LOW = 0, HIGH = 1
      buttonCount++; // 給 LCD 背光作為 on/off 的參考
      if (buttonCount % 2 == 1) {
        securityValue = 1;
      } else {
        securityValue = 0;
      }
    }
    perButtonState = curButtonState; // 狀態交換
  }

}



//偵測switch
void detectSwitch() {
  switchValue = digitalRead(SWITCH_PIN);
}
//偵測 security
void detectSecurity() {
  if (switchValue == 1 && securityValue == 1) {
    dangerValue = 1;
    tone(BUZEER_PIN, 2000, 100);
  } else if (dangerValue == 1 && securityValue == 1) {
    tone(BUZEER_PIN, 2000, 100);
  } else if (dangerValue == 1 && securityValue == 0) {
    dangerValue = 0;
  }
}
void playLED() {
  if (securityValue == 1) {
    digitalWrite(LED_RED_PIN, HIGH);
  } else {
    digitalWrite(LED_RED_PIN, LOW);
  }

}

void playLCD() {
  /*
    LCD 佈局
    ---------------
    Security: OFF
    Switch: OFF
    ---------------
  */

  lcd.setCursor(10, 0);
  lcd.print("     ");
  lcd.setCursor(10, 1);
  lcd.print((securityValue == 1) ? "ON" : "OFF");
  lcd.setCursor(8, 1);
  lcd.print("     ");
  lcd.setCursor(8, 1);
  lcd.print((switchValue == 1) ? "OPEN" : "CLOSE");
}

void printLog() {
  Serial.print("Security: ");
  Serial.print(securityValue);
  Serial.print(", Switch: ");
  Serial.print(switchValue);
  Serial.print(",Security: ");
  Serial.print(dangerValue);
  Serial.print(", LED: ");
  Serial.print(digitalRead(LED_RED_PIN));
  Serial.print(", ButtonCount:");
  Serial.println(buttonCount);


}

void loop() {
  timer1.update();
  timer2.update();
  timer3.update();
  timer4.update();
  timer5.update();
  timer6.update();

}
