// Tag: Easy
// two pointer approach

/*
input: array->[5, 1, 22, 25, 6, -1, 8, 10], sequence->[1, 6, -1, 10] 
output: return true if the given sequence is a valid subsequence of the given array

valid subsequence is a sub-array containing elements that are present given array,
having same order as the given array
*/

#include<iostream>
#include<vector>
using namespace std;

bool ValidSubsequence(vector<int> array, vector<int> sequence)
{
    int idxSequence = 0;

    for(auto value : array)
    {
        // if sequence is exhausted before the array
        // we already got the sequence, so break
        if(idxSequence == sequence.size()) break;

        if(sequence[idxSequence] == value) idxSequence++;
    }
    return idxSequence == sequence.size();
}

int main()
{   
    vector<int> arr = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> seq = {1, 6, -1, 10}; 

    cout << ValidSubsequence(arr, seq) << endl;
    return 0;
}

// TC -> O(n); as only traversing through the main array for worst case
// SC -> O(1); not storing extra anything other than 2 pointers 