#ifndef __INSTRUCTOR_TEST_H
#define __INSTRUCTOR_TEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include "StringWrapper.h"

class StringTest : public CxxTest::TestSuite{
    public:
	//String testString("Hello");
	// Fixture setup
	//void setUp() {
	//}
	
	// Fixture teardown
	//void tearDown() {
	//}
	
	void testDefaultConstructor() {
	    //Run Function and do setup
	    StringWrapper testString;

	    //Test Postconditions
	    //  Make sure that buffer contains an empty string
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), ""), 0);
	    //  Make sure that buffer size is 1 for empty string
	    TS_ASSERT_EQUALS(testString.getBufferSize(), 1);
	}

	void testConversionConstructor() {
	    //Run Function and do setup
	    StringWrapper testString("Hello");

	    //Test Postconditions
	    //  Should have the right contents
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), "Hello"), 0);
	    //  Buffer should be correct size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), 6);
	}

	void testCopyConstructor() {
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    StringWrapper testString2(testString);

	    //Test Postconditions
	    // Buffers should be same size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), testString2.getBufferSize());
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(testString.getBuffer(), testString2.getBuffer());
	}

	void testAssignmentOperator() {
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    StringWrapper testString2("Hi");
	    testString2 = testString;

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(testString.getBuffer(), testString2.getBuffer());
	    // Buffers should be same size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), testString2.getBufferSize());
	}

	void testSetCString() {
	    //Run Function and do setup
	    char testString [] = "Hello";
	    StringWrapper testString2("Hi");
	    testString2.set(testString);

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString, testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(testString, testString2.getBuffer());
	}

	void testC_str() {
	    //Run Function and do setup
	    const char *str = "Hello";
	    StringWrapper testString2(str);
	    const char *testString = testString2.c_str();

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString, testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(str, testString2.getBuffer());
	}

	void testSetString() {
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    StringWrapper testString2("Hi");
	    testString2.set(testString);

	    //Test Postconditions
	    // Buffers should be equivalent ...
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), testString2.getBuffer()), 0);
	    //    but not identical.
	    TS_ASSERT_DIFFERS(testString.getBuffer(), testString2.getBuffer());
	    // Buffers should be same size
	    TS_ASSERT_EQUALS(testString.getBufferSize(), testString2.getBufferSize());
	}

	void testLength() {
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    TS_ASSERT_EQUALS(testString.getLength(), 5);
	}

	void testIndexOperator() {
	    //Run Function and do setup
	    StringWrapper testString("Hello");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString[0], 'H');
	    TS_ASSERT_EQUALS(testString[1], 'e');
	    TS_ASSERT_EQUALS(testString[2], 'l');
	    TS_ASSERT_EQUALS(testString[3], 'l');
	    TS_ASSERT_EQUALS(testString[4], 'o');
	    TS_ASSERT_EQUALS(testString[5], '\0');
	    //  And now test possibly missed casses
	    TS_ASSERT_EQUALS(testString[6], '\0');
	    TS_ASSERT_EQUALS(testString[10000], '\0');
	    TS_ASSERT_EQUALS(testString[-1], '\0');
	    TS_ASSERT_EQUALS(testString[-10000], '\0');
	}

	void testClear() {
	    //Run Function and do setup
	    StringWrapper testString("Hello");
	    testString.clear();

	    //Test Postconditions
	    TS_ASSERT_EQUALS(strcmp(testString.getBuffer(), ""), 0);
	}

	//void testtoUpper1() {
	//    // Testing all lc
	//    //Run Function and do setup
	//    StringWrapper testString("hello");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(strcmp(StringWrapper(testString.toUpper()).getBuffer(), "HELLO"), 0);
	//}

	//void testtoUpper2() {
	//    //Testing with empty string
	//    //Run Function and do setup
	//    StringWrapper testString("");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(strcmp(StringWrapper(testString.toUpper()).getBuffer(), ""), 0);
	//}

	//void testtoUpper3() {
	//    //Testing mixed uc/lc/digits/punct
	//    //Run Function and do setup
	//    StringWrapper testString("H3ll0.");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(strcmp(StringWrapper(testString.toUpper()).getBuffer(), "H3LL0."), 0);
	//}

	//void testtoUpper4() {
	//    //Testing all uc
	//    //Run Function and do setup
	//    StringWrapper testString("HELLO");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(strcmp(StringWrapper(testString.toUpper()).getBuffer(), "HELLO"), 0);
	//}

	//void testtoLower1() {
	//    // Testing all uc
	//    //Run Function and do setup
	//    StringWrapper testString("HELLO");

	//    //Test Postconditions
	//    TS_ASSERT_DIFFERS(strcmp(StringWrapper(testString.toLower()).getBuffer(), "HELLO"), 0);
	//}

	//void testtoLower2() {
	//    // Testing all lc
	//    //Run Function and do setup
	//    StringWrapper testString("hello");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(strcmp(StringWrapper(testString.toLower()).getBuffer(), "hello"), 0);
	//}

	//void testtoLower3() {
	//    // Testing empty string
	//    //Run Function and do setup
	//    StringWrapper testString("");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(strcmp(StringWrapper(testString.toLower()).getBuffer(), ""), 0);
	//}

	//void testtoLower4() {
	//    // Testing mixed lc/uc/digit/punct
	//    //Run Function and do setup
	//    StringWrapper testString("H3!lO.");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(strcmp(StringWrapper(testString.toLower()).getBuffer(), "h3!lo."), 0);
	//}

	void testOperatorEquals1() {
	    // Testing strings that are equivalent
	    //Run Function and do setup
	    StringWrapper testString1("Hello");
	    StringWrapper testString2("Hello");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString1 == testString2, true);
	}

	void testOperatorEquals2() {
	    // Testing strings that are not equivalent
	    //Run Function and do setup
	    StringWrapper testString1("Hello");	// Mixed case
	    StringWrapper testString2("hello");	// Different case

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString1 == testString2, false);
	}

	void testOperatorEquals3() {
	    // Testing strings that are not same length
	    //Run Function and do setup
	    StringWrapper testString1("Hello");	
	    StringWrapper testString2("He");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString1 == testString2, false);
	}

	void testOperatorEquals4() {
	    // Testing with one empty string
	    //Run Function and do setup
	    StringWrapper testString1("Hello");	
	    StringWrapper testString2("");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString1 == testString2, false);
	}

	void testOperatorEquals5() {
	    // Testing with two empty strings
	    //Run Function and do setup
	    StringWrapper testString1("");	
	    StringWrapper testString2("");

	    //Test Postconditions
	    TS_ASSERT_EQUALS(testString1 == testString2, true);
	}

	//void testOperatorLessThan1() {
	//    // Testing strings where #1 < #2
	//    //Run Function and do setup
	//    StringWrapper testString1("aa");
	//    StringWrapper testString2("ab");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 < testString2, true);
	//}

	//void testOperatorLessThan2() {
	//    // Testing strings where #1 > #2
	//    //Run Function and do setup
	//    StringWrapper testString1("ab");
	//    StringWrapper testString2("aa");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 < testString2, false);
	//}

	//void testOperatorLessThan3() {
	//    // Testing strings where #1 == #2
	//    //Run Function and do setup
	//    StringWrapper testString1("aa");
	//    StringWrapper testString2("aa");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 < testString2, false);
	//}

	//void testOperatorLessThan4() {
	//    // Testing strings where #1 is empty -- "" < "aa"
	//    //Run Function and do setup
	//    StringWrapper testString1("");
	//    StringWrapper testString2("aa");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 < testString2, true);
	//}

	//void testOperatorLessThan5() {
	//    // Testing strings where #2 is empty -- "aa" < ""
	//    //Run Function and do setup
	//    StringWrapper testString1("aa");
	//    StringWrapper testString2("");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 < testString2, false);
	//}

	//void testOperatorGreaterThan1() {
	//    // Testing strings where #1 < #2
	//    //Run Function and do setup
	//    StringWrapper testString1("aa");
	//    StringWrapper testString2("ab");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 > testString2, false);
	//}

	//void testOperatorGreaterThan2() {
	//    // Testing strings where #1 > #2
	//    //Run Function and do setup
	//    StringWrapper testString1("ab");
	//    StringWrapper testString2("aa");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 > testString2, true);
	//}

	//void testOperatorGreaterThan3() {
	//    // Testing strings where #1 == #2
	//    //Run Function and do setup
	//    StringWrapper testString1("aa");
	//    StringWrapper testString2("aa");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 > testString2, false);
	//}

	//void testOperatorGreaterThan4() {
	//    // Testing strings where #1 is empty -- "" < "aa"
	//    //Run Function and do setup
	//    StringWrapper testString1("");
	//    StringWrapper testString2("aa");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 > testString2, false);
	//}

	//void testOperatorGreaterThan() {
	//    // Testing strings where #2 is empty -- "aa" > ""
	//    //Run Function and do setup
	//    StringWrapper testString1("aa");
	//    StringWrapper testString2("");

	//    //Test Postconditions
	//    TS_ASSERT_EQUALS(testString1 > testString2, true);
	//}
};

#endif   // ifndef __INSTRUCTOR_TEST_H
