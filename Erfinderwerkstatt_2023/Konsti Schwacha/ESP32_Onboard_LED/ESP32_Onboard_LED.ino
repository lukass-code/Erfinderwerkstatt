#define on_board_LED 27

void setup() {
  pinMode(on_board_LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(on_board_LED,HIGH);
  Serial.println("LED OOON");
  delay(200);
  digitalWrite(on_board_LED,LOW);
  Serial.println("LED OFF");
  delay(200);
}
