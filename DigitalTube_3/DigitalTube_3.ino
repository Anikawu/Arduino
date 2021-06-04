
#include<DigitalTube.h>
DigitalTube dis(4,5,6);
void setup() {
  Serial.begin(9600);
  dis.begin();
  Serial.print("Ready");

}

void loop() {
  //float f=24.37;
  //dis.print(f*100);
  float temp =23.4;
  // ASCII 48->'0', 49->'1', 65->'A', 66->'B', 97->'a', 98->'b'
  //方法1: dis.show(50,52,51,'C');
  //顯示234C
  int tempInt =(int)(temp*10);//234
  //dis.show(tempInt/100,tempInt/10%10,tempInt%10,'C');//先除10 再取餘數
  //dis.show(1+10,2+10,3+10,4+10);//小數點+10
  dis.show(tempInt/100,tempInt/10%10+10,tempInt%10,'C');//23.4c
  delay(2000);

}
