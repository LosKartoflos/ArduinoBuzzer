#include <buzzerScenario.h>



bool findValue(long int *array, int rows, int cols, long int value, int *row, int *col) {
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


int buzzerIndex, buzzerButtonIndex;



bool buzzerActive[5] ={ false, false, false, false,false};

long int buzzerAdresses[5][4] = {{6364833,6364834,6364836,6364840},
                              {16486689,16486690,16486692,16486696},
                              {7916705,7916706,7916708,7916712},
                              {1086753,11086754,11086756,11086760},
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




void parseBuzzer(long int buzzerData){
   //int buzzerNumber[2]  = {-1;-1};

   if (findValue((long int *)buzzerAdresses, 5, 4, buzzerData, &buzzerIndex, &buzzerButtonIndex)) {
        printf("Wert %ld gefunden an Position [%d][%d]\n", buzzerData, buzzerIndex, buzzerButtonIndex);
    } else {
        printf("Wert %ld nicht im Array gefunden\n", buzzerData);
    }
  
}


