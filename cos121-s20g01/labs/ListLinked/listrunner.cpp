/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "__student_singly_linked_list_test.h"

static Stu_Singly_Linked_List_Test suite_Stu_Singly_Linked_List_Test;

static CxxTest::List Tests_Stu_Singly_Linked_List_Test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Stu_Singly_Linked_List_Test( "__student_singly_linked_list_test.h", 10, "Stu_Singly_Linked_List_Test", suite_Stu_Singly_Linked_List_Test, Tests_Stu_Singly_Linked_List_Test );

static class TestDescription_Stu_Singly_Linked_List_Test_testDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testDefaultConstructor() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 14, "testDefaultConstructor" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testDefaultConstructor(); }
} testDescription_Stu_Singly_Linked_List_Test_testDefaultConstructor;

static class TestDescription_Stu_Singly_Linked_List_Test_testParameterizedConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testParameterizedConstructor() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 23, "testParameterizedConstructor" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testParameterizedConstructor(); }
} testDescription_Stu_Singly_Linked_List_Test_testParameterizedConstructor;

static class TestDescription_Stu_Singly_Linked_List_Test_testAdd : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testAdd() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 32, "testAdd" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testAdd(); }
} testDescription_Stu_Singly_Linked_List_Test_testAdd;

static class TestDescription_Stu_Singly_Linked_List_Test_testRemove : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testRemove() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 47, "testRemove" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testRemove(); }
} testDescription_Stu_Singly_Linked_List_Test_testRemove;

static class TestDescription_Stu_Singly_Linked_List_Test_testReplace : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testReplace() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 75, "testReplace" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testReplace(); }
} testDescription_Stu_Singly_Linked_List_Test_testReplace;

static class TestDescription_Stu_Singly_Linked_List_Test_testClear : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testClear() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 95, "testClear" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testClear(); }
} testDescription_Stu_Singly_Linked_List_Test_testClear;

static class TestDescription_Stu_Singly_Linked_List_Test_testIsEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testIsEmpty() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 108, "testIsEmpty" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testIsEmpty(); }
} testDescription_Stu_Singly_Linked_List_Test_testIsEmpty;

static class TestDescription_Stu_Singly_Linked_List_Test_testIsFull : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testIsFull() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 115, "testIsFull" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testIsFull(); }
} testDescription_Stu_Singly_Linked_List_Test_testIsFull;

static class TestDescription_Stu_Singly_Linked_List_Test_testGotoEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testGotoEnd() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 122, "testGotoEnd" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testGotoEnd(); }
} testDescription_Stu_Singly_Linked_List_Test_testGotoEnd;

static class TestDescription_Stu_Singly_Linked_List_Test_testGotoNext : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testGotoNext() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 135, "testGotoNext" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testGotoNext(); }
} testDescription_Stu_Singly_Linked_List_Test_testGotoNext;

static class TestDescription_Stu_Singly_Linked_List_Test_testGotoPrior : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testGotoPrior() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 148, "testGotoPrior" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testGotoPrior(); }
} testDescription_Stu_Singly_Linked_List_Test_testGotoPrior;

static class TestDescription_Stu_Singly_Linked_List_Test_testCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testCopyConstructor() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 169, "testCopyConstructor" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testCopyConstructor(); }
} testDescription_Stu_Singly_Linked_List_Test_testCopyConstructor;

static class TestDescription_Stu_Singly_Linked_List_Test_testAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testAssignmentOperator() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 183, "testAssignmentOperator" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testAssignmentOperator(); }
} testDescription_Stu_Singly_Linked_List_Test_testAssignmentOperator;

static class TestDescription_Stu_Singly_Linked_List_Test_testGetSize : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testGetSize() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 217, "testGetSize" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testGetSize(); }
} testDescription_Stu_Singly_Linked_List_Test_testGetSize;

static class TestDescription_Stu_Singly_Linked_List_Test_testGetCursorPosition : public CxxTest::RealTestDescription {
public:
 TestDescription_Stu_Singly_Linked_List_Test_testGetCursorPosition() : CxxTest::RealTestDescription( Tests_Stu_Singly_Linked_List_Test, suiteDescription_Stu_Singly_Linked_List_Test, 228, "testGetCursorPosition" ) {}
 void runTest() { suite_Stu_Singly_Linked_List_Test.testGetCursorPosition(); }
} testDescription_Stu_Singly_Linked_List_Test_testGetCursorPosition;

#include <cxxtest/Root.cpp>
