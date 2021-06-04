const int BUZEER_PIN =8;
const int DELAY =1000;
void setup() {
  Serial.begin(9600);
  pinMode(BUZEER_PIN,OUTPUT);
}

void loop() {
  //tone(pin,HZ,ms)
  tone(BUZEER_PIN,262,500);//腳位,HZ=262,500=0.5秒
  delay(DELAY);
 

}
