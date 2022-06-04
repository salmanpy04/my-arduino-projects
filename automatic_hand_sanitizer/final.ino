#define relay_pin 7
#define trigPin 12
#define echoPin 13
#define Buzzer  8 // Connect buzzer pin to 8
#define ledPin 6  //Connect LEd pin to 6
int duration, distance; //to measure the distance and time taken 

void setup() {
        Serial.begin (9600); 
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(Buzzer, OUTPUT);
        pinMode(ledPin, OUTPUT);
        pinMode(relay_pin,OUTPUT);
        delay(300);
}

void loop() {
  
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    digitalWrite(ledPin,HIGH);
    
  if (distance >= 200 || distance <= 0) // loop for printing the disatance in serial monitor
        {
        Serial.println("no object detected");
        }
  else {
        Serial.println(" object detected \n");
        Serial.print("distance= ");              
        Serial.print(distance);
        
  }

  if(distance>=7)  
  {
        digitalWrite(relay_pin,HIGH);
        delay(500);
        
  }
  else{
        digitalWrite(Buzzer,HIGH);
        delay(100);
        digitalWrite(Buzzer,LOW);
        delay(100);
        digitalWrite(Buzzer,HIGH);
        delay(100);
        digitalWrite(Buzzer,LOW);
        delay(100);
        
        digitalWrite(relay_pin,LOW);
        delay(500);
        digitalWrite(relay_pin,HIGH);
        delay(2000);
    }


}
