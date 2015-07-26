const int sensorPin=A0;
const float baselineTemp=26.0;

void setup() {
  Serial.begin(9600);
  for(int pinNumber=3; pinNumber<7; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop(){
  int sensorVal=analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float voltage=sensorVal/1024.0*5.0;
  Serial.print(",   Voltage: ");
  Serial.print(voltage);
  float temperature=(voltage-0.5)*100;
  Serial.print(",   Degrees C: ");
  Serial.println(temperature);
  
  if(temperature<baselineTemp){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  else if(temperature<(baselineTemp+2)){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  else if(temperature<(baselineTemp+4)){
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }
  else {
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  }
  loop2();
  loop3();
}

void loop3() {
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  delay(100);
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  delay(100);
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  delay(100);
}
