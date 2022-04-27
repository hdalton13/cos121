//you still need to to the case of and extra delimater at the beginning Ex) {{}



/**
 * checkDelimiters.cpp -- a program that checks for properly balanced 
 * delimiters and marks the problems using the caret ('^') symbol.
 *
 * @author: Heather Dalont
 * @date: 02/27/2020
 */

//-----------------------------------------------------------------
// All the includes go here
//-----------------------------------------------------------------
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <iomanip>
//-----------------------------------------------------------------
// Prototypes. If you write other functions, put the prototypes
// (function signatures) here.
//-----------------------------------------------------------------
void checkDelimiters( char line[] );

//-----------------------------------------------------------------
// Defined constants
//-----------------------------------------------------------------
const int LINESIZE = 1024;

//-----------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------
bool verbose = false;

using namespace std;

int main( int argc, char *argv[] ) {
   char line[LINESIZE];
 
   if( argc == 2 && strcmp( argv[1], "-v" ) == 0) {
      verbose = true;
   }

   if( verbose ) {
      cout << "This program checks a line of characters for balanced delimiter." << endl
  	   << "{ }, [ ], < >, ( )" << endl
	   << "Enter a line (<ENTER> to quit): ";
   }

   // Loop, processing lines one at a time, until reach EOF or empty string.
   cin.getline(line, sizeof line, '\n');

   while( cin && strlen(line) > 0 ) {
      checkDelimiters( line );
      if( verbose ) {
	 cout << "Enter a line (<ENTER> to quit): ";
      }
      cin.getline(line, sizeof line, '\n');
   }

   return 0;
}


//-----------------------------------------------------------------

/**
 * Your code below. If you want extra functions, great. Write the code
 * below and add the function prototypes (signatures) with the other
 * function prototype for 'checkDelimiters' at the top of this file.
 */
void checkDelimiters( char line[] ) {
    stack <char> delimiters;
    stack<int> locations;
    for(int i=0;line[i]!='\0';i++){
        switch(line[i]){
            case '{':
            case '[':
            case '(':
            case '<':
                delimiters.push(line[i]);
                locations.push(i);
                break;
            case '}':
                if (delimiters.empty()){
                    cout<<line<<endl;
                    cout<<setw(i)<<""<<"^"<<endl;
                    cout<<"ERROR: extra closing delimiter "<<endl;
                    return;
                }else if(delimiters.top() != '{'){
                    int difference=i-(locations.top()+1);
                    cout<<line<<endl;
                    cout<<setw(locations.top()+1)<<"^"<<setw(difference+1)<<"^"<<endl;
                    cout<<"ERROR: delimiters don't match"<<endl;
                    return;
                }else{
                    delimiters.pop();
                    locations.pop();
                }break;
            case ']':
                if (delimiters.empty()){
                    cout<<line<<endl;
                    cout<<setw(i)<<""<<"^"<<endl;
                    cout<<"ERROR: extra closing delimiter "<<endl;
                    return;
                }else if(delimiters.top() != '['){
                    int difference=i-(locations.top()+1);
                    cout<<line<<endl;
                    cout<<setw(locations.top()+1)<<"^"<<setw(difference+1)<<"^"<<endl;
                    cout<<"ERROR: delimiters don't match"<<endl;
                    return;
                }else{
                    delimiters.pop();
                    locations.pop();
                }break;

            case ')':
                if (delimiters.empty()){
                    cout<<line<<endl;
                    cout<<setw(i)<<""<<"^"<<endl;
                    cout<<"ERROR: extra closing delimiter "<<endl;
                    return;
                }else if(delimiters.top() != '('){
                    int difference=i-(locations.top()+1);
                    cout<<line<<endl;
                    cout<<setw(locations.top()+1)<<"^"<<setw(difference+1)<<"^"<<endl;
                    cout<<"ERROR: delimiters don't match"<<endl;
                    return;
                }else{
                    delimiters.pop();
                    locations.pop();
                }break;

            case '>':
                if (delimiters.empty()){
                    cout<<line<<endl;
                    cout<<setw(i)<<""<<"^"<<endl;
                    cout<<"ERROR: extra closing delimiter "<<endl;
                    return;
                }else if(delimiters.top() != '<'){
                    int difference=i-(locations.top()+1);
                    cout<<line<<endl;
                    cout<<setw(locations.top()+1)<<"^"<<setw(difference+1)<<"^"<<endl;
                    cout<<"ERROR: delimiters don't match"<<endl;
                    return;
                }else{
                    delimiters.pop();
                    locations.pop();
                }break;

            default:
                //nada
                ;
        }//close switch

    }//close for
    if(!delimiters.empty()){
            cout<<line<<endl;
            cout<<setw(locations.top())<<""<<"^"<<endl;
            cout<<"ERROR: extra opening delimiter "<<endl;
            return;
    }//close if
}//close function
