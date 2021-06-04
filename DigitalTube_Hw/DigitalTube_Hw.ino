//透過 PC 輸入 STOP 顯示 STOP
//透過 PC 輸入 1234 顯示1234
//接線方式
/*
   GND:GND
   dio:6
   rc:5
   sc:4
   vcc:5v
*/
#include<DigitalTube.h>
DigitalTube dis(4, 5, 6); //sclk,rclk,dio

const int CDS_PIN = A4;

void setup() {
  delay(10);
  Serial.begin(9600);
  dis.begin();
  Serial.print("Ready");
  Serial.available();

}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readString();
    int cdsvalue = analogRead(CDS_PIN);//0-1023
    Serial.print(cdsvalue);

    dis.show(cdsvalue.charAt(0), cdsvalue.charAt(1), cdsvalue.charAt(2), cdsvalue.charAt(3));
    delay(500);

  }
}
//int textLength = 0
/*if (Serial.available() > 0) {

  String text = Serial.readString();
  //Serial.print(val)

  //Serial.print(val, format)
  Serial.print(text);

  char one = text.charAt(0);//1
  char two = text.charAt(1);//2
  char three = text.charAt(2);//3
  char four = text.charAt(3);//4
  char five =text.charAt(4);
  int Dot = text.indexOf(".");
  if(Dot ==-1){
  dis.show(one, two, three, four);
  }else{
    switch(Dot){
      case 0://如果.的位置=0 ex:.123 show:0.123
      dis.show(10+0, two, three,four);
      break;
      case 1://如果.的位置=1 ex:2.123 show:2.123
      //ASCII 48=0;50=2,51=3....
      dis.show(10+((int)one)-48,three,four,five);
      break;
      case 2://如果.的位置=2 ex:23.12 show:23.12
      dis.show(one, 10+((int)two)-48,four,five);
      break;
       case 3://如果.的位置=3 ex:231.2 show:231.2
      dis.show(one, two,10+((int)three)-48,five);
      break;


      }

  }
  }
  delay(100);
  }
  /*
  int tempInt =(int)(temp*10);//234

  dis.show(tempInt/100,tempInt/10%10+10,tempInt%10,'C');//23.4c
  delay(2000);

  }
*/
