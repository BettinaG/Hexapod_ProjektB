#include <Setup.h>

void setup() {
  Serial.begin(9600);                                     // Setting up Serial communication
  
  pwm.begin();
  pwm.setPWMFreq(60);
  delay(10);

  innerServo4.attach(10);                                 // Connecting Servo Number 4 to the Digital Pin Number 10 on the Arduino 
  innerServo5.attach(11);                                 // Connection Servo Number 5 to the Digital Pin Number 11 on the Arduino
  delay(10);
  
  
  c = ' ';
  order = 'r';                                            // Setting the current order to 'reset'
  //Startpositionen
  for(int i = 0; i < ELEMENTS; i++){                      // Setting the starposition for each servo motor
      degsBot[i] = 70;                                    // 70° for all the Bottom Motors
      lastDegBot[i] = degsBot[i];
      pulse = setPulse(degsBot[i]);
      pwm.setPWM(BOTTOM_MOTORS + i, 0, pulse);
      
      degsTop[i] = 120;                                   // 120° for all the Top Motors
      lastDegTop[i] = degsTop[i];
      pulse = setPulse(degsTop[i]);
      pwm.setPWM(TOP_MOTORS + i, 0, pulse);
      
      degsIn[i] = 40;                                     // 40° for all the Inner Motors
      lastDegIn[i] = degsIn[i];
      pulse = setPulse(degsIn[i]);
      if(i < 4){
          pwm.setPWM(INNER_MOTORS + i, 0, pulse);
      } else if(i == 4){
          innerServo4.write(degsIn[i]);
      } else if(i == 5){
          innerServo5.write(degsIn[i]);
      }
      
      delay(500);    
  }

  Serial.println("Press f to start walking forwards, b for walking backwards and r to go stop");      // Print out initial instruction 
}

void loop() {  
  if (Serial.available()) {    // is a character available?               
    input = Serial.read();       // get the character
  
    if (input == 'U' || input == 'D' || input == 'u' || input == 'd' || input == 'V') {

    } else {
        Serial.println("Ungueltiger Befehl");
    }
  }
  
  if      (input == 'u' || input == 'd' || input == 'l' || input == 'r' || input == 'v' || input == 'w' || input == 'W')  resetPosition();
  else if (input == 'U') walkForwards();
  else if (input == 'D') walkBackwards();
  else if (input == 'L') walkLeft();
  else if (input == 'R') walkRight();
  else if (input == 'V') dance();
  else if (input == 'S' || input == 's') goToSleep();
  else if (input == 'W') resetPosition();
}


/*
 *  Converts the entered degree to pulse
 */
int setPulse(int degree){
  int newPulse = map(degree, 0,180,SERVOMIN,SERVOMAX);
  return newPulse;
}
