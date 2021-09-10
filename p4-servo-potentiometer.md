```ino
/*
  Dokumentasi
  https://drive.google.com/file/d/1xE9XT-jS8vkNezukiSTY4FsBn0ydWnwd/view?usp=sharing
*/

#include <Servo.h>
 
Servo servo;
int potPin = A0;
int servoPin = 9;
int value;
 
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
}
 
void loop() {
  // Potentiometer dari 0 hingga 1023, sedangkan Servo dari 0 hingga 180
  value = map(analogRead(potPin), 0, 1023, 0, 180);

  // Output ke Servo dan Serial Monitor
  servo.write(value);
  Serial.println(value);
  
  delay(10); 
}
```
