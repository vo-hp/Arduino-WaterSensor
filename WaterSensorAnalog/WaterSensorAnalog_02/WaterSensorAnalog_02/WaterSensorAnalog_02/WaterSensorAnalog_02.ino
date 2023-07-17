
int val = 0;
int led1 = 3; int led2 = 5; int led3 = 6; int led4 = 9; int led5 = 10;

void turnLed() {
  if ( val > 410 ) {
    analogWrite(led1, 60);
  }
  if ( val > 450 ) {
    analogWrite(led2, 60);
  }
  if ( val > 490 ) {
    analogWrite(led3, 60);
  }
  if ( val > 530 ) {
    analogWrite(led4, 60);
  }
  if ( val > 570 ) {
    analogWrite(led5, 60);
  }
  if ( val < 410 ) {
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
  turnLed();
}
