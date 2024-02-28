class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int resLength=0;
        int left, right;

        for(int i=0; i<s.length(); i++){
        
            // for even length
            left = i;
            right = i+1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if((right-left+1) > resLength){
                    resLength = right-left+1;
                    result = s.substr(left, resLength);
                }
                left--;
                right++;
            }
    
            // for odd length
            left = i;
            right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if((right-left+1) > resLength){
                    resLength = right-left+1;
                    result = s.substr(left, resLength);
                }
                left--;
                right++;
            }
        
        }

        return result;
    }
};