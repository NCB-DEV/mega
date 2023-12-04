#include <Servo.h>
Servo porte,fenetre;
long duration,distance;
  int v;
int tri=52,echo =53,buz=8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(tri,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(echo,INPUT);
  porte.attach(2);
  fenetre.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tri,LOW);
  delayMicroseconds(2);
  digitalWrite(tri,HIGH);
  delayMicroseconds(10);
  digitalWrite(tri,LOW);
   duration=pulseIn(echo,HIGH);
   distance=duration*0.034/2;
   v=distance;//<
  if( distance <=5 ){
    //

    tone(buz,1000);
    Serial.println("a");
  }
  else{
    noTone(buz);
    Serial.println("b");
  }
  delay(500);  
}
