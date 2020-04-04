// This example demonstrate the use of MAX5482 10bit POT chip

#include <MAX548X.h>

MAX548X MAX5482(7);   // To include the chip select pin

void setup(){                        
             Serial.begin(9600);  // Start the serial communication channel at 9600 bps                         
             }
              
void loop(){                          
            if(Serial.available()>0){
                                        int buff = (Serial.readString()).toInt();
                                        if(buff>1023){buff=1023;}                         // POT range should be 0 - 1023    
                                        if(buff<0){buff=0;}                               // POT range should be 0 - 1023                                            
                                        MAX5482.setPOT(buff);                              // Set the POT position according to the new value                                        
                                        }
            }
