#ifndef BUZZERSCENARIO_H
#define BUZZERSCENARIO_H

#include <Arduino.h>
// #include "avr8-stub.h"
#include <HardwareSerial.h>
#include <LCDController.h>


void activateBuzzer(int buzzerIndex);
void activateAllBuzzers();
//void parseBuzzer(long int buzzerData));
void parseBuzzer(unsigned long buzzerData);
bool findValueIn2dArray(long int *array, int rows, int cols, long int value, int *row, int *col);
int getBuzzerMode();
bool setBuzzerMode(int mode);

#endif