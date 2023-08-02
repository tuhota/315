#include<Servo.h>
Servo motor;

//angle for servo
int angle = 0;

int sensorPin = 2;
int servoPin = 13;

void setup()
{
    pinMode(sensorPin, INPUT_PULLUP);
    pinMode(servoPin, OUTPUT);
    motor.attach(servoPin);
    
    Serial.begin(9600);
    
    //interrupts when motion detected via sensor (HIGH signal)
    attachInterrupt(digitalPinToInterrupt(sensorPin), interrupt, HIGH);
}

//advanced servo 5 degrees
void interrupt()
{
    angle += 5;
    Serial.print("IR detected. Advancing servo, angle now: ");
    Serial.println(angle);
    motor.write(angle);  
}

void loop()
{  
}
