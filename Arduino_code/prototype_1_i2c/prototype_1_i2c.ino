#include <Wire.h>
#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

double temp;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);  
}

void loop() {
  delay(100);    
}

// callback for received data
void receiveData(int byteCount) {
  while(Wire.available()) {
    number = Wire.read();
    Serial.print("Data received: ");
    Serial.println(number);
  }
}

// callback for sending data
void sendData(){
  Wire.write(number);
}
