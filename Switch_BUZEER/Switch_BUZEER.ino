/*
  磁簧開關:
  任意一條接 GND 另一條 D13
*/
#define SWITCH_PIN 13
#define BUZEER_PIN 3

int switchValue;

void setup() {
  delay(10);
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(BUZEER_PIN, OUTPUT);
  Serial.println("Ready");
}

void loop() {
  switchValue = digitalRead(SWITCH_PIN);
  Serial.print("switchValue= ");
  Serial.println(switchValue);
  if (switchValue == 1) {
    Serial.println("Open");
    tone(BUZEER_PIN, 2000, 100);
  } else {
    Serial.println("Close");
  }
  delay(100);
}
