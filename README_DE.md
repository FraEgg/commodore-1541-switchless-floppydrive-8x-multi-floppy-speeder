<img title="The Multi-Speeder Logo" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/Multi-Speeder_Logo.png?raw=true" alt="Multi-Speeder Logo" style="zoom:25%;" data-align="center">

# Switchless Floppy Drive 8x Multi Floppy Speeder für das Commodore 1541 Diskettenlaufwerk (V2.2c)

Hier ist eine englische Version [> Übersetzung <](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/README.md)!

<img title="Commodore 1541-II Diskettenlaufwerk mit 8x Multi-Speeder 32KB RAM-Erweiterung (RAMBoard)" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/1541_II_install_PCB.jpg?raw=true" alt="Commodore 1541-II Diskettenlaufwerk mit 8x Multi-Speeder 32KB RAM-Erweiterung (RAMBoard)" data-align="center" style="zoom:80%;">

## Beschreibung

Dieses Projekt ist eine Weiterentwicklung des [8x ROM Multi Floppy Speeders V1.7](https://github.com/FraEgg/commodore-1541-floppydrive-8x-multi-floppy-speeder). Die Platine erweitert das Commodore 1541 Diskettenlaufwerk um 32 KB SRAM (RAMBoard-kompatibel) und vereint 8x 64KB ROM-Bänke für verschiedene DOS-Systeme (Speeder) in einem 512KB ROM. Die DOS-Kernals lassen sich in dieser Version 2.2c **"switchless"** ohne Schalter über DOS-Befehle vom Computer umschalten. Es sind keine Löcher oder Schalter mehr im Gehäuse notwendig, um die DOS-/Speeder-Systeme zu wechseln.



Den Switchless 8x Multi-Speeder 32KB RAM gibt es in zwei Varianten. Beide Varianten sind technisch identisch, unterscheiden sich jedoch in der Bauform und sind für die unterschiedlichen 1541-Modelle optimiert.



1. **Through Hole Technology (THT)**: Diese Variante ist bis auf das 32 KB SRAM in THT-Bauweise gestaltet und lässt sich leichter selbst zusammenbauen. Sie ist ideal für die Entwicklung und die Nutzung in den älteren 1541-I-Diskettenlaufwerk-Modellen. Hier können alle ICs gesockelt werden.
   
   

2. **Surface Mount Devices (SMD)**: Bei dieser Variante sind alle ICs als SMD-Version verbaut. Dies ermöglicht den Betrieb des 8x Multi-Speeder 32KB RAM auch in einem neueren 1541-II-Modell. Der 8x Multi-Speeder 32KB RAM passt dann zwischen Platine und Laufwerksmechanik, wenn die CPU nicht gesockelt, sondern direkt verlötet wird. Die SMD-Version passt sowohl in die 1541-I als auch in die 1541-II.
   
   

Beide Varianten des 8x Multi-Speeder 32KB RAM können als PCB bei PCBWay.com bestellt werden, ebenso die Platinen für das Parallelkabel.



Ein Kernal-Switcher für den C64/C128 ist **nicht** Bestandteil dieses Projekts. Hierzu gibt es viele tolle Lösungen von anderen Retro-Entwicklern oder Shops. Ich verwende für die C64-Kernals mein [Ultimate-II+ Cartridge](https://ultimate64.com/Main_products) oder gerne den Universal-Kernal-Switcher von [FaszinationC64](https://www.faszinationc64.de/Universal-EPROM-Adapter).



### Hauptfunktionen:

- **8x 64KB ROM-Bänke**: Für verschiedene DOS-Systeme und Speeder (z. B. DolphinDos, SpeedDos, JiffyDOS ...)
- **Schalterloses Umschalten**: Die DOS-Kernals können direkt über DOS-Befehle am Rechner umgeschaltet werden.
- **Kompatibilität**: Unterstützt DolphinDos 2, SpeedDos Expert, SpeedDos+, JiffyDOS, S-Jiffy und das originale CBMDOS 2.6.
- **RAM-Erweiterung**: Durch das zusätzliche 32 KB SRAM kann die Platine auch als RAMBoard für spezielle Nibble-Kopierprogramme verwendet werden.
  
  

## Installation

![8x Multi-Floppy-Speeder 32KB in einem älteren 1541-I Diskettenlaufwerk](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/1541_I_SMD_install_PCB.jpg?raw=true "8x Multi-Floppy-Speeder 32KB in einem älteren 1541-I Diskettenlaufwerk")

Der Switchless 8x ROM Multi-Speeder wird zwischen die Platine und die 6502-CPU im CPU-Sockel der 1541 eingesetzt (1541 I: Sockel UC4, 1541 II: Sockel U3).



**Vor der Installation müssen die originalen Kernal-ROMs (1541-I: UB3/UB4, 1541-II: U4) entfernt werden, da es sonst Konflikte mit den DOS-ROMs gibt und das Diskettenlaufwerk nicht mehr korrekt startet.**



Hier habe ich eine Fotogalerie mit Schritten für den Zusammenbau des 8x Multi-Speeder 32KB: [/image/setup/README.md](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/README.md).



## Bedienung

### Erste Schritte

Nach der Installation sollte das Diskettenlaufwerk beim ersten Start automatisch in der ersten ROM-Bank mit "CBMDOS 2.6" starten.



### ROM-Banken Übersicht

| ROM-Bank | Kernal           | Hinweis        |
| -------- | ---------------- | -------------- |
| 1        | CBMDOS 2.6       | IEC only       |
| 2        | DolphinDos 2.0   | Parallel + RAM |
| 3        | SpeedDos+40T+GCR | Parallel       |
| 4        | JiffyDOS 5.0 *)  | IEC only       |
| 5        | S-JiffyDOS *)    | IEC only       |
| 6        | RapiDOS Classic  | Parallel       |
| 7        | CBMDOS 2.6       | Placeholder    |
| 8        | SpeedDos Expert  | Parallel + RAM |

Das DOS-512KB-EPROM (27C040/29F040) für den Switchless 8x Multi-Speeder 32KB kann hier [/rom/1541](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/rom/1541) heruntergeladen werden. Die Bänke 4 und 5 sind für JiffyDOS und S-JiffyDOS reserviert und befinden sich aus Copyright-Gründen nicht in der ROM-Datei. JiffyDOS kann im [Restore-Store](https://restore-store.de/89-jiffydos) käuflich erworben werden.

*) Mit CBMDOS 2.6 als Platzhalter belegt.



### C64-Kernals

Meine Test-Kernals für den Commodore C64 befinden sich hier [/rom/C64](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/rom/C64).



### Wechseln der ROM-Bank

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_screenshot_bankswitching.jpg?raw=true" title="Screenshot: Wechsel der ROM-Bank" alt="Screenshot: Wechsel der ROM-Bank" style="zoom:80%;">

Der Wechsel der Speeder kann am Computer durch einfache Befehle ausgelöst werden.

#### Beispiele:

1. **Wechsel zu Bank 2 (DolphinDos 2.0):**
   
   ```plaintext
   LOAD"2@RNROM",8,1
   ```
   
   Das Laufwerk versucht, die Datei "2@RNROM" zu laden. Der 8x Multi-Speeder erkennt den String "2@RNROM", wechselt das DOS-ROM (Bank 2 DolphinDos 2) im 1541-Diskettenlaufwerk und führt einen Reset des Laufwerks durch. Wechseln Sie im C64 auf das korrekte Kernal, und DolphinDos 2 kann genutzt werden.

2. **Wechsel zu Bank 3 (SpeedDos+40T+GCR):**
   
   ```plaintext
   OPEN 1,8,15,"I:3@RNROM":CLOSE 1
   ```
   
   Der Mikrocontroller wechselt zu Bank 3, die LED blinkt dreimal, und das Laufwerk startet neu.

3. **Wechsel zu Bank 5 (S-JiffyDOS):**
   
   ```plaintext
   @I:5@RNROM
   ```
   
   Der Mikrocontroller erkennt den Befehl und wechselt zu Bank 5. Die LED blinkt fünfmal, und das Laufwerk startet neu.

4. **Temporäre Deaktivierung des Switchless-Modus:**
   
   ```plaintext
   @I:0@RNROM
   ```
   
   Dieser Befehl erhöht die Kompatibilität des 8x Multi-Speeders. Der Multi-Speeder reagiert auf keine "x@RNROM"-Befehle mehr. Das DOS-Kernal kann nicht mehr gewechselt werden. Um die Switchless-Umschaltung wieder zu aktivieren, muss das Diskettenlaufwerk komplett aus- und wieder eingeschaltet werden, oder der Reset-Taster des 8x Multi-Speeders wird gedrückt. Die Deaktivierung ist hilfreich, wenn der Speeder beim Laden eines Programms irrtümlich das DOS-ROM umschaltet und einen Reset durchführt.
   
   

## Anschlüsse und Komponenten

Der Switchless 8x ROM Multi Floppy Speeder verfügt über mehrere Anschlüsse, einen Taster (SW1) und eine LED (D1).

### Wichtige Anschlüsse:

#### THT-Variante 8x Multi-Speeder 32KB

<img title="THT-Version" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2c_PCB_BOM_1541_CPU_THT_Speeder_V2.png?raw=true" alt="THT-Version" data-align="inline" style="zoom:25%;">

* **J1 (W65C02 CPU) / R1**: Der Jumper ist standardmäßig für die originale MOS/CSG 6502 geschlossen. Für die Nutzung der neueren W65C02-CPU von WDC muss der Jumper geöffnet und der optionale Widerstand R1 mit 3,3 kOhm bestückt werden. Mit einer originalen MOS/CSG 6502-CPU muss R1 unbestückt bleiben.
* **J2 (SPI)**: Zum Aktualisieren der Firmware des Mikrocontrollers über einen ISP-Programmer.
* **J3**: Jumper für OTP-EPROM 27C040 (Close), **J4** (Open).
* **J4**: Jumper für Flash-EPROM 29F040 (Close), **J3** (Open).
* **J5 (RST-/SELROM)**: Optionaler Anschluss zum Umschalten der ROM-Bänke mit einem externen Taster.
* **SW1 (Reset)**: Führt einen Reset des Diskettenlaufwerks durch, ohne die aktuell ausgewählte ROM-Bank zurückzusetzen. Setzt die Deaktivierung des Switchless-Modus zurück.
* **LED (D1)**: Zeigt die aktive ROM-Bank durch Blinken an (1x für Bank 1, 2x für Bank 2 usw.).
  
  

#### SMD-Variante 8x Multi-Speeder 32KB

<img title="SMD-Version" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2c_PCB_BOM_1541_CPU_SMD_Speeder_V2.png?raw=true" alt="SMD-Version" style="zoom:25%;" data-align="inline">

- **J1 (W65C02 CPU) / R1**: Der Jumper ist standardmäßig für die originale MOS/CSG 6502 geschlossen. Für die Nutzung der neueren W65C02-CPU von WDC muss der Jumper geöffnet und der optionale Widerstand R1 mit 3,3 kOhm bestückt werden. Mit einer originalen MOS/CSG 6502-CPU muss R1 unbestückt bleiben.

- **J2 (SPI)**: Zum Aktualisieren der Firmware des Mikrocontrollers über einen ISP-Programmer.

- **J3**: Jumper für OTP-EPROM 27C040 (Close), **J5** (Open).

- **J5**: Jumper für Flash-EPROM 29F040 (Close), **J3** (Open).

- **J4 (RST-/SELROM)**: Optionaler Anschluss zum Umschalten der ROM-Bänke mit einem externen Taster.

- **SW1 (Reset)**: Führt einen Reset des Diskettenlaufwerks durch, ohne die aktuell ausgewählte ROM-Bank zurückzusetzen. Setzt die Deaktivierung des Switchless-Modus zurück.

- **LED (D1)**: Zeigt die aktive ROM-Bank durch Blinken an (1x für Bank 1, 2x für Bank 2 usw.).
  
  

## ROM-RAM Memorymap

| ROM Bank | ROM Area      | CPU RAM Area(s)     | Kernal                   | Command |
| -------- | ------------- | ------------------- | ------------------------ | ------- |
| 0        | $00000-$0FFFF | $2000 - $9FFF 32 KB | CBMDOS 2.6               | 1@RNROM |
| 1        | $10000-$1FFFF | $2000 - $9FFF 32 KB | DolphinDos 2.0           | 2@RNROM |
| 2        | $20000-$2FFFF | $2000 - $9FFF 32 KB | SpeedDos+40T+GCR         | 3@RNROM |
| 3        | $30000-$3FFFF | $2000 - $9FFF 32 KB | JiffyDOS 5.0             | 4@RNROM |
| 4        | $40000-$4FFFF | $2000 - $7FFF 24 KB | S-JiffyDOS 1             | 5@RNROM |
| 5        | $50000-$5FFFF | $2000 - $7FFF 24 KB | RapiDOS Classic          | 6@RNROM |
| 6        | $60000-$6FFFF | $A000 - $BFFF 08 KB | CBMDOS 2.6 (Placeholder) | 7@RNROM |
| 7        | $70000-$7FFFF | $A000 - $BFFF 08 KB | SpeedDos 2.7 Expert      | 8@RNROM |



### Speicherüberlagerung

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2c_Tabelle_ROM-RAM.png?raw=true" title="Tabelle ROM/RAM" alt="Tabelle ROM/RAM" style="zoom:80%;">

Ab $2000 wird das ROM in den Adressbereich der CPU eingeblendet und nur vom RAM gemäß der Tabelle überlagert.



## EPROMs / EEPROMs

Die DOS-KERNALs werden in einem EPROM zur Verfügung gestellt (z. B. 27C040/29F040 mit 512 KB). Dieses EPROM wird in 8x 64 KB-Bänke unterteilt. Beim Betrieb müssen alle originalen ROMs in der 1541 entfernt oder deaktiviert werden, um Adresskonflikte zu vermeiden.



## ATMega 328P

Der Atmel ATMega 328P-Mikrocontroller überwacht den Datenbus, steuert die ROM-Bänke und ist für den Wechsel der Betriebsmodi zuständig. Die Firmware kann über ein Arduino-Board oder einen AV-Programmer programmiert werden. Ich nutze den XGecu T48 Universal Programmer über eine .mpj-Projektdatei. Beim Programmieren mit dem XGecu und der .mpj-Datei bitte das EEPROM nicht mitprogrammieren, da es sonst zu einer Fehlermeldung kommt. Dieses kann man im Menü des XGecu deaktivieren. 

- [Link](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/atmega)

<img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/XGecuT48UniversalProgrammerEEPROM.png?raw=true" alt="" data-align="center" style="zoom:25%;">

<img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/XGecuT48UniversalProgrammerConfig.png?raw=true" alt="" style="zoom:25%;" data-align="center">

## 8x Multi-Speeder RAM Diagnose-Tool

![1541 8x Multi-Floppy-Speeder 32 KB RAM Diagnostic-Tool](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2b_pcb_diag_tool.jpg?raw=true)

Das Diagnose-Tool im Verzeichnis `/software/` hilft dabei, das 32K RAM des Multi-Floppy-Speeders zu testen. Es schreibt und liest die Speicherstellen mit $00- und $FF-Bytes, um Fehler zu erkennen. Der Test sollte immer mit Bank 0 (1@RNROM) mit dem originalen CBMDOS durchgeführt werden.

[Hier geht's zum Download.](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/software)



## Adressendecoder-Spiegel-Problematik

Die VIAs 6522 der 1541 belegen Speicherbereiche, die bis zur Adresse $8000 gespiegelt werden, was mit der RAM-Erweiterung kollidieren kann. Dieses Problem wird durch eine Anpassung der Adressleitung A15 auf dem Motherboard behoben.



## WDC 65C02 CPU und andere CPUs

Eine modernere WDC W65C02-CPU kann verwendet werden, allerdings verringert sich dadurch die Kompatibilität der 1541, da viele Schnelllader illegale OP-Codes der originalen MOS 6502A-CPU nutzen, die von der WDC W65C02 nicht unterstützt werden.



## Stückliste (BOM)

- Die Stücklisten sind in [/bom/](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/bom) abgelegt.
  
  

## Downloads

1. [ATF16V8 (GAL16V8) Dateien](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/logic)

2. [ATMEL ATMega328P Dateien](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/atmega)

3. [ROMs](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/rom)

4. [Gerber-Dateien zur Platinenherstellung](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/gerber)

5. [Schaltpläne, Dokumentation zum 8x Multi-Speeder 32KB RAM Expansion (DolphinDos2)](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/docs)

6. [Fotogalerie](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/images)
   
   

## Erster Start

1. Bevor die Platine das erste Mal im Diskettenlaufwerk verwendet wird, prüfen Sie, ob alle Bauteile (ICs) richtig gepolt und korrekt eingesetzt sind.

2. Prüfen Sie die Platine auf Kurzschlüsse in der Spannungsversorgung. Kurzschlüsse in der Spannungsversorgung können den Speeder und das Mainboard des Diskettenlaufwerks leicht beschädigen. Prüfen Sie z. B. an den Polen der 0,1 µF-Kondensatoren der Multi-Speeder-Platine, dass **keine** Kurzschlüsse vorliegen.

3. Überprüfen Sie den Sitz der Platine im CPU-Sockel auf dem Mainboard und stellen Sie sicher, dass die Platine keine Kontakte am Mainboard berührt.

4. Achten Sie bei der Montage darauf, dass das Diskettenlaufwerk vom Stromnetz getrennt ist.

## Fehlfunktionen

Beim Zusammenbau kann es zu Problemen kommen. Hier sind einige Fehlfunktionen aufgeführt, die während des Zusammenbaus auftreten können:

1. **Fehler: Beim Start des Diskettenlaufwerks läuft der Floppy-Motor, und die rote LED leuchtet dauerhaft.**  
   **Lösung:** Das Laufwerk kann sich nicht initialisieren. Dies liegt meist an Kontaktproblemen bei den ICs. Beispielsweise haben die SMD-ICs keinen korrekten Kontakt zur Platine, oder Pins wie Adressbus oder Datenbus haben an den Lötstellen einen Kurzschluss (EPROM-Sockel, RAM, ATF16V8, ATMega328).  Prüfen Sie auch, ob EPROM, ATF16V8 und ATMega328 korrekt programmiert sind.

2. **Unter DolphinDos startet das Diskettenlaufwerk korrekt, stürzt jedoch beim Laden ab. Das originale CBMDOS (Bank 0 / 1@RNROM) läuft fehlerfrei.**  
   **Lösung:** Vermutlich funktioniert das RAM nicht korrekt. Prüfen Sie die Lötstellen am RAM-IC. Stellen Sie sicher, dass DolphinDos in Bank 0-3 installiert ist, damit der richtige RAM-Bereich verfügbar ist. Starte das Multi-Speeder-Diagnosetool unter CBMDOS (Bank 0 / 1@RNROM), um das RAM zu testen.

3. **DolphinDos oder SpeedDos lädt mit langsamer Geschwindigkeit.**  
   **Lösung:** Das Parallelkabel ist fehlerhaft oder nicht angeschlossen.

4. **Die Umschaltung der Kernals über die DOS-Befehle x@RNROM funktioniert nicht.**  
   **Lösung:** Prüfe, ob das Kernal-ROM gewechselt wird, wenn Du den PIN SelROM kurz auf GND legst. Damit kannst Du die Bänke von 0-7 (+1) manuell schalten. Wenn Du den PIN RstROM kurz auf GND legst, sollte auf Bank 0 geschaltet werden. Dies ist hilfreich, wenn das Diskettenlaufwerk bei einer defekten Firmware nicht mehr reagiert. Daher sollte in Bank 0 immer das originale CBMDOS gespeichert sein. Wenn die manuelle Umschaltung funktioniert, könnte es an einem Kontaktproblem des 74HTC275N oder des ATMega328 liegen, da der Datenbus D0-D7 möglicherweise nicht korrekt erfasst wird. Wenn die manuelle Umschaltung nicht funktioniert, arbeitet der ATMega328 möglicherweise nicht korrekt (z. B. Quarz oder 22-pF-Kondensatoren prüfen).

5. **Beim Laden führt das Laufwerk einen Reset aus oder stoppt den Ladevorgang, und die rote LED erlischt.**  
   **Lösung:** Der Mikrocontroller wechselt das Kernal-ROM während des Ladens. Dies kann passieren, wenn ein ROM-Wechsel durch einen falschen x@RNROM-Befehl erkannt wird, der z. B. im Programmcode auf der Diskette enthalten ist. In diesem Fall deaktiviere die "switchless" Umschaltung mit dem DOS-Befehl: **OPEN 1,8,15,"I:0@RNROM":CLOSE 1** oder **@I:0@RNROM**. Wenn Du das Laufwerk aus- und wieder einschaltest, ist die "switchless"-Funktion wieder aktiv.

6. **DolphinDos oder SpeedDos zeigen beim Laden des Directory "$" mit F7 wirre Zeichen.**
   **Lösung:** Das Parallelkabel zum Userport ist zu lang oder hat ein Kontaktproblem. Das Parallelkabel sollte insgesamt nicht länger als 60 cm sein.

7. **Das Laufwerk startet mal korrekt und dann stürzt dann einfach ab oder die rote LED blinkt**
   **Lösung:** Prüfe die Kontakte zum Mainboard und dem Multi-Speeder auf Wackelkontakte.
   
   
   
   

## Shared Projects auf PCBWay.com

### Commodore 1541 Switchless 8x Multi-Speeder

1. [PCBWay: Switchless Floppy Drive 8x Multi Floppy Speeder (THT) for the Commodore 1541 Disk Drive (V2.2c)](https://www.pcbway.com/project/shareproject/Switchless_Floppy_Drive_8x_Multi_Floppy_Speeder_for_the_Commodore_1541_Disk_Driv_369dbba4.html)

2. [PCBWay: Switchless Floppy Drive 8x Multi Floppy Speeder (SMD) for the Commodore 1541 Disk Drive (V2.2c)](https://www.pcbway.com/project/shareproject/Switchless_Floppy_Drive_8x_Multi_Floppy_Speeder_for_the_Commodore_1541_Disk_Driv_33eedf94.html)

3. [PCBWay: Parallel Cable Sets for the Commodore 1541 Disk Drive (SpeedDOS, DolphinDOS) with the C64/C128](https://www.pcbway.com/project/shareproject/C64_Userport_Adapter_Parallel_Cable_Set_for_the_Commodore_1541_Disk_Drive_Spe_3b86d1f8.html)

### Commodore 1541 Parallelport-Adapter VIA 6522

1. [1541-I/1541-II Parallel-Adapter (Duo/Slim) - Parallel Cable Set für das Commodore 1541 Diskettenlaufwerk (SpeedDOS, DolphinDOS) mit dem C64/C128](https://www.pcbway.com/project/shareproject/1541_I_1541_II_Parallel_Adapter_Duo_Slim_Parallel_Cable_Set_for_the_Commodor_57072954.html)

2. [1541-I/1541C Parallel-Adapter - Parallel Cable Set für das Commodore 1541 Diskettenlaufwerk (SpeedDOS, DolphinDOS) mit dem C64/C128](https://www.pcbway.com/project/shareproject/1541_I_1541C_Parallel_Adapter_Parallel_Cable_Set_for_the_Commodore_1541_Disk_D_a27176a6.html)

3. [C64 Userport-Adapter - Parallel Cable Set für das Commodore 1541 Diskettenlaufwerk (SpeedDOS, DolphinDOS) mit dem C64/C128](https://www.pcbway.com/project/shareproject/C64_Userport_Adapter_Parallel_Cable_Set_for_the_Commodore_1541_Disk_Drive_Spe_3b86d1f8.html)
   
   

### C128DCR Version Switchless 8x Multi-Floppy Speeder (DolphinDos 3)

1. [8x Multi-Floppy Speeder 32KB RAM Expansion für den Commodore C128DCR](https://www.pcbway.com/project/shareproject/Switchless_8x_Multi_Floppy_Speeder_with_32_KB_RAM_Expansion_for_the_Commodore_C1_557a83c8.html)

2. [C128/C64 Kernal-Switcher für 8x Multi-Floppy-Speeder C128DCR](https://www.pcbway.com/project/shareproject/C128_C64_U32_Kernal_Switcher_Adapter_for_Switchless_8x_Multi_Floppy_Speeder_with_f113e895.html)

3. [Parallelport-Adapter für 8x Multi-Floppy-Speeder C128DCR](https://www.pcbway.com/project/shareproject/Parallelport_Adapter_U4_for_Switchless_8x_Multi_Floppy_Speeder_with_32_KB_RAM_Ex_558623e7.html)
   
   

## Hilfreiche Links

1. DolphinDos: [Dolphin DOS – C64-Wiki](https://www.c64-wiki.de/wiki/Dolphin_DOS) & [https://project64.c64.org/hw/dolphindos.txt](https://project64.c64.org/hw/dolphindos.txt)

2. RAMBoard: [RAMBOard – C64-Wiki](https://www.c64-wiki.de/wiki/RAMBOard) & [https://www.c64copyprotection.com/ramboard/](https://www.c64copyprotection.com/ramboard/)
   
   

## Danke

Zu diesem Projekt haben viele beigetragen, und es ist das Ergebnis der Arbeit vieler Entwickler. Besonders möchte ich mich bei folgenden Entwicklern bedanken:

1. **Jan Bubela und Gunther Jilg**, die DolphinDos entwickelt haben.

2. **RetroNynjah**, der mir geholfen hat, seinen Switchless Multi-ROM auf den 8x Multi-Speeder zu integrieren. [GitHub - RetroNynjah/Switchless-Multi-ROM-for-27128-27256](https://github.com/RetroNynjah/Switchless-Multi-ROM-for-27128-27256)

3. **Oliver Eikemeier und Oliver Joppich**, die 1984 SpeedDos entwickelt haben. 

4. **silverdr**, für die hilfreichen technischen Daten zu DolphinDos. [https://e4aws.silverdr.com/projects/dolphindos2/](https://e4aws.silverdr.com/projects/dolphindos2/)

5. **ytmytm**, für seinen TrackCache: [GitHub - ytmytm/1571-TrackCacheROM: A firmware patch for Commodore 1571 drive and internal C128D drive enabling RAM expansion use for track cache](https://github.com/ytmytm/1571-TrackCacheROM)

6. **Stefan Kauf**, für seine Unterstützung bei der Idee des Multi-Speeders und seine Vorlagen.
   
   

## Haftungsausschluss

Ich habe dieses Projekt mit großer Sorgfalt gestaltet und getestet. Dennoch können Fehler passieren. Dieses Projekt ist ein Hobbyprojekt. Ich übernehme daher keine Garantie für die Funktion oder für Schäden, die durch den Einbau oder die Nutzung dieses Projekts entstehen könnten.



## Spenden

Ich habe viele Stunden an diesem Projekt gearbeitet. Wenn du diese Arbeit unterstützen möchtest, kannst du mir etwas für die Kaffeekasse spenden. Vielen Dank! [Paypal-Spende hier klicken!](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=Q8HXKYARXKT4L&ssrt=1714757590172)



## Nutzungsrecht / Copyright

Du kannst dieses Projekt gerne für private Zwecke nutzen. Die kommerzielle Nutzung, wie z. B. Verkauf oder andere Verbreitung meines Multi-Speeders, ist ohne meine Erlaubnis untersagt.

Ich wünsche euch viel Freude mit meinem 8x Multi-Speeder 32KB RAM Expansion für das Commodore 1541 Diskettenlaufwerk.



Viele Grüße  
Frank Eggen

E-Mail: [retro@emden.net](mailto:retro@emden.net)
