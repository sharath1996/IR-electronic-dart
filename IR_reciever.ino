int j=0,sum=0, gameStatus=0, readPin=P1_4;;
void setup()
{
Serial.begin(9600);
pinMode(readPin, INPUT);
  
}

void loop()
{
  int c= Serial.read();
  if(c=='1'){
   Serial.println("Game starts now");
  gameStatus=1;
  }
  if(c=='2'){
    Serial.println("GAME OVER");
    gameStatus=2;}
    
 int a=digitalRead(readPin);
if(a==0){
 irDecode();
a=1; 
}
}
void irDecode(){
  long int sum=0, j=1, poe=1;
  if (gameStatus==1){
    delay(2);
    for (int i=0; i<16; i++){
      j=digitalRead(readPin);
      delay(4);
      sum=sum+((!j)*poe);
      poe=1<<poe;
    }
     Serial.println(sum);
  }
 
  else if (gameStatus==0){
  Serial.println("GAME YET TO START");
}
else if(gameStatus==2)
Serial.println("GAME OVER");
}
      
