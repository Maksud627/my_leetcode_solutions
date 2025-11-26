// 344. Reverse String: https://leetcode.com/problems/reverse-string/description/
// two pointers, string
// Tag: easy

/*
approach:
-> use two pointers, one at the beginning and one at the end of the string
-> swap the characters at the two pointers
-> move the pointers towards the center until they meet or cross
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            int temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

// TC: O(n/2) -> O(n), SC: O(1)