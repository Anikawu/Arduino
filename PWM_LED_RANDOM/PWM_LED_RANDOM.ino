//9:BLUE,10:RED,11:GREEN
const int LED_RED_PIN    =9;
const int LED_GREEN_PIN  =10;
const int LED_BLUE_PIN   =11;
const int DELAY          =500;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN,OUTPUT);
  pinMode(LED_GREEN_PIN,OUTPUT);
  pinMode(LED_BLUE_PIN,OUTPUT);
}

void loop() {
  //取隨機值
  int r = random(0,256);
  int g = random(0,256);
  int b = random(0,256);
  Serial.print("R:");
  Serial.print(r);
  Serial.print("G:");
  Serial.print(g);
  Serial.print("B:");
  Serial.print(b);
  analogWrite(LED_RED_PIN,r);
  analogWrite(LED_GREEN_PIN,g);
  analogWrite(LED_BLUE_PIN,b);
  delay(DELAY);
  /*
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
  delay(DELAY);*/

}
