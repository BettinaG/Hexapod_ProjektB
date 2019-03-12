/*
 * This file contains all the fundctions to set the Servos to a certain position
 *    resetPosition()
 *    moveLegsUp(int odd_even)
 *    moveLegsDown(int odd_even)
 *    moveEvenLegsForward()
 *    moveOddLegsForward()
 *    moveEvenLegsBackward()
 *    moveoddLegsBackward()
 *    
 *    setLastDegrees()
 *    
 */


/*
 *  Moves all servos back to their neutral positions
 */
void resetPosition(){
  setLastDegrees();

  for(int i = 0; i < ELEMENTS; i++){
      degsBot[i] = 60;
      degsTop[i] = 120;
      degsIn[i] = 40;          
  }

  moveServos();
}

/*
 *  Lifts either the odd or the even numbered legs up
 *  0 == even, 1 == odd
 */
void moveLegsUp(int odd_even){
    setLastDegrees();
  
    for(int i = odd_even; i < ELEMENTS; i+=2){
        degsTop[i] = 30;
    }
    
    for(int i = lastDegTop[odd_even]; i > degsTop[odd_even]; i--){  
        pulse = setPulse(i);
        pwm.setPWM(TOP_MOTORS + odd_even    , 0, pulse);
        pwm.setPWM(TOP_MOTORS + odd_even + 2, 0, pulse);
        pwm.setPWM(TOP_MOTORS + odd_even + 4, 0, pulse);
        delay(5);
    } 
}

/*
 * Puts either the odd or the even numbered legs down
 * 0 == even, 1 == odd
 */
void moveLegsDown(int odd_even){
    setLastDegrees();

    for(int i = odd_even; i < ELEMENTS; i+=2){
        degsTop[i] = 120;
    }

    for(int i = lastDegTop[odd_even]; i < degsTop[odd_even]; i++){  
        pulse = setPulse(i);
        pwm.setPWM(TOP_MOTORS + odd_even    , 0, pulse);
        pwm.setPWM(TOP_MOTORS + odd_even + 2, 0, pulse);
        pwm.setPWM(TOP_MOTORS + odd_even + 4, 0, pulse);
        delay(5);
    }      
}

/*
 * moves all the even numbered legs to a forward position
 */
void moveEvenLegsForwards(){
    setLastDegrees();
    
     degsIn[0] = 50;
    degsBot[0] = 30;
      
     degsIn[2] = 20;
    degsBot[2] = 90;
        
     degsIn[4] = 20;

     moveServos();
}

/*
 *  moves all the odd numbered legs to a forward position
 */
void moveOddLegsForwards(){
    setLastDegrees();
    
    degsIn[1] = 60;

    degsIn[3] = 50;
    degsBot[3] = 90;

    degsIn[5] = 30;
    degsBot[5] = 30;

    moveServos();   
}

/*
 *  moves all the even numbered legs to a backward position
 */
void moveEvenLegsBackwards(){
    setLastDegrees();
    
     degsIn[0] = 50;
    degsBot[0] = 90;
      
     degsIn[2] = 20;
    degsBot[2] = 30;
        
     degsIn[4] = 60;

    moveServos();  
}

/*
 *  moves all te odd numbered legs to a backward position
 */
void moveOddLegsBackwards(){
    setLastDegrees();
    
    degsIn[1] = 20;

    degsIn[3] = 50;
    degsBot[3] = 30;

    degsIn[5] = 30;
    degsBot[5] = 90;

    moveServos();
}

/*
 *  Sets the lastDeg Variable to the current Deg Variables
 */
void setLastDegrees(){
  for(int i = 1; i < ELEMENTS; i++){
        lastDegIn[i] = degsIn[i];
        lastDegBot[i] = degsBot[i];
        lastDegTop[i] = degsTop[i];
    }
}
