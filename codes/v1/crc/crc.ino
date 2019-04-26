const boolean tx[2][7] = {{1,0,1,0,1,0,0},{1,1,1,0,1,0,0}};
int i,j=0;
int z[5];
int flag1, flag2;

void setup() {
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);  
Serial.begin(115200);
}

void loop(){
    flag1=1;
    if(flag1==1 && j < 2){
      digitalWrite(10,1); 
      delay(100);
      digitalWrite(10,0);
      
      Serial.println("Input message bits...");
      for(i=0; i < 7; i++){
        Serial.print(tx[j][i]);
      }
      
      Serial.println(' ');
      Serial.println("CRC encoded message bits...");
      for(i=0; i < 7; i++){
        Serial.print(tx[j][i]);
      }
      
      for(i=4; i >= 0; i--){
        Serial.print(z[i]);
      }
      Serial.println(' ');
      
      for(i = 0; i < 7; i++){
        digitalWrite(i+3,tx[j][i]);  
      }
      
      z[0] = digitalRead(A0);
      z[1] = digitalRead(A1);
      z[2] = digitalRead(A2);
      z[3] = digitalRead(A3);
      z[4] = digitalRead(A4);
      
      if(j==0) j=1;
      else j = 0; 
      
      delay(200);
      
    }

}
