#include <HCSR04.h>

HCSR04 hc(2, 3); //initialisation class HCSR04 (trig pin , echo pin)

String dis_str;
float dis_reel;
void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{

    dis_str = hc.dist();
    dis_reel = dis_str.toFloat();
    Serial.println(hc.dist()); // return curent distance in serial
    delay(1000);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
    if (dis_reel < 50)
    {
      digitalWrite(7, LOW); 
      digitalWrite(13, HIGH); 
    }
    else if (dis_reel >= 50 & dis_reel < 100)
    {
      digitalWrite(13, HIGH);
      delay(10);
      digitalWrite(13, LOW);
      delay(10);
      digitalWrite(7, LOW); 
    }
    else if(dis_reel > 100){
      digitalWrite(13, LOW);
      digitalWrite(7, HIGH); 
    }
        
}
