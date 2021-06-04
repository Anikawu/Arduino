const int BUTTIN_PIN = 7; // 開/關燈按鈕的接腳(PIN)
const int LED_PIN = 9; // LED 燈的接腳



int ledState = 0; // LED開/關狀態值, Ex: ledState = 1 (開燈), 0 (關燈)
int perButtonState = 0; // 前一次 Button 的狀態



void setup() {
Serial.begin(9600);
pinMode(BUTTIN_PIN, INPUT); // 設定按鈕的接腳為輸入，因為我們要讀取他的狀態值
pinMode(LED_PIN, OUTPUT); // 設定LED的接腳為輸出
}



void loop() {
// 判斷是否 BUTTIN_ON_PIN 被按下(開燈)
int curButtonState = digitalRead(BUTTIN_PIN); // 目前 Button 的狀態
Serial.print("curButtonState = ");
Serial.print(curButtonState);
Serial.print(", ");
Serial.print("perButtonState = ");
Serial.println(perButtonState);
if(curButtonState != perButtonState) {
if(curButtonState == LOW) { // LOW = 0, HIGH = 1
ledState = ledState == 0 ? 1 : 0;
}
perButtonState = curButtonState; // 狀態交換
}

// 判斷 ledState 的狀態
if(ledState == 1) { // ledState = 1 (開燈), 0 (關燈)
digitalWrite(LED_PIN, HIGH);
} else {
digitalWrite(LED_PIN, LOW);
}

delay(50);
}
