String myCmd;
int waitPin = 2;
int redPin = 10;
int greenPin = 9;
int bluePin = 8;
int waitT = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(waitPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  while(Serial.available() == 0){
  // looping to wait for data
  // putting pinMode in a while loop is for "dynamic" uses ex) changing from input to output. 
  digitalWrite(waitPin, HIGH);
  delay(waitT);
  digitalWrite(waitPin, LOW);
  delay(waitT);
  Serial.println("Waiting for data...");
  }

digitalWrite(waitPin,LOW);
myCmd = Serial.readStringUntil('\r');

if (myCmd == "red on"){
  digitalWrite(redPin, HIGH);
}
if (myCmd == "red off"){
  digitalWrite(redPin, LOW);
}
if (myCmd == "green on"){
  digitalWrite(greenPin, HIGH);
}
if (myCmd == "green off"){
  digitalWrite(greenPin, LOW);
}
if (myCmd == "blue on"){
  digitalWrite(bluePin, HIGH);
}
if (myCmd == "blue off"){
  digitalWrite(bluePin, LOW);
}
if (myCmd == "OFF"){
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);
}
//Serial.println(myCmd);
}
