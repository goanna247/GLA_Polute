

const int UltraSonic = 11;

void setup() {
  Serial.begin(9600);
}

void loop() {

  long duration, cm;
  pinMode(UltraSonic, OUTPUT);
  //does this work?

  
  digitalWrite(UltraSonic, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonic, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonic, LOW);


  pinMode(UltraSonic, INPUT);
  duration = pulseIn(UltraSonic, HIGH);

  cm = microsecondsToCentimeters(duration);

  //prints the output of the ultrasonic 
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}


long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
