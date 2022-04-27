//Authors: Kayla Rehwoldt and Heather Dalton
//Date: 04/08/2020

#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>

#define PAUSE_TIME 1

using namespace std;

string loadMaze( char maze[10][10]);
int askingRow();
int askingCol();
bool canEscape( char maze[10][10], int row, int col );
void printMaze(char maze[10][10], string fileName);

int main() {
    char maze[10][10];

    string fileName = loadMaze( maze );

    int row, col;

    while ( cin ){
        cout << conio::clrscr() << flush;

        printMaze( maze, fileName );

        row = askingRow();
        col = askingCol();

        bool escape = canEscape( maze, row, col);
        if( escape == false ) {
            cout<< conio:: gotoRowCol(12,1) <<"Can't escape, I will send your family flowers :(" << endl;
            cout << endl;
        } else {
            cout<< conio::gotoRowCol(12,1) << "Can escape!" << endl << endl;
        }
        sleep(PAUSE_TIME * 4);
    }
    return 0;
}

string loadMaze( char maze[10][10]) {
    string fileName;
    cout << "Enter fileName: ";
    cin >> fileName;   
    
    ifstream mazeFile(fileName.c_str());
    while ( ! mazeFile ) {
        mazeFile.clear();
        cout << "Error opening file " << fileName << endl;
        cout << "Enter fileName: ";
        cin >> fileName;
        mazeFile.open(fileName.c_str());
    }
    return fileName;
}

void printMaze(char maze[10][10], string fileName){
    char junk;
    ifstream mazeFile(fileName.c_str());
    cout << conio::clrscr() << flush;
    cout << conio::gotoRowCol(1,1);
    cout << "  0123456789" << endl;
    for( int row=0; row<10; row++) {
        cout << row << ' ';
        for (int col=0; col<10; col++ ) {
            maze[row][col] = mazeFile.get();
            cout << maze[row][col];
        }
        mazeFile.get(junk);
        cout << endl;
    }
    sleep(PAUSE_TIME);
    cin.get(junk);
}

int askingCol(){
    int xAxis;
    cout<< conio::gotoRowCol(14,1) << "What is your column number? --> ";
    cin>> xAxis;
    return xAxis;
}
int askingRow(){
    int yAxis;
    cout<< conio::gotoRowCol(13,1) <<"What is your row number? --> ";
    cin>> yAxis;
    return yAxis;
}

bool canEscape ( char maze[10][10], int row, int col ) {
    
    if (row<0 || row>=10 || col<0 || col>=10) return false;
    else if (maze[row][col] == 'E') return true;
    else if (maze[row][col] == '#') return false;
    else if (maze[row][col] == '!') return false;

    else{
        maze[row][col] = '!';
        cout << conio::gotoRowCol(row+2,col+3) << conio::bgColor(conio::YELLOW) << "!\b" << flush;
        sleep(PAUSE_TIME);
        if (canEscape(maze, row-1,col) ||   //North
            canEscape(maze, row, col+1) ||  //East
            canEscape(maze, row+1, col) ||  //South
            canEscape(maze, row, col-1)     //West
           )
        {
            cout << conio::gotoRowCol(row+2,col+3) << conio::bgColor(conio::GREEN) << "*\b" << conio::resetAll() << flush;
            return true;
        }else{
            cout << conio::gotoRowCol(row+2,col+3) << conio::bgColor(conio::RED) << "x\b" << conio::resetAll() << flush;
            return false;
        }
    }
    return true;
}
