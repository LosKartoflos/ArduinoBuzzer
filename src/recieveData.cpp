#include <recieveData.h>

RCSwitch mySwitch = RCSwitch();
int lastMessat = 0;

void setupRecieveData() {
  Serial.begin(9600); // Initialize serial communication
  mySwitch.enableReceive(0); // Receiver on interrupt 0 => that is pin #2
}


 int loopRecieveData() {
  if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue(); // Get the received value
    if (value == 0) {
      Serial.println("Unknown encoding");
    } else {
      Serial.print("Received from Buzzer ");
      Serial.println( mySwitch.getReceivedValue() ); // Print the received value
      // Serial.print(" / ");
      // Serial.print( mySwitch.getReceivedBitlength() ); // Print the number of bits received
      // Serial.print("bit ");
      // Serial.print("Protocol: ");
      // Serial.println( mySwitch.getReceivedProtocol() ); // Print the protocol
      
    }
    mySwitch.resetAvailable(); // Reset the received value to receive the next one
    return ( int)mySwitch.getReceivedValue() ;
  }
}
