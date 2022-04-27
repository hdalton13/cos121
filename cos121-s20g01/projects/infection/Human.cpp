/**
 * @file Human.cpp
 * @brief The Human class implementation file.
 *
 * @author Kayla Rehwoldt 
 * @author Heather Dalton
 * @date 04/27/2020
 */

#include <cstdlib>
#include <iostream>

#include "Human.h"
#include "conio.h"

using namespace std;

/**
 * @brief The Human class constructor.
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
Human::Human(int initRow, int initCol, bool initInfected, string role, int blessed, int timeInfected, Board* theBoard) {
    row = initRow;
    col = initCol;
    infected = initInfected;
    board = theBoard;
    this->role = role;
    this->blessed = 0;
    this->timeInfected = 0;
}

/**
 * @brief The Human class destructor.
 * The Human class destructor does nothing (so far), but is here as a placeholder to remind
 * you that it is a good idea for classes to have destructors, even if you can't think of 
 * work for destructor at this point.
 */
Human::~Human() {
    // Nothing to do
}

/**
 * @brief Have the human try to move.
 * To know whether it is ok to move to some position (r,c), ask the board
 * whether the position is ok. E.g., "if( board->tryMove(r,c) ) ..."
 * If the move is ok, then update the human's row and column to reflect the move.
 */
void Human::move() {
    // Generate a +/- 2 row and column delta.
    int rowDelta=rand()%5-2, colDelta=rand()%5-2;

    // Ask the board whether you
    if(board->tryMove(row+rowDelta, col+colDelta)) {
        row+=rowDelta;
        col+=colDelta;
    }
}

/**
 * @brief Get the human's current row/col location.
 * Returns the human's current row/column location via the reference parameters.
 * @param[out] currentRow the human's current row  
 * @param[out] currentCol the human's current column
 */
void Human::getLocation(int& currentRow, int& currentCol) {
    currentRow = row;
    currentCol = col;
}

/**
 * @brief Set the human's row/col location.
 * Sets the human's current row/column location to the parameter values.
 * @param[in] newRow the human's new row location
 * @param[in] newCol the human's new column location
 */
void Human::setLocation(int newRow, int newCol) {
    row=newRow;
    col=newCol;
}

/**
 * @brief Changes Infection State
 * If human isn't infected it sets this human object's state to infected (true).
 * If human is infected it sets this human object's state to not infected (false).
 */
void Human::toggleInfected() {
    if( this->infected == true ) {
        this->infected = false;
    } else {
        this->infected = true;
    }
}

/**
 * @brief reports whether this human is infected.
 * @return whether this human object is infected or not..
 */
bool Human::isInfected() {
    return infected;
}

/**
 * @brief tells the role of the human (human, priest) 
 * @return what the role of the human
 */
string Human::getRole() {
    return role;
}

/**
 * @brief sets the role of the human 
 * @param newRole that will be set to the role
 */
void Human::setRole( string newRole ) {
    this->role = newRole;
}

/**
 * @brief this is a placeholder for the Priest Class
 * @param Human object to be blessed
 */
void Human::bless( Human *person ) {
    //Empty because this function relies on Priest.cpp
}

/**
 * @brief Gets blessed value.
 * @return the state of blessed
 */
int Human::getBlessed() {
    return blessed;
}

/**
 * @brief Sets blessed value.
 * @param[in] newBlessed
 */
void Human::setBlessed( int newBlessed ) {
    blessed = newBlessed;
}

/**
 * @brief this is a placeholder for the Priest Class
 * @param Human object to be healed
 */
void Human::heal( Human *person ) {
    //Placeholder for Priest
}

/**
 * @brief tells the amount of time a human is infected
 * @return the time infected
 */
int Human::getTimeInfected() {
    return this->timeInfected;
}

/**
 * @brief sets the amount of time a human is infected
 * @param amount of time infected
 */
void Human::setTimeInfected( int time ) {
    this->timeInfected = time;
}

/**
 * @brief this is a placeholder for the Priest Class
 * @param Human object to be resurrected
 */
void Human::resurrect( Human *person ) {
    //Placeholder for Priest
}

/**
 * @brief Draws the human.
 * Draws the human at the current row/col location on the screen.
 * Remember that the first conio row=1, and first conio col=1.
 */
void Human::draw() {
    cout << conio::gotoRowCol(row+1,col+1);

    //changes color based on timeInfected and if this->role == dead
    if ( this->role == "dead" ) {
        cout << conio::bgColor(conio::GRAY);
    }
    if( infected && this->role != "dead" ) {
        if( this->timeInfected < 3 ) {
            cout << conio::bgColor(conio::YELLOW);
        } else if( this->timeInfected < 7 ) {
            cout << conio::bgColor(conio::RED);
        } else {
            cout << conio::bgColor(conio::MAGENTA);
        }
    } else {
        cout << conio::bgColor(conio::LIGHT_GREEN);
    }

    cout << blessed << conio::resetAll() << flush;
}

