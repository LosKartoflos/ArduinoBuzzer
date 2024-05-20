#include <buzzerScenario.h>



bool findValueIn2dArray(long int *array, int rows, int cols, long int value, int *row, int *col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(array + i * cols + j) == value) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

bool arrayIncludeElement(long int array[], int cols, long int value, int *col) {
 for (int i = 0; i < cols; i++) {
      if (array[i] == value) {
          *col = i;
          return true;
      }
    }
  return false;
 }

int buzzerIndex, buzzerButtonIndex;

bool buzzerActive[5] ={ false, false, false, false,false};

long int buzzerAdresses[5][4] = {{6364833,6364834,6364836,6364840},
                              {16486689,16486690,16486692,16486696},
                              {7916705,7916706,7916708,7916712},
                              {11086753,11086754,11086756,11086760},
                              {11234977,11234978,11234980, 11234984}};

long int masterBuzzerAdress[4] = {15051297,15051298,15051300,15051304};                          

void activateAllBuzzers(){
  for (int i = 0; i <= (int) sizeof(buzzerActive); i++){
       activateBuzzer(i);
  }
}

void activateBuzzer(int buzzerIndex){
  if(buzzerIndex < 0 || buzzerIndex >= (int) sizeof(buzzerActive))
    {
      Serial.print("Buzzer ");
      Serial.print(buzzerIndex);
      Serial.print("is not registered");
      return;
    }

  buzzerActive[buzzerIndex] = true;
  Serial.print("Buzzer activated: ");
  Serial.println(buzzerIndex);
}

void parseBuzzer(unsigned long buzzerData){
   //int buzzerNumber[2]  = {-1;-1};

   if (findValueIn2dArray((long int *)buzzerAdresses, 5, 4, (long int) buzzerData, &buzzerIndex, &buzzerButtonIndex)) {
        //Serial.println("Wert %i gefunden an Position [%i][%lu]\n", buzzerData, buzzerIndex, buzzerButtonIndex);
        Serial.print("BuzzerIndex ");
        Serial.print(buzzerIndex);
        Serial.print(" + buzzerButtonIndex ");
        Serial.println(buzzerButtonIndex);
    } else if (arrayIncludeElement((long int *)masterBuzzerAdress,  4, (long int) buzzerData, &buzzerButtonIndex)){
        Serial.print(" Master at: ");
        Serial.println(buzzerButtonIndex);
    } else {

    }
  
}


