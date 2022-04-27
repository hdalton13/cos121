// Linked List Wrapper.h

#ifndef LISTLINKEDWRAPPER_H
#define LISTLINKEDWRAPPER_H

#include "ListLinked.cpp"

template <typename DataType>
class ListLinkedWrapper: public List<DataType> {
  public:
    ListLinkedWrapper(int ignored=0);
    ListLinkedWrapper(const ListLinkedWrapper<DataType> &other);
    typename List<DataType>::ListNode* __getHeadPtr();
    typename List<DataType>::ListNode* __getCursorPtr();
    DataType __getCursor();
    void __setCursorPtr(typename List<DataType>::ListNode* ptr);
    void __add( const DataType& newDataItem );

};

#endif // ifndef LISTLINKEDWRAPPER_H
