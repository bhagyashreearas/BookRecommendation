// Author Name: Bhagyashree Aras
// File name: BookList.h
// Date: 28 September 2020
// Purpose: Specification file for MemberList class.

#ifndef P1_MEMBERLIST_H
#define P1_MEMBERLIST_H

#include <string>
using namespace std;

class MemberList
{
public:
    MemberList(int);
    // Constructor that takes capacity value
    // Pre condition: capacity >=0
    // Post condition: Members array

    ~MemberList();
    // Destructor
    // Pre condition: none
    // Post condition: deallocate the array from heap

    void add(string);

    // Add element to array
    // Pre condition: String values passed in function
    // Post condition: values are added to the array

    static int size();
    // Number of elements in array
    // Pre condition: none
    // Post condition: return size of ratings array

    string getMember(int) const;
    // Returns string representation of of the MemberList class
    // Pre condition: none
    // Post condition: return memberName

private:
    int capacity;               // capacity of array
    int numElements;            // Number of elements
    static int sizeOfArray;      // size of array
    string* members;             // Pointer to the array
    void resize();              // resize array (when full)
};
#endif //P1_MEMBERLIST_H
