// Author Name: Bhagyashree Aras
// File name: BookList.h
// Date: 28 September 2020
// Purpose: Specification file for RatingList class.

#ifndef P1_RATINGLIST_H
#define P1_RATINGLIST_H
#include <string>
using namespace std;

class RatingList {
public:
    RatingList(int);
    // Constructor that takes capacity value
    // Pre condition: capacity >=0
    // Post condition: ratings array

    ~RatingList();
    // Destructor
    // Pre condition: none
    // Post condition: deallocate the array from heap

    void add(int, int, int);
    // Add element to array
    // Pre condition: int values passed in function
    // Post condition: values are added to the array

    static int size();
    // Number of elements in array
    // Pre condition: none
    // Post condition: return size of ratings array

    int getRating(int, int) const;
    // Returns string representation of of the BookList class
    // Pre condition: none
    // Post condition: return rating

    int vectorProduct(int);
    // Calculate vector product to get similar user
    // Pre condition: index of member is passed
    // Post condition: return Similar user index

    bool validate(int);
    // Does validation of rating
    // Pre condition: integer number is passed
    // Post condition: true if validate otherwise false

private:
    int colCapacity, rowCapacity;         // capacity of array
    static int colCount;                  // Number of elements
    static int rowCount;                 // Number of elements
    int ** ratings;                      // Pointer to the array
    void resizeRow();                    // resize array (when full)
    void resizeCol();
};
#endif //P1_RATINGLIST_H
