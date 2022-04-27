#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main() {
    char ch;
    int keyIndex=0;
    int keytLength=strlen("batterystaple");
    string keyStr = "batterystaple";

    string fileName = "tearoof.bmp";
    ifstream huntFile(fileName.c_str());
    ofstream outFile;
    outFile.open("answer6.txt");
    huntFile.get(ch);
    while(huntFile){
        outFile << char(ch ^ heyStr[keyIndex]);
        keyIndex++;
        if(keyIndex >= keyLength){
            keyIndex = 0;
        }
        huntFile.get(ch);
    }


    return 0;
}
