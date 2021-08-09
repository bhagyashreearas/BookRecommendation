// Author Name: Bhagyashree Aras
// File name: RatingList.cpp
// Date: 28 September 2020
// Purpose: Implementation file for the RatingList class described in
//          RatingList.h used to add values to array and
//          access the size of array.
#include <climits>
#include "RatingList.h"

RatingList::RatingList(int cap) {

    ratings = new int*[cap];
    rowCapacity = cap;
    for (int row = 0; row < cap; row++)
    {
        ratings[row] = new int[cap];
    }
    colCapacity = cap;
}

RatingList::~RatingList()
{
    // And to deallocate memory,
    for (int i = 0; i < rowCapacity; i++) {
        delete[] ratings[i];
    }

    delete[] ratings;
    ratings = NULL;
}
int RatingList::rowCount = 0;
int RatingList::colCount = 0;

void RatingList::add(int rowIndex,int colIndex, int word)
{

    if (rowIndex >= rowCapacity)
    {
        resizeRow();
    }

    if (colIndex >= colCapacity)
    {
        resizeCol();
    }

    // Read a word;
    ratings[rowIndex][colIndex] = word;

    if (rowIndex > rowCount - 1)
    {
        rowCount = rowIndex + 1;
    }

    if (colIndex > colCount - 1)
    {
        colCount = colIndex + 1;
    }
}

int RatingList::size()
{
    return colCount;
}

void RatingList::resizeRow() {
    rowCapacity *= 2;

    // create new array based on updated capacity
    int **tempArr = new int *[rowCapacity];
    for (int row = 0; row < rowCapacity; row++) {
        tempArr[row] = new int[colCapacity];
    }

    // initialising whole array to 0
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++) {
            tempArr[i][j] = 0;
        }
    }

    // copy old array values to new array
    for (int i = 0; i < rowCount; i++) {
        tempArr[i] = ratings[i];
    }

    delete[] ratings;
    ratings = NULL;

    // reassign old array to new array
    ratings = tempArr;
}

void RatingList::resizeCol() {
    colCapacity *= 2;

    // create new array based on updated capacity
    int **tempArr = new int *[rowCapacity];
    for (int row = 0; row < rowCapacity; row++)
    {
        tempArr[row] = new int[colCapacity];
    }

    // initialising whole array to 0
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            tempArr[i][j] = 0;
        }
    }
    // copy old array values to new array
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            tempArr[i][j] = ratings[i][j];
        }
    }

    delete[] ratings;
    ratings = NULL;

    // reassign old array to new array
    ratings = tempArr;
}

int RatingList::getRating(int num, int num2) const
{
    return ratings[num][num2];
}

int RatingList::vectorProduct(int memberNumber){

    int * productList = new int[rowCount];

    for (int i = 0; i < rowCount; i++)
    {
        productList[i] = 0;
    }

    for (int i = 0; i < rowCount; i++)
    {
        if (i != memberNumber)
        {
            for (int j = 0; j < colCount; j++)
            {
                productList[i]  += ratings[memberNumber][j] * ratings[i][j];
            }
        }
        else
        {
            productList[i] = INT_MIN;
        }
    }

    int highest = INT_MIN;
    int highestIndex = -1;
    for (int i = 0; i < rowCount; i++)
    {
        if (productList[i] > highest)
        {
            highest = productList[i];
            highestIndex = i;
        }
    }

    // delete productList
    delete[] productList;
    productList = NULL;
    return highestIndex;
}

bool RatingList :: validate(int num){
    if (num == -5 || num == -3 || num == 0 || num == 1 || num == 3 || num == 5)
        return true;
    else
        return false;
}