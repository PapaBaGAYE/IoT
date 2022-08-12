// Ultrason temperature humidite proximité alarme LED
// dmesg | grep tty           pour identification du port USB sur Rasberry pi
#include <HCSR04.h>
#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
HCSR04 hc(2, 8);   //initialisation class HCSR04 (trig pin , echo pin)

int T=28;
int H=65;
int D=15;
int pin_Bp=5;
bool Bp;
String mess="";
String message;

int LED=13;
int Alarme=7;
int recu;

void setup(){  
 Serial.begin(9600);
    pinMode(5, INPUT);
    pinMode(7, OUTPUT); //alarme
   
    pinMode(2, OUTPUT); // Trig
    pinMode(8, INPUT);// Echo

    dht.begin();

    pinMode(13, OUTPUT);
}
void loop(){                
if (Serial.available()>0) {
    recu = Serial.readString().toInt();    
    if (recu == 11) digitalWrite(LED, 1);
    else if (recu == 10) digitalWrite(LED, 0);
    else if (recu == 20) digitalWrite(Alarme, 0);
    else if (recu == 21) digitalWrite(Alarme, 1);   }      

D=hc.dist();
T=dht.readTemperature();
H=dht.readHumidity();
Bp=digitalRead(pin_Bp);

message = mess+T+','+H+','+D+','+Bp;
Serial.println(message);
delay(1000);
} 
