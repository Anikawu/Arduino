const int LED_PIN =9; //LED 燈的接腳
const int DELAY = 5; //暫停時間MS
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  for(int i=0;i<256;i++){
   analogWrite(LED_PIN,i); //LED 不亮
   delay(DELAY);
  }
  for(int i=255;i>=0;i--)
  {
    analogWrite(LED_PIN,i); //LED 不亮
    delay(DELAY);
  }
}
