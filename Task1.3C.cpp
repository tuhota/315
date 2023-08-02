#include<Servo.h>
Servo motor;

//angle for servo
int angle = 0;

int tiltPin = 2;
int pirPin = 3;
int servoPin = 13;

void setup()
{
    pinMode(tiltPin, INPUT_PULLUP);
    pinMode(pirPin, INPUT_PULLUP);
    pinMode(servoPin, OUTPUT);
    motor.attach(servoPin);
    
    Serial.begin(9600);
    
    //interrupts when tilt detected via sensor (HIGH signal)
    attachInterrupt(digitalPinToInterrupt(tiltPin), interruptTilt, HIGH);
    //interrupts when motion detected via sensor (HIGH signal)
    attachInterrupt(digitalPinToInterrupt(pirPin), interruptPIR, HIGH);
}

//withdraws servo 5 degress
void interruptTilt()
{
    angle -= 5;
    Serial.print("Tilt detected. Withdrawing servo, angle now: ");
    Serial.println(angle);
    motor.write(angle);  
}

//advanced servo 5 degress
void interruptPIR()
{
  	angle += 5;
    Serial.print("Motion detected. Advancing servo, angle now: ");
  	Serial.println(angle);
    motor.write(angle);  
}

void loop()
{  
}
