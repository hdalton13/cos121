// ListLinked.cpp -- file containing the Linked implementation of the List ADT. 
// Your name(s): Heather Dalton and Kayla Rehwoldt
// 04/27/2020

//incomplete status: remove(delItem), replace
//check by Brandle: add(const List<DataType>& otherList), replace, remove(delItem)

#ifndef LISTLINKED_CPP
#define LISTLINKED_CPP

#include <iostream>
#include <stdexcept>

#include "ListLinked.h"

using namespace std;

template <typename DataType>
List<DataType>::ListNode::ListNode( DataType newData, ListNode* next ) {
    dataItem = newData;
    this->next = next;
}

template <typename DataType>
List<DataType>::List() {
    head = (cursor = 0); 
}

template <typename DataType>
List<DataType>::List(int /* maxItems */) {
    head = cursor = 0; 
}

template <typename DataType>
List<DataType>::List(const List& other) {
    head = cursor = 0;
    operator= (other);
}

template <typename DataType>
List<DataType>::~List() {
    clear();
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other) {
    if( this == &other ) return *this;
    
    clear();
    ListNode* otherHead = other.head;
    ListNode* holdCursor = 0;
    while( otherHead != 0 ){
        add (otherHead->dataItem);
        if (otherHead == other.cursor){
            holdCursor = cursor;
        }
        otherHead = otherHead->next;
    }
    cursor = holdCursor;
    
    return *this;
}


// Iterators
template <typename DataType>
bool List<DataType>::gotoNext() {
    if( isEmpty() || cursor->next == 0 ) return false;
    else {
        cursor = cursor->next;
        return true;
    }
}

template <typename DataType>
bool List<DataType>::gotoPrior() {
    if( isEmpty() || cursor == head ) {
        return false;
    } else {
        ListNode* temp = cursor;
        cursor = head;
        while( cursor->next != temp ) {
            cursor = cursor->next;
        }
        return true;
    }
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw(logic_error){
    if (isEmpty()) throw logic_error("List is empty");
    
    cursor = head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw(logic_error){
    if( isEmpty() ) throw logic_error("List is empty");

    while( gotoNext() ){
        continue;
    }
}


// Observers
template <typename DataType>
bool List<DataType>::isEmpty() const {
    /*
    if (head==0) return true;
    else return false;
    */

    return head==0;
}

template <typename DataType>
bool List<DataType>::isFull() const {
    return false; 
}

template <typename DataType>
int List<DataType>::getCursorPosition() const {
    if( isEmpty() ) return -1;

    int i = 0;
    ListNode* temp = head;
    while( temp < cursor ) {
        temp = temp->next;
        i++;
    }

    return i;
}

template <typename DataType>
int List<DataType>::getSize() const {
    
    int i = 0;
    ListNode* temp = head;
    while( temp != 0) {
        temp = temp->next;
        i++;
    }

    return i;

}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error) {
    if( isEmpty() ) throw logic_error("List is empty");

    return cursor->dataItem;
}

template <typename DataType>
DataType List<DataType>::operator[]( int position ) const throw (logic_error) {
    if( isEmpty() ) throw logic_error("List is empty");
    if( position < 0 || position >= getSize() ) throw logic_error("Invalid position");
    
    int i = 0;
    ListNode* temp = head;
    while( i < position ) {
        temp = temp->next;
        i++;
    }

    return temp->dataItem;
}

template <typename DataType>
void List<DataType>::showStructure() const {

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

    if ( isEmpty() ) {
       cout << "Empty list" << endl;
    } 
    else {
        for (ListNode* temp = head; temp != 0; temp = temp->next) {
            if (temp == cursor) {
                cout << "[";
            }

            // Assumes that dataItem can be printed via << because
            // is is either primitive or operator<< is overloaded.
            cout << temp->dataItem;

            if (temp == cursor) {
                cout << "]";
            }
            cout << " ";
        }
        cout << endl;
    }
}
// Debugging function

// Transformers/mutators
template <typename DataType>
bool List<DataType>::search(DataType value) {

    ListNode* temp = head;
    while( temp != 0) {
        if( temp == value ) return true;
        temp = temp->next;
    }

    return false;
}

template <typename DataType>
void List<DataType>::add( const DataType& newItem ) throw (logic_error) {
    if ( isEmpty() ) {
        head = new ListNode( newItem, 0);
        cursor = head;
    } else {
       cursor->next = new ListNode( newItem, cursor->next );
       cursor = cursor->next; 
    }
}

template <typename DataType>
void List<DataType>::add( const List& otherList ) throw (logic_error) {

    //we have no way of verifying this, but the compiler is not complaining.
    ListNode* temp = otherList.head;
    while( temp != 0) {
        add(*temp);
        temp = temp->next;
    }
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error) {
    if( isEmpty() ) throw logic_error("List is empty");

    if( cursor == head ) {
        head = head->next;
        delete cursor;
        cursor = head;
    } else {
        ListNode* zapMe = cursor;
        gotoPrior();
        cursor->next = zapMe->next;
        cursor = cursor->next;
        delete zapMe;
        if( cursor == 0 ) {
            cursor = head;
        }
    }
}

template <typename DataType>
void List<DataType>::remove( const DataType& delItem ) {

    ListNode* temp = head;
    while( temp != 0) {
        if( temp == delItem ) cursor = temp;
        temp = temp->next;
    }

    remove();  
}

template <typename DataType>
void List<DataType>::replace( const DataType& replaceItem ) throw (logic_error) {
    if( isEmpty() ) throw logic_error("List is empty");
    
    cursor->dataItem= replaceItem;
}

template <typename DataType>
void List<DataType>::clear() {
    cursor = head;
    while( head !=0 ) {
        head = head->next;
        delete cursor;
        cursor = head;
    }
}

#endif
