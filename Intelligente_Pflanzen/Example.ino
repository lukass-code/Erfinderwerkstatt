#include <Adafruit_NeoPixel.h> //Einbinden der Adafruit Bibliothek (quasi der Werkzeugkasten um die LED anzusteuern)

#define PIN            33 //Definiere PIN LED Anschluss
#define NUMPIXELS      16 //Definiere Anzahl LEDs

const int sensorPin = 34; //Definiere PIN Sensor
float sensorValue; //Variable anlegen um Sensorwert später zu speichern
int ledanzahl = 0; //Variable anlegen um Anzahl der LEDs die leuchten sollen zu speichern

Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //LED Ring Objekt anlegen
long green_color; //Variable für Farbe Grün
long black_color; //Variable für Farbe Rot

void setup() {
  Serial.begin(9600); //Starten des Seriellen Monitors
  led.begin(); //LED aktivieren (initialisieren)
}

void loop() {
  sensorValue = analogRead(sensorPin); //Sensorwert auslesen
  Serial.println(sensorValue); //Sensorwert im Seriellen Monitor anzeigen
  
  ledanzahl = sensorValue*(16.0/2500.0); //Berechnen wie viele LEDs leuchten sollen
  
  delay(1000); //Warte eine Sekunde

  green_color = led.Color(0, 50, 0); //Grüne Farbe anlegen
  black_color = led.Color(0, 0, 0); // Schwarze Farbe anlegen

  for (int i = 0; i < 16; i++) { //Schleife von 0 bis 15 (16-mal durchlaufen)
    if(i < ledanzahl){ //Wenn dann Bedinngung, wenn i kleiner als die berechnete LED Anzahl ist, wird die LED auf Grün gesetzt
    led.setPixelColor(i, green_color); //Setze die i-te LED auf Grün
    }else{
      led.setPixelColor(i, black_color); //Wenn Bedinnung (oben) nicht erfüllt setze die i-te LED auf Schwarz
    }
  }
  led.show(); //Lasse die LEDs in den Farben leuchten

}
