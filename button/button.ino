const int BUTTON_ON_PIN = 7; // 開燈按鈕的接腳(PIN)
const int BUTTON_OFF_PIN = 12; // 關燈按鈕的接腳(PIN)
const int LED_PIN = 9; // LED 燈的接腳



int ledState = 0; // LED開/關狀態值, Ex: ledState = 1 (開燈), 0 (關燈)



void setup() {
Serial.begin(9600);
pinMode(BUTTON_ON_PIN, INPUT); // 設定按鈕的接腳為輸入，因為我們要讀取他的狀態值
pinMode(BUTTON_OFF_PIN, INPUT); // 設定按鈕的接腳為輸入，因為我們要讀取他的狀態值
pinMode(LED_PIN, OUTPUT); // 設定LED的接腳為輸出
}

void loop() {
  // put your main code here, to run repeatedly:
  //buttonState = digitalRead(BUTTON_PIN);
  //Serial.println(buttonState);
  if(digitalRead(BUTTON_ON_PIN) == LOW){
    ledState=1;
    Serial.println("ON");
  }
  if(digitalRead(BUTTON_OFF_PIN) ==LOW){
     ledState=0;
    Serial.println("OFF");
  }
  if(ledState ==1){
    digitalWrite(LED_PIN,HIGH);
  }else{digitalWrite(LED_PIN,LOW);
  }
  delay(100);
}
