/**
 * Declaration of the Priest class.
 *
 * @author Kayla Rehwoldt 
 * @author Heather Dalton
 * @date 04/26/2020
 */

#include "Human.h"
#include "Board.h"

#ifndef PRIEST_H
#define PRIEST_H
using namespace std;

/**
 * @class Priest
 * @brief The Priest class declaration.
 */
class Priest : public Human {
    public:
        Priest(int initRow, int initCol, bool initInfected, string role, int blessed, int timeInfected, Board* thisBoard); //Priest Constructor
        virtual ~Priest();                      //Priest destructor
        void draw();                            //Draws the priest human
        void bless( Human *person );            //Makes the person immuned for 5 seconds
        void heal( Human *person );             //Changes infected back to uninfected
        void resurrect( Human *person );        //Brings the dead back to life
};

#endif //PRIEST_H
