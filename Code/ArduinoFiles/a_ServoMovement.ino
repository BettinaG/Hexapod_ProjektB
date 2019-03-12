/*
 * This file contains the routine to move all servos to their new positions
 * The while loop is running until all the motors have reached the desired degrees
 */
void moveServos(){
    int8_t diffTop[ELEMENTS],                                   // These variables contain the value that marks wether a motors has a lower or bigger degree than it should have
           diffBot[ELEMENTS],
           diffIn[ELEMENTS];

    for (int j = 0; j < ELEMENTS; j++){                         //Mark wether the new Degree is smaller or bigger than the old one  -1 = the current degree is smaller than it should be
                                                                //                                                                   1 = the current degree is bigger than it should be
        if      (lastDegTop[j] < degsTop[j]) diffTop[j] = -1;   //                                                                   0 = the current degree is correct
        else if (lastDegTop[j] > degsTop[j]) diffTop[j] =  1;
        else                                 diffTop[j] =  0;

        if      (lastDegBot[j] < degsBot[j]) diffBot[j] = -1;
        else if (lastDegBot[j] > degsBot[j]) diffBot[j] =  1;
        else                                 diffBot[j] =  0;

        if      (lastDegIn[j] < degsIn[j]) diffIn[j] = -1;
        else if (lastDegIn[j] > degsIn[j]) diffIn[j] =  1;
        else                               diffIn[j] =  0;
    }

    boolean done = false;
    int8_t doneCounter;                                         // This variable counts the number off correct set motors
        
    while(!done){
        doneCounter = 0;                                        // Set the amount of correct motors to 0
        for(int i = 0; i < ELEMENTS; i++){

            if(diffTop[i] != 0){                                // If one of the Top motors is not in the correct position
                if (diffTop[i] < 0) lastDegTop[i]++;            //  and if the current degree is smaller then increase it
                else                lastDegTop[i]--;            //  else decrease it

                pulse = setPulse(lastDegTop[i]);                // move the motor
                pwm.setPWM(TOP_MOTORS + i, 0, pulse);
            }

            if(diffBot[i] != 0){                                // If one of the Bottom motors ...
                if (diffBot[i] < 0) lastDegBot[i]++;
                else                lastDegBot[i]--;

                pulse = setPulse(lastDegBot[i]);
                pwm.setPWM(BOTTOM_MOTORS + i, 0, pulse);
            }
      
            
            if(diffIn[i] != 0){                                 // If one of the Inner motors ...
                if (diffIn[i] < 0) {
                  lastDegIn[i]++;
                }
                else                lastDegIn[i]--;

                
                
                if (i < 4){
                    pulse = setPulse(lastDegIn[i]);
                    pwm.setPWM(INNER_MOTORS + i, 0, pulse);  
                } else if ( i == 4){
                    innerServo4.write(lastDegIn[i]);
                } else {
                    innerServo5.write(lastDegIn[i]);
                }
                
            }
            
            if(lastDegTop[i] == degsTop[i]) {                   // For each correctly set motor increase the counter by 1
                diffTop[i] = 0;
                doneCounter++;
            } 
            if(lastDegBot[i] == degsBot[i]){
                diffBot[i] = 0;
                doneCounter++;
            }
            if(lastDegIn[i]  == degsIn[i]){
                diffIn[i]  = 0;  
                doneCounter++;
            }

              
        }        

        if (doneCounter == ELEMENTS*3) done = true;           // If the counter equals the amount of motors this routine is done
        
        delay(5);
    }
}  
