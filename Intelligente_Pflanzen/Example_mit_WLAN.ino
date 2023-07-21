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

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  sensorValue = analogRead(sensor_pin);
  Serial.println(sensorValue);

  greenColor = led.Color(0, 50, 0);
  blackColor = led.Color(0, 0, 0);

  maxLedValue = sensorValue * (16.0 / 2000.0);
  for (int i = 0; i < 16; i++) {
    if (i < maxLedValue) {
      Serial.println("green");
      led.setPixelColor(i, greenColor);
    } else {
      Serial.println(maxLedValue);
      led.setPixelColor(i, blackColor);
    }
  }
  led.show();

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String serverPath = "#####" + String(sensorValue);  //Hier muss der Link zu ThingsSpeak eingefügt werden, (bis zum = Zeichen)

    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
    delay(10000);
  }
}