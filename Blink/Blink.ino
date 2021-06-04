int led_pin =13;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serial.println("Ready..");
   //設定數位13腳號=OUTPUT
   pinMode(led_pin,OUTPUT);
}

void loop() {
  // 數位訊號寫入
  digitalWrite(led_pin,HIGH);
  delay(1000);
  digitalWrite(led_pin,LOW);
  delay(1000);

}
