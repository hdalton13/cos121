/**

 * checkout.cpp: checkout queue simulator. Simulates running one checkout register with one
 * customer queue.
 *
 * @author Heather Dalton
 * @date   03/05/2020
 *
 * Compile by typing "g++ -Wall checkout.cpp conio.cpp"
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <list>
#include "conio.h"

#define PAUSE_TIME 1
/***********************************************************************
 * A struct is a way of "clustering/clumping" related variables so that they can be used 
 * as one unit when you assign or compare them.
 * The Customer struct keeps track of everything that you need to know about one customer
 * for this simulation.
 * The Register struct keeps track of everything that you need to know about the activity
 * at the register.
 * Basic struct syntax is "struct StructName { variables };". The ';' at the end is required.
 ***********************************************************************/
struct Customer {
    int arrivalTime;
    int processingTime;
    int customerNumber;
};

struct Register1 {
    bool hasCustomer;
    int remainingTime;
    int customerNumber;
};
struct Register2 {
    bool hasCustomer;
    int remainingTime;
    int customerNumber;
};

/***********************************************************************
 * Prototypes here. A prototype is the declaration of a function that specifies the function name,
 * the parameter types, and the return type. A function prototype is needed whenever the
 * C++ compiler sees a function call to a function before it sees the actual function body
 * (the function definition). 
 ***********************************************************************/
void printQueue( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor );
void printLegend( conio::Color defaultTextColor );

using namespace std;

bool reg2open = false;

int main(int argc, char* argv[], char* envp[]) {

    /***********************************************************************
     * Seed the random number generator.
     * (Do a search on "random number generator to get more detail.)
     * Equally instructive is to run the simulation with the generator seeded and not seeded.
     * - Not seeded will produce the exact same "random number" sequence for each
     * program run. Good for debugging and manually verifying results, but bad
     * for simulating random behavior in general.
     * NOTE: You must only run srand() ONCE anywhere in the program!
     * Doing it more than once can really mess things up.
     ***********************************************************************/
    srand( time(NULL) ); //<=only done once
    
    list<Customer> customerQ;

    int simLength,               // Length of simulation (minutes)
        customerNumber = 0,      // Customer arrival order number (like number in driver's license branch)
        waitTime = 0,            // How long dequeued customer waited
        totalServed = 0,         // Total customers served
        totalWait   = 0,         // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0;         // Number of new arrivals
    Customer currentCustomer = { -1, -1, -1};  // The current customer
    Register1 register1 = { false, 0, -1 };     // The register gets declared and initialized
    Register2 register2 = { false, 0, -1 };

    // Figure out what to do with the text color (light vs. dark screen)
    conio::Color defaultTextColor;
    cout << "Is the screen color dark? ([Y]/n) ";
    char ans;
    cin.get(ans);
    if( ans=='n' || ans=='N' ) {
        defaultTextColor = conio::BLACK;
    } else {
        defaultTextColor = conio::WHITE;
    }
    if( ans != '\n' ) {
        cin.ignore(100, '\n');
    }

    // Determine how long to run the simulator.
    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    for ( int minute=1 ; minute<=simLength ; minute++ ) {
        // system("some command") will run any command that you could have typed at the prompt.
        // I could also have done this with conio, but wanted to demonstrate "system()".
        system("clear");

        /***********************************************************************
         * Determine the number of new customers and add them to the queue ...
         * one chance of one new arrival (the 1), one chance of two new arrivals (the 2),
         * three chances of no new arrivals (the 0 or 3). 
         * Feel free to adjust the switch statement in order to produce a greater
         * or lesser "customer load".
         ***********************************************************************/
        switch(rand() % 4) {
          case 1 : numArrivals = 1; break;
          case 2 : numArrivals = 2; break;
          case 3 : numArrivals = 3; break;
          default: numArrivals = 0;
        }

        /***********************************************************************
         * ... and add them to the queue.
         * Like above, one chance that register time takes 4 minutes (super-slow),
         * one chance that it takes 2 minutes, two chances that it takes one minute.
         * Again, feel free to adjust parameters.
         ***********************************************************************/
        for ( int j=0 ; j<numArrivals ; j++ ) {
            customerNumber++;

            /* -- For your reference.
             struct Customer { int arrivalTime; int processingTime; int customerNumber; };
            */

            Customer newCustomer;
            // Set the customer variable fields.
            newCustomer.arrivalTime = minute;

            // Different way of formatting the case statements. Decide which you think is more readable.
            switch ( rand() % 5 ) {    
              case 1 : newCustomer.processingTime = 6;
                       break;
              case 2 : newCustomer.processingTime = 1;
                       break;
              case 3 : newCustomer.processingTime = 2;
                       break;
              case 4 : newCustomer.processingTime = 3;
                       break;
              default: newCustomer.processingTime = 4;
                       break;
            }
            newCustomer.customerNumber = customerNumber;

            // Put the customer at the back of the queue. Below is the
            // STL version of the standard queue 'enqueue' command.
            customerQ.push_back(newCustomer);
        }

        /***********************************************************************
         * Dequeue the first customer in line (if any). Increment
         * totalServed, add the time that this customer waited to
         * totalWait, and update maxWait if this customer waited
         * longer than any previous customer.
         ***********************************************************************/

        if( ! register1.hasCustomer ) { // Try to get next customer if register is has no customer.

            // Can only get a customer if the queue is not empty.
            if ( ! customerQ.empty() ) {

                // Make a copy of the customer record at the front of the queue.
                // Don't remove customer from queue yet, else they don't show in queue.
                // Remove the customer when the customer has completed activity at the register.
                // NOTE: front() + pop_front() together are the STL equivalent 
                // of the classic queue "dequeue" command.
                currentCustomer = customerQ.front();
                customerQ.pop_front();

                /* -- for your reference
                 struct Register { bool hasCustomer; int remainingTime; int customerNumber; };
                 struct Customer { int arrivalTime; int processingTime; int customerNumber; };
                */
                // Set the register stuff
                register1.hasCustomer = true;
                register1.remainingTime = currentCustomer.processingTime;
                register1.customerNumber = currentCustomer.customerNumber;
            }
        }
        if (reg2open){
            if( ! register2.hasCustomer ) { // Try to get next customer if register is has no customer.
                if ( ! customerQ.empty() ) {
                    
                    currentCustomer = customerQ.front();
                    customerQ.pop_front();
                
                    register2.hasCustomer = true;
                    register2.remainingTime = currentCustomer.processingTime;
                    register2.customerNumber = currentCustomer.customerNumber;
                }
            }   
        }else if (minute - customerQ.front().arrivalTime <5){
                reg2open=false; //this closes reg2 when the current wait time is less than 5 (not red or purple)
        }

        /***********************************************************************
         * Display information about the simulation.
         ***********************************************************************/
        cout << conio::gotoRowCol(1, 1) << "CHECKOUT REGISTER SIMULATION";
        cout << conio::gotoRowCol(2, 1) << "Simulation minute: " << minute;

        // E.g., "Serving customer: 8   (2 minutes left)"
        cout << conio::gotoRowCol(4, 1) << "Reg1 Serving customer: ";
        if( register1.hasCustomer ) {
            cout << conio::fgColor(conio::CYAN) << register1.customerNumber << ' '
                 << conio::fgColor(defaultTextColor)
                 << conio::gotoRowCol(4, 25) << "(" << register1.remainingTime 
                 << " minute" << ((register1.remainingTime == 1)? "" : "s") << " left)";
        }
        cout << conio::gotoRowCol(5, 1) << "Reg2 Serving customer: ";
        if( register2.hasCustomer ) {
            cout << conio::fgColor(conio::CYAN) << register2.customerNumber << ' '
                 << conio::fgColor(defaultTextColor)
                 << conio::gotoRowCol(5, 25) << "(" << register2.remainingTime
                 << " minute" << ((register2.remainingTime == 1)? "" : "s") << " left)";
        }
        else {
            cout << conio::fgColor(conio::CYAN) << setw(10) << "none" 
                 << conio::fgColor(defaultTextColor);
        }
        cout << conio::gotoRowCol(10, 1) << "# customers finished: " << totalServed;

        // Show queue with the people in the queue, including highlighting to show how long they have waited.
        printQueue( customerQ, minute, defaultTextColor );
        printLegend( defaultTextColor );

        // Move the cursor out of the way and use "flush" to force all accumulated output to be sent to screen.
        cout << conio::gotoRowCol(15, 1) << flush;

        /***********************************************************************
         * Another minute has gone by. 
         * - Decrement the register count if there is a customer.
         * - If customer has finished at register, mark register is empty.
         ***********************************************************************/
        if( register1.hasCustomer ) {
            register1.remainingTime--;

            // If just finished serving this customer, mark register as not busy
            // and remove current customer from queue.
            if( register1.remainingTime == 0 ) {
                totalServed++;
                register1.hasCustomer = false;

                // Update general information used for statistics
                waitTime = minute-currentCustomer.arrivalTime;
                totalWait += waitTime;
                if( waitTime > maxWait ) {
                    maxWait = waitTime;
                }

                // Remove customer from queue
                // NOTE: front() + pop_front() together are the STL equivalent 
                // of the classic queue "dequeue" command.
                //customerQ.pop_front();

                // Update the screen information
            }
        }
        if( register2.hasCustomer ) {
            register2.remainingTime--;

            // If just finished serving this customer, mark register as not busy
            // and remove current customer from queue.
            if( register2.remainingTime == 0 ) {
                totalServed++;
                register2.hasCustomer = false;

                // Update general information used for statistics
                waitTime = minute-currentCustomer.arrivalTime;
                totalWait += waitTime;
                if( waitTime > maxWait ) {
                    maxWait = waitTime;
                }

                // Update the screen information
            }
        }
//        cout << conio::gotoRowCol(9, 1) << "# customers finished: " << totalServed;

        /***********************************************************************
         * Pause simulation for one second so screen doesn't go by too quickly to read.
         ***********************************************************************/
        sleep(PAUSE_TIME);

    } // End of the simulation loop

    /***********************************************************************
     * Print out simulation results.
     ***********************************************************************/
    cout << conio::gotoRowCol(16, 1) << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;

    return 0;
}

/***********************************************************************
 * Prints the customers in the queue using their customer numbers. Also does 
 * color coding of customers to show how long they have been waiting for service.
 * @param customers The list of customers, passed in as a reference so as to avoid
 *                  making a copy of it.
 * @param currentMinute The current minute in the simulation. Used to calculate
 *                  how long a customer has been in the queue.
 * @param defaultTextColor The default text color to set the text color
 *        back to after having changed it to other colors.
 ***********************************************************************/
void printQueue( list<Customer>& customers, int currentMinute, conio::Color defaultTextColor ) {
    list<Customer>::iterator it;
    cout << conio::gotoRowCol(7, 1) << "Customer queue: ";

    for (it=customers.begin(); it!=customers.end(); ++it) {
        if(currentMinute - it->arrivalTime > 10) {
            cout << conio::fgColor(conio::LIGHT_RED);
            reg2open = true;
        }
        else if(currentMinute - it->arrivalTime > 5) {
            cout << conio::fgColor(conio::LIGHT_MAGENTA);
        }
        else {
            cout << conio::fgColor(conio::LIGHT_GREEN);
        }
        cout << it->customerNumber << ' ' << conio::fgColor(defaultTextColor);
    }
}

/***********************************************************************
 * Prints the customer queue coloring legend.
 * @param defaultTextColor The default text color to set the text color
 *        back to after having changed it to other colors.
 ***********************************************************************/
void printLegend( conio::Color defaultTextColor ) {
    cout << conio::gotoRowCol(12, 1) 
         << "Wait time legend " << endl
         << conio::fgColor(conio::LIGHT_GREEN) << '*' << conio::fgColor(defaultTextColor) << " = wait < 5 min" << endl
         << conio::fgColor(conio::LIGHT_MAGENTA) << '*' << conio::fgColor(defaultTextColor) << " = wait 5-9 min" << endl
         << conio::fgColor(conio::LIGHT_RED) << '*' << conio::fgColor(defaultTextColor) << " = wait 10+ min" << endl;
}

