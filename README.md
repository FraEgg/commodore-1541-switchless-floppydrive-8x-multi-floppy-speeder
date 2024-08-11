![1541 8x Multi-Floppy-Speeder PCB Prototype](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_proto.jpg?raw=true)

# Allgemeines

Dieses ist mein Switchless 8x ROM Multi Floppy Speeder Projekt. Es ist die Weiterentwicklung meiner Version 1.7. Diese Platine erweitert das Commodore 1541 Diskettenlaufwerk um 32KB SRAM und bietet mit seinem 512KB Eprom ausreichend Platz für bis zu 8x belibige Kernal-Betriebsysteme zur Verfügung. Es ist z.B. kompatibel für DolphinDos 2, SpeedDos Expert, SpeedDos+, Jiffy-DOS, S-Jiffy und dem original CBMDOS2.6. Durch die 32KB zusätzlichen SRAM kann es auch als RAMBoard für spezielle Nibble-Kopierprogramme verwendet werden. Für Speeder mit paralleler Übertragung ist ein zusätzlichen Parallel-Kabel z.B. zum Userport notwendig. Ich beitreibe meine Speeder mit einem SpeedDos kompatiblen Parallel-Kabel.

![1541 PCB Setup](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_PCB_Setup_Proto.jpg?raw=true)
# Installation
Der Switchless 8x ROM Multi Floppy Speeder wird in der 1541 in den CPU Sockel zwischen Platine und 6502 CPU platziert (1541 I Sockel UC5 und 1541 II Sockel U3).

Die original Kernal ROMs müssen beim Betrieb des Switchless 8x ROM Multi Floppy Speeder entfernt werden (1541 I UB3 u. UB4 / 1541 II U4) Die 1541 II hat nur ein Kernal-ROM (U4). Die neue Platine kommt sonst beim Einblenden der neue ROMs in konflikt mit den originalen ROMs und das Diskettenlaufwerk würde beim einschalten nicht korrekt starten.
