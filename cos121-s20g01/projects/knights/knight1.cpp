/*
Authors: Kayla Rehwoldt & Heather Dalton
Date: 04/21/2020
*/

#include <iostream>

using namespace std;

const int MAX_BOARD_SIZE = 20;
const int INIT_VALUE = -1;

int countJumps(int boardSize, int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] );
void initializeBoard(int boardSize, int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] );
void visitSpots(int boardSize, int row, int col, int jumps, int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE]);

int main( ) {
    
    int row, col, jumps, boardSize;
    int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    
    cin >> boardSize >> row >> col >> jumps;

    while(cin) {
        initializeBoard( boardSize, board );
        visitSpots( boardSize, row, col, jumps, board );
        cout << countJumps( boardSize, board ) << endl;
        cin >> boardSize >> row >> col >> jumps;
    }

    return 0;
}

int countJumps(int boardSize, int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE]) {
    int jumps = 0;
    for(int row=0; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            if( board[row][col] != INIT_VALUE ) {
                jumps++;
            }
        }
    }
    
    return jumps;
}

void initializeBoard(int boardSize, int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] ) {
    for( int row=0; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            board[row][col] = INIT_VALUE;
        }
    }
}

void visitSpots( int boardSize, int row, int col, int jumps, int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] ) {
    
    if( row >= boardSize || row < 0 || col >= boardSize || col < 0 ) return; //check in bounds
    if( jumps < board[row][col] ) return; //checks if previously there with more jumps left
    board[row][col] = jumps; //marking that we've been here
    if( jumps == 0 ) return; //no jumps left

    visitSpots( boardSize, row+1, col+2, jumps-1, board);
    visitSpots( boardSize, row+1, col-2, jumps-1, board);
    visitSpots( boardSize, row-1, col+2, jumps-1, board); 
    visitSpots( boardSize, row-1, col-2, jumps-1, board);
    visitSpots( boardSize, row-2, col+1, jumps-1, board);
    visitSpots( boardSize, row-2, col-1, jumps-1, board);
    visitSpots( boardSize, row+2, col+1, jumps-1, board); 
    visitSpots( boardSize, row+2, col-1, jumps-1, board);
     
    return;

}
