/*
 * 接線
 * LCD i2c 接線
 * GND -GND
 * VCC - 5V
 * SDA - A4
 * SCL - A5
 */

 #include<Wire.h>
 #include<LCD.h>
 #include<LiquidCrystal_I2C.h>

 #define I2C_ADDR 0x27 //0x27 或0x3F 定義 i2c的 Address位置(PCF8574T)
 /*   En, Rw, Rs, d4, d5,  d6, d7,Backlight_pin
  *腳位 2, 1,  0,   4,  5,  6,  7, 3
  *   LiquidCrystal_I2C( uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs);
   // Constructor with backlight control
      LiquidCrystal_I2C(uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs,
                     uint8_t backlighPin, t_backlighPol pol);   
      LiquidCrystal_I2C(uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs, 
                     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7 );
   // Constructor with backlight control
      LiquidCrystal_I2C(uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs, 
                     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
                     uint8_t backlighPin, t_backlighPol pol);//控制背光 
  */
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);
void setup() {
  delay(10);
  Serial.begin(9600);
  lcd.begin(16,2);
  //lcd.setBacklightPin(3,POSITIVE);//設定背光(POSITIVE 積極的)(把參數往上寫即可)
  //lcd.backlight();//開啟背光
  lcd.setBacklight(HIGH); //HIGH/LOW 控制LCD的背光
  //清空LCD
  lcd.clear();
  //設定cursor
  lcd.setCursor(5,0); //(欄0-15,列0-1)
  //印字
  lcd.print("Hello!");
  //設定cursor
  lcd.setCursor(0,1); //(欄0-15,列0-1)
  //印字
  lcd.print("*LCD@#$%^&");

}

void loop() {
  /*lcd.setBacklight(HIGH); //LCD 背光閃爍
  delay(2000);
  lcd.setBacklight(LOW);
  delay(2000);*/
  
}
