/*
Authors: Kayla Rehwoldt & Heather Dalton
Date: 04/21/2020
*/

#include <iostream>

using namespace std;

//int BOARD_SIZE = 8;
const int BOARD_SIZE = 8;
const int INIT_VALUE = 1000;

int countJumps ( int board[BOARD_SIZE][BOARD_SIZE] );
void initializeBoard( int board[BOARD_SIZE][BOARD_SIZE] );
void visitSpots( int row, int col, int jumps, int board[BOARD_SIZE][BOARD_SIZE]);

int main( ) {
    
    int row, col, jumps;
    int board[BOARD_SIZE][BOARD_SIZE];
//    cin >> BOARD_SIZE >> row >> col >> jumps;
//    int board[BOARD_SIZE][BOARD_SIZE];
    
    cin >> row >> col >> jumps;

    while(cin) {
        initializeBoard( board );
        visitSpots( row, col, jumps, board );
        cout << countJumps( board ) << endl;
        cin >> row >> col >> jumps;
        //cin >> BOARD_SIZE >> row >> col >> jumps;
        //board = board[BOARD_SIZE][BOARD_SIZE];
    }

    return 0;
}

int countJumps( int board[BOARD_SIZE][BOARD_SIZE]) {
    int jumps = 0;
    for(int row=0; row<BOARD_SIZE; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            if( board[row][col] != INIT_VALUE ) {
                jumps++;
            }
        }
    }
    
    return jumps;
}

void initializeBoard( int board[BOARD_SIZE][BOARD_SIZE] ) {
    for( int row=0; row<BOARD_SIZE; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            board[row][col] = INIT_VALUE;
        }
    }
}

void visitSpots( int row, int col, int jumps, int board[BOARD_SIZE][BOARD_SIZE] ) {
    
    if( row > BOARD_SIZE || row < 0 || col > BOARD_SIZE || col < 0 ) return; //check in bounds
    if( board[row][col] != INIT_VALUE && jumps < board[row][col] ) return; //checks if previously there
    board[row][col] = jumps; //marking that we've been here
    if( jumps == 0 ) return; //no jumps left

    visitSpots( row+1, col+2, jumps-1, board);
    visitSpots( row+1, col-2, jumps-1, board);
    visitSpots( row-1, col+2, jumps-1, board); 
    visitSpots( row-1, col-2, jumps-1, board);
    visitSpots( row-2, col+1, jumps-1, board);
    visitSpots( row-2, col-1, jumps-1, board);
    visitSpots( row+2, col+1, jumps-1, board); 
    visitSpots( row+2, col-1, jumps-1, board);
     
    return;

}
