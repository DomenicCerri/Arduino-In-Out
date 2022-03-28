int ledPin = 13;                // Laser is connected to pin 13
int switchPin = 2;              // med associates is connected to pin 2
int val;                    // variable for reading the pin status


void setup() {
 pinMode(ledPin, OUTPUT);      // Set the LED pin as output
 pinMode(switchPin, INPUT);    // Set the switch pin as input
 }
 
void loop(){
 val = digitalRead(switchPin);   // read input value and store it in val
 if (val == LOW) {               // check if external trigger is present
   digitalWrite(ledPin, HIGH);   // turn Laser on
   delay(5);                     // 5 ms pulse duration
   digitalWrite(ledPin, LOW);   // turn Laser off
   delay(45);                    //change this to change the frequency
 }
}
