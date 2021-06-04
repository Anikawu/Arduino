const int LED_PIN =9;
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
   analogWrite(LED_PIN,0); //LED 不亮
   delay(1000);
   analogWrite(LED_PIN,80);
   delay(1000);
   analogWrite(LED_PIN,255);
   delay(1000);
}
