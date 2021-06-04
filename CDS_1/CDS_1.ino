/*
 * 接線方式
 * sig :A4
 * VCC:5V
 * GND:GND
 */
const int CDS_PIN =A4;
void setup() {
 delay(100);
 Serial.begin(9600);


}

void loop() {
  int cdsvalue = analogRead(CDS_PIN);//0-1023
  Serial.print(cdsvalue);
  delay(500);

}
