/**
 * @file ListArray.cpp
 * @brief Array-based implementation of the List ADT.
 * @authors: Heather Dalton & Kayla Rehwoldt 
 */

#ifndef LISTARRAY_CPP
#define LISTARRAY_CPP

#include <iostream>
#include "ListArray.h"

using namespace std;

/**
 * @brief Default constructor.
 * @returns Nothing Constructors do not have a return value of any kind.
 * Initializes the List object's instance variables, sets the array size to defaultMaxSize,
 * makes dataItems point at a dynamically created array of the correct size.
 */
template <typename DataType>
List<DataType>::List()
// Initialize the object's member variables
: maxSize(defaultMaxSize), size(0), cursor(-1)
{
    // Make the array to put the items in and point dataItems there.
     dataItems = new DataType[maxSize];
}

template <typename DataType>
List<DataType>::List(int maxItems)
:maxSize(maxItems), size(0), cursor(-1)
{
    dataItems = new DataType[maxSize];
}

template <typename DataType>
List<DataType>::List(const List& other){
    maxSize = other.maxSize;
    size = other.size;
    cursor = other.cursor;
    dataItems = new DataType[maxSize];
    operator=( other );
}

template <typename DataType>
List<DataType>::~List(){
    delete[] dataItems;
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other){
    if( this == &other) return *this;

    delete[] dataItems;
    maxSize = other.maxSize;
    cursor = other.cursor;
    size = other.size;    
    dataItems = new DataType[maxSize];
    
    for(int i=0; i<size; i++){
        dataItems[i] = other.dataItems[i];
    }

    return *this;
}

template <typename DataType>
bool List<DataType>::gotoNext(){
    if( cursor == size -1 ) return false;
    else {
        cursor++;
        return true;
    }
}    

template <typename DataType>
bool List<DataType>::gotoPrior(){
    //double check at end (doesn't work in ./test3)
    if( cursor != 0 ) {
        cursor--;
        return true;
    }
    else {
        return false;
    }
}    

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error){
    if( isEmpty() ) throw logic_error("List is empty");

    cursor = 0;
}
    
template <typename DataType>
void List<DataType>:: gotoEnd() throw (logic_error) {
    if( isEmpty() ) throw logic_error("List is empty");

    cursor = size - 1;
}    

//Observers
template <typename DataType>
bool List<DataType>::isEmpty() const{
    return size==0;
}

template <typename DataType>
bool List<DataType>::isFull() const{
    return size==maxSize;
}

template <typename DataType>
int List<DataType>::getCursorPosition() const{
    //double check
    return cursor;
}

template <typename DataType>
int List<DataType>::getSize() const{
    return size;
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error){
    if( isEmpty() ) throw logic_error("List is empty");

    return dataItems[cursor]; 

}

template <typename DataType>
DataType List<DataType>::operator[]( int position ) const throw (logic_error){
    // ! <0 or >=size
    if( isEmpty() ) throw logic_error("List is empty");
    if( position>=size | position < 0 ) throw logic_error("Position is out of bounds");
    return dataItems[cursor];
}

template <typename DataType>
void List<DataType>::showStructure() const { //Debudding function
// Outputs the data items in a list. if the list is empty, outputs
// "empty list". this operation is intended for testing/debugging
// purposes only.

    int j;   // loop counter

    if ( size == 0 ) {
       cout << "empty list" << endl;
    } else {
       cout << "size = " << size
            <<  "   cursor = " << cursor << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ ) {
          if( j == cursor ) {
              cout << "[";
              cout << dataItems[j];
              cout << "]";
              cout << "\t";
          }
          else {
              cout << dataItems[j] << "\t";
          }
       }
       cout << endl;
    }
}


// Transformers/mutators

template <typename DataType>
bool List<DataType>::search(DataType value){
    for(int i=0; i< size; i++ ){
       if ( dataItems[i] == value ) return true; 
    }
    return false;
}

template <typename DataType>
void List<DataType>::add( const DataType& newItem ) throw (logic_error){
    if( isFull() ) throw logic_error("List is full");

    for( int i=size; i>cursor+1; i--) {
        dataItems[i] = dataItems[i-1];
    }

    cursor++;
    dataItems[cursor] = newItem;
    size++;
}


template <typename DataType>
void List<DataType>::add( const List& otherList ) throw (logic_error){ //double check

    if( isFull() ) throw logic_error("List is full");

    for( int i=size; i>cursor+1; i--) {
        dataItems[i] = dataItems[i-1];
    }

    cursor++;
    size++;

}

template <typename DataType>
void List<DataType>::remove() throw (logic_error){ //double check
    
    if( isEmpty() ) throw logic_error("List is empty");

    // 0123|4567
    // abde|????
    //   C |S 
    //     |C
    for (int i=cursor; i<size-1; i++){
        dataItems[i] = dataItems[i+1];
    }

    size--;
    if( cursor == size ) cursor = 0; 
    if (isEmpty()) cursor= -1;
}

template <typename DataType>
void List<DataType>::remove( const DataType& delItem ){ //double check

    //int index= -1;
    for( int i=0; i<size; i++) {
        if( dataItems[i] == delItem ) {
            cursor=i;
            remove();
            break;
        }
    }
}


template <typename DataType>
void List<DataType>::replace( const DataType& replaceItem ) throw (logic_error){ //double check

    if( isEmpty() ) throw logic_error("List is empty");

    dataItems[cursor] = replaceItem;
    
}

template <typename DataType>
void List<DataType>::clear(){ 
    cursor = -1;
    size = 0;
}








// The rest of the code is up to you to add.
/* The pattern for each function is listed below:

template <typename DataType>
Class<TemplatedType>::function() {
  function body code
}
 
*/

#endif     // #ifndef LIST_CPP
