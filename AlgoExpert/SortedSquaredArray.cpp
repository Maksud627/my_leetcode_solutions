// Tag: Easy
// two pointer approach

/*
input: SortedArray->[-4, -2, -1, 0, 1, 3]
output: SquaredSortedArray->[0, 1, 1, 4, 9, 16]

Given a sorted array containing negative to positive, 
have to return squared sorted array of that
*/

#include<iostream>
#include<vector>
using namespace std;

// optimal solution: two pointer approach
vector<int> SquaredSortedArray(vector<int> array)
{   
    vector<int> sqSortedArray;
    int leftPointer = 0;
    int rightPointer = array.size() - 1;
    int sortedArrIdxR = array.size() - 1;

    for (int i = 0; i < array.size(); i++)
        sqSortedArray[i] = 0;

    while(leftPointer < rightPointer)
    {
        if(abs(array[leftPointer]) < abs(array[rightPointer]))
        {
            sqSortedArray[sortedArrIdxR] = array[rightPointer] * array[rightPointer];
            rightPointer--;
            sortedArrIdxR--;
        }
        else
        {
            sqSortedArray[sortedArrIdxR] = array[leftPointer] * array[leftPointer];
            leftPointer++;
            sortedArrIdxR--;
        }
    }
    return sqSortedArray;
}