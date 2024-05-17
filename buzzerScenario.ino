bool buzzerActive[4] ={ false, false, false, false};

int buzzerAdresses[5][4] = {{15051297,15051298,15051300,15051304},
                              {6364833,6364834,6364836,6364840},
                              {16486689,16486690,16486692,16486696},
                              {7916705,7916706,7916708,7916712}};


void activateAllBuzzers(){
  
}

void activateBuzzer(int buzzerIndex){
  if(buzzerIndex < 0 || buzzerIndex >= sizeof(buzzerActive))
    {
      Serial.print("Buzzer ");
      erial.print(buzzerIndex);
      Serial.print("is not registered");
      return;
    }

  buzzerActive[buzzerIndex] = true;
}
