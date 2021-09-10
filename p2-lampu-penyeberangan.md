```ino
/*
   Dokumentasi
   https://drive.google.com/file/d/1RsCHzIimj8qKr9LWPArMbmYQDWtaVTFv/view?usp=sharing
*/
#define N 10
const int BUTTON = 3;
const int GREEN = 9;
const int YELLOW = 10;
const int RED = 11;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  // Cek jika button ditekan, maka buttonState = HIGH
  if(buttonState == HIGH) {
    // Lampu merah menyala
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    
    // Lampu kuning kedip-kedip
    for(int i = 0; i < N; i++) {
      digitalWrite(YELLOW, HIGH);
      delay(1000);
      digitalWrite(YELLOW, LOW);
      delay(1000);
    }
  } else {
    // Lampu hijau menyala
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
  }
}
```
