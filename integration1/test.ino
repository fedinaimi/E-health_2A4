// Code for sensing a switch status and writing the value to the serial port.

byte switchPin = 3;  // Switch connected to pin 3
const int redPin = 9;
const int greenPin = 10;
char data1;

void setup() {
  pinMode(switchPin, INPUT);// Set pin 2 as an input
  pinMode(redPin, OUTPUT); // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,LOW);
  Serial.begin(9600);// Start serial communication at 9600 bps
}

void loop() {
  //if (Serial.available()){
   // data=Serial.read();
  if (digitalRead(switchPin) == LOW) {  // If switch is ON,
    //Serial.write("1"); // send 1 to Serial (Processing)
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  } 
  /*else if (digitalRead(switchPin) == LOW){                               // If the switch is not ON,
    Serial.write("0");                     // send 0 to Serial (Processing)
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }*/
  else if(digitalRead(switchPin) == HIGH)
  {
    data1='2';

  digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    delay(1000);
  
  }
//}
}
