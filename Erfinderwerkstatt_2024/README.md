# Erfinderwerkstatt 2024

Hier findet ihr eure Programme aus der Erfinderwerkstatt


## 0. Grundlagen

### Programmaufbau:
Ein Arduinoprogramm besteht aus einem Header und einem Loop Teil.
Hierbei wird der Loop Teil sehr schnell wiederholt solange der Arduino läuft.

```
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

```

### Erstes Programm (Hello World)

Wir lassen die eingebaute LED auf dem ESP blinken

```
void setup() {
  pinMode(2, OUTPUT);

}

void loop() {
  digitalWrite(2, HIGH);
  delay(500);

}
```
Blinkt die LED? Wenn nicht warum blinkt sie nicht? Ändere den Code, dass die Blink
<br> (TIPP: um die LED Auszuschalten verwende "LOW")


Besserer Programmierstil:
```
#define LED_PIN  2

void setup() {
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);

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

### Schleifen

Eine Schleife hilft dabei wiederholende Abläufe zu programmieren.


```
for (int i=0; i < 10; i++){
    Serial.println(i);
}
```
 ### Übung:
Erzeuge folgende Ausgabe in der Console:

```
0
2
4
6
8
10
12
14
18
20
0
2
...
```
Tipp: Das Multiplizierzeichen ist folgendes: *


Etwas schwieriger

 Erzeuge folgende Ausgabe in der Console:
 (Die letze Reihe enthält 100 #)

 ```
 #
 ##
 ###
 ####
 #####
 ######
 #######
 ...
 ##################################################################################################
 #
 ##
 ###
 ...
 ```



## RGB - LED


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
Erklärung der wichtigsten Teile des Codes

    #include <Adafruit_NeoPixel.h>: Damit holen wir uns die NeoPixel-Bibliothek. Diese Bibliothek hilft uns, die RGB-LED-Streifen einfach zu steuern.

    #define PIN 10: Wir sagen dem Arduino, an welchem Pin das LED-Kabel angeschlossen ist. In diesem Fall verwenden wir den Pin 10.

    #define NUMPIXELS 4: Hier legen wir fest, wie viele LEDs wir verwenden möchten. In unserem Fall sind es 4 LEDs. Ändere die Zahl, wenn du mehr oder weniger LEDs hast!

Was passiert in der setup()-Funktion?

    led.begin();: Damit startet die LED und wir bereiten sie darauf vor, Farben anzuzeigen.

Was passiert in der loop()-Funktion?

Hier beginnt der Hauptteil des Codes – die loop()-Funktion läuft immer wieder und sorgt dafür, dass die LED dauerhaft in einer Farbe leuchtet, solange der Arduino an ist.

    Farbe festlegen
    red_color = led.Color(250,0,0);
    Hier sagen wir der LED, in welcher Farbe sie leuchten soll. Die Zahlen stehen für die RGB-Farben:
        Rot (die erste Zahl)
        Grün (die zweite Zahl)
        Blau (die dritte Zahl)

    Die Werte können von 0 bis 255 gehen – je höher der Wert, desto stärker leuchtet die Farbe. Hier ist die LED zum Beispiel rot.

    Farbe anwenden
    led.setPixelColor(0, red_color);
    Damit stellen wir ein, dass die erste LED (Nummer 0) in der Farbe leuchtet, die wir gewählt haben.

    Farbe anzeigen
    led.show();
    Mit led.show(); zeigen wir die Farbe auf der LED an.

So änderst du die Farben 🎨

Du kannst die Farbe der LED ändern, indem du die Zahlen im led.Color()-Teil anpasst. Hier sind ein paar Beispiele:

    Grün: led.Color(0,250,0);
    Blau: led.Color(0,0,250);
    Gelb: led.Color(250,250,0);
    Violett: led.Color(250,0,250);

Tipp: Andere Farben ausprobieren

Schau dir diese Seite an, um weitere Farbwerte zu finden und sie auszuprobieren: htmlcolorcodes.com



### Verwendung von Schleifen mit den LEDs

```
#include <Adafruit_NeoPixel.h>

#define PIN            10
#define NUMPIXELS      4  // Anzahl der LEDs

Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
long red_color;

void setup() {
  led.begin();
}

void loop() {
  // Farbe festlegen: Rot
  red_color = led.Color(250, 0, 0);

  // 1. Schritt: Alle LEDs nacheinander einschalten
  for (int i = 0; i < NUMPIXELS; i++) {  // Schleife läuft von LED 0 bis NUMPIXELS-1
    led.setPixelColor(i, red_color);  // LED an Position i auf Rot setzen
    led.show();  // Die Farbe wird angezeigt
    delay(500);  // Halbe Sekunde warten, bevor zur nächsten LED gewechselt wird
  }

  // 2. Schritt: Alle LEDs nacheinander ausschalten
  for (int i = 0; i < NUMPIXELS; i++) {
    led.setPixelColor(i, led.Color(0, 0, 0));  // LED an Position i ausschalten
    led.show();  // Die Farbe wird angezeigt
    delay(500);  // Halbe Sekunde warten, bevor zur nächsten LED gewechselt wird
  }
}
```

Erklärung des Codes:

    Farbe einstellen: red_color = led.Color(250, 0, 0);
    Hier wird die Farbe auf Rot gesetzt.

    Einschalten-Schleife: for (int i = 0; i < NUMPIXELS; i++)
    Die Schleife startet mit i = 0 und läuft bis zur Anzahl der LEDs (NUMPIXELS). In jedem Durchlauf wird die nächste LED eingeschaltet:
        led.setPixelColor(i, red_color); stellt die LED in Position i auf Rot.
        led.show(); zeigt die eingestellte Farbe an.
        delay(500); sorgt dafür, dass nach jeder LED eine halbe Sekunde gewartet wird.

    Ausschalten-Schleife: for (int i = 0; i < NUMPIXELS; i++)
    Diese Schleife funktioniert genauso wie die erste, schaltet aber die LEDs aus, indem sie die Farbe auf Schwarz (led.Color(0, 0, 0)) setzt.

Tipp: Ändere die Farbe und Geschwindigkeit! ✨

Du kannst den Farbwert red_color anpassen, um eine andere Farbe auszuprobieren. Ändere den delay(500);-Wert, um die Geschwindigkeit zu erhöhen oder zu verringern.

### Beispiel für Random (zufällige) Farben

``` 
// Jede LED erhält eine zufällige Farbe
  for (int i = 0; i < NUMPIXELS; i++) {
    int red = random(0, 256);   // Zufälliger Rot-Wert zwischen 0 und 255
    int green = random(0, 256); // Zufälliger Grün-Wert zwischen 0 und 255
    int blue = random(0, 256);  // Zufälliger Blau-Wert zwischen 0 und 255

    led.setPixelColor(i, led.Color(red, green, blue));  // Zufällige Farbe setzen
  }

  led.show();  // Farben anzeigen
  delay(500);  // Halbe Sekunde warten, bevor die Farben neu generiert werden`
  ```
- random(0, 256); : Erzeugt eine Zufallszahl zwischen 0 und 255 für Rot, Grün und Blau.
- Schleife: Jeder LED wird eine zufällige Farbe zugewiesen, und die Farben ändern sich nach jeder halben Sekunde.


## 3. Taster

--- Für Profis ---

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
Der Taster kann ein Wahr (HIGH) und Falsch (LOW)  Signal erzeugen. (gedrückt und nicht gedrückt)
Um den Status "dedrückt zu speichern, wir die Variable pressed verwendet.
Andernfalls müsst eman den Taster ständig gedrückt halten um im Status pressed zu bleiben.

```
bool pressed = LOW;
boolean Taster = LOW;

void setup() {
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  Taster  = digitalRead(8);
  if(Taster && !pressed){
    Serial.println("Taster gedrückt");
    pressed = HIGH;
  }
  if(!Taster && pressed){
    Serial.println("Taster nicht gedrückt");
    pressed = LOW;
  }

}

```


### Switch-Case:

Stelle dir vor du öffnest den Müslischrank morgens und hast mehrere Müslis zu Auswahl. Greifst aber nur eines. Diese Auswahl kann man in der Programmierung mit Switch-Case Anweisungen realisieren. Diese sehen gefolgt aus:

```

void setup() {
  

}

void loop() {

    switch (var) {
  case label1:
    // Statement(s)
    break;
  case label2:
    // Statement(s)
    break;
  default:
    // Statement(s)
    break; // Wird nicht benötigt, wenn Statement(s) vorhanden sind
}
  

}

```

Auch ein Taster kann genutzt werden um von einem case in den nächsten zu springen.
So können verschiedene Modi erstellt werden.

```
...

void loop() {

    switch (num) {
  case 1:
    // Statement(s)
    if (taster){
      num = num + 1;
    }
    break;
  case 2:
    // Statement(s)
    if (taster){
      num = 1;
    }
    break;
}
  

}

```