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
#include "pitches.h"
#include "mypin.h"

int flag = 0; // 是否是搶答狀態 ?
int gameOver = false; // 遊戲結束
int greenCount = 0;
int blueCount = 0;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(LED_GREEN_1_PIN, OUTPUT);
  pinMode(LED_GREEN_2_PIN, OUTPUT);
  pinMode(LED_BLUE_1_PIN, OUTPUT);
  pinMode(LED_BLUE_2_PIN, OUTPUT);
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
    if (greenCount == WIN_COUNT || blueCount == WIN_COUNT) {
      gameOver = true;
      if (greenCount == WIN_COUNT) {
        Serial.println("GREEN WIN");
      } else {
        Serial.println("BLUE WIN");
      }
      gameOverSong();
    }
  }
  delay(DELAY);
}

void play() {
  if (flag == 0) {
    ledAllOff();
    delay(random(1000, 5000));
    ledRedOn();
    tone(BUZZER_PIN, 2000, 200);
    Serial.println("Go...");
    flag = 1;
  }
  
  if (digitalRead(BUTTON_GREEN_PIN) == LOW && flag == 1) {
    flag = 0;
    greenCount++;
    ledGreenOn();
    tone(BUZZER_PIN, 1000, 200);
    printScore();
    delay(1000);
  }

  if (digitalRead(BUTTON_BLUE_PIN) == LOW && flag == 1) {
    flag = 0;
    blueCount++;
    ledBlueOn();
    tone(BUZZER_PIN, 1000, 200);
    printScore();
    delay(1000);
  }

}

void printScore() {
  Serial.print("GREEN: ");
  Serial.print(greenCount);
  Serial.print(", BLUE: ");
  Serial.println(blueCount);
}

void ledAllOff() {
  analogWrite(LED_RED_PIN, 255);
  analogWrite(LED_GREEN_PIN, 255);
  analogWrite(LED_BLUE_PIN, 255);
}

void ledRedOn() {
  analogWrite(LED_RED_PIN, 255);
  analogWrite(LED_GREEN_PIN, 0);
  analogWrite(LED_BLUE_PIN, 0);
}

void ledGreenOn() {
  // 亮RGB綠燈
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 255);
  analogWrite(LED_BLUE_PIN, 0);
  // 亮LED綠燈
  if(greenCount == 1) {
    digitalWrite(LED_GREEN_1_PIN, HIGH); // 亮第一個綠燈
  } else if(greenCount == 2) {
    digitalWrite(LED_GREEN_2_PIN, HIGH); // 亮第二個綠燈
  }
}

void ledBlueOn() {
  // 亮RGB藍燈
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 0);
  analogWrite(LED_BLUE_PIN, 255);
  // 亮LED藍燈
  if(blueCount == 1) {
    digitalWrite(LED_BLUE_1_PIN, HIGH); // 亮第一個藍燈
  } else if(blueCount == 2) {
    digitalWrite(LED_BLUE_2_PIN, HIGH); // 亮第二個藍燈
  }
}

void gameOverSong() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER_PIN);
  }
}
