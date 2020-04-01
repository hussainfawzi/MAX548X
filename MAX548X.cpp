/*
  MAX548X.h - Library for controlling the 10-bit digital POTs:
		- MAX5481 Voltage-divider 10KΩ
		- MAX5482 Voltage-divider 50KΩ
		- MAX5483 Variable Resistor 10KΩ
		- MAX5484 Variable Resistor 50KΩ
		
  Created by HS, January 11, 2020.  
*/

#include "Arduino.h"
#include "MAX548X.h"
#include <SPI.h>

MAX548X::MAX548X(int CSpin){
							 pinMode(CSpin, OUTPUT);
							 _CSpin = CSpin;
							 SPI.begin();
							 }

void MAX548X::setPOT(int wiper){
								_high = wiper >> 2;
                                _low = wiper << 6;
								digitalWrite(_CSpin, LOW);
								SPI.transfer(0b00000000);
                                SPI.transfer(_high);
                                SPI.transfer(_low);
								digitalWrite(_CSpin, HIGH);
								}

void MAX548X::toNV(){
					 digitalWrite(_CSpin, LOW);
					 SPI.transfer(0b00100000);
					 digitalWrite(_CSpin, HIGH);
					 }
					 
void MAX548X::fromNV(){
					   digitalWrite(_CSpin, LOW);
					   SPI.transfer(0b00110000);
					   digitalWrite(_CSpin, HIGH);
					   }					 