const int redLEDPin=11;
const int greenLEDPin=9;
const int blueLEDPin=10;
  
const int redSensorPin=A2;
const int greenSensorPin=A1;
const int blueSensorPin=A0;
  
int redValue=0;
int greenValue=0;
int blueValue=0;
  
int redSensorValue=0;
int greenSensorValue=0;
int blueSensorValue=0;

void setup() {
  Serial.begin(9600);
  
  pinMode(redLEDPin,OUTPUT);
  pinMode(greenLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
  
}

void loop() {
  redSensorValue=analogRead(redSensorPin);
  delay(5);
  greenSensorValue=analogRead(greenSensorPin);
  delay(5);
  blueSensorValue=analogRead(blueSensorPin);
  
  Serial.print("red sensor: ");
  Serial.println(redSensorValue);
  
  redValue=redSensorValue/4;
  greenValue=greenSensorValue/4;
  blueValue=blueSensorValue/4;
  
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
