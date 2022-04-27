//--------------------------------------------------------------------
//
//  Laboratory 1                                           test1.cpp
//
//  Test program for the operations in the String ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "String.h"

//--------------------------------------------------------------------
//
//  Function prototype

void copyTester ( String copyString );   // copyString is passed by value
void print_help ( );

//--------------------------------------------------------------------

int main()
{
    String a("a"),                // Predefined test String objects
         alp("alp"),
         alpha("alpha"),
         epsilon("epsilon"),
         empty,
         assignString,          // Destination for assignment
         inputString;           // Input String object
    int n;                        // Input subscript
    char ch,                      // Character specified by subscript
         selection;               // Input test selection

    // Get user test selection.
    print_help();

    // Execute the selected test.
    cin >> selection;

    cout << endl;
    switch ( selection )
    {
      case '1' :
           // Test 1 : Tests the constructors.
           cout << "Structure of various String objects: " << endl;
           cout << "String object: alpha" << endl;
           alpha.showStructure();
           cout << "String object: epsilon" << endl;
           epsilon.showStructure();
           cout << "String object: a" << endl;
           a.showStructure();
           cout << "empty String object" << endl;
           empty.showStructure();
           break;
      case '2' :
           // Test 2 : Tests the length operation.
           cout << "Lengths of various String object:"  << endl;
           cout << " alpha   : " << alpha.getLength() << endl;
           cout << " epsilon : " << epsilon.getLength() << endl;
           cout << " a       : " << a.getLength() << endl;
           cout << " empty   : " << empty.getLength() << endl;
           break;

      case '3' :
           // Test 3 : Tests the subscript operation.
           cout << "Enter a subscript : ";
           cin >> n;
           ch = alpha[n];
           cout << "  alpha[" << n << "] : ";
           if ( ch == '\0' )
              cout << "\\0" << endl;
           else
              cout << ch << endl;
           break;

      case '4' :
           // Test 4 : Tests the assignment and clear operations.
           cout << "Assignments:" << endl;
           cout << "assignString = alpha" << endl;
           assignString = alpha;
           assignString.showStructure();
           cout << "assignString = a" << endl;
           assignString = a;
           assignString.showStructure();
           cout << "assignString = empty" << endl;
           assignString = empty;
           assignString.showStructure();
           cout << "assignString = epsilon" << endl;
           assignString = epsilon;
           assignString.showStructure();
           cout << "assignString = assignString" << endl;
           assignString = assignString;
           assignString.showStructure();
           cout << "assignString = alpha" << endl;
           assignString = alpha;
           assignString.showStructure();
           cout << "Clear assignString" << endl;
           assignString.clear();
           assignString.showStructure();
           cout << "Confirm that alpha has not been cleared" << endl;
           alpha.showStructure();
           break;

      case '5' :
           // Test 5 : Tests the copy constructor and operator= operations.
           cout << "Calls by value:" << endl;
           cout << "alpha before call" << endl;
           alpha.showStructure();
           copyTester(alpha);
           cout << "alpha after call" << endl;
           alpha.showStructure();

           cout << "a before call" << endl;
           a.showStructure();
           a = epsilon;
           cout << "a after call" << endl;
           a.showStructure();
           cout << "epsilon after call" << endl;
           epsilon.showStructure();
           break;

#if   LAB1_TEST1
      case '6' :                                  // In-lab Exercise 2
           // Test 6 : Tests toUpper and toLower
           cout << "Testing toUpper and toLower." 
                << "Enter a mixed case string: " << endl;
	   cin >> inputString;
	   cout << "Input string:" << endl;
           inputString.showStructure();
           cout << "Upper case copy: " << endl;
           inputString.toUpper().showStructure();
           cout << "Lower case copy: " << endl;
           inputString.toLower().showStructure();
           break;
#endif // LAB1_TEST1

#if   LAB1_TEST2
      case '7' :                                  // In-lab Exercise 3
           // Test 7 : Tests the relational operations.
           cout << "  left     right     <   ==   > " << endl;
           cout << "--------------------------------" << endl;
           cout << " alpha    epsilon    " << (alpha<epsilon)
                << "    " << (alpha==epsilon) << "   "
                << (alpha>epsilon) << endl;
           cout << " epsilon   alpha     " << (epsilon<alpha)
                << "    " << (epsilon==alpha) << "   "
                << (epsilon>alpha) << endl;
           cout << " alpha     alpha     " << (alpha<alpha) << "    "
                << (alpha==alpha) << "   " << (alpha>alpha) << endl;
           cout << "  alp      alpha     " << (alp<alpha) << "    "
                << (alp==alpha) << "   " << (alp>alpha) << endl;
           cout << " alpha      alp      " << (alpha<alp) << "    "
                << (alpha==alp) << "   " << (alpha>alp) << endl;
           cout << "   a       alpha     " << (a<alpha) << "    "
                << (a==alpha) << "   " << (a>alpha) << endl;
           cout << " alpha       a       " << (alpha<a) << "    "
                << (alpha==a) << "   " << (alpha>a) << endl;
           cout << " empty     alpha     " << (empty<alpha) << "    "
                << (empty==alpha) << "   " << (empty>alpha) << endl;
           cout << " alpha     empty     " << (alpha<empty) << "    "
                << (alpha==empty) << "   " << (alpha>empty) << endl;
           cout << " empty     empty     " << (empty<empty) << "    "
                << (empty==empty) << "   " << (empty>empty) << endl;
           break;
#endif // LAB1_TEST2

      default :
           cout << "'" << selection << "' specifies an inactive or invalid test" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------

void copyTester ( String copyString )

// Dummy routine that is passed a String object using call by value. Outputs
// copyString and clears it.

{
    cout << "Copy of String object" << endl;
    copyString.showStructure();
    cout << "Clear copy" << endl;
    copyString.clear();
    copyString.showStructure();
}

//--------------------------------------------------------------------

void print_help()
{
    cout << endl << "Tests:" << endl;
    cout << "  1  Tests the constructors" << endl;
    cout << "  2  Tests the length operation" << endl;
    cout << "  3  Tests the subscript operation" << endl;
    cout << "  4  Tests the assignment and clear operations" << endl;
    cout << "  5  Tests the copy constructor and operator= operations" << endl;

    cout << "  6  Tests the toUpper and toLower operations      " 
#if	LAB1_TEST1
         << "(Active   : "
#else
         << "(Inactive : "
#endif	// LAB1_TEST1
         << "In-lab Exercise 2)" << endl;

    cout << "  7  Tests the relational operations    "
#if	LAB1_TEST2
         << "           (Active   : "
#else
         << "           (Inactive : "
#endif	// LAB1_TEST2
         << "In-lab Exercise 3)" << endl;
    cout << "Select the test to run : ";
}


