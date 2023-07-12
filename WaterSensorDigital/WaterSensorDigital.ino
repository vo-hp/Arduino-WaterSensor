int preVal = 0;
int val;
int count = 1;
int relay = 9;

void xuLi () {
  Serial.print("detect water ");
  Serial.println(count++);
  digitalWrite(13, HIGH);
  batBom();
  digitalWrite(13, LOW);
}

void batBom() {
  digitalWrite(relay, HIGH);
  guiTinNhan();
  digitalWrite(relay, LOW);
}

void guiTinNhan () {
  Serial.println("Bom da duoc bat");
  for (int i = 30; i >= 0; i--) {
    Serial.print("Bom se tat sau ");
    Serial.print(i);
    Serial.println(" giay");
    delay(1000);
  }
  //delay(30000);
  Serial.println("Bom da tat");
}

void setup() {
  Serial.begin(9600);
  Serial.println("cam bien nuoc da duoc kich hoat");
  Serial.println("--");
  pinMode(8, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(13, OUTPUT);
  preVal = digitalRead(8);
  digitalWrite(relay, LOW);
  digitalWrite(13, LOW);
}

void loop() {
  val = digitalRead(8);
  if ( val == 1 and preVal == 0 ) {
    xuLi();
  }
  preVal = val;
}
