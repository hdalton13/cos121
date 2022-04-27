// Insert the code in this file into your ListArray.cpp file.

/**
 * @brief A debugging tool to help see what data is located where in the list.
 * The code for this method is provided for you.
 */
template <typename DataType>
void List<DataType>::showStructure() const // Debugging function
// Outputs the data items in a list. if the list is empty, outputs
// "empty list". this operation is intended for testing/debugging
// purposes only.

{
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

