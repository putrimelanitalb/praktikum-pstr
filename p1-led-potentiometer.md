```ino
/*
  Dokumentasi
  https://drive.google.com/file/d/1cURxHxCf0hdQJCvGVtiqqc_2fHnEAKJN/view?usp=sharing
*/

int readVal = 0;  // Variabel nilai input dari A0
int ledVal = 0;   // Variabel nilai output dari potentiometer 

void setup() {
  // Inisialisasi pinMode
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Read nilai dari A0
  int readVal = analogRead(A0);
  // Re-map dari 0-1023 ke 0-255
  int ledVal = map(readVal, 0, 1023, 0, 255);
  
  analogWrite(LED_BUILTIN, ledVal);
}
```
