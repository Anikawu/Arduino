int led_pin = 13;
int play = false; //啟動
int minSpeed = 100;
int maxSpeed = 10000;
int initSpeed = 1000;
int curSpeed = initSpeed;
int delta = 100;//調整 delta(ms)
int alwaysOn = false; //恆亮

int ButtonState = 0; //宣告初始狀態不亮
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ready..");

  pinMode(led_pin, OUTPUT); //設定數位13腳號=OUTPUT
}
void loop() {
  readData(); //讀取資料
  playLED(); //
}

void readData() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    switch (c) {
      case '1':  //啟動
        play = true;
        alwaysOn = false;
        break;
      case '2': //關燈
        play = false;
        break;
      case '3':  //加速
        curSpeed -= delta;
        if (curSpeed < minSpeed) curSpeed = minSpeed;
        break;
        
      case '4':  //減速
        curSpeed += delta;
        if (curSpeed >= maxSpeed) curSpeed = maxSpeed;
        break;
      case '5':  //恆亮
        alwaysOn = true;
        break;
    }
  }
}
void playLED() {
  if (play) {
    if (alwaysOn) {
      digitalWrite(led_pin, HIGH);
    } else {
      digitalWrite(led_pin, HIGH);
      delay(curSpeed);
      digitalWrite(led_pin, LOW);
      delay(curSpeed);
      //Serial.ptintln("curSpeed:");
      Serial.print(curSpeed);
    }
  } else {
    digitalWrite(led_pin, LOW);
  }
}
