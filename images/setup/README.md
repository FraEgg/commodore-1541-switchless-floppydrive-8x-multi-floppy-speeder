<img title="The Multi-Speeder Logo" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/Multi-Speeder_Logo.png?raw=true" alt="Multi-Speeder Logo" style="zoom:25%;" data-align="center">

# Switchless Floppy Drive 8x Multi Floppy Speeder for the Commodore 1541 Disk Drive (V2.2c)



<img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/MS_SMD.jpg?raw=true" alt="" data-align="inline" style="zoom:10%;"><img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/MS_DIP.jpg?raw=true" alt="" data-align="inline" style="zoom:13%;">

On the left the 8x Multi-Speeder in the SMD and on the right in the THT version.

## Setup

<img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup0_1541-II.jpg?raw=true" alt="" style="zoom:15%;" data-align="inline">

Assembly using the example of a 1541 II.



### Setup 1

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup1_PCB_Setup.jpg?raw=true" title="" alt="" style="zoom:15%;">

Positioning of the circuit board.

### Setup 2

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup2_PCB_Soldering.jpg?raw=true" title="" alt="" style="zoom:15%;">

Soldering the components. For me it has proven to be a good idea to solder the SMD components first and then the PIN header for the CPU socket, then the CPU socket, then the capacitors, resistors, buttons and PIN connections for LEDs etc.

### Setup 3

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup3_HeaderPIN.jpg?raw=true" title="" alt="" style="zoom:15%;">

The PIN headers connect the board via the CPU socket. Please remember that the mainboard of the 1541 must first be fitted with a socket. Likewise the VIA 6522 next to the CPU. If the SMD board is to be operated in a 1541 II, then I solder the CPU directly onto the multi-speeder board, as otherwise the drive mechanics will no longer fit via the multi-speeder.

### Setup 4

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup3_HeaderPIN.jpg?raw=true" title="" alt="" style="zoom:15%;">

The PIN headers connect the board via the CPU socket. Please remember that the mainboard of the 1541 must first be fitted with a socket. Likewise the VIA 6522 next to the CPU. If the SMD board is to be operated in a 1541 II, then I solder the CPU directly onto the multi-speeder board, as otherwise the drive mechanics will no longer fit via the multi-speeder.

### Setup 5 (1541-I)

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup6_HeaderPIN.jpg?raw=true" title="" alt="" style="zoom:15%;">

If the board is to be used in a 1541-I, I add a socket to the PIN header. This way, the board is slightly higher in the 1541-I and does not touch any other components on the mainboard. However, this is not absolutely necessary if you check the distances between the multi-speeder board and the mainboard.

### Setup 6

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup7_TOP_THT.jpg?raw=true" title="" alt="" style="zoom:15%;"><img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup8_TOP_SMD.jpg?raw=true" title="" alt="" style="zoom:15%;">

The ready-soldered boards 8x Multi-Speeder 32KB as THT and SMD version.



### Setup 7

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup9_1541-II-PCB.jpg?raw=true" title="" alt="" style="zoom:15%;">

In the 1541-II and 1541-I, all ROMs for the firmware/kernals must be removed. The 1541-II has one ROM, the 1541-I has two ROMs. The firmware/ROMs are provided by the Multi-Speeder for the 1541. If the original ROMs are not removed, the floppy disk drive will not start correctly (RED LED lights up or flashes continuously).

### Setup 8 (1541-II)

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup17_Para_6522.jpg?raw=true" title="" alt="" style="zoom:15%;">

**Only with the 1541-II** the PIN 1-2 must be disconnected. PIN 1 (GND) connects PIN 2 (PA0) to GND. However, PIN 2 is required for parallel data transmission and must therefore not be permanently set to GND. Therefore, the bridge between PIN1 and PIN2 on the mainboard (rear) must be disconnected from U6! This procedure is only required for the 1541-II or 1541C. This step is not necessary for the 1541-I.

### Setup 9

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup10_1541-II-PCB.jpg?raw=true" title="" alt="" style="zoom:15%;">

This is what the correctly prepared mainboard of the 1541-II looks like for the installation of the multi-speeder board. Sockets are installed instead of the 6502 CPU and the VIA 6522. The ROM(s) have been removed.



### Setup 10

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup11_Para.jpg?raw=true" title="" alt="" style="zoom:15%;"><img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup12_Para.jpg?raw=true" title="" alt="" style="zoom:15%;"><img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup13_Para.jpg?raw=true" title="" alt="" style="zoom:15%;"><img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup14_Para.jpg?raw=true" title="" alt="" style="zoom:15%;">

I soldered the adapter board with Gold Round Female Male PINs. Alternatively, you can also use the Round PINs from sockets and use them with the adapter board.  

### Setup 11

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup16_Para.jpg?raw=true" title="" alt="" style="zoom:15%;"><img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup15_Para.jpg?raw=true" title="" alt="" style="zoom:15%;">

For the parallel cable I use a Micromatch 2.54mm Pitch Double Row Female IDC Box Header Connector.

### Setup 12

<img title="" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/XGecuT48UniversalProgrammerEEPROM.png?raw=true" alt="" style="zoom:25%;">

To ensure the 8x Multi-Speeder 32KB operates correctly, the 27C040/29F040 EPROM, ATF16v8 PLD, and the ATMega328 must be programmed. I use the T48Pro EPROM Programmer with the Xgpro Windows software for all three components.



#### EPROM 27C040/29F040 PLCC32

The 8x Multi-Speeder requires a 4Mb (512K x 8) EPROM in the PLCC32 form factor for the firmware/Kernals of the 1541 disk drive. I use 27C040 or 29F040 PLCC32 EPROMs. It is important to ensure the appropriate solder bridge (on the back) is closed for the correct EPROM type, as these EPROM types differ slightly in their pinout.



More information can be found on the project's GitHub page. 



The example firmware can be downloaded from [/rom/1541](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/rom/1541).



#### ATF16V8 PLD

ATF16V8 is a high-performance CMOS Electrically-Erasable Programmable Logic Device. This component controls the address logic of the EPROM and RAM for the 8x Multi-Speeder. I use ATF16V8B(QL) types in DIP (THT) or SOIC (SMD) form factors.



The firmware file `ATF16V8_Logic_Vx_xx.jed` can be downloaded from [/logic/](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/logic).



#### ATMega328

The ATMega328 is an advanced virtual RISC microcontroller. This microcontroller monitors the 6502 CPU data bus of the 1541 disk drive and switches the appropriate ROM bank when it detects the corresponding command on the data bus. The microcontroller can operate with a 16MHz or 20MHz crystal. I typically use a 20MHz crystal, as it ensures very reliable detection for switching.



The firmware for the ATMega328 can be downloaded from [/atmega/](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/tree/master/logic).



**Note**: When using the T48Pro EPROM Programmer software Xgpro, I use the project file `Firmware_ATMega328P_vx.xx.mpj`. This file contains the correct configuration for the ATMega328. When flashing, make sure not to write to the EEPROM. Since there is no data stored in the EEPROM, attempting to write it may result in an error during flashing.



### Setup 13

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup21_1541-I-PCB.jpg?raw=true" title="" alt="" style="zoom:15%;">

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup22_1541-I-PCB.jpg?raw=true" title="" alt="" style="zoom:15%;">

<img src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/setup/Setup20_1541-II-PCB.jpg?raw=true" title="" alt="" style="zoom:15%;">

Installation of the 8x Multi-Speeder 32KB with parallel adapter in the 1541-I and 1541-II.

## Disclaimer

I have designed and tested this project with great care, but errors can always happen. This project is a hobby project. Therefore, I do not guarantee its functionality or take responsibility for any potential damage caused by the installation or use of this project in any way.


