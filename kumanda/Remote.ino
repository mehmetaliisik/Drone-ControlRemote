//RampBreakers Transmiitter Code

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[13] = "rampBreakers";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
 int remoteValue[4];
 remoteValue[0] = analogRead(A0); // gas
 remoteValue[1] = analogRead(A1); // yaw
 remoteValue[2] = analogRead(A2); // roll
 remoteValue[3] = analogRead(A3); // pitch
 radio.write(remoteValue, sizeof(remoteValue));
}
