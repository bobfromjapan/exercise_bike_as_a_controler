#include <Keyboard.h>
const int A_PIN = 7;
const int D_PIN = 8;
double v_logs[5] = {3.3,3.3,3.3,3.3,3.3}; 
double thresh = 3.3;


void setup(){
    pinMode(A_PIN, INPUT_PULLUP);
    pinMode(D_PIN, INPUT_PULLUP);
    Serial.begin( 9600 );
}

void loop(){
    int value_a, value_d;
    double value_w = analogRead(A0);
    value_w *= 5;
    value_w /= 1024;

    int i;
    double sum = 0 ;
  
    for (i = 0; i < 4; i = i + 1){
    v_logs[i] = v_logs[i+1];
    sum += v_logs[i];
    //Serial.println(v_logs[i]);
    }
    
    v_logs[4] = value_w; 
    sum += value_w;
  
    if(((sum/5) < thresh) && (sum > 10)){
      Keyboard.press(0x77);
      delay(100);
    }else{
      Keyboard.release(0x77);
    }
    
    value_a = digitalRead(A_PIN);
    if(value_a == LOW){
      Keyboard.press(0x61);
    }else{
      Keyboard.release(0x61);
    }

    value_d = digitalRead(D_PIN);
    if(value_d == LOW){
      Keyboard.press(0x64);
    }else{
      Keyboard.release(0x64);
    }
}
