/**
 * @file    Calculator.cpp
 * Calculator.cpp: a program that contains a calculator class and a main
 * function to use and test the function.
 *
edited by:   Heather Dalton and Kayla Rehwoldt
date:        04/30/2020

test     g++ -Wall *.cpp


 * For each function in the class declaration, first change the ';' to {}, then
 * fill in the body of the function to make the class work.
 */

#include "Calculator.h"

using namespace std;

/**
 *  This class represents a simple calculator that contains a single
 *  integer accumulator.  It provides basic methods to set/get/clear the
 *  accumulator's value, as well as to add, subtract, multiply, and
 *  divide.  All operations leave their results in the accumulator for
 *  further manipulation.
 *
 *  @author  Stephen Edwards, modified by Stefan Brandle
 *  @version 2009.09.10
 */

/**
 * Initializes a new Calculator object with zero in the accumulator.
 */

Calculator::Calculator() {
    this->value = 0;
    //this->value == value 
    //every obj. has a pointer like this. this contains
        //(* this).value
    //
}

/**
 * Does any final cleanup for the object (e.g., returning memory to the memory manager) before object is destroyed.
 */
Calculator::~Calculator() {
    // Nothing to be done here in the destructor.
	// Normally, the destructor returns memory to the memory manager
	// and does other "cleaning up before the object disappears" tasks.
}

/**
 * Retrieve the current value stored in the accumulator.
 * @return the accumulator's value
 */

// Write the entire getValue function below.
// Format is: returnValue className::functionName( params ) const { ...
// NOTE: the const is only when the prototype in Calculator.h has const after the parameter parentheses.

int Calculator::getValue() const{
    return this->value;
}

/**
 * Sets the value of the accumulator to a new value.
 * @param val the new accumulator value
 */
// write the setValue function below

void Calculator::setValue( int newVal ){
    this->value = newVal;
}


/**
 * Clears the accumulator by setting its value to zero.
 */
// write the clear function below

void Calculator::clear(){
    this->value = 0;
}

/**
 * Update the accumulator by adding a number to
 * @param val the amount to add
 */
// write the add function below

void Calculator::add( int valAdd ){
    this->value += valAdd; 
}

/**
 * Update the accumulator by subtracting a number from it.
 * @param val the amount to subtract
 */
// write the subtract function below

void Calculator::subtract( int valSub ){
    this->value -= valSub;
}

/**
 * Update the accumulator by multiplying it by a specified amount.
 * @param val the amount to multiply by
 */
// write the multiplyBy function below

void Calculator::multiplyBy( int valMult ){
    this->value *= valMult;
}



/**
 * Update the accumulator by dividing it by a specified amount.
 * @param val the amount to divide by
 */
// write the divideBy function below

void Calculator::divideBy( int valDiv ){
    this->value /= valDiv;
}

