#include <dht.h>
#include <LiquidCrystal_I2C.h>
#define outpin 8

dht dht11;
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte Temp1[8] = {
0b00000,
0b00001,
0b00010,
0b00100,
0b00100,
0b00100,
0b00100,
0b00111
};

byte Temp2[8] = {
0b00000,
0b10000,
0b01011,
0b00100,
0b00111,
0b00100,
0b00111,
0b11100
};

byte Temp3[8] = {
0b00111,
0b00111,
0b00111,
0b01111,
0b11111,
0b11111,
0b01111,
0b00011
};

byte Temp4[8] = {
0b11111,
0b11100,
0b11100,
0b11110,
0b11111,
0b11111,
0b11110,
0b11000
};

byte Hum1[8] = {
0b00000,
0b00001,
0b00011,
0b00011,
0b00111,
0b01111,
0b01111,
0b11111
};

byte Hum2[8] = {
0b00000,
0b10000,
0b11000,
0b11000,
0b11100,
0b11110,
0b11110,
0b11111
};

byte Hum3[8] = {
0b11111,
0b11111,
0b11111,
0b01111,
0b00011,
0b00000,
0b00000,
0b00000
};

byte Hum4[8] = {
0b11111,
0b11111,
0b11111,
0b11110,
0b11000,
0b00000,
0b00000,
0b00000
};

void setup() {
  lcd.init();
  lcd.backlight();

  // Create icon temperatur
  lcd.createChar(0, Temp1);
  lcd.createChar(1, Temp2);
  lcd.createChar(2, Temp3);
  lcd.createChar(3, Temp4);

  // Create icon humidity
  lcd.createChar(4, Hum1);
  lcd.createChar(5, Hum2);
  lcd.createChar(6, Hum3);
  lcd.createChar(7, Hum4);

  lcd.clear();
}

void loop() {
  dht11.read11(outpin);

  int t = dht11.temperature;  // Read temperature
  int h = dht11.humidity;     // Read humidity

  // Print temperature
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.write(byte(1));

  lcd.setCursor(0, 1);
  lcd.write(byte(2));
  lcd.write(byte(3));

  lcd.setCursor(3, 0);
  lcd.print("Temp");
  lcd.setCursor(3, 1);
  lcd.setCursor(3, 1);
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  // Print humidity
  lcd.setCursor(9, 0);
  lcd.write(byte(4));
  lcd.write(byte(5));

  lcd.setCursor(9, 1);
  lcd.write(byte(6));
  lcd.write(byte(7));
  
  lcd.setCursor(12, 0);
  lcd.print("Humi");
  lcd.setCursor(12, 1);
  lcd.print(h);
  lcd.print((char)37);
  
  delay(500);
}
