// LC 3: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// hashmap, sliding window, medium

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        unordered_map<char, int> mp;
        for(int right = 0, left = 0; right < s.length(); right++){
            // map will have have keys as the char of the string
            // and their position as the values
            // check if the char is in the map and also in the substring (left<=right)
            if(mp.find(s[right])!=mp.end() && mp[s[right]] >= left){
                left = mp[s[right]] + 1; 
            }
            // this part is to include in the map and find the max length
            max_len = max(max_len, right-left+1);
            mp[s[right]] = right;
        }
        return max_len;
    }
};

// TC: O(n) as we are traversing the whole string
// SC: O(1) as we created a map for the sliding window checking