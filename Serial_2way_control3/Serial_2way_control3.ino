//若   受到"+" 每次-50
//若   受到"-" 每次+50
//若   受到"r" 表示還原200ms 的速度
int i=1;
int initspeed = 200;
int curspeed = initspeed; 
int delta = 50;  
boolean play=false;//
void setup() {
  Serial.begin(9600);
  Serial.println("Ready...");
}
void loop() {
 i++;
  if(Serial.available()>0){
    char c=Serial.read();  
    switch(c){
      case '1':
         play = true;
         break;
      case '2':
         play = false;
         break;
      case '+':
         curspeed -= delta;
         if(curspeed <0){curspeed = 0;}
         break;
      case '-':
         curspeed += delta;
         if(curspeed >10000){curspeed = 10000;}
         break;
      case 'r':
         curspeed = initspeed;
         break;
     
      }

  }
   if(play){
   Serial.println(i);
 }

 delay(curspeed);

}
