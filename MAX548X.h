/*
  MAX548X.h - Library for controlling the 10-bit digital POTs:
		- MAX5481 Voltage-divider 10KΩ
		- MAX5482 Voltage-divider 50KΩ
		- MAX5483 Variable Resistor 10KΩ
		- MAX5484 Variable Resistor 50KΩ
		
  Created by HS, January 11, 2020.  
*/

#include "Arduino.h"

class MAX548X{
			  public:
					 MAX548X(int CSpin);
					 void setPOT(int wiper);
					 void toNV();
					 void fromNV();
			  private:
					  int _CSpin;
					  int _wiper;
					  int _high;
					  int _low;
			  };