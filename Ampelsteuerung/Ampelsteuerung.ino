#include <Adafruit_NeoPixel.h>

// LED und Ampel
#define LED_PIN        10
#define NUMPIXELS      4
Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
#define Autoampel_1 0
#define Autoampel_2 1
#define Fussgaengerampel_1  2
#define Fussgaengerampel_2  3

long red_color = led.Color(250,0,0);
long yellow_color = led.Color(250,250,0);
long green_color = led.Color(0,250,0);

// Hall-Sensor
#define Hall_Sensor_1_PIN  8
#define Hall_Sensor_2_PIN  9
bool Hall_Sensor_1 = HIGH;
bool Hall_Sensor_2 = HIGH;
bool mag_da_1 = LOW;
bool mag_da_2 = LOW;

// Taster
#define Taster_1_PIN  6
#define Taster_2_PIN  7
bool Taster_1 = HIGH;
bool Taster_2 = HIGH;
bool pressed_1 = LOW;
bool pressed_2 = LOW;

// Ampelstatus
int ampel_status = 0;

void setup() {
  led.begin();
  
  pinMode(Hall_Sensor_1_PIN, INPUT);
  pinMode(Hall_Sensor_2_PIN, INPUT);
  pinMode(Taster_1_PIN, INPUT_PULLUP);
  pinMode(Taster_2_PIN, INPUT_PULLUP);
  
  Serial.begin(9600);

}

void loop() {
  Serial.println(ampel_status);
  // Eingänge abfragen
  Hall_Sensor_1  = digitalRead(Hall_Sensor_1_PIN);
  //Hall_Sensor_2  = digitalRead(Hall_Sensor_2_PIN);
  Taster_1  = digitalRead(Taster_1_PIN);
  //Taster_2  = digitalRead(Taster_2_PIN);

  
  switch (ampel_status) {
    case 0:
      // Ampelfarben setzen
      led.setPixelColor(Autoampel_1, green_color);
      led.setPixelColor(Autoampel_2, green_color);
      led.setPixelColor(Fussgaengerampel_1, red_color);
      led.setPixelColor(Fussgaengerampel_2, red_color);
      led.show();

      if((!Taster_1 && !pressed_1)|| (!Taster_2 && !pressed_2)){
        Serial.println("Taster gedrückt");
        pressed_1, pressed_2 = HIGH;
        ampel_status = 1;
      }
      break;
    case 1:
    // Ampelfarben setzen
      led.setPixelColor(Autoampel_1, yellow_color);
      led.setPixelColor(Autoampel_2, yellow_color);
      led.setPixelColor(Fussgaengerampel_1, red_color);
      led.setPixelColor(Fussgaengerampel_2, red_color);
      led.show();
      
      delay(1000);
      ampel_status = 2;
      break;
    case 2:
    // Ampelfarben setzen
      led.setPixelColor(Autoampel_1, red_color);
      led.setPixelColor(Autoampel_2, red_color);
      led.setPixelColor(Fussgaengerampel_1, red_color);
      led.setPixelColor(Fussgaengerampel_2, red_color);
      led.show();
      
      delay(1000);
      ampel_status = 3;
      break;
    case 3:
    // Ampelfarben setzen
      led.setPixelColor(Autoampel_1, red_color);
      led.setPixelColor(Autoampel_2, red_color);
      led.setPixelColor(Fussgaengerampel_1, green_color);
      led.setPixelColor(Fussgaengerampel_2, green_color);
      led.show();

      if((!Hall_Sensor_1 && !mag_da_1) || (!Hall_Sensor_2 && !mag_da_2)){
        Serial.println("Magnet da");
        mag_da_1, mag_da_2 = HIGH;
        ampel_status = 4;
      }
      break;
    case 4:
    // Ampelfarben setzen
      led.setPixelColor(Autoampel_1, red_color);
      led.setPixelColor(Autoampel_2, red_color);
      led.setPixelColor(Fussgaengerampel_1, red_color);
      led.setPixelColor(Fussgaengerampel_2, red_color);
      led.show();

      delay(1000);
      ampel_status = 5;
      break;
    case 5:
    // Ampelfarben setzen
      led.setPixelColor(Autoampel_1, yellow_color);
      led.setPixelColor(Autoampel_2, yellow_color);
      led.setPixelColor(Fussgaengerampel_1, red_color);
      led.setPixelColor(Fussgaengerampel_2, red_color);
      led.show();

      delay(1000);
      ampel_status = 0;
      break;
  }

  if((Taster_1 && pressed_1)|| (Taster_2 && pressed_2)){
    Serial.println("Taster nicht gedrückt");
    pressed_1, pressed_2 = LOW;
  }
  
  if((Hall_Sensor_1 && mag_da_1) || (Hall_Sensor_2 && mag_da_2)){
    Serial.println("Magnet weg");
    mag_da_1, mag_da_2 = LOW;
  }


}
