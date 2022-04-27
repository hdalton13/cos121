//--------------------------------------------------------------------
//  Class declaration for the String class.
//  Last mod: Mon Apr  6 11:58:36 EDT 2020
//  Kayla Rehwoldt and Heather Dalton 
//--------------------------------------------------------------------

//to compile g++ -Wall -c String.cpp

#ifndef STRING_CPP
#define STRING_CPP

#include <string>
#include <cstring>
#include "String.h"

//--------------------------------------------------------------------
// Constructors, destructors, and assignment
//--------------------------------------------------------------------
// Default copy constructor
String::String ( ) {
    this->bufferSize = 1;
    this->buffer = new char[bufferSize];
    this->buffer[0] = '\0';
    //this->buffer[0] = char(0);
}

// Copy constructor: initializes object to be equivalent to the "other" object.
String::String ( const String &other ) {
    this->bufferSize = other.bufferSize;
    this->buffer = new char[bufferSize];
    strcpy( this->buffer, other.buffer);
}

// Copy constructor: initializes object to represent an equivalent 
// string as the C-string pointed to be "charSeq".
String::String ( const char *charSeq ) {
    this->bufferSize = strlen( charSeq ) + 1;
    this->buffer = new char[bufferSize];
    strcpy( this->buffer, charSeq );
}

// Assignment operator. Sets this object to be equivalent to other object.
void String::operator = ( const String &other ) {
    if (this ==&other) return;

    if (bufferSize < other.bufferSize){
        delete[] buffer;
        bufferSize= other.bufferSize;
        this->buffer =  new char[bufferSize];
    }
    strcpy(buffer, other.buffer);
}

// Destructor. Main purpose is to return borrowed memory to the memory manager.
String::~String() {
    delete[] buffer;
}

//--------------------------------------------------------------------
// Transformers
//--------------------------------------------------------------------
// Setters
void String::set( char *charSeq ) {

    delete[] buffer;
    bufferSize = strlen(charSeq) + 1;
    buffer = new char[bufferSize];
    strcpy (buffer, charSeq);
}

void String::set( string other ) {
    // c string
    // I'm stuck on the function void String::set( string other ). Can 

   delete[] buffer;
   bufferSize = strlen(other.c_str())+ 1;
   buffer = new char[bufferSize];
   strcpy (buffer, other.c_str());
}


void String::set( String other ) {
    operator=(other);
}

// Getters
const char* String::c_str() const {
    return buffer;
}

// Other transformers
void String::clear () {
    this->buffer[0] = char(0);
}


//--------------------------------------------------------------------
// Observers
//--------------------------------------------------------------------

int String::getLength () const {

    return strlen(buffer );
}

char String::operator [] ( int n ) const {
    if (n<0 || (unsigned int) n >= strlen(buffer)) return char(0);
    return buffer[n];
}

bool String::operator == ( const String &other ) const {
    
    if( strcmp( other.buffer, this->buffer ) == 0 ) return true;
    return false;
}

void String::print () const {
    cout << "bufferSize = " << bufferSize << ", buffer = " << buffer << endl;
}

#endif    /* ifndef STRING_CPP */
