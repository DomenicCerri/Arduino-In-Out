int ledPin = 13;                // Laser is connected to pin 13
int input1 = 2;              // med associates is connected to pin 2
int input2 = 3;            // med associates is connected to pin 3
int val1;                    // variable for reading the pin status
int val2;

void setup() {
 pinMode(ledPin, OUTPUT);      // Set the LED pin as output
 pinMode(input1, INPUT);    // Set the switch pin as input
 pinMode(input2, INPUT);    // Set the switch pin as input
 }
 
void loop(){
 val1 = digitalRead(input1);
 val2 = digitalRead(input2); // read input value and store it in val
 if (val1 == LOW) {               // check if external trigger is present
   digitalWrite(ledPin, HIGH);   // turn Laser on
   delay(5);                     // 5 ms pulse duration
   digitalWrite(ledPin, LOW);   // turn Laser off
   delay(7);                    //change this to change the frequency
 }
 if (val2 == LOW) {               // check if external trigger is present
   digitalWrite(ledPin, HIGH);   // turn Laser on
   delay(5);                     // 5 ms pulse duration
   digitalWrite(ledPin, LOW);   // turn Laser off
   delay(45);                    //change this to change the frequency
 }
}
