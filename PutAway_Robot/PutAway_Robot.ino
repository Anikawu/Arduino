#include<MatrixMini.h>

int data;
int redVal, minVal, maxVal, midVal;
int stop_find_Tracks = 0; //停止循跡


void red_light(){
        Mini.RGB2.setRGB(255, 0, 0);
        Mini.RGB2.setRGB(255, 0, 0);
        delay(100);
        Mini.RGB2.setRGB(0, 0, 0);
        Mini.RGB2.setRGB(0, 0, 0);
        delay(100);
  }
void green_light(){
        Mini.RGB2.setRGB(0, 255, 0);
        Mini.RGB2.setRGB(0, 255, 0);
        delay(100);
        Mini.RGB2.setRGB(0, 0, 0);
        Mini.RGB2.setRGB(0, 0, 0);
        delay(100);
  }





void find_Tracks() {     //循跡
  float front;
  while (1) {
    green_light();
    data = Mini.A1.getANG();
    Serial.println(Mini.A1.getANG());
    if (data > midVal) {
      Mini.M1.set(0);
      Mini.M2.set(30);
    } else {
      Mini.M1.set(30);
      Mini.M2.set(0);
    }

    front = Mini.D1.get();
    if (front == 0)
      break;
  }
}

void find_Tracks_to_des() {     //循跡
  int data_;
  while (1) {
    red_light();
    data_ = Mini.A1.getANG();
    Serial.println(Mini.A1.getANG());
    if (data_ > midVal) {
      Mini.M1.set(0);
      Mini.M2.set(30);
    } else {
      Mini.M1.set(30);
      Mini.M2.set(0);
    }

    if (data_ < redVal) {
      Serial.println("have been to active");
      Mini.M1.set(0);
      Mini.M2.set(0);
      break;
    }
    
  }
}

void turn() {
  while ((data < midVal)) { //走到黑色邊即轉彎
    green_light();
    data = Mini.A1.getANG();
    Mini.M1.set(30);
    Mini.M2.set(-30);
  }
}
void go_destination() {
  Serial.println("go_destination START");
  
  find_Tracks_to_des();  //尋找軌跡直到終點
  front_monitor_drop();  //放下物品
  delay(5000);
  Serial.println("go_destination stop");
  
}


void front_monitor() {     //判斷前方是否有障礙物
  //接觸到物品 舉起前臂
  Serial.println("接觸到物品 舉起前臂");
  red_light();
  Mini.M1.set(0);
  Mini.M2.set(0);
  delay(500);
  Mini.RC3.set(0);
  delay(2000);     //舉起前臂
  Mini.M1.set(20);
  Mini.M2.set(20);   //前進
  delay(1500);
  Mini.M1.set(0);
  Mini.M2.set(0);   //停止
  delay(500);
  Mini.RC3.set(90);  //放下前臂
  delay(1000);
  stop_find_Tracks = 1;
  
}

void front_monitor_drop() {     //抵達終點
  
  Serial.println("抵達終點 舉起前臂");
   red_light();
  
  Mini.RC3.set(0);
  delay(2000);     //舉起前臂
  Mini.M1.set(-20);
  Mini.M2.set(-20);   //後退
  delay(2000);
  Mini.M1.set(0);
  Mini.M2.set(0);   //停止
  delay(500);
  Mini.RC3.set(90);  //放下前臂
  delay(1000);
  stop_find_Tracks=0;
 
}

void setup() {
  Serial.begin(9600);
  Mini.begin();
  redVal = 180;    //紅色
  minVal = 450;    //白色
  maxVal = 918;    //黑色
  midVal = (minVal + maxVal) / 2;
  while (true) {
    Serial.println("START");
    Serial.print("距離 : ");
    Serial.println(Mini.A1.getANG());
    data = Mini.A1.getANG();   //紅外線偵測軌跡

    Serial.print(Mini.D4.US.get());
    Serial.println("cm");
    float distance = Mini.D4.US.get();  //超音波偵測距離開始動
    //感應前方是否有物體
    float front = Mini.D1.get();
    Serial.println(front);
    if (front == 0) {
      Serial.println("front == 0");
      front_monitor();   //執行前臂
      go_destination();  //抵達終點
    } else {
      Serial.println("front == 1");
      if (distance < 10) {    //偵測距離
        Serial.println("Run turn");
        turn();
      } else {
          find_Tracks();
      }
    }
  }
  Serial.println("END");
}

void loop() {

}
