// LC: 11 Container With Most Water: https://leetcode.com/problems/container-with-most-water/
// two poiners, greedy, medium

// approach
// watch this: https://youtu.be/UuiTKBwPgAo

// first solution: this one gets TLE (obviously for O(n^2) sol)
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int vec_size = height.size();
//         int water_amount, max_water_amount=0;

//         for(int i=0; i<vec_size; i++) {
//             for(int j=i+1; j<vec_size; j++) {
//                 water_amount = min(height[i], height[j]) * (j-i);
//                 if(water_amount > max_water_amount) max_water_amount = water_amount;
//             }
//         }
//         return max_water_amount;
//     }
// };

// second solution [O(n)]
// each time check which pointer is smaller
// then increase left if that is smaller or decrease right if that smaller
class Solution {
public:
    int maxArea(vector<int>& height) {
        int vec_size = height.size();
        int water_amount, max_water_amount=0;
        int low = 0, high = vec_size-1;

        while(low < high) {
            water_amount = min(height[low], height[high]) * (high-low);
            if(water_amount > max_water_amount) max_water_amount = water_amount;

            if(height[low] < height[high]) low++;
            else high--;
        }
        return max_water_amount;
    }
};

// TC: O(n) as we are just traversing the whole vector once or not

