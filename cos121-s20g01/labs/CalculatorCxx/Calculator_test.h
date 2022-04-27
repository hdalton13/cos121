/**
  *Authors: Heather Dalton and Kayla Rehwoldt
  *Date: 04/30/2020
  */

#ifndef __INSTRUCTOR__TEST_
#define __INSTRUCTOR__TEST_

#include <cxxtest/TestSuite.h>
#include "Calculator.h"

/**
 *  Test class for Calculator.
 *
 *  @author  Stephen Edwards
 *  @version 2006.06.14
 *  Modified by Stefan Brandle
 *
 *  Comments: The class declaration line right below must be all on the same line, 
 *    else you get a compiler error. Astounding, but true.
 */

class Instructor__test : public CxxTest::TestSuite {
public:
    /**
     * Check that a new calculator starts off with a zero value.
     */
    void testConstructor() {
        Calculator calc;
        TS_ASSERT_EQUALS( calc.getValue(), 0 );
    }

    /**
     * Check that setValue/getValue work correctly.
     */
    void testSetValue() {
        Calculator calc;
        calc.setValue( 11 );
        TS_ASSERT_EQUALS( calc.getValue(), 11 );
    }

    /**
     * Check that clear works correctly.
     */
    void testClear() {
       Calculator calc;
       calc.setValue(46);
       calc.clear();
       TS_ASSERT_EQUALS( calc.getValue(), 0 );
    }

    /**
     * Check that add works correctly.
     */
    void testAdd() {
        Calculator calc;
        calc.setValue( 10 );
        calc.add( 7 );
        TS_ASSERT_EQUALS( calc.getValue(), 17 );
    }

    /**
     * Check that subtract works correctly.
     */
    void testSubtract() {
        Calculator calc;
        calc.setValue( 10 );
        calc.subtract( 7 );
        TS_ASSERT_EQUALS( calc.getValue(), 3 );
    }

    /**
     * Check that multiplyBy works correctly.
     */
    void testMultiplyBy() {
        Calculator calc;
        calc.setValue( 2 );
        calc.multiplyBy( 10 );
        TS_ASSERT_EQUALS( calc.getValue(), 20 );
    }

    /**
     * Check that divideBy works correctly.
     */
    void testDivideBy() {
        Calculator calc;
        calc.setValue( 20 );
        calc.divideBy( 10 );
        TS_ASSERT_EQUALS( calc.getValue(), 2 );
    }

};

#endif /*__INSTRUCTOR__TEST_*/
