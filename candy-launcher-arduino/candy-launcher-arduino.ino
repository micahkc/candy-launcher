#include <Servo.h>
Servo catapult;
Servo load;
int c;
String input ="";
bool fire;
void setup() {
  Serial.begin(9600);
  catapult.attach(9);
  load.attach(10);
  load.write(90);
  catapult.write(90);
}


void loop() {
  while (Serial.available()) {
    c = Serial.read();
    if(c == 'F'){
      fire=true;
    }
  }
  if (fire){
    catapult.write(20);
    delay(1000);
    load.write(40);
    delay(1000);
    load.write(90);
    delay(1000);
    catapult.write(0);
    delay(2000);
    catapult.write(90);
    fire = false;
  }
}
