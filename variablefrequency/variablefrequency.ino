int outone = 13;                // LED1 is connected to pin 13
int outtwo = 12;            // LED2 is connected to pin 13
int frequency = 2;              // TTL1 is connected to pin 2
int LEDon = 3;                  //TTL2 is connected to pin 3
int LEDstate;                    // variable for reading LEDon
int freqstate = 0;                    // variable for reading frequency
int freqcount = 0;
int lastfreqstate = 0;
int pulsedelay;
int pulsenumber;
int pulsecount;

void setup() {
    pinMode(outone, OUTPUT);
    pinMode(outtwo, OUTPUT);
    pinMode(frequency, INPUT);
    pinMode(LEDon, INPUT);
}

void loop(){
    freqstate = digitalRead(frequency);   // read input value and store it in val
    if (freqstate != lastfreqstate) {               // check if external trigger is present
        lastfreqstate = freqstate;
        if (freqstate == LOW) {
            freqcount++;
            if (freqcount == 5) {
                freqcount = 1;
            }
            switch(freqcount){
                case 1:
                    pulsedelay = 95;
                    pulsenumber = 100;
                    break;
                case 2:
                    pulsedelay = 45;
                    pulsenumber = 200;
                    break;
                case 3:
                    pulsedelay = 15;
                    pulsenumber = 500;
                    break;
                case 4:
                    pulsedelay = 7.5;
                    pulsenumber = 800;
                    break;
            }
        }
    }
        
    LEDstate = digitalRead(LEDon);   // read input value and store it in LEDstate
    if (LEDstate == LOW){
        freqcount = 0;
        for (pulsecount = 0; pulsecount < pulsenumber; pulsecount++) {               // check if external trigger is present
            digitalWrite(outone, HIGH);
            digitalWrite(outtwo, HIGH);   // turn Laser on
            delay(5);                     // 5 ms pulse width
            digitalWrite(outone, LOW);
            digitalWrite(outtwo, LOW);
            delay(pulsedelay);   //change this to change the frequency
        }
    }
}