#include <HCSR04.h>

HCSR04 hc(2, 8); //initialisation class HCSR04 (trig pin , echo pin)

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
String dis_str;
float dis_reel;

int T;
float H;
int D;
int pin_Bp = 5;
int Bp;

String mess = "";
String message;

void setup()
{
    Serial.begin(9600);
    pinMode(5, INPUT);
    pinMode(7, OUTPUT);
    
    pinMode(2, OUTPUT); // Trig
    pinMode(8, INPUT);  // Echo

    dht.begin();

    pinMode(13, OUTPUT);

    while (!Serial) {;}
    pinMode(pin_Bp, INPUT);
}

void loop()
{
    // Serial.println(digitalRead(5));
    // dis_str = hc.dist();
    // dis_reel = dis_str.toFloat();
    
    // Serial.println(String(hc.dist()) + " cm"); // return curent distance in serial
    // delay(1000); 
    
    // digitalWrite(13, HIGH);
    // Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
    // Serial.println("Humidite = " + String(dht.readHumidity())+" %");
    // delay(1000);
    // digitalWrite(7, LOW);

    T = dht.readTemperature();
    H = dht.readHumidity();
    D = hc.dist();
    
    Bp = digitalRead(pin_Bp);
      message = mess + T +  " , " + H + ", " + D + ", " + Bp;
      Serial.println(message);
      delay(1000);
           
}
