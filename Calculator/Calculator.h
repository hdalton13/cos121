//Heather Dalton
//03/12/2020

// The two lines below add "double inclusion protection". 
// Double inclusion protection will be explained later in the semester.

#ifndef CALCULATOR_H
#define CALCULATOR_H

// This file contains the class prototypes and variables. You should read through this,
// but do NOT write any code in "Calculator.h".


/**
 *  This class represents a simple calculator that contains a single integer accumulator.  
 *  The Calculator provides basic methods to set/get/clear the accumulator's value, 
 *  as well as to add, subtract, multiply, and divide.  
 *  All operations leave their results in the accumulator for further manipulation.
 *
 *  @file    Calculator.h
 *  @author  Stephen Edwards
 *  @author  Stefan Brandle (modifications)
 *  @version 2020.03.07
 */

class Calculator {
  public:
    /**
     * @brief Constructor: initializes a new Calculator object with zero in the accumulator.
     */
    Calculator();

    /**
     * @brief Destructor: does any final cleanup for the object (e.g., returning memory to the memory manager)
     * before object is destroyed.
     */
    virtual ~Calculator();

    /**
     * @brief Retrieve the current value stored in the accumulator.
     * @return the accumulator's value
     */
    virtual int getValue() const;

    /**
     * @brief Sets the value of the accumulator to a new value.
     * @param val the new accumulator value
	 * @return Nothing
     */
    virtual void setValue( int val );

    /**
     * @brief Clears the accumulator by setting its value to zero.
	 * @return Nothing
     */
    virtual void clear();

    /**
     * @brief Update the accumulator by adding a number to it.
     * @param val the amount to add
	 * @return Nothing
     */
    virtual void add( int val );

    /**
     * @brief Update the accumulator by subtracting a number from it.
     * @param val the amount to subtract
	 * @return Nothing
     */
    virtual void subtract( int val );

    /**
     * @brief Update the accumulator by multiplying it by a specified amount.
     * @param val the amount to multiply by
	 * @return Nothing
     */
    virtual void multiplyBy( int val );

    /**
     * @brief Update the accumulator by dividing it by a specified amount.
     * @param val the amount to divide by
	 * @return Nothing
     */
    virtual void divideBy( int val );

  private:
    int value;
};

#endif /*CALCULATOR_H*/
