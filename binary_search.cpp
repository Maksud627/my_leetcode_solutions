// 704. Binary Search: https://leetcode.com/problems/binary-search/
// binary search, easy

/*
approach:
- define min, set low = 0, high = size()-1
- if target>mid, set low = mid+1, high = high
- else if target<mid, set low = low, high = mid-1
- else if mid = target, return the index of mid
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, low=0, high=nums.size()-1;
        
        while(mid!=target)
        {

        }
    }
};
