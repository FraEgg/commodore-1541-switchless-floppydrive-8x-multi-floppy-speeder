<img title="The Multi-Speeder Logo" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/Multi-Speeder_Logo.png?raw=true" alt="Multi-Speeder Logo" style="zoom:25%;" data-align="center">

# Switchless Floppy Drive 8x Multi Floppy Speeder for the Commodore 1541 Disk Drive (V2.2c)

## ROM-RAM Memory Map

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



### Memory Overlay

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2c_Tabelle_ROM-RAM.png?raw=true" title="ROM/RAM Table" alt="ROM/RAM Table" style="zoom:80%;">

Starting from $2000, the ROM is mapped into the CPU's address space and is overlaid only by RAM according to the table.



## EPROMs / EEPROMs

The DOS Kernals are provided in an EPROM (e.g., 27C040/29F040 with 512 KB). This EPROM is divided into 8x 64 KB banks. During operation, all original ROMs in the 1541 must be removed or deactivated to avoid address conflicts.](mailto:retro@emden.net)
