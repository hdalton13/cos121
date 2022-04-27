/**
 * @file Priest.cpp
 * @brief The Priest class implementation file.
 *
 * @author Kayla Rehwoldt 
 * @author Heather Dalton
 * @date 04/26/2020
 */

#include <cstdlib>
#include <iostream>

#include "Priest.h"
#include "conio.h"

using namespace std;

/**
 * @brief The Priest class constructor.
 * This function initializes the row, col, infected, and board variables.
 *
 * @param initRow the initial human row location. 
 * @param initCol the initial human column location.
 * @param initInfected whether the human is initially infected.
 * @param role identifies if the human object is a person, priest, or dead
 * @param blessed is the amount of time left of immunity
 * @param timeInfected states the amount of time a person is infected before they should be considered dead
 * @param theBoard a pointer to the board (used to ask board whether a proposed move is ok).
 */

Priest::Priest(int initRow, int initCol, bool initInfected, string role, int blessed, int timeInfected, Board* theBoard)
:Human(initRow, initCol, false, role, blessed, timeInfected, theBoard)
{
    //calling Human constructor
}

/**
 * @brief The Priest class destructor.
 */
Priest::~Priest() {
    //destructor from ListArray
    //delete[] dataItem;
}

/**
 * @brief Draws the Priest using LIGHT_CYAN
 * Draws the priest at the current row/col location on the screen. 
 */
void Priest::draw() {
    cout << conio::gotoRowCol(this->row+1, this->col+1)
         << conio::bgColor(conio::LIGHT_CYAN)
         << 'P' << conio::resetAll() << flush;
}

/**
 * @brief The Bless function
 * Blesses those next to the Priest that aren't infected. 
 */
void Priest::bless( Human *person ) {
    if( this->isInfected()==false ) {
        person->setBlessed(5);
    }
}

/**
 * @brief the heal function
 * Heals the humans that are infected
 */
void Priest::heal( Human *person ) {
    person->toggleInfected();
    person->setTimeInfected( 0 );
}

/**
  * @brief The Resurrect function
  * Brings dead humans back to life
  */
void Priest::resurrect( Human *person ) {
    if( person->getRole()!="dead" ) {
        return;
    } else {
        person->setRole("person");
        person->toggleInfected();
        person->setTimeInfected( 0 );
    }
}
