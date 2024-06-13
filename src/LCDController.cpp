/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
#include <LCDController.h> 

unsigned long startTime;
const unsigned long desiredinterval = 200;
bool needABeep = false;
bool isBeeping = false;

int Buzzer = 4;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int buzzersPressedCounter = 0;

int possibleAnswers = 4;

bool buzzerPressed[5] =  {false,false,false, false, false};

void setupLCDController()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  pinMode(Buzzer, OUTPUT);
  
  // lcd.setCursor(0,1);
  // lcd.print("test");

}

void loopLCDController()
{
  if(needABeep){
      digitalWrite(Buzzer, HIGH);

      needABeep = false;
      isBeeping = true;
      startTime =millis();
  }
   
  if(isBeeping && millis() - startTime >desiredinterval){
    isBeeping = false;
    digitalWrite(Buzzer, LOW);
  }

  
}

void buzzeredSuccessfull(){

}

void resetDisplay(){
  
for(int i=0; i < (int) sizeof(buzzerPressed); i++){
  buzzerPressed[i] = false;
}

  buzzersPressedCounter = 0;

  lcd.clear();
  if(getBuzzerMode() == 0){
        lcd.setCursor(0,1);
        lcd.print("Quiz");
    }
    else if(getBuzzerMode() == 1){
        lcd.setCursor(0,1);
        lcd.print("Speed Mode");
    }
}

void displayTeamAnswer(int teamID, int answer){

   if(checkIfTeamHasAlreadyBuzzerd(teamID)){
    return NULL;
  }

  digitalWrite(Buzzer, LOW);
  needABeep =true;

    if(getBuzzerMode() == 0){
        displayTeamAnswerQuiz(teamID, answer);
    }
    else if(getBuzzerMode() == 1){
        displayTeamAnswerFirstComeFirstServe(teamID, answer);
    }

}

void displayTeamAnswerQuiz(int teamID, int answer){

     


  Serial.println (teamID);
    
  int cursorPos = teamID*3;

  lcd.setCursor(cursorPos,0);
  lcd.print(teamID+1);
  lcd.setCursor(cursorPos+1,0);
  lcd.print(returnAnswerLetter(answer));


  //count up the teams and bnlock the team;
  buzzerPressed [teamID] = true;
  buzzersPressedCounter++;
}

void displayTeamAnswerFirstComeFirstServe(int teamID, int answer){

  
  // if(!checkIfTeamIsValid(teamID)){
  //   return NULL;
  // }
  //   if(!checkIfAnswerInRange(answer)){
  //   return NULL;
  // }
    if(checkIfTeamHasAlreadyBuzzerd(teamID)){
    return NULL;
  }

  Serial.println (teamID);
    
  int cursorPos = buzzersPressedCounter*3;

  lcd.setCursor(cursorPos,0);
  lcd.print(teamID+1);
  lcd.setCursor(cursorPos+1,0);
  lcd.print(returnAnswerLetter(answer));


  //count up the teams and bnlock the team;
  buzzerPressed [teamID] = true;
  buzzersPressedCounter++;

}


String returnAnswerLetter(int i){
  // }
  //   if(!checkIfAnswerInRange(answer)){
  //   return NULL;
  // }

  switch (i)
  {
  case 0:
    return "A";
    break;

    case 1:
    return "B";
    break;

    case 2:
    return "C";
    break;

    case 3:
    return "D";
    break;
  
  default:
  return "x";
    break;
  }
}

bool checkIfTeamHasAlreadyBuzzerd(int teamID){
  // if(!checkIfTeamIsValid(teamID)){
  //     return false;
  // }
  Serial.print(teamID);
  
  return buzzerPressed [teamID];
}

bool checkIfTeamIsValid(int teamID){
  if(teamID >=(int)( sizeof(buzzerPressed)))
    {
      Serial.print(teamID);
      Serial.println("team id out if range");

      return false;
    }
    else
    {
      return true;
    }
}

bool checkIfAnswerInRange(int answer){
     if(answer >= possibleAnswers)
    {
      Serial.print(answer);
      Serial.println(" answer is out of range");

      return false;
    }

    else {
      return true;
    }
}