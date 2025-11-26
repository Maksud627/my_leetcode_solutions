// 1929. Concatenation of Array: https://leetcode.com/problems/concatenation-of-array/description/
// array, simulation
// Tag: easy

/*
approach:
-> create a new array of size 2*n
-> traverse through the original array and fill the new array twice
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();
        for(int i = 0; i < 2*n; i++)
        {
            ans.push_back(nums[i % n]);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            nums.push_back(nums[i % n]);
        }
        return nums;
    }
};