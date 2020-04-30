const int trigPin = 12;
const int echoPin = 11;
int m1 = 7;
int m2 = 6;
int m3 = 5;
int m4 = 4;

char initial;
int i;
void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}
long duration, distance;

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  if (Serial.available() > 0) {
    initial = Serial.read();
  }

  if (initial == 'F') {
    //forward
    if (distance < 30)
    {
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
      delay(100);
    }
    else
    {
      digitalWrite(m1, HIGH);
      digitalWrite(m3, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m4, LOW);
    }
  }
  if (initial == 'B') {
    //Backward
    digitalWrite(m2, HIGH);
    digitalWrite(m4, HIGH);
    digitalWrite(m1, LOW);
    digitalWrite(m3, LOW);
  }

  if (initial == 'R') {
    //Right


    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  if (initial == 'L') {
    //Left
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
  }
  if (initial == 'P') {
    //stop
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    i = 0;
  }
}




