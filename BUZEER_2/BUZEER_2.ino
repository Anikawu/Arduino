const int BUZZER_PIN =8;
const int DELAY =1000;
int frequence[]={262,294,330,349,392,440,494};
void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN,OUTPUT);
  for(int i=0;i<8;i++){
  tone(BUZZER_PIN,frequence[i],500);
  delay(DELAY);
  }
}

void loop() { }
