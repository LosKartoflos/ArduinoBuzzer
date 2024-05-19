#ifndef BUZZERSCENARIO_H
#define BUZZERSCENARIO_H

#include <Arduino.h>
#include "avr8-stub.h"
#include <HardwareSerial.h>


void activateBuzzer(int buzzerIndex);
void activateAllBuzzers();
//void parseBuzzer(long int buzzerData));
void parseBuzzer(long int buzzerData);
bool findValue(long int *array, int rows, int cols, long int value, int *row, int *col);

#endif