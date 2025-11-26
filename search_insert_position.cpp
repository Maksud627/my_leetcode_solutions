// 35. Search Insert Position: https://leetcode.com/problems/lexicographical-numbers/description/
// medium, tree, dfs

/*
    typical binary seach algorithm
    time complexity will be divided into half
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int middle = left + (right - left) / 2;

            if(target == nums[middle]) return middle;
            else if(target < nums[middle]){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        return left;
    }
};

// TC : O(logn) as each time we are dividing the numbers into half rather than traversing the whole array
// SC : O(1)