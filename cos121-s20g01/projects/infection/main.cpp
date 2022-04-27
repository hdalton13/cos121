/**
 * @file main.cpp
 * @brief Contains the main function that starts the infection simulation.
 *
 * @creator Stefan Brandle
 * @date March 2012
 *
 * @author Heather Dalton 
 * @author Kayla Rehwoldt
 * @date: April 26, 2020
 **/

#include <iostream>
#include <cstdlib>
#include "conio.h"
#include <unistd.h> 

// Board.h needs to be included here because we create a Board
// object below.
#include "Board.h"

using namespace std;

void changesDisplay();

/**
 * @fn main()
 * @brief main function that starts the simulation running
 * The main function does the following:
 * (1) seeds the random number generator
 * (2) creates a board object that is 20 rows, 80 columns, 70 humans
 * (3) starts the simulation running by calling the board's run function.
 **/
int main() {
    // Only seed the random number generator once!
    srandom( time(NULL) );

    Board board(20, 80, 70);
    changesDisplay();
    board.run();

    return 0;
}

/**
 * @brief shows a screen that explains the simulators behavior changes you have made 
 */
void changesDisplay(){

    cout << "We have added a Priest class (the Humans drawn in blue) that can heal the infected, bless the healthy, and resurrect the dead." << endl;
    cout << "   Heal = Infected person is set to healthy" << endl;
    cout << "   Bless = Healthy person is immune from infection for 5 seconds" << endl;
    cout << "   Resurrect = Dead person is healed and now can move" << endl;
    cout << "Our 'wow' factor is that an infected Human's color changes based on the amount of time they have been infected: " << endl;
    cout << "   Yellow = <3 seconds" << endl;
    cout << "   Red = <7 seconds" << endl;
    cout << "   Magenta = <10 seconds" << endl;
    cout << "Once an infected person reaches 10 seconds of infection, they die. They turn gray and can no longer move." << endl << endl << endl;
    
    sleep( 15 );
    cout << conio::clrscr() << flush;
}
