/*
#########################################################################################
#                                                                                       #
#  ROM switcher sketch for CBM disk drives                                              #
#  To be used with Switchless Floppy Drive 8x Multi Floppy Speeder for the Commodore    #
#  1541 Disk Drive by Frank Eggen                                                       #
#  Code by Per Bengtsson (https://github.com/RetroNynjah                                #
#                                                                                       #
#  Version 1.0a                                                                         #
#  https://github.com/FraEgg                                                            #
#                                                                                       #
#########################################################################################
*/

#include <EEPROM.h>

// searchString is the command that is used for switching ROM.
// It is passed by the 1541-II in reverse order so the variable should be reversed too.
// The command should be preceded by a ROM number between 1 and <romCount> when used.
// The below reversed searchString in hex ascii is MORNR@ which is specified like this on the C64: 1@RNROM, 2@RNROM and so on.
byte searchString[] = {0x4D,0x4F,0x52,0x4E,0x52,0x40};
int romCount = 8;


// pin defitions
int resetPin = 11;
int clockPin = 13;
int ledPin = A0;
int rstRomPin = A4; //PC4
int selRomPin = A5; //PC5

int commandLength = sizeof(searchString);
int bytesCorrect = 0;
int tempOFF = 0;
volatile bool state;
static byte byteCurr;
static byte switchPins;

void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}


ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{    
       // read state of pin 13
       state = PINB & B00100000;
}
 

void cleareeprom(){
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
}


void resetdrive(){

  digitalWrite(resetPin, LOW);
  pinMode(resetPin, OUTPUT);
  delay(50);
  digitalWrite(resetPin, HIGH);
  pinMode(resetPin, INPUT);

}


void switchrom(int romnumber){

  // blink romnumber of times
  for (int x = 0; x <= romnumber; x++){
    digitalWrite (ledPin, LOW);
    delay(30);
    digitalWrite (ledPin, HIGH);
    delay(250);
  }
  delay (200);
  
  // roll over to zero if rom number is too high
  
  if ((romnumber == -1) && (tempOFF ==0)){
    tempOFF = 1;
    int lastROM = EEPROM.read(0);
    romnumber = lastROM;
  }

  if (romnumber >= romCount){
    romnumber = 0;
  }

  // switch eprompin A16 (D8/PB0)
  if (romnumber & B01){
    digitalWrite(8 , HIGH);
  }  
  else {
    digitalWrite(8 , LOW);
  }

  // switch eprompin A17 (D9/PB1)
  if (romnumber & B10){
    digitalWrite(9 , HIGH);
  }  
  else {
    digitalWrite(9 , LOW);
  }

  // switch eprompin A18 (D10/PB2)
  if (romnumber & B100){
    digitalWrite(10 , HIGH);
  }  
  else {
    digitalWrite(10 , LOW);
  }

  int savedROM = EEPROM.read(0);
  if (savedROM != romnumber){
    EEPROM.write(0, romnumber);
  }
  resetdrive();
}


void setup() {

  // set data pins as inputs
  DDRD = B00000000;
  
  pinMode(13, INPUT); // clock pin
  pinMode(8, OUTPUT); // eprom A16
  pinMode(9, OUTPUT); // eprom A17
  pinMode(10, OUTPUT); // eprom A18

  pinMode(clockPin, INPUT); // R/!W
  pinMode(resetPin, INPUT); // Keep reset pin as input while not performing reset.

  pinMode (ledPin, OUTPUT);

  pinMode(rstRomPin, INPUT_PULLUP); // Reset ROM button
  pinMode(selRomPin, INPUT_PULLUP); // Select ROM button

  // retrieve last used ROM from ATmega EEPROM and switch ROM using A14/A15
  int lastROM = EEPROM.read(0);
  if (lastROM >= romCount){
    cleareeprom();
    lastROM = 0;
  }
  switchrom(lastROM);
  
  // enable pin change interrupt on pin D13(PB5) connected to R/W on 6502
  pciSetup(clockPin); 
}


void loop() {
  if (state == HIGH){
    byteCurr = PIND;
    state=LOW;
      
    // we don't have full search string yet. check if current byte is what we are looking for
    if (byteCurr == searchString[bytesCorrect]){
      // It is the byte we're waiting for. increase byte counter
      bytesCorrect++;
	    if (bytesCorrect == commandLength){
        // we have our full search string. wait for next byte
		    while(state == LOW){}
    		byteCurr = PIND;
    		// This byte should be the ROM number
    		// valid numbers are 0-8 (ASCII 48-56)
    		if ((byteCurr >= 48)&&(byteCurr<=56)&&(tempOFF==0)){
              // rom number within valid range. Switch rom
              switchrom(byteCurr-49);
    		}
    		else if(byteCurr == searchString[0]){
              // it was the first byte in string, starting with new string
              bytesCorrect = 1;
    		}
        else{
          bytesCorrect = 0;
        }
  	  }
    }
    // byte isn't what we are looking for, is it the first byte in the string then?
    else if(byteCurr == searchString[0]){
        // it was the first byte in string, starting with new string
        bytesCorrect = 1;
    }
    else {
      // command byte not correct at all. Start over from the beginning
      bytesCorrect = 0;
    }
    // end clock state == HIGH
  }
  else {
    // clock state == LOW, do non-command related things
    switchPins = PINC;
    if(!(switchPins & B00010000)){
      //RSTROM (PC4) LOW
      switchrom(0);
    }
    else if(!(switchPins & B00100000)){
      //SELROM (PC5) LOW
      int lastROM = EEPROM.read(0);
      lastROM++;
      // roll-over if romCount reached
      if (lastROM >= romCount){
        lastROM = 0;
      }
      switchrom(lastROM);
    }
  }
}
