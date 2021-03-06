/*
搶答燈
遊戲開始:
1. 燈滅
2. delay(random(1000, 5000)) -> 亮紅燈
3. 若下方BUTTON先按 -> 亮綠燈 (停一秒)
4. 若上方BUTTON先按 -> 亮藍燈 (停一秒)
5. 從 1 開始
三戰二勝
最後透過 Serial.println() 告知藍/綠誰勝利 ?
*/
const int LED_BLUE_PIN = 9; // LED BLUE 燈的接腳( 9 = PIN(PWM))
const int LED_RED_PIN = 10; // LED RED 燈的接腳(10 = PIN(PWM))
const int LED_GEEEN_PIN = 11; // LED GEEEN 燈的接腳(11 = PIN(PWM))
const int BUTTON_GREEN_PIN = 7; // 搶答按鈕的接腳(PIN)
const int BUTTON_BLUE_PIN = 12; // 搶答按鈕的接腳(PIN)
const int DELAY = 100; // 暫停時間 ms
const int WIN_COUNT   =2;  //贏家次數
int flag = 0; // 是否是搶答狀態 ?
int gameOver = false; // 遊戲結束
int greenCount = 0;
int blueCount = 0;



void setup() {
Serial.begin(9600);
pinMode(LED_RED_PIN, OUTPUT);
pinMode(LED_GEEEN_PIN, OUTPUT);
pinMode(LED_BLUE_PIN, OUTPUT);
pinMode(BUTTON_GREEN_PIN, INPUT);
pinMode(BUTTON_BLUE_PIN, INPUT);
// 預設全滅
ledAllOff();
Serial.println("READY !");
}

void loop() {
if (gameOver == false) {
// 遊戲開始
play();
// 判斷贏家
if (greenCount == 2 || blueCount == 2) {
gameOver = true;
if (greenCount == 2) {
Serial.println("GREEN WIN");
} else {
Serial.println("BLUE WIN");}}
}
delay(DELAY);
}



void play() {
if (flag == 0) {
ledAllOff();
delay(random(1000, 5000));
ledRedOn();
Serial.println("Go...");
flag = 1;
}

if (digitalRead(BUTTON_GREEN_PIN) == LOW && flag == 1) {
flag = 0;
greenCount++;
ledGreenOn();
printScore();
delay(1000);
}



if (digitalRead(BUTTON_BLUE_PIN) == LOW && flag == 1) {
flag = 0;
blueCount++;
ledBlueOn();
printScore();
delay(1000);
}}



void printScore() {
Serial.print("GREEN: ");
Serial.print(greenCount);
Serial.print(", BLUE: ");
Serial.println(blueCount);
}



void ledAllOff() {
analogWrite(LED_RED_PIN, 255);
analogWrite(LED_GEEEN_PIN, 255);
analogWrite(LED_BLUE_PIN, 255);
}



void ledRedOn() {
analogWrite(LED_RED_PIN, 255);
analogWrite(LED_GEEEN_PIN, 0);
analogWrite(LED_BLUE_PIN, 0);
}



void ledGreenOn() {
analogWrite(LED_RED_PIN, 0);
analogWrite(LED_GEEEN_PIN, 255);
analogWrite(LED_BLUE_PIN, 0);
}



void ledBlueOn() {
analogWrite(LED_RED_PIN, 0);
analogWrite(LED_GEEEN_PIN, 0);
analogWrite(LED_BLUE_PIN, 255);
}
