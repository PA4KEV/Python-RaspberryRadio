#include <LedControl.h>
#include <Servo.h>
  const int DATAIN_1 = 12;
  const int CS = 11;
  const int CLK = 10; 
  const int totalModules = 1;

  LedControl lc = LedControl(DATAIN_1,CLK,CS,totalModules);  
  Servo myservo;
      
void setup() {  
    myservo.attach(9);
    myservo.write(55);  //46 CC slow / 54 C slow
  
    lc.shutdown(0,false); //wake up the MAX72XX from power-saving mode
    lc.setIntensity(0,15);
}

void loop() {  
    animSnake(2);      
    animFlip(10);
    animDroplets(10);
    animChargeUp(3);
}

void animSnake(int times) {
    resetLEDs();
    for(int x = 0; x < times; x++) {
      int timer = 120;
      lc.setRow(0,1,B11000011);
      lc.setRow(0,2,B00000001);
      delay(timer);
      lc.setRow(0,2,B00000011);
      delay(timer);
      lc.setRow(0,2,B00000111);
      delay(timer);
      lc.setRow(0,2,B00001111);
      delay(timer);
      lc.setRow(0,2,B00011111);
      delay(timer);
      lc.setRow(0,2,B00111110);
      delay(timer);
      lc.setRow(0,2,B01111100);
      delay(timer);
      lc.setRow(0,2,B11111000);
      delay(timer);
      lc.setRow(0,2,B11110000);
      lc.setRow(0,3,B00000001);
      delay(timer);
      lc.setRow(0,2,B11100000);
      lc.setRow(0,3,B00000011);
      delay(timer);
      lc.setRow(0,2,B11000000);
      lc.setRow(0,3,B00000111);
      delay(timer);
      lc.setRow(0,2,B10000000);
      lc.setRow(0,3,B00001111);
      delay(timer);
      lc.setRow(0,2,B00000000);
      lc.setRow(0,3,B00011111);
      delay(timer);      
      lc.setRow(0,3,B00111110);
      delay(timer);      
      lc.setRow(0,3,B11111100);
      delay(timer);      
      lc.setRow(0,3,B11111000);
      lc.setRow(0,4,B00000001);
      delay(timer);      
      lc.setRow(0,3,B11110000);
      lc.setRow(0,4,B00000011);      
      delay(timer);      
      lc.setRow(0,3,B11100000);
      lc.setRow(0,4,B00000111);
      delay(timer);      
      lc.setRow(0,3,B11000000);
      lc.setRow(0,4,B00001111);
      delay(timer);      
      lc.setRow(0,3,B00000000);
      lc.setRow(0,4,B00011111);
      delay(timer);            
      lc.setRow(0,4,B00111110);
      delay(timer);            
      lc.setRow(0,4,B01111100);
      delay(timer);            
      lc.setRow(0,4,B11111000);
      delay(timer);            
      lc.setRow(0,4,B11110000);
      lc.setRow(0,1,B11111111);
      delay(timer);
      lc.setRow(0,4,B11100000);
      delay(timer);
      lc.setRow(0,4,B11000000);
      delay(timer);
      lc.setRow(0,4,B10000000);
      delay(timer);
      lc.setRow(0,4,B00000000);
      delay(timer*5);
      lc.setRow(0,0,B00000001);
      delay(timer);
      lc.setRow(0,0,B00000011);
      delay(timer);
      lc.setRow(0,0,B00000111);
      delay(timer);
      lc.setRow(0,0,B00001111);
      delay(timer);
      lc.setRow(0,0,B00011111);
      delay(timer);
      lc.setRow(0,0,B00111110);
      delay(timer);
      lc.setRow(0,0,B01111100);
      delay(timer);
      lc.setRow(0,0,B11111000);
      delay(timer);
      lc.setRow(0,6,B00000011);
      lc.setRow(0,0,B11110000);
      delay(timer);
      lc.setRow(0,6,B00000111);
      lc.setRow(0,0,B11100000);
      delay(timer);
      lc.setRow(0,6,B00001111);
      lc.setRow(0,0,B11000000);
      delay(timer);
      lc.setRow(0,6,B00011111);
      lc.setRow(0,0,B10000000);
      delay(timer);
      lc.setRow(0,6,B00111111);
      lc.setRow(0,0,B00000000);
      delay(timer);
      lc.setRow(0,6,B01111100);
      delay(timer);
      lc.setRow(0,6,B11111000);
      delay(timer);
      lc.setRow(0,6,B11110000);
      lc.setRow(0,7,B00000001);
      delay(timer);
      lc.setRow(0,6,B11100000);
      lc.setRow(0,7,B00000011);
      delay(timer);
      lc.setRow(0,6,B11000000);
      lc.setRow(0,7,B00000111);
      delay(timer);
      lc.setRow(0,6,B10000000);
      lc.setRow(0,7,B00001111);
      delay(timer);
      lc.setRow(0,6,B00000000);
      lc.setRow(0,7,B00011111);
      delay(timer);      
      lc.setRow(0,7,B00111110);
      delay(timer);      
      lc.setRow(0,7,B01111100);
      delay(timer);      
      lc.setRow(0,7,B11111000);
      delay(timer);      
      lc.setRow(0,7,B11110000);
      delay(timer);      
      lc.setRow(0,7,B11100000);
      delay(timer);      
      lc.setRow(0,7,B11000000);
      delay(timer);      
      lc.setRow(0,7,B10000000);
      delay(timer);      
      lc.setRow(0,7,B00000000);
      delay(timer*5);
    }
}

void animFlip(int times) {
    resetLEDs();
    for(int x = 0; x < times; x++) {
      lc.setRow(0,2,B10101010);
      lc.setRow(0,3,B10101010);
      lc.setRow(0,4,B01010101);
      lc.setRow(0,7,B10101010);
      lc.setRow(0,6,B10101010);
      lc.setRow(0,0,B01010101);
      lc.setRow(0,1,B10101010);
      delay(130);
      lc.setRow(0,2,B01010101);
      lc.setRow(0,3,B01010101);
      lc.setRow(0,4,B10101010);
      lc.setRow(0,7,B01010101);
      lc.setRow(0,6,B01010101);
      lc.setRow(0,0,B10101010);
      lc.setRow(0,1,B01010101);
      delay(130);
    }
}

/* void animRandoms() {
    resetLEDs();
    for(int x = 0; x < 400; x++) {
      int column = random(0, 8);
      int val = random(0, 257);
      lc.setRow(0,column,val); 
      delay(40);
    }
} */

void animDroplets(int times) {
    resetLEDs();
    for(int x = 0; x < times; x++) {
      int timer = 200;
      int modifier = 15;
      lc.setRow(0,1,B11111111);    
      lc.setRow(0,3,B00000000);
      lc.setRow(0,6,B00000000);
      lc.setRow(0,0,B00000001);
      lc.setRow(0,4,B10000000);
      delay(timer);
      lc.setRow(0,0,B00000011);
      lc.setRow(0,4,B11000000);
      delay(timer);
      lc.setRow(0,0,B00000111);
      lc.setRow(0,4,B11100000);
      delay(timer);
      lc.setRow(0,0,B00001111);
      lc.setRow(0,4,B11110000);
      delay(timer);
      lc.setRow(0,0,B00011111);
      lc.setRow(0,4,B11111000);
      delay(timer);
      lc.setRow(0,0,B00111111);
      lc.setRow(0,4,B11111100);
      delay(timer);
      lc.setRow(0,0,B01111111);
      lc.setRow(0,4,B11111110);
      delay(timer);
      lc.setRow(0,0,B11111111);
      lc.setRow(0,4,B11111111);
      delay(timer);
      lc.setRow(0,3,B11000000);
      lc.setRow(0,6,B00000011);
      delay(timer);
      lc.setRow(0,3,B11100000);
      lc.setRow(0,6,B00000111);
      delay(timer);
      lc.setRow(0,3,B11100000);
      lc.setRow(0,6,B00000111);
      delay(timer);
      timer -= modifier;
      lc.setRow(0,3,B11010000);
      lc.setRow(0,6,B00001011);
      delay(timer);
      timer -= modifier;
      lc.setRow(0,3,B11001000);
      lc.setRow(0,6,B00010011);
      delay(timer);
      timer -= modifier;
      lc.setRow(0,3,B11000100);
      lc.setRow(0,6,B00100011);
      delay(timer);
      timer -= modifier;
      lc.setRow(0,3,B11000010);
      lc.setRow(0,6,B01000011);
      delay(timer);
      timer -= modifier;
      lc.setRow(0,3,B11000001);
      lc.setRow(0,6,B10000011);
      delay(timer);
      timer -= modifier;
      lc.setRow(0,3,B11000000);
      lc.setRow(0,6,B00000011);
      lc.setRow(0,7,B00000001);
      lc.setRow(0,2,B10000000);    
      delay(timer);
      timer -= modifier;
      lc.setRow(0,7,B00000010);
      lc.setRow(0,2,B01000000);    
      delay(timer);
      timer -= modifier;
      lc.setRow(0,7,B00000100);
      lc.setRow(0,2,B00100000);    
      delay(timer);
      timer -= modifier;
      lc.setRow(0,7,B00001000);
      lc.setRow(0,2,B00010000);    
      delay(timer);
      timer -= modifier;
      lc.setRow(0,7,B00010000);
      lc.setRow(0,2,B00001000);    
      delay(timer);
      timer -= modifier;
      lc.setRow(0,7,B00100000);
      lc.setRow(0,2,B00000100);    
      delay(timer);
      timer -= modifier;
      lc.setRow(0,7,B01000000);
      lc.setRow(0,2,B00000010);    
      delay(timer);
      timer -= modifier;
      lc.setRow(0,7,B10000000);
      lc.setRow(0,2,B00000001);    
      delay(timer);
      timer += 15;
      lc.setRow(0,7,B01000000);
      lc.setRow(0,2,B00000010);
      delay(timer);    
      lc.setRow(0,7,B10000000);
      lc.setRow(0,2,B00000001);
      delay(timer);    
      lc.setRow(0,7,B00000000);
      lc.setRow(0,2,B00000000);
      delay(50);
      lc.setRow(0,1,B00111100);
      delay(50);
      lc.setRow(0,1,B11111111);
      delay(50);
      lc.setRow(0,1,B00111100);
      delay(50);
      lc.setRow(0,1,B11111111);
      delay(50);
      lc.setRow(0,1,B00111100);
      delay(50);
      lc.setRow(0,1,B11111111);
      delay(50);
      lc.setRow(0,1,B00111100);
      delay(50);
      lc.setRow(0,1,B11111111);
      delay(50);
      lc.setRow(0,1,B00111100);
      delay(50);
      lc.setRow(0,1,B11111111);
      delay(50);
      lc.setRow(0,1,B00111100);
      delay(50);
      lc.setRow(0,1,B11111111);
      delay(50);
      lc.setRow(0,1,B00111100);
      delay(50);
      lc.setRow(0,1,B11111111);
      delay(700);
    }
}
    
void animChargeUp(int times) {
    resetLEDs();
    for(int x = 0; x < times; x++) {
      int timer = 50; 
      lc.setRow(0,1,B11000011);
      delay(timer);
      lc.setRow(0,2,B00000001);
      lc.setRow(0,7,B10000000);
      lc.setRow(0,1,B00000000);
      delay(timer);    
      lc.setRow(0,2,B00000010);
      lc.setRow(0,7,B01000000);    
      delay(timer);
      lc.setRow(0,2,B00000100);
      lc.setRow(0,7,B00100000);
      delay(timer);
      lc.setRow(0,2,B00001000);
      lc.setRow(0,7,B00010000);
      delay(timer);
      lc.setRow(0,2,B00010000);
      lc.setRow(0,7,B00001000);
      delay(timer);
      lc.setRow(0,2,B00100000);
      lc.setRow(0,7,B00000100);
      delay(timer);
      lc.setRow(0,2,B01000000);
      lc.setRow(0,7,B00000010);
      delay(timer);
      lc.setRow(0,2,B10000000);
      lc.setRow(0,7,B00000001);
      delay(timer);
      lc.setRow(0,2,B00000000);
      lc.setRow(0,7,B00000000);
      lc.setRow(0,3,B00000001);
      lc.setRow(0,6,B10000000);
      delay(timer);
      lc.setRow(0,3,B00000010);
      lc.setRow(0,6,B01000000);
      delay(timer);
      lc.setRow(0,3,B00000100);
      lc.setRow(0,6,B00100000);
      delay(timer);
      lc.setRow(0,3,B00001000);
      lc.setRow(0,6,B00010000);
      delay(timer);
      lc.setRow(0,3,B00010000);
      lc.setRow(0,6,B00001000);
      delay(timer);
      lc.setRow(0,3,B00100000);
      lc.setRow(0,6,B00000100);
      delay(timer);
      lc.setRow(0,3,B11000000);
      lc.setRow(0,6,B00000011);
      delay(timer);
      lc.setRow(0,3,B00000000);
      lc.setRow(0,6,B00000000);
      lc.setRow(0,4,B00000001);
      lc.setRow(0,0,B10000000);
      delay(timer);
      lc.setRow(0,4,B00000010);
      lc.setRow(0,0,B01000000);
      delay(timer);
      lc.setRow(0,4,B00000100);
      lc.setRow(0,0,B00100000);
      delay(timer);
      lc.setRow(0,4,B00001000);
      lc.setRow(0,0,B00010000);
      delay(timer);
      lc.setRow(0,4,B00010000);
      lc.setRow(0,0,B00001000);
      delay(timer);
      lc.setRow(0,4,B00100000);
      lc.setRow(0,0,B00000100);
      delay(timer);
      lc.setRow(0,4,B01000000);
      lc.setRow(0,0,B00000010);
      delay(timer);
      lc.setRow(0,4,B10000000);
      lc.setRow(0,0,B00000001);
      delay(timer);
      lc.setRow(0,4,B00000000);    
      lc.setRow(0,0,B00000000); 
      delay(timer);
      lc.setRow(0,1,B00111100);  
      delay(timer);
      lc.setRow(0,1,B00000000);  
      delay(timer);
    }
}

void resetLEDs() {
  for(int x = 0; x < 8; x++) {      
      lc.setRow(0,x,0);
  }
}

