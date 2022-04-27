/*
Authors: Kayla Rehwoldt & Heather Dalton
Date: 04/21/2020
*/

#include <iostream>

using namespace std;

const int BOARD_SIZE = 8;
const int INIT_VALUE = 1000;

int countJumps ( int board[BOARD_SIZE][BOARD_SIZE] );
void initializeBoard( int board[BOARD_SIZE][BOARD_SIZE] );
void visitSpots( int startRow, int startCol, int endRow, int endCol, int jumps, int board[BOARD_SIZE][BOARD_SIZE]);

int main( ) {
    
    int startRow, startCol, endRow, endCol;
    int jumps = 0;
    int board[BOARD_SIZE][BOARD_SIZE];
    
    cin >> startRow >> startCol >> endRow >> endCol;

    while(cin) {
        initializeBoard( board );
        visitSpots( startRow, startCol, endRow, endCol, jumps, board );
        cout << board[endRow][endCol] << endl;
        cin >> startRow >> startCol >> endRow >> endCol;
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

void visitSpots( int startRow, int startCol, int endRow, int endCol, int jumps, int board[BOARD_SIZE][BOARD_SIZE] ) {
    
    if( startRow > BOARD_SIZE || startRow < 0 || startCol > BOARD_SIZE || startCol < 0 ) return; //check in bounds
    if( board[startRow][startCol] != INIT_VALUE && jumps > board[startRow][startCol] ) return; //checks if previously there
    board[startRow][startCol] = jumps; //marking that we've been here
    if( startRow == endRow && endCol == startCol ) return;

    visitSpots( startRow+1, startCol+2, endRow, endCol, jumps+1, board);
    visitSpots( startRow+1, startCol-2, endRow, endCol, jumps+1,board);
    visitSpots( startRow-1, startCol+2, endRow, endCol, jumps+1, board); 
    visitSpots( startRow-1, startCol-2, endRow, endCol, jumps+1, board);
    visitSpots( startRow-2, startCol+1, endRow, endCol, jumps+1, board);
    visitSpots( startRow-2, startCol-1, endRow, endCol, jumps+1, board);
    visitSpots( startRow+2, startCol+1, endRow, endCol, jumps+1, board); 
    visitSpots( startRow+2, startCol-1, endRow, endCol, jumps+1, board);
     
    return;

}
