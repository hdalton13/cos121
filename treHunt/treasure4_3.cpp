#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
    char ch;
    
    string fileName = "fileio.c";
    ifstream huntFile(fileName.c_str());
    ofstream outFile;
    outFile.open("answer3.txt");
    huntFile.get(ch);

    while(huntFile){
        outFile << char(~ch);
        huntFile.get(ch);
    }

    return 0;
}
