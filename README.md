<img title="The Multi-Speeder Logo" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/Multi-Speeder_Logo.png?raw=true" alt="Multi-Speeder Logo" style="zoom:25%;" data-align="center">

# Switchless Floppy Drive 8x Multi Floppy Speeder for the Commodore 1541 Disk Drive (V2.2c)

Here is an German version [> German <](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/README_DE.md)!

<img title="Commodore 1541-II disk drive with 8x Multi-Speeder 32KB RAM expansion (RAMBoard)" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/1541_II_install_PCB.jpg?raw=true" alt="Commodore 1541-II disk drive with 8x Multi-Speeder 32KB RAM expansion (RAMBoard)" data-align="center" style="zoom:80%;">

## Description

This project is an advanced development of the [8x ROM Multi Floppy Speeder V1.7](https://github.com/FraEgg/commodore-1541-floppydrive-8x-multi-floppy-speeder). The board expands the Commodore 1541 disk drive with 32 KB SRAM (RAMBoard compatible) and integrates 8x 64KB ROM banks for various DOS systems (Speeders) in a single 512KB ROM. In this version 2.2c, the DOS Kernals can be switched **"switchless"**, i.e., without a physical switch, via DOS commands from the computer. No holes or switches are needed on the casing to switch between DOS/Speeders.



The Switchless 8x Multi-Speeder 32KB RAM is available in two variants. Both are technically identical but differ in their form factor and are optimized for different 1541 models.



1. **Through Hole Technology (THT)**: This variant, except for the 32 KB SRAM, is designed in THT construction and is easier to assemble yourself. It is ideal for development and use in older 1541-I disk drive models. All ICs can be socketed.

2. **Surface Mount Devices (SMD)**: In this variant, all ICs are built as SMD components. This enables the operation of the 8x Multi-Speeder 32KB RAM in newer 1541-II models. The 8x Multi-Speeder 32KB RAM fits between the PCB and drive mechanism when the CPU is soldered directly and not socketed. The SMD version fits both 1541-I and 1541-II.
   
   

Both variants of the 8x Multi-Speeder 32KB RAM can be ordered as PCBs from PCBWay.com, along with the PCBs for the parallel cable.

A Kernal switcher for the C64/C128 is **not** included in this project. Many excellent solutions for this are available from other retro developers or shops. For my C64 Kernals, I use my [Ultimate-II+ Cartridge](https://ultimate64.com/Main_products) or the universal Kernal switcher from [FaszinationC64](https://www.faszinationc64.de/Universal-EPROM-Adapter).



### Key Features:

- **8x 64KB ROM Banks**: For various DOS systems and Speeders (e.g., DolphinDos, SpeedDos, JiffyDOS, ...)
- **Switchless Switching**: DOS Kernals can be switched directly via DOS commands on the computer.
- **Compatibility**: Supports DolphinDos 2, SpeedDos Expert, SpeedDos+, JiffyDOS, S-Jiffy, and the original CBMDOS 2.6.
- **RAM Expansion**: The additional 32 KB SRAM allows the board to also function as a RAMBoard for specialized nibble copy programs.
  
  

## Installation

![8x Multi-Floppy-Speeder 32KB in an older 1541-I disk drive](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/1541_I_SMD_install_PCB.jpg?raw=true "8x Multi-Floppy-Speeder 32KB in an older 1541-I disk drive")

The Switchless 8x ROM Multi-Speeder is installed between the PCB and the 6502 CPU in the CPU socket of the 1541 (1541 I: Socket UC4, 1541 II: Socket U3).



**Before installation, the original Kernal ROMs (1541-I: UB3/UB4, 1541-II: U4) must be removed to prevent conflicts with the DOS ROMs and to ensure the disk drive starts correctly.**



A photo gallery with steps for assembling the 8x Multi-Speeder 32KB is available here: [/image/setup/README.md](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/README.md).



## Operation

### Getting Started

After installation, the disk drive should automatically boot into the first ROM bank with "CBMDOS 2.6" on initial startup.



### ROM Bank Overview

| ROM Bank | Kernal           | Note           |
| -------- | ---------------- | -------------- |
| 1        | CBMDOS 2.6       | IEC only       |
| 2        | DolphinDos 2.0   | Parallel + RAM |
| 3        | SpeedDos+40T+GCR | Parallel       |
| 4        | JiffyDOS 5.0 *)  | IEC only       |
| 5        | S-JiffyDOS *)    | IEC only       |
| 6        | RapiDOS Classic  | Parallel       |
| 7        | CBMDOS 2.6       | Placeholder    |
| 8        | SpeedDos Expert  | Parallel + RAM |

The 512KB DOS EPROM (27C040/29F040) for the Switchless 8x Multi-Speeder 32KB can be downloaded here: [/rom/1541](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/rom/1541). Banks 4 and 5 are reserved for JiffyDOS and S-JiffyDOS and are not included in the ROM file due to copyright restrictions. JiffyDOS can be purchased at the [Restore-Store](https://restore-store.de/89-jiffydos).



*) Placeholder occupied with CBMDOS 2.6.



### C64 Kernals

My test Kernals for the Commodore C64 are available here: [/rom/C64](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/rom/C64).



### Switching ROM Banks

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.1_pcb_1541_screenshot_bankswitching.jpg?raw=true" title="Screenshot: Switching ROM Banks" alt="Screenshot: Switching ROM Banks" style="zoom:80%;">

Switching Speeders can be triggered from the computer using simple commands.

#### Examples:

1. **Switch to Bank 2 (DolphinDos 2.0):**
   
   ```plaintext
   LOAD"2@RNROM",8,1
   ```
   
   The drive attempts to load the file "2@RNROM". The 8x Multi-Speeder detects the string "2@RNROM", switches the DOS-ROM (Bank 2 DolphinDos 2) in the 1541 disk drive, and performs a drive reset. Switch to the corresponding Kernal on the C64, and DolphinDos 2 will be ready for use.

2. **Switch to Bank 3 (SpeedDos+40T+GCR):**
   
   ```plaintext
   OPEN 1,8,15,"I:3@RNROM":CLOSE 1
   ```
   
   The microcontroller switches to Bank 3, the LED blinks three times, and the drive restarts.

3. **Switch to Bank 5 (S-JiffyDOS):**
   
   ```plaintext
   @I:5@RNROM
   ```
   
   The microcontroller detects the command, switches to Bank 5, the LED blinks five times, and the drive restarts.

4. **Temporarily Disable the Switchless Mode:**
   
   ```plaintext
   @I:0@RNROM
   ```
   
   This command increases the compatibility of the 8x Multi-Speeder. The Multi-Speeder will no longer respond to "x@RNROM" commands. The DOS Kernal cannot be switched. To re-enable switchless operation, completely power off and restart the disk drive, or press the reset button on the 8x Multi-Speeder. Disabling this mode is useful if the Speeder accidentally switches the DOS-ROM and resets during program loading.
   
   

## Connectors and Components

The Switchless 8x ROM Multi Floppy Speeder features several connectors, a button (SW1), and an LED (D1).



### Key Connectors:

#### THT Version 8x Multi-Speeder 32KB

<img title="THT Version" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2c_PCB_BOM_1541_CPU_THT_Speeder_V2.png?raw=true" alt="THT Version" data-align="inline" style="zoom:25%;">

* **J1 (W65C02 CPU) / R1**: The jumper is set by default for the original MOS/CSG 6502. For using the newer W65C02 CPU from WDC, the jumper must be opened, and the optional resistor R1 with 3.3 kOhm must be installed. For the original MOS/CSG 6502 CPU, R1 must remain uninstalled.
* **J2 (SPI)**: For updating the microcontroller firmware via an ISP programmer.
* **J3**: Jumper for OTP-EPROM 27C040 (Close), **J4** (Open).
* **J4**: Jumper for Flash-EPROM 29F040 (Close), **J3** (Open).
* **J5 (RST-/SELROM)**: Optional connection for switching ROM banks with an external button.
* **SW1 (Reset)**: Resets the disk drive without resetting the currently selected ROM bank. Re-enables the switchless mode.
* **LED (D1)**: Indicates the active ROM bank by blinking (1x for Bank 1, 2x for Bank 2, etc.).
  
  

#### SMD Version 8x Multi-Speeder 32KB

<img title="SMD Version" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2c_PCB_BOM_1541_CPU_SMD_Speeder_V2.png?raw=true" alt="SMD Version" style="zoom:25%;" data-align="inline">

- **J1 (W65C02 CPU) / R1**: The jumper is set by default for the original MOS/CSG 6502. For using the newer W65C02 CPU from WDC, the jumper must be opened, and the optional resistor R1 with 3.3 kOhm must be installed. For the original MOS/CSG 6502 CPU, R1 must remain uninstalled.
- **J2 (SPI)**: For updating the microcontroller firmware via an ISP programmer.
- **J3**: Jumper for OTP-EPROM 27C040 (Close), **J5** (Open).
- **J5**: Jumper for Flash-EPROM 29F040 (Close), **J3** (Open).
- **J4 (RST-/SELROM)**: Optional connection for switching ROM banks with an external button.
- **SW1 (Reset)**: Resets the disk drive without resetting the currently selected ROM bank. Re-enables the switchless mode.
- **LED (D1)**: Indicates the active ROM bank by blinking (1x for Bank 1, 2x for Bank 2, etc.).
  
  

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

The DOS Kernals are provided in an EPROM (e.g., 27C040/29F040 with 512 KB). This EPROM is divided into 8x 64 KB banks. During operation, all original ROMs in the 1541 must be removed or deactivated to avoid address conflicts.



## ATMega 328P

The Atmel ATMega 328P microcontroller monitors the data bus, controls the ROM banks, and manages the switching of operating modes. The firmware can be programmed using an Arduino board or an AV programmer. I use the XGecu T48 Universal Programmer with an .mpj project file. When programming with the XGecu and the .mpj file, make sure not to program the EEPROM as this can cause an error. This can be disabled in the XGecu menu.

- [Link](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/atmega)

<img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/XGecuT48UniversalProgrammerEEPROM.png?raw=true" alt="" data-align="center" style="zoom:25%;">

<img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/XGecuT48UniversalProgrammerConfig.png?raw=true" alt="" style="zoom:25%;" data-align="center">

## 8x Multi-Speeder RAM Diagnostic Tool

![1541 8x Multi-Floppy-Speeder 32 KB RAM Diagnostic Tool](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2b_pcb_diag_tool.jpg?raw=true)

The diagnostic tool in the `/software/` directory helps test the 32K RAM of the Multi-Floppy-Speeder. It writes and reads memory locations with $00 and $FF bytes to detect errors. The test should always be performed with Bank 0 (1@RNROM) using the original CBMDOS.

[Download here.](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/software)



## Address Decoder Mirror Issue

The 6522 VIAs of the 1541 occupy memory areas that are mirrored up to address $8000, which can conflict with the RAM expansion. This issue is resolved by modifying the A15 address line on the motherboard.



## WDC 65C02 CPU and Other CPUs

A modern WDC W65C02 CPU can be used; however, compatibility with the 1541 decreases as many fast loaders use illegal opcodes of the original MOS 6502A CPU, which are not supported by the WDC W65C02.



## Bill of Materials (BOM)

The BOM are stored in [/bom/](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/bom).



## Downloads

1. [ATF16V8 (GAL16V8) Files](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/logic)

2. [ATMEL ATMega328P Files](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/atmega)

3. [ROMs](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/rom)

4. [Gerber Files for PCB Manufacturing](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/gerber)

5. [Schematics, Documentation for 8x Multi-Speeder 32KB RAM Expansion (DolphinDos2)](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/docs)

6. [Photo Gallery](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/images)

## First Start

1. Before using the board in the disk drive for the first time, check if all components (ICs) are correctly oriented and properly inserted.

2. Inspect the board for short circuits in the power supply. Short circuits in the power supply can easily damage the Speeder and the disk drive's mainboard. Check, for example, at the poles of the 0.1 µF capacitors on the Multi-Speeder board to ensure there are **no short circuits present**.

3. Verify the board's placement in the CPU socket on the mainboard and ensure the board does not touch any contacts on the mainboard.

4. During installation, make sure the disk drive is disconnected from the power supply.

## Troubleshooting

Issues may arise during assembly. Here are some common problems that might occur and their solutions:

1. **Problem:** Upon starting the disk drive, the floppy motor runs, and the red LED remains lit.
    **Solution:** The drive fails to initialize. This is often due to contact issues with the ICs. For example, SMD ICs may not be making proper contact with the board, or pins such as the address or data bus may have short circuits at solder points (EPROM socket, RAM, ATF16V8, ATMega328). Check whether the EPROM, ATF16V8, and ATMega328 are properly programmed.

2. **Problem:** Under DolphinDos, the disk drive starts correctly but crashes during loading. The original CBMDOS (Bank 0 / 1@RNROM) works without issues.
    **Solution:** The RAM may not be functioning correctly. Inspect the solder joints on the RAM IC. Ensure DolphinDos is installed in Bank 0-3 so that the appropriate RAM area is available. Run the Multi-Speeder diagnostic tool under CBMDOS (Bank 0 / 1@RNROM) to test the RAM.

3. **Problem:** DolphinDos or SpeedDos loads at a slow speed.
    **Solution:** The parallel cable is faulty or not connected.

4. **Problem:** Switching Kernals using the DOS commands x@RNROM does not work.
    **Solution:** Check if the Kernal-ROM changes when you briefly connect the SelROM pin to GND. This allows you to manually switch between banks 0-7 (+1). Briefly connecting the RstROM pin to GND should reset to Bank 0. This is useful if the disk drive becomes unresponsive due to a faulty firmware. Bank 0 should always contain the original CBMDOS. If manual switching works, the issue may be due to contact problems with the 74HTC275N or ATMega328, as the data bus (D0-D7) might not be read correctly. If manual switching does not work, the ATMega328 may not function correctly (check the crystal or 22-pF capacitors).

5. **Problem:** The drive resets during loading, or the loading process stops and the red LED turns off.
    **Solution:** The microcontroller switches the Kernal-ROM during loading. This may occur if a ROM switch is mistakenly triggered by an incorrect x@RNROM command embedded in the disk's program code. To disable the "switchless" mode, use the DOS command:

```
OPEN 1,8,15,"I:0@RNROM":CLOSE 1  
```

or

```
@I:0@RNROM
```

When you turn the drive off and on again, the "switchless" functionality will be reactivated.

6. **Problem:** DolphinDos or SpeedDos displays garbled characters when loading the directory "$" with F7.
    **Solution:** The parallel cable connected to the user port is either too long or has a contact issue. The total length of the parallel cable should not exceed 60 cm.

7. **Problem:** The drive starts correctly at times but then crashes or the red LED blinks.
    **Solution:** Check the connections between the mainboard and the Multi-Speeder for loose or intermittent contacts.
   
   

## Shared Projects on PCBWay.com

### Commodore 1541 Switchless 8x Multi-Speeder

1. [Switchless Floppy Drive 8x Multi Floppy Speeder (THT) for the Commodore 1541 Disk Drive (V2.2c)](https://www.pcbway.com/project/shareproject/Switchless_Floppy_Drive_8x_Multi_Floppy_Speeder_for_the_Commodore_1541_Disk_Driv_369dbba4.html)

2. [Switchless Floppy Drive 8x Multi Floppy Speeder (SMD) for the Commodore 1541 Disk Drive (V2.2c)](https://www.pcbway.com/project/shareproject/Switchless_Floppy_Drive_8x_Multi_Floppy_Speeder_for_the_Commodore_1541_Disk_Driv_33eedf94.html)

3. [Parallel Cable Sets for the Commodore 1541 Disk Drive (SpeedDOS, DolphinDOS) with the C64/C128](https://www.pcbway.com/project/shareproject/C64_Userport_Adapter_Parallel_Cable_Set_for_the_Commodore_1541_Disk_Drive_Spe_3b86d1f8.html)

### Commodore 1541 Parallel Port Adapter VIA 6522

1. [1541-I/1541-II Parallel Adapter (Duo/Slim) - Parallel Cable Set for the Commodore 1541 Disk Drive (SpeedDOS, DolphinDOS) with the C64/C128](https://www.pcbway.com/project/shareproject/1541_I_1541_II_Parallel_Adapter_Duo_Slim_Parallel_Cable_Set_for_the_Commodor_57072954.html)

2. [1541-I/1541C Parallel Adapter - Parallel Cable Set for the Commodore 1541 Disk Drive (SpeedDOS, DolphinDOS) with the C64/C128](https://www.pcbway.com/project/shareproject/1541_I_1541C_Parallel_Adapter_Parallel_Cable_Set_for_the_Commodore_1541_Disk_D_a27176a6.html)

3. [C64 User Port Adapter - Parallel Cable Set for the Commodore 1541 Disk Drive (SpeedDOS, DolphinDOS) with the C64/C128](https://www.pcbway.com/project/shareproject/C64_Userport_Adapter_Parallel_Cable_Set_for_the_Commodore_1541_Disk_Drive_Spe_3b86d1f8.html)
   
   

### C128DCR Version Switchless 8x Multi-Floppy Speeder (DolphinDos 3)

1. [8x Multi-Floppy Speeder 32KB RAM Expansion for the Commodore C128DCR](https://www.pcbway.com/project/shareproject/Switchless_8x_Multi_Floppy_Speeder_with_32_KB_RAM_Expansion_for_the_Commodore_C1_557a83c8.html)

2. [C128/C64 Kernal Switcher for 8x Multi-Floppy-Speeder C128DCR](https://www.pcbway.com/project/shareproject/C128_C64_U32_Kernal_Switcher_Adapter_for_Switchless_8x_Multi_Floppy_Speeder_with_f113e895.html)

3. [Parallel Port Adapter for 8x Multi-Floppy-Speeder C128DCR](https://www.pcbway.com/project/shareproject/Parallelport_Adapter_U4_for_Switchless_8x_Multi_Floppy_Speeder_with_32_KB_RAM_Ex_558623e7.html)
   
   

## Helpful Links

1. DolphinDos: [Dolphin DOS – C64-Wiki](https://www.c64-wiki.de/wiki/Dolphin_DOS) & [https://project64.c64.org/hw/dolphindos.txt](https://project64.c64.org/hw/dolphindos.txt)

2. RAMBoard: [RAMBOard – C64-Wiki](https://www.c64-wiki.de/wiki/RAMBOard) & [https://www.c64copyprotection.com/ramboard/](https://www.c64copyprotection.com/ramboard/)
   
   

## Thanks

Many people contributed to this project, and it is the result of the efforts of many developers. I would especially like to thank the following developers:



1. **Jan Bubela and Gunther Jilg**, who developed DolphinDos.

2. **RetroNynjah**, who helped me integrate his Switchless Multi-ROM into the 8x Multi-Speeder. [GitHub - RetroNynjah/Switchless-Multi-ROM-for-27128-27256](https://github.com/RetroNynjah/Switchless-Multi-ROM-for-27128-27256)

3. **Oliver Eikemeier und Oliver Joppich**, who developed SpeedDos.

4. **silverdr**, for the helpful technical data on DolphinDos. [https://e4aws.silverdr.com/projects/dolphindos2/](https://e4aws.silverdr.com/projects/dolphindos2/)

5. **ytmytm**, for his TrackCache: [GitHub - ytmytm/1571-TrackCacheROM: A firmware patch for Commodore 1571 drive and internal C128D drive enabling RAM expansion use for track cache](https://github.com/ytmytm/1571-TrackCacheROM)

6. **Stefan Kauf**, for his support of the Multi-Speeder concept and his templates.
   
   

## Disclaimer

I have designed and tested this project with great care. However, errors can still occur. This project is a hobby project. Therefore, I do not assume any warranty for functionality or for damages caused by the installation or use of this project.



## Donations

I have spent many hours working on this project. If you would like to support this work, you can make a contribution to my coffee fund. Thank you very much! [Click here to donate via PayPal!](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=Q8HXKYARXKT4L&ssrt=1714757590172)



## Usage Rights / Copyright

You are welcome to use this project for private purposes. Commercial use, such as sales or other distribution of my Multi-Speeder, is prohibited without my permission.



I hope you enjoy my 8x Multi-Speeder 32KB RAM Expansion for the Commodore 1541 disk drive.



Best regards,  
Frank Eggen

E-Mail: [retro@emden.net](mailto:retro@emden.net)


