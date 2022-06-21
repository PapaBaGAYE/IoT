
// Capteur de temperature et d'humidite DHT11

// https://tutoduino.fr/

// Copyleft 2020

 

#include "DHT.h"

 

// Definit la broche de l'Arduino sur laquelle la

// broche DATA du capteur est reliee

#define DHTPIN 2

 

// Definit le type de capteur utilise

#define DHTTYPE DHT11

 

// Declare un objet de type DHT

// Il faut passer en parametre du constructeur

// de l'objet la broche et le type de capteur

DHT dht(DHTPIN, DHTTYPE);

 

void setup() {
  Serial.begin(9600);
  // Initialise la capteur DHT11
  dht.begin();
}

void loop() {
  // Recupere la temperature et l'humidite du capteur et l'affiche
  // sur le moniteur serie
  Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
  Serial.println("Humidite = " + String(dht.readHumidity())+" %");

  // Attend 10 secondes avant de reboucler
  delay(10000);
}
