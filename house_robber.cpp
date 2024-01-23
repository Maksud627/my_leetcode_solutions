// 198. House Robber: https://leetcode.com/problems/house-robber/description/
// dp, medium

/*
approach:
    https://youtu.be/VXqUQYGMnQg
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        // base case if nums.size == 1
        if(nums.size() < 2){
            return nums[0];
        }

        // declare dp to store the max
        int res[nums.size()];

        // get max values for first 2 elem
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            // either we take present n and max of n-2, or max of n-1
            res[i] = max(nums[i] + res[i-2], res[i-1]);
        }

        return res[nums.size() - 1];
    }
};