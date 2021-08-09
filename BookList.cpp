// Author Name: Bhagyashree Aras
// File name: BookList.cpp
// Date: 28 September 2020
// Purpose: Implementation file for the BookList class described in BookList.h.
//          Used to add values to array and access the size of array.

#include "BookList.h"

BookList::BookList(int cap)
{
    list = new myStruct[cap];
    capacity = cap;
    numElements = 0;
}

BookList::~BookList()
{
    delete [] list;
}

int BookList::sizeOfStruct = 0;

void BookList::add(string author , string title, string year)
{

    if (numElements >= capacity) {
        resize();
    }

    list[numElements].author = author;
    list[numElements].title = title;
    list[numElements].year = year;
    list[numElements].isbn = numElements + 1;
    numElements++;
    sizeOfStruct++;
}

int BookList::size()
{
    return sizeOfStruct;
}

void BookList::resize() {
    // update capacity
    capacity *= 2;

    // create new array based on updated capacity
    myStruct * tempArr = new myStruct[capacity];

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)
        tempArr[i] = list[i];

    // delete old array
    delete [] list;

    // reassign old array to new array
    list = tempArr;
}
string BookList :: getBook(int num)const
{
    return ::to_string(list[num].isbn) + ", " + list[num].author + ", " +
           list[num].title + ", " + list[num].year;
}

bool BookList :: getIsbn(int num){
    if (num > 0 && num <= sizeOfStruct)
    {
        return true;
    }
    else
    {
        return false;
    }

}
