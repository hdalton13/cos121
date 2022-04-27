/**
 * @brief DuckyPlayer AI for battleships
 * @file DuckyPlayerV2.cpp
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004 Updated 2015 for multi-round play.
 *
 * @author Kayla Rehwoldt, Heather Dalton
 * @date 05/07/2020
 *
 * This Battleships AI is very simple and does nothing beyond playing
 * a legal game. However, that makes it a good starting point for writing
 * a more sophisticated AI.
 */

#include <iostream>
#include <cstdio>

#include "DuckyPlayerV2.h"

/**
 * @brief Constructor that initializes any inter-round data structures.
 * @param boardSize Indication of the size of the board that is in use.
 *
 * The constructor runs when the AI is instantiated (the object gets created)
 * and is responsible for initializing everything that needs to be initialized
 * before any of the rounds happen. The constructor does not get called 
 * before rounds; newRound() gets called before every round.
 */
DuckyPlayerV2::DuckyPlayerV2( int boardSize )
    :PlayerV2(boardSize)
{
    // Could do any initialization of inter-round data structures here.
    initializeOBoards( boardSize );
    this->maxVal = 0;
    this->lowestRisk = 10000;
    this->totalRounds = 0;
}

/**
 * @brief Destructor placeholder.
 * If your code does anything that requires cleanup when the object is
 * destroyed, do it here in the destructor.
 */
DuckyPlayerV2::~DuckyPlayerV2( ) {}

/*
 * Private internal function that initializes a MAX_BOARD_SIZE 2D array of char to water.
 */
void DuckyPlayerV2::initializeBoard() {
    for(int row=0; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            this->board[row][col] = WATER;
            this->ships[row][col] = WATER;
        }
    }
}

void DuckyPlayerV2::initializeOBoards( int boardSize ) {
    for(int row=0; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            this->oShips[row][col] = 0;
            this->oShots[row][col] = 0;
        }
    }
}

void DuckyPlayerV2::findVal( int& maxVal ) {
    for(int row=0; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            if( oShips[row][col] > maxVal ) maxVal = oShips[row][col];
        }
    }
}

/**
 * @brief Specifies the AI's shot choice and returns the information to the caller.
 * @return Message The most important parts of the returned message are 
 * the row and column values. 
 *
 * See the Message class documentation for more information on the 
 * Message constructor.
 */
Message DuckyPlayerV2::getMove() {

    this->shotsFired++;
    if( firstShot == true && totalRounds < 20 ) {
        //change once learning is started
        shotRow = 0;
        shotCol = 0;
        scanRow = shotRow;
        scanCol = shotCol;
        firstShot = false;
        Message shot( SHOT, shotRow, shotCol, "Bang", None, 1 );
        return shot;

    } else {

        if( board[scanRow][scanCol] == HIT ) {
            oShips[scanRow][scanCol]++;
            killShip( scanRow, scanCol, shotRow, shotCol);
            Message shot( SHOT, shotRow, shotCol, "Bang", None, 1 );
            return shot;
        } else if( strayHit( scanRow, scanCol) ) {
            killShip( scanRow, scanCol, shotRow, shotCol );
            Message shot( SHOT, shotRow, shotCol, "Bang", None, 1 );
            return shot;
        } else {
            findShot(scanRow, scanCol);
            shotRow = scanRow;
            shotCol = scanCol;
            Message shot( SHOT, shotRow, shotCol, "Bang", None, 1 );
            return shot;
        }
    }
}

bool DuckyPlayerV2::strayHit( int& scanRow, int& scanCol ) {
    
    for(int row=0; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            if( board[row][col] == HIT ) {
                scanRow = row;
                scanCol = col;
                return true;
            }
        }
    }
    return false;
}

void DuckyPlayerV2::killShip( int scanRow, int scanCol, int& shotRow, int& shotCol ) {
    if( killShipNorth( scanRow, scanCol, shotRow, shotCol ) ) return;
    else if( killShipEast( scanRow, scanCol, shotRow, shotCol) ) return; 
    else if( killShipSouth( scanRow, scanCol, shotRow, shotCol ) ) return; 
    else if( killShipWest( scanRow, scanCol, shotRow, shotCol ) ) return; 

}

bool DuckyPlayerV2::killShipNorth( int scanRow, int scanCol, int& shotRow, int& shotCol ) {
    for ( int r = scanRow-1; r >= 0; r-- ){
        switch(board[r][scanCol]){
            case WATER:
                shotRow = r;
                shotCol = scanCol;
                return true; //brings us out of the function (all it has to do is set the shotRow and shotCol)
                break;
            case HIT:
                oShips[r][scanCol]++;
                break; //brings us out of the switch and keeps decrementing through the 
            case KILL:
            case MISS:
                return false;
        }
    }
    return false;
    
}

bool DuckyPlayerV2::killShipEast( int scanRow, int scanCol, int& shotRow, int& shotCol ){

    for ( int c = scanCol+1; c <= 9; c++ ){
        switch(board[scanRow][c]){
            case WATER:
                shotRow = scanRow;
                shotCol = c;
                return true;
                break;
            case HIT:
                oShips[scanRow][c]++;
                break;
            case KILL:
            case MISS:
                return false;
        }
    }
    return false;
    
}
bool DuckyPlayerV2::killShipSouth( int scanRow, int scanCol, int& shotRow, int& shotCol ){ 
    for ( int r = scanRow+1; r <= 9; r++ ){
        switch(board[r][scanCol]){
            case WATER:
                shotRow = r;
                shotCol = scanCol;
                return true;
                break;
            case HIT:
                oShips[r][scanCol]++;
                break;
            case KILL:
            case MISS:
                return false;
        }
    }
    return false;
    
}
bool DuckyPlayerV2::killShipWest( int scanRow, int scanCol, int& shotRow, int& shotCol ){ 
    for ( int c = scanCol-1; c >= 0; c-- ){
        switch(board[scanRow][c]){
            case WATER:
                shotRow = scanRow;
                shotCol = c;
                return true;
                break;
            case HIT:
                oShips[scanRow][c]++;
                break;
            case KILL:
            case MISS:
                return false;
        }
    }
    return false;
    
}
void DuckyPlayerV2::findShot( int& scanRow, int& scanCol ) {


    if( totalRounds < 20 ) {
        
        finish( scanRow, scanCol );

    } else {
        if( shotsFired < 20 ) {
            bestLocation( scanRow, scanCol, maxVal );
        } else {
            finish( scanRow, scanCol );
        }
    }
    return;

}//end of void

void DuckyPlayerV2::bestLocation( int& scanRow, int& scanCol, int& maxVal ) {

    while( shotsFired < 20 ) {
        for(int row=0; row<boardSize; row++) {
            for(int col=0; col<boardSize; col++) {
                if( oShips[row][col] == maxVal && board[row][col] == WATER && logicalLocation( row, col ) ) {
                    scanRow = row;
                    scanCol = col;
                    
                    return;
                } 
            }
        }
        maxVal--;
    }
}

bool DuckyPlayerV2::logicalLocation( int row, int col ) {

    if( board[row][col+1] == WATER && board[row][col-1] == WATER ) return true;
    if( board[row+1][col] == WATER && board[row-1][col] == WATER ) return true;

    if( board[row][col+1] == WATER && board[row][col+2] == WATER ) return true;
    if( board[row][col-1] == WATER && board[row][col-2] == WATER ) return true;
    if( board[row+1][col] == WATER && board[row+2][col] == WATER ) return true;
    if( board[row-1][col] == WATER && board[row-2][col] == WATER ) return true;
    return false; 

}

void DuckyPlayerV2::finish( int& scanRow, int& scanCol ){

    for(int row=0; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            if( board[row][col-2] == WATER && board[row][col-1] == WATER && board[row][col] == WATER) {
                scanRow = row;
                scanCol = col;
                return;
            }
            if( board[row-2][col] == WATER && board[row-1][col] == WATER && board[row][col] == WATER ) {
                scanRow = row;
                scanCol = col;
                return;
            }
        }
    }
}



/**
 * @brief Tells the AI that a new round is beginning.
 * The AI show reinitialize any intra-round data structures.
 */
void DuckyPlayerV2::newRound() {
    /* DuckyPlayer is too simple to do any inter-round learning. Smarter players 
     * reinitialize any round-specific data structures here.
     */
    findVal( maxVal );
    this->totalRounds++;
    this->lastRow = 0;
    this->lastCol = -1;
    this->numShipsPlaced = 0;
    this->firstShot = true;
    this->shotsFired = 0;
    this->initializeBoard();
}

/**
 * @brief Gets the AI's ship placement choice. This is then returned to the caller.
 * @param length The length of the ship to be placed.
 * @return Message The most important parts of the returned message are 
 * the direction, row, and column values. 
 *
 * The parameters returned via the message are:
 * 1. the operation: must be PLACE_SHIP 
 * 2. ship top row value
 * 3. ship top col value
 * 4. a string for the ship name
 * 5. direction Horizontal/Vertical (see defines.h)
 * 6. ship length (should match the length passed to placeShip)
 */
/*
lowestRisk = 1000000;

for r in rows
   for c in cols
      risk = calculateRisk(r, c, Horizontal, length)
      if(risk < lowestRisk) {
         bestRow = r; bestCol = c; bestDir = Horizontal;
         lowestRisk = risk;
      }

      risk = calculateRisk(r, c, Vertical, length)
      if(risk < lowestRisk) {
         bestRow = r; bestCol = c; bestDir = Horizontal;
         lowestRisk = risk;
      }

place ship at bestRow, bestCol, bestDir

*/
Message DuckyPlayerV2::placeShip(int length) {
    while( true ) {
        // If just placing ships randomly
        int row = -1, col = -1;
        Direction dir = None;
        lowestRisk = 1000;

        //if( totalRounds < 20 ) {
        if( totalRounds < 10000 ) {
            row = rand()%boardSize;
            col = rand()%boardSize;
            dir = Direction(rand()%2 + 1 );

            /*
            if( canPlaceShip(row, col, dir, length) ) {
                markShip( row, col, dir, length );
                Message ship( PLACE_SHIP, row, col, "", dir, length );
                return ship;
            }
            */
        } else {
            row = 0;
            col = 0;
            dir = Direction(1);

            for(int r=0; r<boardSize; r++) {
                for(int c=0; c<boardSize; c++) {
                    int riskH = calculateRisk( r, c, Direction(1), length); 
                    if( riskH < lowestRisk ) {
                        row = r;
                        col = c;
                        dir = Direction(1);
                        lowestRisk = riskH;
                    }

                    int riskV = calculateRisk( r, c, Direction(2), length); 
                    if( riskV < lowestRisk ) {
                        row = r;
                        col = c;
                        dir = Direction(2);
                        lowestRisk = riskV;
                    }
                }
            }// end of nested for
        } // end of else
        if( canPlaceShip(row, col, dir, length) ) {
            markShip( row, col, dir, length );
            Message ship( PLACE_SHIP, row, col, "", dir, length );
            return ship;
        }
    } // end of while
} // end of function

int DuckyPlayerV2::calculateRisk( int r, int c, int dir, int length ) {

    int total = 0;
    if( dir == Horizontal ) {
        if(c+length>boardSize) return 10000;
        for( int i = 0; i < length; i++ ) {
            if( ships[r][c+i] == SHIP ) return 10000;
            total += oShots[r][c+i];
        }
    } else {
        if(r+length>boardSize) return 10000;
        for( int i = 0; i < length; i++ ) {
            if( ships[r+i][c] == SHIP ) return 10000;
            total += oShots[r+i][c];
        }
    }
    return total;
}


bool DuckyPlayerV2::canPlaceShip( int row, int col, int dir, int length ) {
    if ( dir == 1 ) {
        if( row < 0 || row >= boardSize ) return false;
        if( col < 0 || col > boardSize-length) return false;
        for( int c = col; c < col+length; c++ ) {
            if( ships[row][c] == SHIP ) return false;
        }
    } else {
        if( row < 0 || row >= boardSize-length ) return false;
        if( col < 0 || col <= boardSize ) return false;
        for( int r = row; r < row + length; r++ ) {
            if( (ships[r][col]) == SHIP ) return false;
        }
    }
    return true;
}


void DuckyPlayerV2::markShip( int row, int col, int dir, int length ) {
   if( dir == 1 ) {
       for( int c = col; c < col+length; c++ ) {
           ships[row][c] = SHIP;
       }
   } else {
       for( int r = row; r < row+length; r++ ) {
          ships[r][col] = SHIP;
       }
   }
}

/**
 * @brief Updates the AI with the results of its shots and where the opponent is shooting.
 * @param msg Message specifying what happened + row/col as appropriate.
 */
void DuckyPlayerV2::update(Message msg) {
    switch(msg.getMessageType()) {
        case HIT:
        case KILL:
        case MISS:
            board[msg.getRow()][msg.getCol()] = msg.getMessageType();
            break;

        case WIN:
            break;
        case LOSE:
            break;
        case TIE:
            break;
        case OPPONENT_SHOT:
            oShots[msg.getRow()][msg.getCol()] += 1;
            break;
    }
}

