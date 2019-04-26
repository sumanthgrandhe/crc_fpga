const boolean tx[9] = {1,0,1,0,1,0,0,1,0};
int i,j=0;
int z[3];
int flag=1;

void setup() {
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);  
Serial.begin(115200);
}

void loop(){
   
      digitalWrite(12,1);
      digitalWrite(13,flag);
      delay(100);
      digitalWrite(12,0);
      digitalWrite(13,0);
      

      digitalWrite(11,tx[0]);  
      digitalWrite(10,tx[1]);
      digitalWrite(3,tx[2]);
      digitalWrite(4,tx[3]);
      digitalWrite(5,tx[4]);
      digitalWrite(6,tx[5]);
      digitalWrite(7,tx[6]);
      digitalWrite(8,tx[7]);
      digitalWrite(9,tx[8]);
      
      z[0] = digitalRead(A0);
      z[1] = digitalRead(A1);
      z[2] = digitalRead(A2); 
      
      if(flag){
         Serial.println("CRC reminder... ");
         for(i=2; i >= 0; i--){
          Serial.print(z[i]);
         }
         Serial.println(' ');
        if(z[0]==0 && z[1]==0 && z[2]==0) Serial.println("No Error!");
        else Serial.println("Error!");
      }
      if(!flag){
        Serial.println("Input message bits...");
        for(i=0; i < 6; i++){
          Serial.print(tx[i]);
        }
         Serial.println(' ');
         Serial.println("CRC encoded message bits...");
         for(i=0; i < 6; i++){
           Serial.print(tx[i]);
         }
         for(i=2; i >= 0; i--){
          Serial.print(z[i]);
         }
         Serial.println(' ');
      }
      
      delay(1000);
      
}
