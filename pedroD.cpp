/**
 * Pedro's dilemma program starter.
 * Your name: Heather Dalton
 * Today's date: 02/20/2020
 * 
 * Pedro was getting married and wanted to figure out what his new budget would be. He decided that the easy way was
 * to write a program that read in all the current budget numbers, multiplied them by two, and printed the product. He also
 * decided to have the program keep a running total and print the total as the last thing the program did.
 *
 * Your program will read each integer input (just whole numbers, no decimal part) one number per line, multiple the number by two,
 * and print the product on a separate line.
 *
 * When your program reaches the end of input (the system indicates to the program that there is no more data by setting 'cin' to false), 
 * your program is to print (on a line by itself) the total of all the products in the format "Total = N", where "N" represents the total of the products.
 */

// Include the Input/Output data STREAM information needed by the program
#include <iostream>
using namespace std;

int main() {
// Your code goes below.
	int total=0;
	int num=-1;
	string name="Total= ";
	cin >> num;
	while (cin){
		cout<<num*2<<endl;
		total= total +num*2;
		cin>>num;
	}
	cout<<name<<total<<endl;	

// When the program has finished running, it should return the value 0 to the system to show that the program terminated without problems.
    return 0;
}
