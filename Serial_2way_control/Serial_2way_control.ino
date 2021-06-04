//若   受到"on" 表示一直印出i的值
//若   受到"off" 表示停止印出i的值
int i=1;  
boolean play=false;//控制是否要顯示 i值的變數
void setup() {
  Serial.begin(9600);
  Serial.println("Ready...");

}

void loop() {
 i++;
 if(Serial.available()>0){
    String str =Serial.readString();  //"on\n 或 off\n"
    Serial.print(str);
    if (str == "on\n"){//讀一個字串
     play = true;
    }
    else if(str =="off\n"){
      play = false;
    }
 }
 if(play){
   Serial.println(i);
  }
delay(100);

}
