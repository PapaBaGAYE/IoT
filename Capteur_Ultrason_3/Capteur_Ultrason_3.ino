#include <HCSR04.h>

HCSR04 hc(2, 8); //initialisation class HCSR04 (trig pin , echo pin)

String dis_str;
float dis_reel;
void setup()
{
    Serial.begin(9600);
    pinMode(7, OUTPUT);
    pinMode(3, OUTPUT);
    
    pinMode(2, OUTPUT); // Trig
    pinMode(8, INPUT);// Echo
}

void loop()
{

    /*dis_str = hc.dist();
    dis_reel = dis_str.toFloat();
    */
    
    Serial.println(String(hc.dist()) + " cm"); // return curent distance in serial
    delay(1000);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
    if (hc.dist() < 50)
    {
      digitalWrite(3, HIGH);
    }
    else if (hc.dist() >= 50 & hc.dist() < 100)
    {
      
      digitalWrite(7, HIGH);
      digitalWrite(3, HIGH); 
      delay(100);
      
      digitalWrite(7, LOW);
      digitalWrite(3, LOW);
      delay(100); 
    }
    /*else if(hc.dist() > 100){
      digitalWrite(13, LOW);
      digitalWrite(7, HIGH); 
    }*/
        
}
