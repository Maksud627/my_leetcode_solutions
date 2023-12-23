// 78. Subsets: https://leetcode.com/problems/subsets/
// array, backtracking, bit manipulation, medium

/*
approach:
- for any elements in the array
- we have 2 choice, either include that in the subset or not
- we have to generate all the subsets containing
- including for each elements and not including for each elements
- so recursion to the array and then
- include one element or not include it
*/

class Solution {
public:
    // subsets generator
    void subset_maker(int i, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
        // check if reached to the end of vector, then save to ans
        if(i == nums.size()){
            // that means already passed the last element
            ans.push_back(temp);
        }
        else{
            // consider when choosing ith element
            // push that to temp
            temp.push_back(nums[i]);
            subset_maker(i+1, nums, temp, ans);

            // another case ignoring the ith element
            temp.pop_back(); // this is pop the element we inserted
            subset_maker(i+1, nums, temp, ans);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subset_maker(0, nums, temp, ans);
        return ans;
    }
};

// TC: for every elements we have 2 choice(include or not include), so O(2^n)
// SC: we are storing at most n vector sized elements O(n) for ans, temp