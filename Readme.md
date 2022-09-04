# Ampelkreuzung - Arduino-Guide

## 0. Grundlagen

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

### LED leuchten lassen:


```
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
}
```




___

## 1. Autoampel

Mache dich vertraut mit dem Ablauf einer Ampel.
Unsere Ampel soll zu Beginn rot sein.

Rot -> Gelb -> ... -> Rot

Denke an die Zeiten, wie lange eine Ampelphase gehen soll!!

Bevor wir etwas Programmieren können, muss zunächst der Schaltkreis aufgebaut werden. 
Schließe dazu den Minus-Pol der LED an den Minuspol des Arduino an (GND). Und den Plus Pol an den Plus Pol des Arduinos (5V).
Verbinde nun den Datenport mit **Port 10** des Arduinos

Programmierung:

```
#include <Adafruit_NeoPixel.h>

#define PIN            10
#define NUMPIXELS      4

Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
    
    // Rote Farbe
    red_color = led.Color(250,0,0);
    // LED 0 rot leuchten lassen
    led.setPixelColor(0, red_color);
    led.show();
}
```

## 2. Hall-Sensor

Der Hallsensor erkennt Magneten. Beispiel:

```
bool mag_da = LOW;

void setup() {
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, HIGH);
  boolean Sensor  = digitalRead(8);
  if(!Sensor && !mag_da){
    Serial.println("Magnet da");
    mag_da = HIGH;
  }
  if(Sensor && mag_da){
    Serial.println("Magnet weg");
    mag_da = LOW;
  }

}
```


## 3. Taster

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
## 4. Ampelsteuerung
Dazu  Ampelstatus definieren. (Was passiert bei jeweiligem Status und was kann dabi passieren)
- 0: Ampel grün; Fußgänger rot; Überprüfe: Fußgänger drückt Knopf
- 1: Ampel gelb; Fußgänger rot;
- 2: Ampel rot; Fußgänger rot;
- 3: Ampel rot; Fußgänger grün;
Überprüfe ob Auto Hallsensor triggert
- 4: Ampel rot; Fußgänger rot;
- 5: Ampel gelb; Fußgänger rot;
- danach wieder Status 0 

