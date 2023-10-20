// 424. Longest Repeating Character Replacement: https://leetcode.com/problems/longest-repeating-character-replacement/
// sliding window, medium, hash table

// approach
// watch this: https://youtu.be/gqXU1UyA8pk
// if totalwindowsize - max_freq of a char in that window = less of equal to given k, then okay
// otherwise slide left pointer to right and decrease frequency of left pointer

class Solution {
public:
    int characterReplacement(string s, int k) {
        // stores the freq of each char
        vector<int> count(26);
        // left and right pointer
        int left = 0;
        int right = 0;
        // store maxcount
        int maxCount = 0;
        // store result
        int result = 0;

        while(right < s.size()){
            // this is storing freq of char
            count[s[right] - 'A']++;
            // then collect the max_freq
            maxCount = max(maxCount, count[s[right] - 'A']);

            // violation
            if(right-left+1 - maxCount > k){
                // decrement of freq
                // at the left pointer
                count[s[left]-'A']--;
                left++;
            }
            // if not violated then got the max_window
            result = max(result, right-left+1);
            right++;
        }
        return result;
    }
};

// TC: O(n): traversing all the way of the given vector once in the loop
// SC: O(26)/O(1) for the count vector