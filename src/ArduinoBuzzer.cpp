#include <Arduino.h>
#include <recieveData.h>
#include <buzzerScenario.h>
#include "avr8-stub.h"

int lastData = -1;
 int receivedData = -2;

int *lastDataPtr;
 int *receivedDataptr;


void setup() {
   debug_init();
  //Serial.begin(9600); // Initialize serial communication
    setupRecieveData();

    lastDataPtr = &lastData;
    receivedDataptr = &receivedData;

}

void loop() {
  int data = loopRecieveData();
  if(data != 0){
    Serial.println(data);
  }
    
    // *receivedDataptr = loopRecieveData();
    // //  Serial.print(lastData);
    // //   Serial.print(" - ");
    // //  Serial.println(receivedData);
    // if(*receivedDataptr != *lastDataPtr && *receivedDataptr != 0)
    // {
    //     Serial.print("Buzzer Data ");
    //     Serial.println(*receivedDataptr);
    //     *lastDataPtr = *receivedDataptr;
    // }
  // if(0 != receivedData){
  //       parseBuzzer(receivedData);
  //   }
    
}