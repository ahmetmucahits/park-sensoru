// HC-SR04 Sensor pin bilgileri

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int BUZZER_PIN = 8;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float mesafe = mesafeOlc();

  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  if (mesafe > 0 && mesafe <= 5) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(60);
  } else if (mesafe > 5 && mesafe <= 10) {
    bip(100);
  } else if (mesafe > 10 && mesafe <= 15) {
    bip(350);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    delay(60);
  }
}

float mesafeOlc() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long sure = pulseIn(ECHO_PIN, HIGH, 3000);
  return sure * 0.0343 / 2;
}

void bip(int bekleme) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(50);
  digitalWrite(BUZZER_PIN, LOW);
  delay(bekleme);
}