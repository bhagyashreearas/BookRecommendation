// Author Name: Bhagyashree Aras
// File name: MemberList.cpp
// Date: 28 September 2020
// Purpose: Implementation file for the MemberList class described in
//          MemberList.h used to add values to array, return member,
//          access the size of array and resize if necessary.

#include <string>
using namespace std;
#include "MemberList.h"

MemberList::MemberList(int cap) {

    members = new string[cap];
    capacity = cap;
    numElements = 0;
}

MemberList::~MemberList()
{
    delete[] members;
    members = NULL;
}
int MemberList::sizeOfArray = 0;
void MemberList::add(string line1) {

    if (numElements >= capacity)
    {
        resize();
    }

    members[numElements] = line1;
    numElements++;
    sizeOfArray++;
}

int MemberList::size()
{
    return sizeOfArray;
}

void MemberList::resize()
{
    // update capacity
    capacity *= 2;

    // create new array based on updated capacity
    string* tempArr = new string[capacity];

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)
        tempArr[i] = members[i];

    // delete old array
    delete[] members;

    // reassign old array to new array
    members = tempArr;
}

string MemberList :: getMember(int num)const
{
   return members[num];
}

