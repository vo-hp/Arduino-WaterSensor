#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int val = 0;
int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int led5 = 10;
int perCent;

byte ngoisao[] = {
  B00000,
  B00100,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001,
  B00000
};


byte trong[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
}; 

void turnLed() {
  if (val > 120) {  //410
    analogWrite(led1, 60);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
  }
  if (val > 240) {  //450
    analogWrite(led1, 60);
    analogWrite(led2, 60);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
  }
  if (val > 360) {  //490
    analogWrite(led1, 60);
    analogWrite(led2, 60);
    analogWrite(led3, 60);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
  }
  if (val > 480) {  //530
    analogWrite(led1, 60);
    analogWrite(led2, 60);
    analogWrite(led3, 60);
    analogWrite(led4, 60);
    analogWrite(led5, 0);
  }
  if (val > 600) {  //570
    analogWrite(led1, 60);
    analogWrite(led2, 60);
    analogWrite(led3, 60);
    analogWrite(led4, 60);
    analogWrite(led5, 60);
  }
  if (val < 120) {
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
  }
}


void star() {
  if (perCent > 5) {
    lcd.setCursor(7, 1);
    lcd.write(0);
    lcd.setCursor(9, 1);
    lcd.write(1);
    lcd.setCursor(11, 1);
    lcd.write(1);
    lcd.setCursor(13, 1);
    lcd.write(1);
    lcd.setCursor(15, 1);
    lcd.write(1);

  }
  if (perCent > 20) {
    lcd.setCursor(9, 1);
    lcd.write(0);
    lcd.setCursor(11, 1);
    lcd.write(1);
    lcd.setCursor(13, 1);
    lcd.write(1);
    lcd.setCursor(15, 1);
    lcd.write(1);
  }
  if (perCent > 40) {
    lcd.setCursor(11, 1);
    lcd.write(0);
    lcd.setCursor(13, 1);
    lcd.write(1);
    lcd.setCursor(15, 1);
    lcd.write(1);
  }
  if (perCent > 60) {
    lcd.setCursor(13, 1);
    lcd.write(0);
    lcd.setCursor(15, 1);
    lcd.write(1);
  }
  if (perCent > 80) {
    lcd.setCursor(15, 1);
    lcd.write(0);
  }
  if (perCent <= 5) {
    lcd.setCursor(7, 1);
    lcd.write(1);
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, ngoisao);
  lcd.createChar(1, trong);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
  turnLed();
  perCent = map(val, 0, 690, 1, 100);
  String percent = String(perCent) + "%" ;
  lcd.setCursor(12, 0);
  lcd.print(perCent);
  // lcd.setCursor(15, 0);
  // lcd.print("%");
  star();
}
