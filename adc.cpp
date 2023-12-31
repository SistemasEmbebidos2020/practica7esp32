#include <Arduino.h>
const int pinAnalog= 26;
int pines[]={2,4,5,18,19,21,22,23,32,33};
int ADC=0;
void mostrarleds(){
  float r=(ADC/1023.0)*3.3;
  if(r<0.33){
    for(int i=0;i<=9;i++){
      if(i<1){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);
      }}}
  else if(r<0.66){
    for(int i=0;i<=9;i++){
      if(i<=1){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);
      }}}
  else if(r<0.99){
    for(int i=0;i<=9;i++){
      if(i<=2){
        digitalWrite(pines[i], HIGH);
      }else{
        digitalWrite(pines[i],LOW);
      }}}
  else if(r<1.32){
    for(int i=0;i<=9;i++){
      if(i<=3){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);
      }}}
  else if(r<1.65){
    for(int i=0;i<=9;i++){
      if(i<=4){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);
      }}}
  else if(r<1.98){
    for(int i=0;i<=9;i++){
      if(i<=5){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);
      }}}
  else if(r<2.31){
    for(int i=0;i<=9;i++){
      if(i<=6){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);
      }}}
  else if(r<2.64){
    for(int i=0;i<=9;i++){
      if(i<=7){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);
      }}}
  else if(r<2.97){
    for(int i=0;i<=9;i++){
      if(i<=8){
        digitalWrite(pines[i], HIGH);
      }else{digitalWrite(pines[i],LOW);        
      }}}
    else if(r<3.30){
      for(int i=0;i<=9;i++){
        digitalWrite(pines[i], HIGH);
      }}    
}
void setup() {
  pinMode(pinAnalog, INPUT);
  for(int i=0; i<10;i++){
  pinMode(pines[i], OUTPUT);
  }
  analogReadResolution(10);
  delay(100);
}
void loop() {
  ADC = analogRead(pinAnalog);
  mostrarleds();
  delay(500);
}
