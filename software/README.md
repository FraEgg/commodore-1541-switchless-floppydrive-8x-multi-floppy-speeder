<img title="The Multi-Speeder Logo" src="https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/Multi-Speeder_Logo.png?raw=true" alt="Multi-Speeder Logo" style="zoom:25%;" data-align="center">

# Switchless Floppy Drive 8x Multi Floppy Speeder for the Commodore 1541 Disk Drive (V2.2c)

## 8x Multi-Speeder RAM Diagnostic Tool

![1541 8x Multi-Floppy-Speeder 32 KB RAM Diagnostic Tool](https://github.com/FraEgg/commodore-1541-switchless-floppydrive-8x-multi-floppy-speeder/blob/master/images/v2.2b_pcb_diag_tool.jpg?raw=true)

The diagnostic tool in the `/software/` directory helps test the 32K RAM of the Multi-Floppy-Speeder. It writes and reads memory locations with $00 and $FF bytes to detect errors. The test should always be performed with Bank 0 (1@RNROM) using the original CBMDOS.


