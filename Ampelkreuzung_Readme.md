# Ampelkreuzung - Arduino-Guide

TODO:
- state machine?? -> ans ende als bonus!!
- auto taster (hall sensor)
- fußgänger

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


___

## 1. Autoampel

Mache dich vertraut mit dem Ablauf einer Ampel.
Unsere Ampel soll zu Beginn rot sein.

Rot -> Gelb -> ... -> Rot

Denke an die Zeiten, wie lange eine Ampelphase gehen soll!!

Bevor wir etwas Programmieren können, muss zunächst der Schaltkreis aufgebaut werden. 
Schließe dazu den Minus-Pol der LED an den Minuspol des Arduino an (GND). Und den Plus Pol an den Plus Pol des Arduinos (5V).
Verbinde nun den Datenport mit **Port 8** des Arduinos

Programmierung:

```

```


