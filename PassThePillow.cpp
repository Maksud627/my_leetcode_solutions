// 2582. Pass the Pillow: https://leetcode.com/problems/pass-the-pillow/description/
// math, simulation
// Tag: easy

/*
approach:
-> keep a bool value for the direction
-> traverse through the index
-> whenever it is the last person or the first person,
-> we change the direction untill time is 0
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;
        bool direction = true; // positive side
        while(time--){
            if(direction){
                idx++;
                if(idx == n) direction = !direction;
            }
            else {
                idx--;
                if(idx == 1) direction = !direction;
            }
        }
        return idx;
    }
};


// TC -> O(time)
// SC -> O(1)