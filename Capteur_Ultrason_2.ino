#include <HCSR04.h>

HCSR04 hc(2, 3); //initialisation class HCSR04 (trig pin , echo pin)

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop()
{
    
    if (hc.dist() < 50) digitalWrite(13, HIGH); else digitalWrite(13, LOW); 
    
    Serial.println(hc.dist()); // return curent distance in serial
    delay(1000);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
    
}
