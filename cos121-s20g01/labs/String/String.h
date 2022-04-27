//--------------------------------------------------------------------
//  Class declaration for the String class.
//  Last mod: Wed Feb 23 12:58:19 EST 2011
//--------------------------------------------------------------------

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String
{
  public:

    // Constructors, destructors, and assignment
    String ( );                                      // Default constructor
    String ( const String &other );                  // Copy constructor
    String ( const char *charSeq );                  // Copy constructor
    void operator = ( const String &other );         // Assignment
    ~String();                                       // Destructor

    // Transformer functions
    // - Setters
    void set( char *charSeq );                       // Sets string equiv to charSeq
    void set( string other );                        // Sets string equiv to other
    void set( String other );                        // Sets string equiv to other
    //     Other transformers
    void clear ();                                   // Clear string

    // Observer functions
    // - Getters
    const char* c_str() const;                       // Returns C-string
    // - Other observers
    int getLength () const;                          // # characters
    char operator [] ( int n ) const;                // Subscript
    bool operator == ( const String& other ) const;
    void print () const;                             // Print the string for debugging

  protected:

    // Data members
    int bufferSize;   // Size of the string buffer
    char *buffer;     // String buffer containing a null-terminated sequence of characters

};
#endif    /* ifndef STRING_H */
