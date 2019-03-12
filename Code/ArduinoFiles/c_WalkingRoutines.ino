/*
 *  This file contains all the routines that make the Hexapod walk to a certain direction
 */


/*
 * Calls the Degree Settings in an order that makes the hexapod move in a forward direction
 * Forward being the middle between the number 0 and 5 servos
 */
void walkForwards(){
   moveLegsUp(1);    
   moveOddLegsForwards();
   moveLegsDown(1);

   moveLegsUp(0);
   moveOddLegsBackwards();
   moveEvenLegsForwards();

   moveLegsDown(0);
   moveLegsUp(1);
   moveEvenLegsBackwards();  
}


/*
 * Calls the Degree Settings in an order that makes the hexapod move in a backward direction
 * Backwards being the middle between the number 2 and 3 servos
 */
void walkBackwards(){
    moveLegsUp(1);
    moveOddLegsBackwards();
    moveLegsDown(1);

    moveLegsUp(0);
    moveOddLegsForwards();
    moveEvenLegsBackwards();

    moveLegsDown(0);
    moveLegsUp(1);
    moveEvenLegsForwards();
}

/*
 *  Calls the Degree Settings in an order that makes th hexapod move in a dance motion
 */
void dance(){
   moveOddLegsForwards();
   moveOddLegsBackwards();
   moveEvenLegsForwards();
   moveEvenLegsBackwards(); 
}
