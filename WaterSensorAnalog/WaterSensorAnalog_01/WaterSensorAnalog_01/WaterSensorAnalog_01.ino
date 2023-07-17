int val;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);


}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
}