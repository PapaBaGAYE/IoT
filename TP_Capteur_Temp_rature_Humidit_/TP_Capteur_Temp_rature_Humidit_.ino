
// Capteur de temperature et d'humidite DHT11

// https://tutoduino.fr/

// Copyleft 2020

 

#include "DHT.h"

 

// Definit la broche de l'Arduino sur laquelle la

// broche DATA du capteur est reliee

#define DHTPIN 13

 

// Definit le type de capteur utilise

#define DHTTYPE DHT11

String dis_str;
float dis_reel;

// Declare un objet de type DHT

// Il faut passer en parametre du constructeur

// de l'objet la broche et le type de capteur

DHT dht(DHTPIN, DHTTYPE);

 

void setup() {
  dis_str = dht.readTemperature();
  dis_reel = dis_str.toFloat();
    
  Serial.begin(9600);
  // Initialise la capteur DHT11
  dht.begin();

  pinMode(13, OUTPUT);
  //pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  
  // Recupere la temperature et l'humidite du capteur et l'affiche
  // sur le moniteur serie
  Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
  Serial.println("Humidite = " + String(dht.readHumidity())+" %");

  // Attend 10 secondes avant de reboucler
  delay(1000);

  // digitalWrite(7, HIGH);

  /*if (dht.readTemperature() > 30) 
  {
    digitalWrite(7, HIGH);
    delay(50);
    digitalWrite(7, LOW);
    delay(50);
  }*/
  //else digitalWrite(7, LOW);
}
