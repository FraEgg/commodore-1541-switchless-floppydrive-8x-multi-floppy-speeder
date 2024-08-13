# Switchless Floppydrive 8x Multi Floppy Speeder für das Commodore 1541 Diskettenlaufwerk

Here is an English version [> translation <](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/README_EN.md)!

![1541 8x Multi-Floppy-Speeder PCB Prototype](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_proto.jpg?raw=true)

## Allgemeines

Dies ist mein Switchless 8x ROM Multi Floppy Speeder Projekt. Es ist die Weiterentwicklung meiner Version 1.7. Diese Platine erweitert das Commodore 1541 Diskettenlaufwerk um 32 KB SRAM und bietet mit seinem 512 KB Eprom ausreichend Platz für bis zu 8 beliebige Kernals/Speeder. Die Kernals lassen sich switchless (schalterlos) mit "DOS"-Befehlen vom Rechner umschalten. Das ist auch die wesentliche Weiterentwicklung. Für das Umschalten habe ich einen Mikrocontroller verbaut, der den Datenbus auf Kommandos zum Wechseln der Kernals überwacht. Dazu habe ich die Idee von RetroNynjah [1541-Switchless-Multi-ROM](https://github.com/RetroNynjah/1541-Switchless-Multi-ROM) übernommen und auf meinen 8x ROM Multi Floppy Speeder integriert.

Mein 8x ROM Multi Floppy Speeder ist kompatibel mit DolphinDos 2, SpeedDos Expert, SpeedDos+, Jiffy-DOS, S-Jiffy und dem originalen CBMDOS 2.6. Durch die 32 KB zusätzlichen SRAM kann es auch als RAMBoard für spezielle Nibble-Kopierprogramme verwendet werden. Für Speeder mit paralleler Übertragung ist ein zusätzliches Parallel-Kabel, z.B. zum Userport, notwendig. Ich betreibe meine Speeder mit einem SpeedDos-kompatiblen Parallel-Kabel.

Ein Kernal-Umschalter für den Rechner ist nicht Bestandteil dieses Projektes. In diesem Fall kann jeder C64/C128 Kernal-Switcher verwendet werden. Empfehlen kann ich hierzu auch die passenden Projekte von RetroNynjah unter https://github.com/RetroNynjah.

## Installation
![1541 PCB Setup](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_PCB_Setup_Proto.jpg?raw=true)

Der Switchless 8x ROM Multi Floppy Speeder wird in der 1541 in den CPU-Sockel zwischen Platine und 6502 CPU platziert (1541 I Sockel UC5 und 1541 II Sockel U3).

Die originalen Kernal-ROMs müssen beim Betrieb des Switchless 8x ROM Multi Floppy Speeder entfernt werden (1541 I UB3 u. UB4 / 1541 II U4). Die 1541 II hat nur ein Kernal-ROM (U4). Die neue Platine kommt sonst beim Einblenden der neuen ROMs in Konflikt mit den originalen ROMs, und das Diskettenlaufwerk würde beim Einschalten nicht korrekt starten.

## Bedienung
Nachdem der Switchless 8x ROM Multi Floppy Speeder installiert ist, sollte beim ersten Start das Diskettenlaufwerk in der ROM-Bank 1 starten. In meinem Fall ist das das originale CBMDOS.

### ROM-Bank Beispiel:
| ROM Bank | Kernal | Hinweis |
| -------- | -------- | -------- |
| 1 | CBMDOS 2.6 | IEC only |
| 2 | DolphinDos 2.0 | Parallel + RAM |
| 3 | SpeedDos+40T | Parallel |
| 4 | JiffyDos 5.0 | IEC only |
| 5 | S-JiffyDos | IEC only |
| 6 | CBMDOS 2.6 | Placeholder |
| 7 | CBMDOS 2.6 | Placeholder |
| 8 | SpeedDos Expert | Parallel + RAM |

### Wechsel der ROM-Bank / des Kernals / Speeder

Der Wechsel der Speeder kann am Computer durch einen LOAD-Befehl oder einen DOS-Befehl ausgelöst werden. Hier ein paar Beispiele:

1.
> LOAD"2@RNROM",8,1

Das Diskettenlaufwerk versucht, die Datei mit dem Namen "2@RNROM" zu laden, und antwortet mit einer "FILE NOT FOUND" Fehlermeldung. Jedoch erkennt der Mikrocontroller die Anweisung "2@RNROM" und wechselt auf die ROM-Bank 2. Die LED am PCB blinkt dann zweimal, und das Diskettenlaufwerk führt einen Reset durch, um das neue Kernel-ROM korrekt zu starten. Danach ist der entsprechende Speeder "Dolphin Dos 2.0" funktionsfähig. Achte darauf, dass du auch auf deinem Rechner das entsprechende passende Kernal-ROM aktivierst.

2.
> OPEN 1,8,15,"I:3@RNROM":CLOSE 1

Das Laufwerk führt den Befehl "I" aus und initialisiert sich neu. Der Mikrocontroller erkennt den Befehl "3@RNROM" und wechselt zur ROM-Bank 3. Die LED blinkt dreimal und das Diskettenlaufwerk führt einen Reset aus. Danach ist der Speeder "SpeedDos+40T" aktiv.

3.
> @I:5@RNROM

Einige Rechner-Kernals ermöglichen das einfache Senden von Diskettenkommandos via @-Befehl (DolphinDos, SpeedDos, Jiffy-DOS). Damit ist der Wechsel besonders komfortabel. Bei diesem Beispiel führt das Laufwerk den Befehl "I" aus und initialisiert sich. Der Mikrocontroller erkennt den "5@RNROM" Befehl und wechselt zu ROM-Bank 5 "S-JiffyDos 1". Die PCB-LED blinkt 5 Mal, und das Laufwerk führt einen Reset aus, um den Speeder korrekt zu aktivieren.

![Screenshot Bankswitching](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_screenshot_bankswitching.jpg?raw=true)

## Anschlüsse
![PCB Connectors](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_render_JP-SW.jpg?raw=true)

Der Switchless 8x ROM Multi Floppy Speeder verfügt über mehrere Anschlüsse (J4/J5), einen Taster (SW1) und eine LED (D1). Der SW1 ist immer auf der Platine verlötet. Der J5 RST-/SELROM und J4 SPI sind optional und nicht mit Bauteilen bestückt. Das hat den Vorteil, dass der Nutzer selbst entscheiden kann, ob er diese mit Kabeln oder PIN-Headern versieht und nutzt. Zudem können zu hohe PIN-Header auch störend beim Einbau der PCB in eine 1541 II sein, da darüber die Mechanik des Laufwerks platziert ist und diese dann die Mechanik stören kann.

### SW1 (Reset)
Dieser Taster führt einen reinen Reset aus. Zuerst führt der Mikrocontroller des Switchless 8x ROM Multi Floppy Speeder einen Neustart durch, und dann bekommt das Diskettenlaufwerk einen Reset. Es ist mit einem Power-ON des Laufwerks zu vergleichen. Die ausgewählte ROM-BANK wird nicht zurückgesetzt. Der Mikrocontroller merkt sich das zuletzt verwendete ROM auch nach einem Reset oder Power OFF/ON.

### J5 (RST-/SELROM)
Dieser Anschluss ist optional. Die Belegung ist 1 = SELROM, 2 = GND/MASSE, 3 = RSTROM. Wird SELROM z.B. mit einem Taster kurz auf GND/MASSE gelegt, dann wird auf die nächste ROM-Bank (+1) umgeschaltet. Wird RSTROM kurz auf GND/MASSE gelegt, dann wird der ROM-Zähler auf 1 gesetzt. Das ermöglicht, die ROM-Bank zurückzusetzen, wenn mal eine ROM-Bank nicht belegt ist. Sollte das der Fall sein, dann stürzt die CPU des Diskettenlaufwerks ab und der ROM-Wechsel über den Rechner ist nicht mehr möglich. Mit RSTROM wird immer die ROM-Bank 1 aktiviert und ein Laufwerks-Reset durchgeführt. Deshalb sollte die ROM-Bank 1 immer mit einem funktionierenden Kernal-System versehen sein. Ich platziere dort immer das originale CBMDOS.

### J4 (SPI)
Mit dem Serial Peripheral Interface (SPI) kann über einen ASP-Programmer die Firmware des ATMEGA328 Mikrocontrollers aktualisiert werden. Hierzu bitte vor dem Programmieren immer die Platine aus dem Sockel des Laufwerks nehmen und die CPU 6502 aus dem Sockel entfernen!

### LED (D1)
Die LED blinkt, wenn zu einer anderen ROM-Bank geschaltet wird. Wenn ROM-Bank 1 aktiviert ist, dann blinkt die LED einmal, ROM-Bank 2 blinkt zweimal usw. Danach führt das Diskettenlaufwerk einen Reset durch, damit das richtige ROM korrekt startet.

## ROM-RAM Memorymap V2.2

| ROM-Bank | ROM-Bereich | CPU-RAM-Bereich(e) | Kernal | Command |
| -------- | -------------- | ------------------ | ----------- | ------- |
| 0        | $00000-$0FFFF | $6000 - $9FFF 32 KB | CBMDOS 2.6  | 1@RNROM |
| 1        | $10000-$1FFFF | $6000 - $9FFF 32 KB | DolphinDos 2.0 | 2@RNROM |
| 2        | $20000-$2FFFF | $6000 - $9FFF 32 KB | SpeedDos+40T | 3@RNROM |
| 3        | $30000-$3FFFF | $6000 - $9FFF 32 KB | JiffyDos 5.0 | 4@RNROM |
| 4        | $40000-$4FFFF | $6000 - $7FFF 08 KB | S-JiffyDos 1 | 5@RNROM |
| 5        | $50000-$5FFFF | $6000 - $7FFF 08 KB | CBMDOS 2.6 (Placeholder) | 6@RNROM |
| 6        | $60000-$6FFFF | $4000 - $7FFF 16 KB<br>$A000 - $BFFF 08 KB | CBMDOS 2.6 (Placeholder) | 7@RNROM |
| 7        | $70000-$7FFFF | $4000 - $7FFF 16 KB<br>$A000 - $BFFF 08 KB | SpeedDos 2.7 Expert | 8@RNROM |

## EPROM / Kernals
Die DOS-KERNALs werden in einem EPROM abgelegt. Das EPROM, z.B. 27C040/29F040, ist ein 512 KB EPROM. Es wird in 8x 64 KB Bänke (Bank 0-7) aufgeteilt. Jede Bank $x0000 - $xFFFF spiegelt den 64 KB Speicherbereich der Floppy 1:1 wider. Das ROM wird grundsätzlich ab dem Speicherbereich $2000 - $FFFF in den CPU-Adressenbereich eingefügt. Überlagert wird der ROM-Bereich nur durch die RAM-Bereiche (siehe Tabelle RAM-ROM Memorymap).

Beim Betrieb der Multi-Speeder-Platine müssen alle originalen ROM-Bausteine (ICs) der 1541 entfernt bzw. deaktiviert werden (CS/CE/OE auf Dauer-High), da diese sich sonst mit dem ROM des Multi-Speeder im Adressenkonflikt befinden. Die Folge wäre ein Absturz der Floppy direkt beim Einschalten.

## RAM
Ebenso wie das ROM wird das 32 KB RAM auch in verschiedenen Bereichen der 1541 eingeblendet. Wo das RAM eingeblendet wird, ist von der Bank abhängig, die gerade aktiv ist.

### Welche RAM-Bereiche werden wann eingeblendet?
> BANK 0-3 $6000 - $9FFF (32 KB)<br>
> BANK 4-5 $6000 - $7FFF (08 KB)<br>
> BANK 6-7 $A000 - $BFFF (08 KB)<br>
> Die RAM-Bereiche überlagern immer den ROM-Adressenraum.

## EPROMs / EEPROMs
Es gibt mehrere Varianten, die verwendet werden können. Getestet habe ich diverse 27C040 Eproms oder ein Flash-EPROM 29F040. Es muss darauf geachtet werden, dass der jeweilige Jumper JP2 oder JP3 gesetzt wird! Ansonsten funktioniert das Umschalten der Bänke nicht korrekt, da sich das PIN-Layout dieser EPROM-Typen leicht unterscheidet (PIN 1/PIN 32).

## 1541 Adressendecoder-Spiegel-Problematik
Bei der 1541 hat Commodore am Adressdecoder gespart. Die VIAs 6522 belegen die Speicherbereiche $1800-$18FF und $1C00-$1CFF und werden dann bis zur Adresse $8000 immer wieder gespiegelt. Das kollidiert mit der RAM-Erweiterung. Das Problem habe ich behoben, indem ich die Adressleitung A15 über die Platine entsprechend auf dem Motherboard anpasse. Das stoppt das Spiegel-Problem für das RAM. Somit kollidiert ab der Adresse $2000 in der 1541 nichts mehr. 

## WDC 65C02 CPU und andere CPUs
Es kann auch eine modernere WDC W65C02 CPU verwendet werden. Hierzu muss jedoch der optionale Widerstand R1 mit 3,3K und der JP1 geöffnet werden! Jedoch wird die 1541 dadurch nicht sehr kompatibel. Das originale CBM-DOS läuft, aber die meisten Floppyspeeder nutzen auch illegale OP-Codes der originalen alten MOS 6502A CPU. Diese kennt die neuere WDC W65C02 CPU nicht. Die Folge ist, dass viele Schnelllader, die illegale OP-Codes verwenden, nicht funktionieren. Deshalb suche ich noch eine FPGA-Emulation, die man für meinen Multi-Speeder anstelle einer originalen MOS 6502A CPU verwenden kann. Rockwell 6502 CPUs und die von UMC sowie SY6502A funktionieren problemlos. 

## Bauteile / BOM
Die Elektronik besteht aus folgenden Bauteilen:

- 2x Pin Header 2,54 Straight 1 x 20 (BKL10120536) (Connector to 1541 Mainboard)
- 1x IC Socket DIP40 2,54 mm Pin Connector Socket (U1) (CPU 6502 / UC5 / U3)
- 2x IC Socket DIP20 2,54 mm Pin Connector Socket (U3/U5) (74HCT273N / Atmel F16V8 BQL-15PV)
- 1x IC Socket PLCC32 DIP PLCC IC socket adapter (EEPROM/EPROM)
- 1x IC Atmel F16V8 BQL-15SU (U5) (GAL/PAL) (U5)
- 1x IC 74HCT273D Octal D-type flip-flop with reset; positive-edge trigger (U3) 
- 1x IC SRAM ISSI 62C256AL-45ULI 28-PIN SOP (U6)
- 1x IC ATmega328PB 8-Bit-ATMega AVR Microcontroller, 32 KB, 20 MHz, TQFP-32 (U4)
- 1x DIP Crystal Oscillator 16 MHz HC-49 (Y1)
- 1x EPROM-OTP AT27C040-70JU PLCC32 / AM27C040-120JC PLCC32 oder EEPROM 29F040 (PLCC32) (U2)
- 4x Tantalum Capacitor 16V 100nF radial DIP (C1, C2, C5, C6)
- 2x Tantalum Capacitor 16V 22pF radial DIP (C3, C4)
- 1x Resistor 560R THT Axial L 3,6 mm D 1,6 mm P 5,08 mm Horizontal (R3)
- 3x Resistor 10K THT Axial L 3,6 mm D 1,6 mm P 5,08 mm Horizontal (R2, R4, R5) 
- 1x LED Diode THT 3,0 mm
- 1x Tactile Tact Push Button Switch DIP 4Pin 6*6*4,3 mm Micro Switch Self-reset DIP Key Switches (JTP-1130) (SW1)
 
Optional:
- 1x Connector Pin Header 2x03 Pol P 2,00 mm Vertical (BKL10120739) (SPI) (J4)
- 1x Connector Pin Header 1x03 Pol P 2,00 mm Vertical (BKL10120728) (RST-/SELROM) (J5)
- 1x Resistor 3,3K THT Axial L 3,6 mm D 1,6 mm P 5,08 mm Horizontal (only WDC65C02 CPU) (R1)

## Spenden
Wer meine Arbeit unterstützen möchte, der kann mir gerne eine Spende über Paypal senden.
[> Spenden <](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=Q8HXKYARXKT4L&ssrt=1714757590172)

## Haftungsausschluss
Ich gebe mir sehr viel Mühe und lege Wert auf Sorgfalt. Aber ich kann natürlich keine Fehler ausschließen. Das ist ein Hobbyprojekt, und ich übernehme deshalb auch keine Garantie für die Funktion oder Folgen, die ein Umbau/Einbau in deine Geräte mit meinen Projekten haben kann. Auch für mögliche Folgeschäden bei beschriebener korrekter Nutzung meiner Platine übernehme ich keinerlei Garantie oder Haftung.

## Danke
Ich möchte mich bei allen bedanken, die mich bei diesem Projekt unterstützt haben. Nicht nur den Spendern, sondern auch den Nutzern, die mir hilfreiche Tipps oder Hinweise für Verbesserungen gegeben haben.

Speziell möchte ich mich bei RetroNynjah für seine Idee mit dem switchless ROM/Banking bedanken. Diese Funktion habe ich mit leichten Anpassungen übernommen. Seine tollen Projekte findest du hier: [https://github.com/RetroNynjah/](https://github.com/RetroNynjah/)

## Viel Spaß
Ich wünsche euch viel Spaß mit diesem Projekt.

Viele Grüße  
Frank Eggen
