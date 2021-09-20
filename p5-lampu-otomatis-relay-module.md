```ino
/*
  Dokumentasi
  https://drive.google.com/file/d/1O-u-E6wGmuln-VUyos7_ViIfTWSEsJ3w/view?usp=sharing
*/

#include <NewPing.h>
#define relayPin 6
#define trigPin  9
#define echoPin  10

NewPing sonar(trigPin, echoPin);

const int threshold = 3;
int distance = 0;

void setup() {
  Serial.begin (9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // Read distance
  distance = sonar.ping_cm();

  // Output
  if(distance < threshold) {
    digitalWrite(relayPin, HIGH);
    delay(500);
  } else {
    digitalWrite(relayPin, LOW);
    delay(500);
  }

  // Print nilai ke Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
```
