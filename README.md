![1541 8x Multi-Floppy-Speeder PCB Prototype](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_proto.jpg?raw=true)

# Allgemeines

Dieses ist mein Switchless 8x ROM Multi Floppy Speeder Projekt. Es ist die Weiterentwicklung meiner Version 1.7. Diese Platine erweitert das Commodore 1541 Diskettenlaufwerk um 32KB SRAM und bietet mit seinem 512KB Eprom ausreichend Platz für bis zu 8x belibige Kernal-Betriebsysteme zur Verfügung. Es ist z.B. kompatibel für DolphinDos 2, SpeedDos Expert, SpeedDos+, Jiffy-DOS, S-Jiffy und dem original CBMDOS2.6. Durch die 32KB zusätzlichen SRAM kann es auch als RAMBoard für spezielle Nibble-Kopierprogramme verwendet werden. Für Speeder mit paralleler Übertragung ist ein zusätzlichen Parallel-Kabel z.B. zum Userport notwendig. Ich beitreibe meine Speeder mit einem SpeedDos kompatiblen Parallel-Kabel.

![1541 PCB Setup](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_PCB_Setup_Proto.jpg?raw=true)
# Installation
Der Switchless 8x ROM Multi Floppy Speeder wird in der 1541 in den CPU Sockel zwischen Platine und 6502 CPU platziert (1541 I Sockel UC5 und 1541 II Sockel U3).

Die original Kernal ROMs müssen beim Betrieb des Switchless 8x ROM Multi Floppy Speeder entfernt werden (1541 I UB3 u. UB4 / 1541 II U4) Die 1541 II hat nur ein Kernal-ROM (U4). Die neue Platine kommt sonst beim Einblenden der neue ROMs in konflikt mit den originalen ROMs und das Diskettenlaufwerk würde beim einschalten nicht korrekt starten.

# Bedienung
Der Switchless 8x ROM Multi Floppy Speeder verfügt über mehrere Anschlüsse (J4/J5) einen Taster (SW1) und LED (D1).

## SW1 (Reset)
Dieser Taster führt reinen Reset aus. Erst führt der Microcontroler des Switchless 8x ROM Multi Floppy Speeder einen Neustart durch uns dann bekommt das Diskettenlaufwerk einen Reset. Es ist mit einem Power ON des Laufwerks zu vergleichen. Die ausgewählte ROM BANK wird nicht zurück gesetzt. Der Microcontroller merkt sich das zuletzt verwendete ROM auch nach einem Reset oder Power OFF/ON.

## J5 (RST-/SELROM)
Dieser Anschluss ist optional. Die Belegung ist 1=SELROM, 2=GND/MASSE, 3=RSROM. Wird SELROM z.B. mit einem Taster kurz auf GND/MASSE gelegt, dann wird auf die nächste ROM Bank (+1) umgeschaltet. Wird RSTROM kurz auf GND/MASSE gelegt, dann wird der ROM-Zähler auf 1 gesetzt. Das ermöglicht, die ROM-Bank zurück zu setzen wenn mal eine ROM-Bank nicht belegt ist. Sollte dass der Fall sein, dann stürzt die CPU des Diskettenlaufwerks ab und dann ist der ROM-Wechsel über den Rechner nicht mehr möglich. Mit dem RSTROM wird immer die ROM-Bank 1 aktiviert und ein Laufwerks-Reset durchgeführt. Deshalb sollte die ROM-Bank 1 immer mit einem funktionierenden Kernal-System versehen sein. Ich plaziere dort immer das original CBMDOS.

## J4 (SPI)
Mit dem Serial Peripheral Interface (SPI) kann über ein ASP Programmer die Firmware des ATMEGA328 Microcontroller aktualisiert werden. Hierzu bitte vor dem Programmieren immer die Platine aus dem Sockel des Laufwerks nehmen und die CPU 6502 aus dem Sockel entfernen!
