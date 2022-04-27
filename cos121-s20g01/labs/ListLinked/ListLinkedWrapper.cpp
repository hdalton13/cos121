/**
 * ListLinkedWrapper.cpp: the wrapper code for the class that provides
 * access functions for the Linked List class.
 */

#ifndef LISTLINKEDWRAPPER_CPP
#define LISTLINKEDWRAPPER_CPP

#include "ListLinkedWrapper.h"

template <typename DataType>
ListLinkedWrapper<DataType>::ListLinkedWrapper(int ignored)
:List<DataType>(ignored)
{}

template <typename DataType>
ListLinkedWrapper<DataType>::ListLinkedWrapper(const ListLinkedWrapper<DataType> &other)
:List<DataType>(other)
{}

template <typename DataType>
typename List<DataType>::ListNode* ListLinkedWrapper<DataType>::__getHeadPtr()
{
    return List<DataType>::head;
}

template <typename DataType>
typename List<DataType>::ListNode* ListLinkedWrapper<DataType>::__getCursorPtr()
{
    return List<DataType>::cursor;
}

template <typename DataType>
void ListLinkedWrapper<DataType>::__setCursorPtr(typename List<DataType>::ListNode* ptr) {
    List<DataType>::cursor = ptr;
}

template <typename DataType>
DataType ListLinkedWrapper<DataType>::__getCursor()
{
    return List<DataType>::cursor->dataItem;
}

template <typename DataType>
void ListLinkedWrapper<DataType>::__add( const DataType& newDataItem )
{
    if ( this->head == 0 ) {
        this->cursor = this->head = new typename List<DataType>::ListNode(newDataItem, 0);
    } else {
        this->cursor = this->cursor->next = 
        new typename List<DataType>::ListNode(newDataItem, this->cursor->next);
    }
}

#endif  // ifndef LISTlINKEDWRAPPER_CPP
