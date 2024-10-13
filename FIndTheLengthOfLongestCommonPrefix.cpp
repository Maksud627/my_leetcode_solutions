// 3043. Find the Length of the Longest Common Prefix: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/
// medium, hashset, trie

/*
    iterate over the first array
    and store the 10 reverse-factored each values in the hashset

    iterate over the second array
    check if the int contains in the hashset, eliminate single digit each time 
    from the array

    check for until the longest length is found
    return the longest length
*/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set <int> allPrefixes;

        for(int val : arr1)
        {
            while(!allPrefixes.count(val) && val > 0)
            {
                allPrefixes.insert(val);

                val /= 10;
            }
        }

        int longestPrefixLength = 0;
        for(int val : arr2)
        {
            while(!allPrefixes.count(val) && val > 0)
            {
                val /= 10;
            }

            if(val > 0)
            {   
                longestPrefixLength = max(longestPrefixLength, static_cast<int>(log10(val) + 1));
            }
        }

        return longestPrefixLength;
        
    }
};