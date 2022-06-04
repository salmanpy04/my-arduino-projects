int const trigPin = 6;
int const echoPin = 7;
int const buzzPin = 3;
int IRSensor = 2;
int distance;

void setup() {

  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width

  pinMode (IRSensor, INPUT); //IR sensor pin INPUT
  pinMode(buzzPin,OUTPUT);

  Serial.begin (9600);

}

void loop() {

  int duration, distance;
  
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
 
    if (distance <= 50 && distance >= 0) {
      
      digitalWrite(buzzPin, HIGH);
     
    } else {
     
      digitalWrite(buzzPin, LOW);
    }
    
    delay(60);
    Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  distance=digitalRead(IRSensor);
  if ((distance)== LOW)
  {
    digitalWrite(buzzPin,HIGH);
    
    delay(10);
  }
  else 
  {
    
    digitalWrite(buzzPin,LOW);
    delay(10);
  }
}
