/*
Given an array, we have to find
maximum sum of contiguous subarray from the given array

we can use Kadane's Algorithm for this
- track of finding max_sum so far when iterating
- also make sure the max_sum does not go to negative

*/

// #include<iostream>
// #include<vector>
// #include<math.h>
// using namespace std;

// class Solution {
// public:
// //int getJ;
//     int maxSubArray(vector<int>& nums) {
//         int maxSum = nums[0];
//         int maxSoFar = 0;
        

        
//         return maxSum;
//     }
// };

// int main()
// {
//     int ans;
//     vector <int> givenInput = {-2,1,-3,4,-1,2,1,-5,4};
//     Solution obj;
//     ans = obj.maxSubArray(givenInput);
//     cout << ans << endl;
    
// }

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>& a) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < a.size(); i++) {      
        max_ending_here = max_ending_here + a[i];
      
        // If max_ending_here becomes more than 
        // the current result
        max_so_far = max(max_so_far, max_ending_here);
       
        // If max_ending_here becomes negative
        max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
}

// Driver Code
int main() {
    vector<int> a = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << "Maximum contiguous sum is " 
         <<  maxSubArraySum(a);
    return 0;
}