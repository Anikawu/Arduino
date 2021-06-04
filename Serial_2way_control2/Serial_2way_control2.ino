//若   受到"1" 表示一直印出i的值
//若   受到"2" 表示停止印出i的值
int i=1;  
boolean play=false;//控制是否要顯示 i值的變數
void setup() {
  Serial.begin(9600);
  Serial.println("Ready...");
}

void loop() {
 i++;
 if(Serial.available()>0){
    char c=Serial.read();  
    Serial.print(c);
    if (c == '1'){//讀一個字元
     play = true;
    }
    else if(c =='2'){
      play = false;
    }
 }
 if(play){
   Serial.println(i);
  }
delay(100);

}
