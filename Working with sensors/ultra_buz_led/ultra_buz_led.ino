
/*
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    ---------------------
 * | HC-SC04 | Arduino |    | 3 pins  | Arduino |
 * ---------------------    ---------------------
 * |   Vcc   |   5V    |    |   Vcc   |   5V    |
 * |   Trig  |   7    | OR |   SIG   |   13    |
 * |   Echo  |   8    |    |   Gnd   |   GND   |
 |   Gnd   |   GND   |    ---------------------
  ---------------------
 
*/
/* This simple project describes how to make an ultrasonic alarm system using 
LED, Ultasonic Sensor(HC-SR04) and a buzzer.*/ 

//Firstly the connections of ultrasonic Sensor.Connect +5v and GND normally and trigger pin to 12 & echo pin to 13. 
int relay_pin = 7;
int led_pin = 11;
#define trigPin 12
#define echoPin 13
int Buzzer = 8; // Connect buzzer pin to 8
int ledPin= 6;  //Connect LEd pin to 6
int duration, distance; //to measure the distance and time taken 

void setup() {
        Serial.begin (9600); 
        //Define the output and input objects(devices)
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(Buzzer, OUTPUT);
        pinMode(ledPin, OUTPUT);

        pinMode(relay_pin,OUTPUT);
  pinMode(led_pin,OUTPUT);  
  digitalWrite(led_pin,HIGH);
}

void loop() {

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    //when distance is greater than or equal to 200 OR less than or equal to 0,the buzzer and LED are off
  if (distance >= 200 || distance <= 0) 
        {
        Serial.println("no object detected");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
        }
  else {
        Serial.println(" object detected \n");
        Serial.print("distance= ");              
        Serial.print(distance);        //prints the distance if it is between the range 0 to 200
        tone(Buzzer,400);              // play tone of 400Hz for 500 ms
        digitalWrite(ledPin,HIGH);
        
  }

  if(distance>=7)
  {
        digitalWrite(relay_pin,LOW);
        delay(2000);
        
  }
  else{
        digitalWrite(relay_pin,HIGH);
        delay(2000);
    }
  
}
