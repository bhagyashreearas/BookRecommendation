// Author Name: Bhagyashree Aras
// File name: BookList.h
// Date: 28 September 2020
// Purpose: Specification file for BookList class.

#ifndef P1_BOOKLIST_H
#define P1_BOOKLIST_H

#include <string>
using namespace std;

class BookList {
public:
    BookList(int);
    // Constructor that takes capacity value
    // Pre condition: capacity >=0
    // Post condition: struct array is created, number of elements is equal to 0
    //                and capacity assigned to the values passed in constructor

    ~BookList();
    // Destructor
    // Pre condition: none
    // Post condition: deallocate the array from heap

    void add(string,string,string);
    // Add element to array
    // Pre condition: string values passed in function
    // Post condition: values are added to the array

    static int size();
    // Number of elements in array
    // Pre condition: none
    // Post condition: return size of struct array

    string getBook(int) const;
    // Returns string representation of of the BookList class
    // Pre condition: none
    // Post condition: return string

    bool getIsbn(int);
    // validate isbn
    // Precondition: integer number
    // Post condition : true if validated otherwise false

private:
    struct myStruct
    {
        int isbn;               // isbn number
        string author;          // author name
        string title;           // book title
        string year;            // year
    };

    int capacity;               // capacity of array
    int numElements;            // Number of elements
    myStruct * list;            // Pointer to the array
    static int sizeOfStruct;    // static
    void resize();              // resize array (when full)

};

#endif //P1_BOOKLIST_H
