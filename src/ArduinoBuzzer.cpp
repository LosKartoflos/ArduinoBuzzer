#include <Arduino.h>
#include <recieveData.h>
#include <buzzerScenario.h>
// #include "avr8-stub.h"


unsigned long lastData = -1;
unsigned long receivedData = -2;

int *lastDataPtr;
 int *receivedDataptr;


void setup() {
  //  debug_init();
  //Serial.begin(9600); // Initialize serial communication
    setupRecieveData();

    // lastDataPtr = &lastData;
    // receivedDataptr = &receivedData;

}

void loop() {
  receivedData = loopRecieveData();
 
  // int data = loopRecieveData();
  if(receivedData != 0){
    //Serial.println(receivedData);
    parseBuzzer(receivedData);
  }
    
    //*receivedDataptr = loopRecieveData();
    // Serial.print ("receivedDataptr ");
    // Serial.println (receivedDataptr);
    // //  Serial.print(lastData);
    //   Serial.print(" - ");
    //  Serial.println(receivedData);
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