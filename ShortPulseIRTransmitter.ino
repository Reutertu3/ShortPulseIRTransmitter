// IRPulse


int IRledPin =  0;    // LED connected to digital pin 3
int powerLed = 1;    //Power LED is connected to pin 1

void setup()   {              
  
  pinMode(IRledPin, OUTPUT);
  pinMode(powerLed, OUTPUT);
  digitalWrite(powerLed, HIGH);
}

void loop()                  
{
  pulseIR(468);
  delayMicroseconds(1200);
  pulseIR(468);
  delayMicroseconds(1200);
  pulseIR(468);
  delayMicroseconds(6000);
}


void pulseIR(long microsecs) {    // This procedure sends a 38KHz pulse to the IRledPin
                                  // for a certain # of microseconds.
                                  // we'll count down from the number of microseconds we are told to wait                                                                                                                                         

  cli();  // this turns off any background interrupts

  while (microsecs > 0) {
                                                                                                                                                                                                                            // 38 kHz is about 26 microseconds - to give 50% duty cycle 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds

   // so 26 microseconds altogether
   microsecs -= 26;
  }

  sei();  // this turns them back on
}
