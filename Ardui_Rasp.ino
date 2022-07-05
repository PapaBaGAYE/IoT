#include <HCSR04.h>

HCSR04 hc(2, 8); //initialisation class HCSR04 (trig pin , echo pin)

#include "DHT.h"
#define DHTPIN 13


#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
String dis_str;
float dis_reel;
void setup()
{
    Serial.begin(9600);
    pinMode(5, INPUT);
    pinMode(7, OUTPUT);
    
    pinMode(2, OUTPUT); // Trig
    pinMode(8, INPUT);// Echo

    dht.begin();

    pinMode(13, OUTPUT);
}

void loop()
{
    Serial.println(digitalRead(5));
    dis_str = hc.dist();
    dis_reel = dis_str.toFloat();
    
    Serial.println(String(hc.dist()) + " cm"); // return curent distance in serial
    delay(1000); 
    
    digitalWrite(13, HIGH);
    Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
    Serial.println("Humidite = " + String(dht.readHumidity())+" %");
    delay(1000);// we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
    digitalWrite(7, LOW);
           
}
