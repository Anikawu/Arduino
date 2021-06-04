//9:BLUE,10:RED,11:GREEN
const int LED_RED_PIN    =9;
const int LED_GREEN_PIN  =10;
const int LED_BLUE_PIN   =11;
const int DELAY          =100;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN,OUTPUT);
  pinMode(LED_GREEN_PIN,OUTPUT);
  pinMode(LED_BLUE_PIN,OUTPUT);
}

void loop() {
  //紅色
   analogWrite(LED_RED_PIN,255);
  analogWrite(LED_GREEN_PIN,0);
  analogWrite(LED_BLUE_PIN,0);
  delay(DELAY);
  //綠色
   analogWrite(LED_RED_PIN,0);
  analogWrite(LED_GREEN_PIN,255);
  analogWrite(LED_BLUE_PIN,0);
  delay(DELAY);
  //藍色
  analogWrite(LED_RED_PIN,0);
  analogWrite(LED_GREEN_PIN,0);
  analogWrite(LED_BLUE_PIN,255);
  delay(DELAY);
   //白色
  analogWrite(LED_RED_PIN,255);
  analogWrite(LED_GREEN_PIN,250);
  analogWrite(LED_BLUE_PIN,250);
  delay(DELAY);

}
