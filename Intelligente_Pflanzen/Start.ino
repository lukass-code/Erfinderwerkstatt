#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "####";
const char* password = "#####";

#define PIN            32
#define NUMPIXELS      16
Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


const int sensor_pin = 34;
int sensorValue = 0;
float maxLedValue = 0;

long greenColor;
int blackColor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");
  led.begin();

  // Setup Wifi

}

void loop() {
  // Read Sensor Value

  // Set LED

  // Send Value to Cloud

  

    delay(10000);
}