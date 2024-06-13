#ifndef LCDCONTROLLER_H
#define LCDCONTROLLER_H

#include <Arduino.h>
#include <ArduinoBuzzer.h>
#include <buzzerScenario.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

void buzzeredSuccessfull();

void setupLCDController();
void loopLCDController();
void resetDisplay();
void displayTeamAnswer(int teamID, int answer);
void displayTeamAnswerQuiz(int teamID, int answer);
void displayTeamAnswerFirstComeFirstServe(int teamID, int answer);

String returnAnswerLetter(int i);

bool checkIfTeamHasAlreadyBuzzerd(int teamID);
bool checkIfTeamIsValid(int teamID);
bool checkIfAnswerInRange(int answer);
#endif