int i=0;
void setup() {
  Serial.begin(9600);  //傳輸速率 bps
  Serial.println("call setup...");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  i++;
  if(i%2==0){
  Serial.print("call loop i: ");
  Serial.println(i);
  }
  delay(500);

}
