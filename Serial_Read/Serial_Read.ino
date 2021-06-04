void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  // 判斷arduino 是否收到pc傳來的資料
  if(Serial.available()> 0){
    //char c=Serial.read();//讀一個字
    //Serial.println(num);
    
    //int num = Serial.read();  //讀一個字 轉ASCII(A->65,B->66,C->67)
    //if(num !=10){
    //Serial.println(num);
    String str =Serial.readString();  //讀一個字串
    Serial.print(str);
    
    }

}
