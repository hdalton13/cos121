#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>

using namespace std;

int main(/**/){

    char ch;
    //question 4 is the answer from hamster.vim
    //question 5 is the answer from cheetah.vim

    string fileName = "cheetah.vim";
    ifstream huntFile(fileName.c_str());
    ofstream outFile;
    outFile.open("answer5.txt");
      
    huntFile.get(ch);
   // cin.get(ch);

    while(huntFile){
       
        char high = ch & 0xf0;
        
        char newLow = (high >> 4) & 0x0f;
        char low = ch & 0x0f;
        char newHigh = low << 4;

        outFile << char (newHigh | newLow);
        huntFile.get(ch);
        //cout << char ( newHigh | newLow);
        //cin.get(ch);
    }

return 0;
}
