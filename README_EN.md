# Switchless Floppy Drive 8x Multi Floppy Speeder for the Commodore 1541 Disk Drive

Here is an German version [> German <](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/README.md)!

![1541 8x Multi-Floppy-Speeder 32 KB RAM PCB](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1b_pcb_smd_dip.jpg?raw=true)

## Overview

This project is an advancement of my 8x ROM Multi Floppy Speeder V1.7. The board extends the Commodore 1541 disk drive with 32 KB SRAM and 512 KB EPROM, providing space for up to 8 Kernals/Speeder. The Kernals can be switched without any physical switch (switchless) directly via DOS commands from the computer.

### Main Features:

- **Switchless Switching**: Kernals can be switched directly via DOS commands.
- **Compatibility**: Supports DolphinDos 2, SpeedDos Expert, SpeedDos+, Jiffy-DOS, S-Jiffy, and the original CBMDOS 2.6.
- **RAM Expansion**: The additional 32 KB SRAM allows the board to be used as a RAM board for special nibble copier programs.

## Installation

![Installation 1541 II](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1b_pcb_1541II.jpg?raw=true)

The Switchless 8x ROM Multi Floppy Speeder is placed between the board and the 6502 CPU in the CPU socket of the 1541 (1541 I: Socket UC5, 1541 II: Socket U3). Before installation, the original Kernal ROMs must be removed to avoid conflicts.

## Operation

### Getting Started

After installation, the disk drive should automatically start in ROM Bank 1, which contains the original CBMDOS.

### ROM Bank Overview

| ROM Bank | Kernal            | Note                  |
| -------- | ----------------- | --------------------- |
| 1        | CBMDOS 2.6        | IEC only              |
| 2        | DolphinDos 2.0    | Parallel + RAM        |
| 3        | SpeedDos+40T      | Parallel              |
| 4        | JiffyDos 5.0      | IEC only              |
| 5        | S-JiffyDos        | IEC only              |
| 6        | RapiDOS Cl.       | Parallel              |
| 7        | CBMDOS 2.6        | Placeholder           |
| 8        | SpeedDos Expert   | Parallel + RAM        |

### Switching ROM Banks

The Speeder can be switched on the computer using simple commands:

1. **Switch to Bank 2 (DolphinDos 2.0):**

   ```plaintext
   LOAD"2@RNROM",8,1
   ```

   The drive switches to Bank 2 and automatically restarts.

2. **Switch to Bank 3 (SpeedDos+40T):**

   ```plaintext
   OPEN 1,8,15,"I:3@RNROM":CLOSE 1
   ```

   The microcontroller switches to Bank 3, the LED blinks three times, and the drive restarts.

3. **Switch to Bank 5 (S-JiffyDos):**

   ```plaintext
   @I:5@RNROM
   ```

   The microcontroller recognizes the command and switches to Bank 5. The LED blinks five times, and the drive restarts.

4. **Temporarily Disable Switchless Mode:**

   ```plaintext
   @I:0@RNROM
   ```

   The switchless mode is temporarily disabled until the drive is restarted.

## Connections and Components

![PCB Connectors](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_render_JP-SW.jpg?raw=true)

The Switchless 8x ROM Multi Floppy Speeder features several connections, a button (SW1), and an LED (D1).

### Key Connections:

- **SW1 (Reset)**: Resets the disk drive without resetting the currently selected ROM bank.
- **J5 (RST-/SELROM)**: Optional connection for switching ROM banks with an external button.
- **J4 (SPI)**: For updating the microcontroller's firmware via an ISP programmer.
- **LED (D1)**: Indicates the active ROM bank by blinking (1x for Bank 1, 2x for Bank 2, etc.).

## ROM-RAM Memory Map

| ROM Bank | ROM Area         | CPU RAM Area(s)       | Kernal                | Command  |
| -------- | ---------------- | --------------------- | --------------------- | -------- |
| 0        | $00000-$0FFFF    | $2000 - $9FFF 32 KB   | CBMDOS 2.6            | 1@RNROM  |
| 1        | $10000-$1FFFF    | $2000 - $9FFF 32 KB   | DolphinDos 2.0        | 2@RNROM  |
| 2        | $20000-$2FFFF    | $2000 - $9FFF 32 KB   | SpeedDos+40T          | 3@RNROM  |
| 3        | $30000-$3FFFF    | $2000 - $9FFF 32 KB   | JiffyDos 5.0          | 4@RNROM  |
| 4        | $40000-$4FFFF    | $2000 - $7FFF 24 KB   | S-JiffyDos 1          | 5@RNROM  |
| 5        | $50000-$5FFFF    | $2000 - $7FFF 24 KB   | RapiDos Classic | 6@RNROM  |
| 6        | $60000-$6FFFF    | $A000 - $BFFF 08 KB   | CBMDOS 2.6 (Placeholder) | 7@RNROM  |
| 7        | $70000-$7FFFF    | $A000 - $BFFF 08 KB   | SpeedDos 2.7 Expert   | 8@RNROM  |

### Memory Overlay

![MemoryMap / Logic / Overlay](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2b_logic.png?raw=true)

Starting at $2000, the ROM is mapped into the working memory and is only overlaid by RAM as specified in the table.

## EPROMs / EEPROMs

The DOS Kernals are stored in an EPROM (e.g., 27C040/29F040 with 512 KB). These are divided into 8x 64 KB banks. When in operation, all original ROMs in the 1541 must be removed or deactivated to avoid address conflicts.

## 8x Multi-Speeder RAM Diagnostic Tool

![1541 8x Multi-Floppy-Speeder 32 KB RAM Diagnostic-Tool](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2b_pcb_diag_tool.jpg?raw=true)

The diagnostic tool in the `/software/` directory helps test the 32K RAM of the Multi-Floppy Speeder. It writes and reads memory locations with $00 and $FF bytes to detect errors. The test should always be conducted with Bank 0 and the original CBMDOS.

[Download here.](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/software)

## Address Decoder Mirroring Issue

The VIAs 6522 of the 1541 occupy memory areas that are mirrored up to address $8000, which can collide with the RAM expansion. This issue is resolved by adjusting the A15 address line on the motherboard.

## WDC 65C02 CPU and Other CPUs

A more modern WDC W65C02 CPU can be used, but the compatibility of the 1541 is reduced since many fast loaders use illegal opcodes of the original MOS 6502A CPU, which the WDC W65C02 does not support.

## Components (BOM)
The electronics consist of the following components:

- 2x Pin Header 2.54 Straight 1 x 20 (BKL10120536) (Connector to 1541 Mainboard)
- 1x IC Socket DIP40 2.54 mm Pin Connector Socket (U1) (CPU 6502 / UC5 / U3)
- 2x IC Socket DIP20 2.54 mm Pin Connector Socket (U3/U5) (74HCT273N / Atmel F16V8 BQL-15PV)
- 1x IC Socket PLCC32 DIP PLCC IC Socket Adapter (EEPROM/EPROM)
- 1x IC Atmel F16V8 BQL-15SU (U5) (GAL/PAL)
- 1x IC 74HCT273D Octal D-type flip-flop with reset; positive-edge trigger (U3)
- 1x IC SRAM ISSI 62C256AL-45ULI 28-PIN SOP (U6)
- 1x IC ATmega328PB 8-Bit ATMega AVR Microcontroller, 32 KB, 20 MHz, TQFP-32 (U4)
- 1x DIP Crystal Oscillator 16 MHz HC-49 (Y1)
- 1x EPROM-OTP AT27C040-70JU PLCC32 / AM27C040-120JC PLCC32 or EEPROM 29F040 (PLCC32) (U2)
- 4x Tantalum Capacitor 16V 100nF radial DIP (C1, C2, C5, C6)
- 2x Tantalum Capacitor 

16V 22pF radial DIP (C3, C4)
- 1x Resistor 560R THT Axial L 3.6 mm D 1.6 mm P 5.08 mm Horizontal (R3)
- 1x Resistor 10K THT Axial L 3.6 mm D 1.6 mm P 5.08 mm Horizontal (R2)
- 1x LED Diode THT 3.0 mm *)
- 1x Tactile Push-Button Switch DIP 4Pin 6x6x4.3 mm Micro Switch Self-Reset DIP Key Switches (JTP-1130) (SW1)
 
Optional:
- 1x Connector Pin Header 2x03 Pol P 2.00 mm Vertical (BKL10120739) (SPI) (J4)
- 1x Connector Pin Header 1x03 Pol P 2.00 mm Vertical (BKL10120728) (RST-/SELROM) (J5)
- 1x Resistor 3.3K THT Axial L 3.6 mm D 1.6 mm P 5.08 mm Horizontal (only for WDC65C02 CPU) (R1)
- 2x Resistor 10K THT Axial L 3.6 mm D 1.6 mm P 5.08 mm Horizontal (R4, R5) (not needed and will be omitted in future versions)

*) Instead of the LED diode, a PIN header can be soldered. This allows the green LED of the disk drive to be used as an indicator LED.

## Donations

If you would like to support my work, I would appreciate a donation via PayPal. [Donate here.](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=Q8HXKYARXKT4L&ssrt=1714757590172)

## Disclaimer

This project is a hobby project. I cannot guarantee its functionality or any damages that may occur from installation or use.

## Acknowledgements

Special thanks to RetroNynjah for his idea with switchless ROM/Banking, which I have adapted with minor modifications. You can find his projects [here](https://github.com/RetroNynjah).

## Enjoy

I wish you a lot of fun with this project.

Best regards,  
Frank Eggen
