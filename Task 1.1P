#include<Servo.h>
Servo motor;

int C;
int raw;

int angle = 0;

int sensorPin = A5;
int servoPin = 7;

void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(servoPin, OUTPUT);
  motor.attach(servoPin);
  
  Serial.begin(9600);
}

void loop()
{  
  //raw milliVolt input
  raw = analogRead(A0);
  //converts raw input in milliVolts to celsius
  C = (raw - 500) / 10;
  
  //display raw input and celsius conversion
  Serial.print("Raw: ");
  Serial.println(raw);
  Serial.print("Celsius: ");
  Serial.println(C);
  
  //advance servo 5 degrees if temperature is greater than 20C
  if(C > 20)
  {
	angle += 5;
    Serial.print("Advancing, angle now: ");
  	Serial.println(angle);
    motor.write(angle);  
  }
  
  delay(1000); 
}
