
// 567. Permutation in String: https://leetcode.com/problems/permutation-in-string/description/
// medium, sliding window


/*
hashmap of 26 fixed length for s2
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());

        for(int i = 0; i <= s2.length() - s1.length(); i++){
            if(s1.equals(s2[i], s2[i + s1.length() - 1]), s1[0]) return true;
        }
        return false;
    }
};