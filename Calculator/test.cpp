/**
 * @file    test.cpp
 * @brief   Calculator class test program.
 * @author  Heather Dalton
 */

#include <iostream>

// You need to #include the Calculator header file right below this.
#include "Calculator.h"

using namespace std;

int main() {

    Calculator calc;

    cout << endl << "*** Start UNIT tests of Calculator class." << endl << endl;

    // Test the constructor. The calculator accumulator (value) should be 0.
    if(calc.getValue() != 0) {
        cout << ". Constructor test: fail. getValue() should return 0, but returns " << calc.getValue() << endl;
    } else {
        cout << "F Constructor test: pass" << endl;
    }
    
	//**********************************
    // Now write tests that demonstrate the rest of your Calculator class code works correctly.
	//**********************************

	// Test getValue() & Test setValue()
	calc.setValue(5); 
    if (calc.getValue()!=5){
        cout<< "F getValue/setValue test: fail. getValue should equal 5 but returns"<< calc.getValue()<<endl;
    }else{
        cout<< "getValue/setValue test: PASS"<<endl;
    }
	 
	// Test clear()
	calc.clear();
    if (calc.getValue()!=0){
        cout<< "F clear test: fail. getValue should equal 0 but returns"<< calc.getValue()<<endl;
    }else{
        cout<< "clear test: PASS"<<endl;
    }

	// Test add()
    calc.add(10);
    if (calc.getValue()!=10){
        cout<< "F add test: fail. getValue should equal 10 but returns"<< calc.getValue()<<endl;
    }else{
        cout<< "add test: PASS"<<endl;
    }	 

	// Test subtract()
	calc.subtract(5);
    if (calc.getValue()!=5){
        cout<< "F subtract test: fail. getValue should equal 5 but returns"<< calc.getValue()<<endl;
    }else{
        cout<< "subtract test: PASS"<<endl;
    }
     
	// Test multiplyBy()
	calc.multiplyBy(5);
    if (calc.getValue()!=25){
        cout<< "F multiplyBy test: fail. getValue should equal 25 but returns"<< calc.getValue()<<endl;
    }else{
        cout<< "multiplyBy test: PASS"<<endl;
    }
     
	// Test divideBy()
    calc.divideBy(5);
    if (calc.getValue()!=5){
        cout<< "F divideBy test: fail. getValue should equal 5 but returns"<< calc.getValue()<<endl;
    }else{
        cout<< "divideBy test: PASS"<<endl;
    }
	 
     
    cout << endl << "*** END UNIT tests of Calculator class." << endl << endl;

    return 0;
}
