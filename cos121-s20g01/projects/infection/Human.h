/**
 * Declaration of the Human class.
 *
 * @author Stefan Brandle
 * @date March 2012
 *
 * @author Kayla Rehwoldt
 * @author Heather Dalton
 * @date May 2020
 */

#include <string>

#include "Board.h"

#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

/**
 * @class Human
 * @brief The Human class declaration.
 */
class Human {
  public:
    Human(int initRow, int initCol, bool initInfected, string role, int blessed, int timeInfected, Board* thisBoard); //Human class constructor
    virtual ~Human();                                    //Human class destructor
    virtual void move();                                 //Function that moves human characters around the board
    virtual void draw();                                 //Function that draws the Humans in the board
    virtual void bless( Human *person );                 //Placeholder Function that makes the humans immune from the infected
    virtual void heal( Human *person );                  //Placeholder Function that heals the humans and returns them to a healthy state
    virtual void resurrect( Human *person );             //Placeholder Function that will return the dead humans back to life 

    // "Setters" and "getters"
    virtual void getLocation(int& row, int& col);        //Get the location of the human
    virtual void setLocation(int row, int col);          //Sets the location of the human
    virtual void toggleInfected();                       //Changes the state of infection
    virtual bool isInfected();                           //Returns the state of infection
    virtual string getRole();                            //Tells what Role the this->human has (person, priest, dead)
    virtual void setRole( string newRole );              //Changes the Role of this->human
    virtual int getBlessed();                            //Returns the state of blessed
    virtual void setBlessed( int newBlessed );           //Sets the state of blessed
    virtual int getTimeInfected();                       //Returns the amount of time a human has been infected
    virtual void setTimeInfected( int time );            //Sets the infection time

  protected:
    bool infected;     // Track whether or not this human is infected
    int row, col;      // The row and column where this human is on the board
    string role;       // Keep track of role
    int blessed;       // Keep track of amount of blessing 
    int timeInfected;  // Keep track of how much time has passed since infection incrementally
    Board *board;      // Pointer to the board so the human can ask the board whether
                       // the human can move to a given location on the board
};

#endif // HUMAN_H
