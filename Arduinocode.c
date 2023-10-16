 #include <Servo.h>
 Servo servo;
 int servo_pin = 2;
int TRIG_PIN = 13;
int ECHO_PIN = 12;
 int MOTOR_PIN1 = 6;
int MOTOR_PIN2 = 5;
 float SPEED_SOUND = 0.0345;
void setup(){
pinMode(MOTOR_PIN1, OUTPUT);
pinMode(MOTOR_PIN2, OUTPUT);
pinMode(TRIG_PIN, OUTPUT);
digitalWrite(TRIG_PIN, LOW);
pinMode(ECHO_PIN, INPUT);
servo.attach(servo_pin,540,2000);
Serial.begin(9600);
}
void loop(){
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(60);
digitalWrite(TRIG_PIN, LOW);
int microsecs = pulseIn(ECHO_PIN, HIGH);
float cms = microsecs*SPEED_SOUND/2;
Serial.println(cms);
if (cms < 10) {
digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
for (int i = 0; i <= 180; i++) {
servo.write(i);
delay(5);
 }
 for (int i = 180; i >= 0; i--) {
 servo.write(i);
 delay(5);
 }
 } else{
 digitalWrite(MOTOR_PIN1, HIGH);
digitalWrite(MOTOR_PIN2, HIGH);
 
