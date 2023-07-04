# Intelligente Pflanzen

Wir wollen mit einem ESP32 (eine Art Arduino mit Wlan) den Feuchtigkeitsgrad einer Pflanze überwachen und diesen mit einem LED Ring anzeigen.

## 0. Einrichtung:

Für den ESP32:<br>
-> Siehe https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

Wir verwenden aber:
```
https://dl.espressif.com/dl/package_esp32_index.json
boardsmanager.additional.urls=https://dl.espressif.com/dl/package_esp32_index.json
```

Für Adafruit:
<br>
https://github.com/adafruit/Adafruit_NeoPixel


___

## 1. Grundlagen

### Programmaufbau:
Ein Arduinoprogramm besteht aus einem Header und einem Loop Teil.
Hierbei wird der Loop Teil sehr schnell wiederholt solange dar Arduino läuft.

```
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```
### Variablen:
Variablen sind wie Kisten. In sie kann etwas reingepackt werden. Man kann das was man reingepackt hat auch wieder auspacken oder verändern. es gibt verschiedene Typen. Wir nutzen:
- Zahlen: int
- Wahr/Falsch Wert: boolen

Zur Anzeige von Werten nutzen wir noch Serial.println(MeinWert);

Verwendung:

```
int meineVariable = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    meineVariable = meineVariable + 1;
    Serial.println(meineVariable);
}
```
-> Was passiert bei diesem Programm ??

### Wenn-dann Bedingungen:
Stelle dir vor du stehst an einer Weggebelung. Du kannst entweder den einen ander anderen Weg gehen. Dies hängt ab von einer Bedinngung. Du stehst also im Wald. Wenn die Blätter grün sind gehst du rechts, wenn sie gelb sind, links.
<br>Als Programm würde das etwa so aussehen:
```
bool blaetter_gruen = HIGH;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if(blaetter_gruen == HIGH){
        Serial.println("gehe rechts");
    }else{
        Serial.println("gehe links");
    }
}
```

### Neopixel:

Weitere Informationen: https://blog.berrybase.de/blog/2020/11/09/neopixel-ring-mit-arduino-ansteuern-so-wirds-gemacht/

<br> Beispiel:



```
#include <Adafruit_NeoPixel.h>

#define PIN            10
#define NUMPIXELS      4

Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
long red_color;

void setup() {
  led.begin();
}

void loop() {
    
    // Rote Farbe
    red_color = led.Color(250,0,0);
    // LED 0 rot leuchten lassen
    led.setPixelColor(0, red_color);
    led.show();
}
```

