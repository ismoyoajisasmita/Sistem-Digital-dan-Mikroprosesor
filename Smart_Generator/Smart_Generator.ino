int ledPin = 2;int buzzer = 10;
int triggerPin = 7;int echoPin = 6;
int pln = 9;int genset = 8;
void(* reset_Arduino) (void) = 0;
void setup(){
  Serial.begin(9600);
  pinMode(echoPin, INPUT);pinMode(triggerPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin+1, OUTPUT);
  pinMode(ledPin+2, OUTPUT);
  pinMode(ledPin+3, OUTPUT);
  pinMode(pln, INPUT);pinMode(genset, INPUT);
  digitalWrite(pln, HIGH);digitalWrite(genset, LOW);}
void systemOn(){
  digitalWrite(ledPin+2, HIGH);delay(500);
  digitalWrite(ledPin+3, HIGH);}
void systemOff(){
  digitalWrite(ledPin+3, LOW);delay(100);
  digitalWrite(ledPin+2, LOW);}
void startingEngine(){
  digitalWrite(ledPin+1, HIGH);delay(500);
  digitalWrite(ledPin+1, LOW);delay(50);}
void loop(){
  long duration, distance;
  digitalWrite(triggerPin, LOW);delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/4330.06;
  Serial.println(distance);delay(10);
  if(digitalRead(pln) == LOW && distance <= 13 && digitalRead(genset) == LOW){
    digitalWrite(ledPin, HIGH);delay(500);
    systemOff();startingEngine();}
  else if(digitalRead(pln) == LOW && distance <= 13 && digitalRead(genset) == HIGH){
    systemOn();}
  else{
    systemOff();
    digitalWrite(ledPin, LOW);reset_Arduino();}}
