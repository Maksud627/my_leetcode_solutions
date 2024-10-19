// 33. Search in Rotated Sorted Array: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// binary search, medium

/*
binary search impl with a twist of identifying sorted portion and then impl bs
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, mid;
        int right = nums.size() - 1;

        while(left <= right){
            mid = left + (right - left) / 2;
            if(target == nums[mid]) return mid;

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid])
                    right = mid - 1;
                else left = mid + 1;
            }
            else if(nums[mid] <= nums[right]){
                if(nums[mid] <= target && target <= nums[right])
                    left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

// tc -> O(logn)
// sc -> O(1)