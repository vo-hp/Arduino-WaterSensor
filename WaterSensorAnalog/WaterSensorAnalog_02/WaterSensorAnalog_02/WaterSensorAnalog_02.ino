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

byte ngoisao1[] = {
  B00000,
  B00100,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001,
  B00000
};

byte ngoisao2[] = {
  B00000,
  B00100,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001,
  B00000
};

byte ngoisao3[] = {
  B00000,
  B00100,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001,
  B00000
};

byte ngoisao4[] = {
  B00000,
  B00100,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001,
  B00000
};

byte ngoisao5[] = {
  B00000,
  B00100,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001,
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
  if (perCent < 5) {
  }
  if (perCent > 5) {
    if (perCent <= 20) {
      lcd.setCursor(8, 1);
      lcd.write(0);
    }
  }
  if (perCent <= 40) {
    if (perCent > 20) {
      lcd.setCursor(10, 1);
      lcd.write(0);
      lcd.write(1);
    }
  }
  if (perCent <= 60 and perCent > 40) {
    lcd.setCursor(12, 1);
    lcd.write(2);
  }
  if (perCent <= 80 and perCent > 60) {
    lcd.setCursor(14, 1);
    lcd.write(3);
  }
  if (perCent <= 100 and perCent > 80) {
    lcd.setCursor(16, 1);
    lcd.write(4);
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, ngoisao1);
  lcd.createChar(1, ngoisao2);
  lcd.createChar(2, ngoisao3);
  lcd.createChar(3, ngoisao4);
  lcd.createChar(4, ngoisao5);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
  turnLed();
  perCent = map(val, 0, 685, 1, 100);
  String percent = String(perCent) + "%";
  lcd.setCursor(12, 0);
  lcd.print(percent);
  star();
}
