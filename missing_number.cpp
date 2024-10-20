// 268. Missing Number: https://leetcode.com/problems/missing-number/description/
// array, set, easy

/*
insert all values from [0, n] in a set, and then traverse the array to find it
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set <int> checker;
        int ans;

        for(int num: nums)
            checker.insert(num);

        for(int i = 0; i <= nums.size(); i++)
        {
            if(checker.find(i) == checker.end())
                ans = i;
            else continue;
        }
        return ans;
    }
};

// tc -> O(n) + O(1)
// sc -> O(1)