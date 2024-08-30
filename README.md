# Switchless Floppy Drive 8x Multi Floppy Speeder für das Commodore 1541 Diskettenlaufwerk

Here is an English version [> translation <](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/README_EN.md)!

![1541 8x Multi-Floppy-Speeder 32 KB RAM PCB](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1b_pcb_smd_dip.jpg?raw=true)

## Überblick

Dieses Projekt ist eine Weiterentwicklung meiner Version 1.7 des 8x ROM Multi Floppy Speeders V1.7. Die Platine erweitert das Commodore 1541 Diskettenlaufwerk um 32 KB SRAM und 512 KB EPROM, was Platz für bis zu 8 Kernals/Speeder bietet. Die Kernals lassen sich ohne Schalter (switchless) direkt über DOS-Befehle vom Rechner aus umschalten. 

### Hauptfunktionen:

- **Schalterloses Umschalten**: Kernals können direkt über DOS-Befehle umgeschaltet werden.
- **Kompatibilität**: Unterstützt DolphinDos 2, SpeedDos Expert, SpeedDos+, Jiffy-DOS, S-Jiffy und das originale CBMDOS 2.6.
- **RAM-Erweiterung**: Durch das 32 KB zusätzliche SRAM kann die Platine auch als RAMBoard für spezielle Nibble-Kopierprogramme verwendet werden.

## Installation

![Installation 1541 II](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1b_pcb_1541II.jpg?raw=true)

Der Switchless 8x ROM Multi Floppy Speeder wird zwischen die Platine und die 6502 CPU im CPU-Sockel der 1541 eingesetzt (1541 I: Sockel UC5, 1541 II: Sockel U3). Vor der Installation müssen die originalen Kernal-ROMs entfernt werden, um Konflikte zu vermeiden.

## Bedienung

### Erste Schritte

Nach der Installation sollte das Diskettenlaufwerk beim ersten Start automatisch in der ROM-Bank 1 starten, in der sich das originale CBMDOS befindet.

### ROM-Banken Übersicht

| ROM-Bank | Kernal            | Hinweis                |
| -------- | ----------------- | ---------------------- |
| 1        | CBMDOS 2.6        | IEC only               |
| 2        | DolphinDos 2.0    | Parallel + RAM         |
| 3        | SpeedDos+40T+GCR  | Parallel               |
| 4        | JiffyDos 5.0      | IEC only               |
| 5        | S-JiffyDos        | IEC only               |
| 6        | RapiDOS Classic   | Parallel               |
| 7        | CBMDOS 2.6        | Placeholder            |
| 8        | SpeedDos Expert   | Parallel + RAM         |

### Wechseln der ROM-Bank

Der Wechsel der Speeder kann am Computer durch einfache Befehle ausgelöst werden:

1. **Wechsel zu Bank 2 (DolphinDos 2.0):**

   ```plaintext
   LOAD"2@RNROM",8,1
   ```

   Das Laufwerk wechselt zu Bank 2 und startet automatisch neu.

2. **Wechsel zu Bank 3 (SpeedDos+40T+GCR):**

   ```plaintext
   OPEN 1,8,15,"I:3@RNROM":CLOSE 1
   ```

   Der Mikrocontroller wechselt zu Bank 3, die LED blinkt dreimal, und das Laufwerk startet neu.

3. **Wechsel zu Bank 5 (S-JiffyDos):**

   ```plaintext
   @I:5@RNROM
   ```

   Der Mikrocontroller erkennt den Befehl und wechselt zu Bank 5. Die LED blinkt fünfmal, und das Laufwerk startet neu.

4. **Temporäre Deaktivierung des Switchless-Modus:**

   ```plaintext
   @I:0@RNROM
   ```

   Der Switchless-Modus wird vorübergehend deaktiviert, bis das Laufwerk neu gestartet wird.

## Anschlüsse und Komponenten

![PCB Connectors](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_render_JP-SW.jpg?raw=true)

Der Switchless 8x ROM Multi Floppy Speeder verfügt über mehrere Anschlüsse, einen Taster (SW1) und eine LED (D1).

### Wichtige Anschlüsse:

- **SW1 (Reset)**: Führt einen Reset des Diskettenlaufwerks durch, ohne die aktuell ausgewählte ROM-Bank zurückzusetzen.
- **J5 (RST-/SELROM)**: Optionaler Anschluss zum Umschalten der ROM-Banken mit einem externen Taster.
- **J4 (SPI)**: Zum Aktualisieren der Firmware des Mikrocontrollers über einen ISP-Programmer.
- **LED (D1)**: Zeigt die aktive ROM-Bank durch Blinken an (1x für Bank 1, 2x für Bank 2 usw.).

## ROM-RAM Memorymap

| ROM Bank | ROM Area         | CPU RAM Area(s)       | Kernal                | Command  |
| -------- | ---------------- | --------------------- | --------------------- | -------- |
| 0        | $00000-$0FFFF    | $2000 - $9FFF 32 KB   | CBMDOS 2.6            | 1@RNROM  |
| 1        | $10000-$1FFFF    | $2000 - $9FFF 32 KB   | DolphinDos 2.0        | 2@RNROM  |
| 2        | $20000-$2FFFF    | $2000 - $9FFF 32 KB   | SpeedDos+40T+GCR      | 3@RNROM  |
| 3        | $30000-$3FFFF    | $2000 - $9FFF 32 KB   | JiffyDos 5.0          | 4@RNROM  |
| 4        | $40000-$4FFFF    | $2000 - $7FFF 24 KB   | S-JiffyDos 1          | 5@RNROM  |
| 5        | $50000-$5FFFF    | $2000 - $7FFF 24 KB   | RapiDos Classic       | 6@RNROM  |
| 6        | $60000-$6FFFF    | $A000 - $BFFF 08 KB   | CBMDOS 2.6 (Placeholder) | 7@RNROM  |
| 7        | $70000-$7FFFF    | $A000 - $BFFF 08 KB   | SpeedDos 2.7 Expert   | 8@RNROM  |

### Speicherüberlagerung

![MemoryMap / Logic / Overlay](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2b_logic.png?raw=true)

Ab $2000 wird das ROM in den Arbeitsspeicher eingeblendet und nur vom RAM gemäß der Tabelle überlagert.

## EPROMs / EEPROMs

Die DOS-KERNALs werden in einem EPROM gespeichert (z.B. 27C040/29F040 mit 512 KB). Diese Speicher werden in 8x 64 KB Bänke unterteilt. Beim Betrieb müssen alle originalen ROMs der 1541 entfernt oder deaktiviert werden, um Adresskonflikte zu vermeiden.

## 8x Multi-Speeder RAM Diagnose-Tool

![1541 8x Multi-Floppy-Speeder 32 KB RAM Diagnostic-Tool](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2b_pcb_diag_tool.jpg?raw=true)

Das Diagnose-Tool im Verzeichnis `/software/` hilft dabei, das 32K RAM des Multi-Floppy-Speeders zu testen. Es schreibt und liest die Speicherstellen mit $00- und $FF-Bytes, um Fehler zu erkennen. Der Test sollte immer mit Bank 0 und dem originalen CBMDOS durchgeführt werden.

[Hier geht's zum Download.](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/software)

## Adressendecoder-Spiegel-Problematik

Die VIAs 6522 der 1541 belegen Speicherbereiche, die bis zur Adresse $8000 gespiegelt werden, was mit der RAM-Erweiterung kollidieren kann. Dieses Problem wird durch eine Anpassung der Adressleitung A15 auf dem Motherboard behoben.

## WDC 65C02 CPU und andere CPUs

Eine modernere WDC W65C02 CPU kann verwendet werden, allerdings verringert sich dadurch die Kompatibilität der 1541, da viele Schnelllader illegale OP-Codes der originalen MOS 6502A CPU nutzen, die von der WDC W65C02 nicht unterstützt werden.

## Bauteile (BOM)
Die Elektronik besteht aus folgenden Bauteilen:

- 2x Pin Header 2,54 Straight 1 x 20 (BKL10120536) (Connector to 1541 Mainboard)
- 1x IC-Sockel DIP40 2,54 mm Pin Connector Socket (U1) (CPU 6502 / UC5 / U3)
- 2x IC-Sockel DIP20 2,54 mm Pin Connector Socket (U3/U5) (74HCT273N / Atmel F16V8 BQL-15PV)
- 1x IC-Sockel PLCC32 DIP PLCC IC Socket Adapter (EEPROM/EPROM)
- 1x IC Atmel F16V8 BQL-15SU (U5) (GAL/PAL) (U5)
- 1x IC 74HCT273D Octal D-type flip-flop with reset; positive-edge trigger (U3) 
- 1x IC SRAM ISSI 62C256AL-45ULI 28-PIN SOP (U6)
- 1x IC ATmega328PB 8-Bit-ATMega AVR Microcontroller, 32 KB, 20 MHz, TQFP-32 (U4)
- 1x DIP-Kristalloszillator 20 MHz HC-49 (Y1)
- 1x EPROM-OTP AT27C040-70JU PLCC32 / AM27C040-120JC PLCC32 oder EEPROM 29F040 (PLCC32) (U2)
- 4x Tantal-Kondensator 16V 100nF radial DIP (C1, C2, C5, C6)
- 2x Tantal-Kondensator 16V 22pF radial DIP (C3, C4)
- 1x Widerstand 560R THT axial L 3,6 mm D 1,6 mm P 5,08 mm horizontal (R3)
- 1x Widerstand 10K THT axial L 3,6 mm D 1,6 mm P 5,08 mm horizontal (R2) 
- 1x LED-Diode THT 3,0 mm *)
- 1x Taktile Push-Button Switch DIP 4Pin 6*6*4,3 mm Micro Switch Self-Reset DIP Key Switches (JTP-1130) (SW1)
 
Optional:
- 1x Connector Pin Header 2x03 Pol P 2,00 mm vertical (BKL10120739) (SPI) (J4)
- 1x Connector Pin Header 1x03 Pol P 2,00 mm vertical (BKL10120728) (RST-/SELROM) (J5)
- 1x Widerstand 3,3K THT axial L 3,6 mm D 1,6 mm P 5,08 mm horizontal (nur für WDC65C02 CPU) (R1)
- 2x Widerstand 10K THT axial L 3,6 mm D 1,6 mm P 5,08 mm horizontal (R4, R5) (wird nicht benötigt und entfällt zukünftig ganz)

*) Anstelle der LED-Diode kann auch ein PIN-Header verlötet werden. Dann kann die grüne LED des Diskettenlaufwerks als Indikator-LED genutzt werden. 

## Spenden

Wenn Sie meine Arbeit unterstützen möchten, freue ich mich über eine Spende via Paypal. [Hier spenden.](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=Q8HXKYARXKT4L&ssrt=1714757590172)

## Haftungsausschluss

Dieses Projekt ist ein Hobbyprojekt. Ich übernehme keine Garantie

 für die Funktion oder für etwaige Schäden, die durch den Einbau oder die Nutzung entstehen könnten.

## Danksagung

Ein besonderer Dank geht an RetroNynjah für seine Idee mit dem switchless ROM/Banking, die ich mit leichten Anpassungen übernommen habe. Seine Projekte finden Sie [hier](https://github.com/RetroNynjah).

## Viel Spaß

Ich wünsche Ihnen viel Spaß mit diesem Projekt.

Mit freundlichen Grüßen  
Frank Eggen
