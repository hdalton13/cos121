/**
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004
 *
 * Please type in your name[s] here if you change the code:
 *
 */

#ifndef DUCKYPLAYERV2_H        // Double inclusion protection
#define DUCKYPLAYERV2_H

using namespace std;

#include "PlayerV2.h"
#include "Message.h"
#include "defines.h"

// DuckyPlayer inherits from/extends PlayerV2

class DuckyPlayerV2: public PlayerV2 {
  public:
    DuckyPlayerV2( int boardSize );
    ~DuckyPlayerV2();
    void newRound();
    Message placeShip(int length);
    Message getMove();
    void update(Message msg);
    void markShip( int row, int col, int dir, int length );
    bool canPlaceShip( int row, int col, int dir, int length );
    void killShip( int scanRow, int scanCol, int& shotRow, int& shotCol ); 
    bool killShipNorth( int scanRow, int scanCol, int& shotRow, int& shotCol ); 
    bool killShipEast( int scanRow, int scanCol, int& shotRow, int& shotCol ); 
    bool killShipSouth( int scanRow, int scanCol, int& shotRow, int& shotCol ); 
    bool killShipWest( int scanRow, int scanCol, int& shotRow, int& shotCol ); 
    void bestLocation( int& scanRow, int& scanCol, int& maxVal );
    void findShot( int& scanRow, int& scanCol );
    void initializeOBoards( int boardSize );
    void findVal( int& maxVal ); 
    bool logicalLocation( int row, int col );
    bool strayHit( int& scanRow, int& scanCol ); 
    void finish( int& scanRow, int& scanCol );
    int calculateRisk( int r, int c, int dir, int length );

  private:
    void initializeBoard();
    int lastRow;
    int lastCol;
    int numShipsPlaced;
    char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    char ships[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    int oShips[MAX_BOARD_SIZE][MAX_BOARD_SIZE];  //This is where the opponent is most likely to be placed
    int oShots[MAX_BOARD_SIZE][MAX_BOARD_SIZE];  //This is where the opponent is most likely to shoot
    bool firstShot;
    int shotRow;
    int shotCol;
    int scanRow;
    int scanCol;
    int oShipsMax;
    int totalRounds;
    int maxVal;
    int lowestRisk;
    int shotsFired;
};

#endif
