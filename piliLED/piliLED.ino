const int P1_PIN = 13;
const int P2_PIN = 12;
const int P3_PIN = 11;
const int P4_PIN = 10;
const int P5_PIN = 9;
int minSpeed = 100;
int maxSpeed = 10000;
int curSpeed = 1000;
int delta = 100;//調整 delta(ms)
int play = false; // 啟動
int alwaysOn = false; // 恆亮


void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(P1_PIN, OUTPUT);
  pinMode(P2_PIN, OUTPUT);
  pinMode(P3_PIN, OUTPUT);
  pinMode(P4_PIN, OUTPUT);
  pinMode(P5_PIN, OUTPUT);
}



void loop() {
  //Homework
  /*
    1:onAll(), 2:offAll(), 3:blinkLed(), 4:piliLed(), 5:antiPiliLed(), 6:randomLed()
    7:加速, 8:減速
  */
  //onAll();
  //offAll();
  //blinkLed();
  //piliLed();
  //antiPiliLed();
  //randomLed();

  readData();
}

void readData() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    switch (c) {
      case '1':  //啟動
        alwaysOn = true;
        onAll();
        break;
      case '2': //關燈
        alwaysOn = false;
        offAll();
        break;
      case '3':  //閃爍
        play = true;
        alwaysOn = false;
        blinkLed();
        break;
      case '4':  //霹靂燈
        play = true;
        alwaysOn = false;
        piliLed();
        break;
      case '5':  //反霹靂燈
        antiPiliLed();
        break;
      case '6':
        play = true;
        alwaysOn = false;
        randomLed();
        break;
      case '7':  //加速
        play = true;
        alwaysOn = false;
        curSpeed -= delta;
        if (curSpeed < minSpeed) curSpeed = minSpeed;
        break;
      case '8':  //減速
        curSpeed += delta;
        if (curSpeed >= maxSpeed) curSpeed = maxSpeed;
        Serial.println(curSpeed);
        break;
    }
  }

}

// 隨機燈
void randomLed() {
  if (play) {
    if (alwaysOn) {
      onAll();
    } else { // 閃爍 Blink

      int pin = random(9, 14);
      Serial.print("random = ");
      Serial.println(pin);
      offAll();
      digitalWrite(pin, HIGH);
      delay(curSpeed);
      Serial.println(curSpeed);
    }

  } else offAll();
}




// 反霹靂燈
void antiPiliLed() {
 if (play) {
    if (alwaysOn) {
      onAll();
    } else { 
  // 由 9 .. 13 由 下 往 上
  for (int pin = P5_PIN ; pin < P5_PIN + 5 ; pin++) {
    onAll();
    digitalWrite(pin, LOW);
    delay(curSpeed);
  }
  // 由 13 .. 9 由 上 往 下
  for (int pin = P5_PIN + 3 ; pin > P5_PIN ; pin--) {
    onAll();
    digitalWrite(pin, LOW);
    delay(curSpeed);
  }
  Serial.println(curSpeed);
    }

  } else offAll();
}



// 霹靂燈
void piliLed() {
 if (play) {
    if (alwaysOn) {
      onAll();
    } else { 
  // 由 9 .. 13 由 下 往 上
  for (int pin = P5_PIN ; pin < P5_PIN + 5 ; pin++) {
    offAll();
    digitalWrite(pin, HIGH);
    delay(curSpeed);
    Serial.println(curSpeed);
  }
  // 由 13 .. 9 由 上 往 下
  for (int pin = P5_PIN + 3 ; pin > P5_PIN ; pin--) {
    offAll();
    digitalWrite(pin, HIGH);
    delay(curSpeed);
    Serial.println(curSpeed);
  }
  Serial.println(curSpeed);

    }

  } else offAll();
}





void offAll() {

  digitalWrite(P1_PIN, LOW);
  digitalWrite(P2_PIN, LOW);
  digitalWrite(P3_PIN, LOW);
  digitalWrite(P4_PIN, LOW);
  digitalWrite(P5_PIN, LOW);
}



void onAll() {

  digitalWrite(P1_PIN, HIGH);
  digitalWrite(P2_PIN, HIGH);
  digitalWrite(P3_PIN, HIGH);
  digitalWrite(P4_PIN, HIGH);
  digitalWrite(P5_PIN, HIGH);

}



// 閃爍
void blinkLed() {
  if (play) {
    if (alwaysOn) {
      onAll();
    } else {
      onAll();
      delay(curSpeed);
      offAll();
      delay(curSpeed);
      Serial.println(curSpeed);
      
    }

  } else offAll;
}
