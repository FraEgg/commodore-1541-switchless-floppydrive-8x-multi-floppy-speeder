# Switchless Floppy Drive 8x Multi Floppy Speeder for the Commodore 1541 Disk Drive

Here is an German version [> German <](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/README.md)!

![1541 8x Multi-Floppy-Speeder PCB Prototype](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_proto.jpg?raw=true)

## General Information

This is my Switchless 8x ROM Multi Floppy Speeder project. It is the further development of my version 1.7. This board expands the Commodore 1541 disk drive with 32 KB SRAM and offers enough space with its 512 KB EPROM for up to 8 selectable Kernals/Speeders. The Kernals can be switched switchless (without a switch) using "DOS" commands from the computer. This is also the main advancement. For switching, I have installed a microcontroller that monitors the data bus for commands to change the Kernals. I have adopted the idea from RetroNynjah's [1541-Switchless-Multi-ROM](https://github.com/RetroNynjah/1541-Switchless-Multi-ROM) and integrated it into my 8x ROM Multi Floppy Speeder.

My 8x ROM Multi Floppy Speeder is compatible with DolphinDos 2, SpeedDos Expert, SpeedDos+, Jiffy-DOS, S-Jiffy, and the original CBMDOS 2.6. Due to the additional 32 KB of SRAM, it can also be used as a RAMBoard for special nibble copier programs. For Speeders with parallel transmission, an additional parallel cable, e.g., to the user port, is necessary. I operate my Speeders with a SpeedDos-compatible parallel cable.

A Kernal switcher for the computer is not part of this project. In this case, any C64/C128 Kernal switcher can be used. I also recommend the suitable projects from RetroNynjah at https://github.com/RetroNynjah.

## Installation
![1541 PCB Setup](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_PCB_Setup_Proto.jpg?raw=true)

The Switchless 8x ROM Multi Floppy Speeder is placed in the CPU socket between the board and the 6502 CPU in the 1541 (1541 I Socket UC5 and 1541 II Socket U3).

The original Kernal ROMs must be removed when operating the Switchless 8x ROM Multi Floppy Speeder (1541 I UB3 and UB4 / 1541 II U4). The 1541 II has only one Kernal ROM (U4). The new board would otherwise conflict with the original ROMs when the new ROMs are activated, and the disk drive would not start correctly when powered on.

## Operation
After the Switchless 8x ROM Multi Floppy Speeder is installed, the disk drive should start in ROM-Bank 1 at the first boot. In my case, this is the original CBMDOS.

### ROM-Bank Example:
| ROM Bank | Kernal | Note |
| -------- | -------- | -------- |
| 1 | CBMDOS 2.6 | IEC only |
| 2 | DolphinDos 2.0 | Parallel + RAM |
| 3 | SpeedDos+40T | Parallel |
| 4 | JiffyDos 5.0 | IEC only |
| 5 | S-JiffyDos | IEC only |
| 6 | CBMDOS 2.6 | Placeholder |
| 7 | CBMDOS 2.6 | Placeholder |
| 8 | SpeedDos Expert | Parallel + RAM |

### Switching ROM Bank / Kernal / Speeder

The Speeder can be switched on the computer by using a LOAD command or a DOS command. Here are a few examples:

1.
> LOAD"2@RNROM",8,1

The disk drive attempts to load the file named "2@RNROM" and responds with a "FILE NOT FOUND" error. However, the microcontroller recognizes the command "2@RNROM" and switches to ROM Bank 2. The LED on the PCB then blinks twice, and the disk drive performs a reset to correctly start the new Kernel-ROM. Afterward, the corresponding Speeder "Dolphin Dos 2.0" is operational. Make sure you also activate the corresponding matching Kernal-ROM on your computer.

2.
> OPEN 1,8,15,"I:3@RNROM":CLOSE 1

The drive executes the "I" command and reinitializes itself. The microcontroller recognizes the command "3@RNROM" and switches to ROM Bank 3. The LED blinks three times, and the disk drive performs a reset. Afterward, the Speeder "SpeedDos+40T" is active.

3.
> @I:5@RNROM

Some computer Kernals allow the easy sending of disk commands via the @ command (DolphinDos, SpeedDos, Jiffy-DOS). This makes the switch particularly convenient. In this example, the drive executes the "I" command and reinitializes itself. The microcontroller recognizes the "5@RNROM" command and switches to ROM Bank 5 "S-JiffyDos 1". The PCB LED blinks 5 times, and the drive performs a reset to correctly activate the Speeder.

![Screenshot Bankswitching](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_screenshot_bankswitching.jpg?raw=true)

## Connections
![PCB Connectors](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_render_JP-SW.jpg?raw=true)

The Switchless 8x ROM Multi Floppy Speeder has several connections (J4/J5), a button (SW1), and an LED (D1). The SW1 is always soldered onto the board. The J5 RST-/SELROM and J4 SPI are optional and are not equipped with components. This has the advantage that the user can decide whether to equip them with cables or pin headers and use them. Additionally, tall pin headers can also interfere with the installation of the PCB in a 1541 II, as the drive mechanism is placed above it and could interfere with the mechanics.

### SW1 (Reset)
This button performs a pure reset. First, the microcontroller of the Switchless 8x ROM Multi Floppy Speeder performs a restart, and then the disk drive receives a reset. It is comparable to a power-on of the drive. The selected ROM BANK is not reset. The microcontroller remembers the last used ROM even after a reset or power OFF/ON.

### J5 (RST-/SELROM)
This connection is optional. The pinout is 1 = SELROM, 2 = GND/GROUND, 3 = RSTROM. If SELROM is briefly connected to GND/GROUND via a button, it switches to the next ROM Bank (+1). If RSTROM is briefly connected to GND/GROUND, the ROM counter is set to 1. This allows resetting the ROM Bank if a ROM Bank is not populated. If this happens, the disk drive's CPU crashes, and the ROM switch is no longer possible from the computer. With RSTROM, ROM Bank 1 is always activated, and a drive reset is performed. Therefore, ROM Bank 1 should always be equipped with a functioning Kernal system. I always place the original CBMDOS there.

### J4 (SPI)
With the Serial Peripheral Interface (SPI), the firmware of the ATMEGA328 microcontroller can be updated via an ASP programmer. Before programming, always remove the board from the drive socket and remove the 6502 CPU from the socket!

### LED (D1)
The LED blinks when switching to another ROM Bank. When ROM Bank 1 is activated, the LED blinks once, ROM Bank 2 blinks twice, etc. After that, the disk drive performs a reset to correctly start the new ROM.

## ROM-RAM Memory Map V2.2

| ROM Bank | ROM Area      | CPU RAM Area(s)  | Kernal     | Command |
| -------- | --------------| ------------------ | ----------- | ------- |
| 0        | $00000-$0FFFF | $6000 - $9FFF 32 KB | CBMDOS 2.6  | 1@RNROM |
| 1        | $10000-$1FFFF | $6000 - $9FFF 32 KB | DolphinDos 2.0 | 2@RNROM |
| 2        | $20000-$2FFFF | $6000 - $9FFF 32 KB | SpeedDos+40T | 3@RNROM |
| 3        | $30000-$3FFFF | $6000 - $9FFF 32 KB | JiffyDos 5.0 | 4@RNROM |
| 4        | $40000-$4FFFF | $6000 - $7FFF 08 KB | S-JiffyDos 1 | 5@RNROM |
| 5        | $50000-$5FFFF | $6000 - $7FFF 08 KB | CBMDOS 2.6 (Placeholder) | 6@RNROM |
| 6        | $60000-$6FFFF | $4000 - $7FFF 16 KB<br>$A000 - $BFFF 08 KB | CBMDOS 2.6 (Placeholder) | 7@RNROM |
| 7        | $70000-$7FFFF | $4000 - $7FFF 16 KB<br>$A000 - $BFFF 08 KB | SpeedDos 2.7 Expert |

 8@RNROM |

## EPROM / Kernals
The DOS KERNALs are stored in an EPROM. The EPROM, e.g., 27C040/29F040, is a 512 KB EPROM. It is divided into 8x 64 KB banks (Bank 0-7). Each bank $x0000 - $xFFFF mirrors the 64 KB memory area of the floppy 1:1. The ROM is generally inserted into the CPU address area from the memory area $2000 - $FFFF. The ROM area is only overlaid by the RAM areas (see table RAM-ROM Memory Map).

When operating the Multi-Speeder board, all original ROM chips (ICs) of the 1541 must be removed or deactivated (CS/CE/OE permanently high), as they would otherwise conflict with the ROM of the Multi-Speeder in the address space. The result would be a crash of the floppy disk drive upon power-on.

## RAM
Just like the ROM, the 32 KB RAM is also mapped into different areas of the 1541. Where the RAM is mapped depends on the active bank.

### Which RAM areas are mapped when?
> BANK 0-3 $6000 - $9FFF (32 KB)<br>
> BANK 4-5 $6000 - $7FFF (08 KB)<br>
> BANK 6-7 $A000 - $BFFF (08 KB)<br>
> The RAM areas always overlay the ROM address space.

## EPROMs / EEPROMs
There are several variants that can be used. I have tested various 27C040 EPROMs or a Flash-EPROM 29F040. It is important to ensure that the corresponding jumper JP2 or JP3 is set! Otherwise, the bank switching will not work correctly, as the pin layout of these EPROM types differs slightly (PIN 1/PIN 32).

## 1541 Address Decoder Mirror Problem
In the 1541, Commodore skimped on the address decoder. The VIAs 6522 occupy the memory areas $1800-$18FF and $1C00-$1CFF and are then mirrored repeatedly up to address $8000. This conflicts with the RAM expansion. I solved the problem by adjusting the A15 address line on the board accordingly to the motherboard. This stops the mirroring problem for the RAM. Therefore, nothing in the 1541 collides starting at address $2000.

## WDC 65C02 CPU and Other CPUs
A more modern WDC W65C02 CPU can also be used. However, the optional resistor R1 must be installed with 3.3K and JP1 opened! However, this does not make the 1541 very compatible. The original CBM-DOS runs, but most floppy speeders also use illegal opcodes from the original old MOS 6502A CPU. The newer WDC W65C02 CPU does not recognize these. The result is that many fast loaders that use illegal opcodes do not work. Therefore, I am still looking for an FPGA emulation that can be used for my Multi-Speeder instead of an original MOS 6502A CPU. Rockwell 6502 CPUs and those from UMC and SY6502A work without problems.

## Components / BOM
The electronics consist of the following components:

- 2x Pin Header 2.54 Straight 1 x 20 (BKL10120536) (Connector to 1541 Mainboard)
- 1x IC Socket DIP40 2.54 mm Pin Connector Socket (U1) (CPU 6502 / UC5 / U3)
- 2x IC Socket DIP20 2.54 mm Pin Connector Socket (U3/U5) (74HCT273N / Atmel F16V8 BQL-15PV)
- 1x IC Socket PLCC32 DIP PLCC IC socket adapter (EEPROM/EPROM)
- 1x IC Atmel F16V8 BQL-15SU (U5) (GAL/PAL) (U5)
- 1x IC 74HCT273D Octal D-type flip-flop with reset; positive-edge trigger (U3) 
- 1x IC SRAM ISSI 62C256AL-45ULI 28-PIN SOP (U6)
- 1x IC ATmega328PB 8-Bit-ATMega AVR Microcontroller, 32 KB, 20 MHz, TQFP-32 (U4)
- 1x DIP Crystal Oscillator 16 MHz HC-49 (Y1)
- 1x EPROM-OTP AT27C040-70JU PLCC32 / AM27C040-120JC PLCC32 or EEPROM 29F040 (PLCC32) (U2)
- 4x Tantalum Capacitor 16V 100nF radial DIP (C1, C2, C5, C6)
- 2x Tantalum Capacitor 16V 22pF radial DIP (C3, C4)
- 1x Resistor 560R THT Axial L 3.6 mm D 1.6 mm P 5.08 mm Horizontal (R3)
- 3x Resistor 10K THT Axial L 3.6 mm D 1.6 mm P 5.08 mm Horizontal (R2, R4, R5) 
- 1x LED Diode THT 3.0 mm
- 1x Tactile Tact Push Button Switch DIP 4Pin 6*6*4.3 mm Micro Switch Self-reset DIP Key Switches (JTP-1130) (SW1)
 
Optional:
- 1x Connector Pin Header 2x03 Pol P 2.00 mm Vertical (BKL10120739) (SPI) (J4)
- 1x Connector Pin Header 1x03 Pol P 2.00 mm Vertical (BKL10120728) (RST-/SELROM) (J5)
- 1x Resistor 3.3K THT Axial L 3.6 mm D 1.6 mm P 5.08 mm Horizontal (only WDC65C02 CPU) (R1)

## Donations
If you would like to support my work, you are welcome to send me a donation via PayPal.
[> Donate <](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=Q8HXKYARXKT4L&ssrt=1714757590172)

## Disclaimer
I put a lot of effort into this and strive for accuracy. However, I cannot rule out mistakes. This is a hobby project, and I do not provide any guarantees for the functionality or consequences that a modification/installation of my projects may have on your devices. I also assume no liability for possible consequential damages from the described proper use of my board.

## Thanks
I would like to thank everyone who supported me in this project. Not only the donors but also the users who gave me helpful tips or suggestions for improvements.

I would especially like to thank RetroNynjah for his idea with the switchless ROM/Banking. I have adopted this function with slight adjustments. You can find his great projects here: [https://github.com/RetroNynjah/](https://github.com/RetroNynjah/)

## Have fun
I wish you all a lot of fun with this project.

Best regards,  
Frank Eggen