
#include <Servo.h>
Servo porte,fenetre;
int pot;
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
   v=distance;
   //<
  if( distance <=30 ){
    //
    tone(buz,1000);
    Serial.print("la distance est ");
    Serial.println(distance);
  }
  else{
    noTone(buz);
    Serial.print("la distance est ");
    Serial.println(distance);
  }
  pot=analogRead(A0);
  
  Serial.print("la valeur du potentiometre est ");
  Serial.println(pot);
  pot=map(pot,0,1023,0,150);

    fenetre.write(pot);
    delay(50);

}
void ouvrirPorte(Servo porte){
  for(int i=90;i <= 180; i++){
    porte.write(i);
    delay(50);
  }
}
void fermerPorte(Servo porte){
  for(int i=180;i >= 90; i--){
    porte.write(i);
    delay(50);
  }
}