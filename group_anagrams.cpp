// LC: 49 Group Anagrams: https://leetcode.com/problems/group-anagrams/
// Array, hashtable, string, sorting, medium

// approach:
/*
- sort each of the string in the vector
- store the keys of hashmap as the sorted string and the values as the actual strings
- return all the vectors of a common keys inside another vector
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;

        // sorting each strings and inseritng to the map as key values
        for(auto x: strs){
            string temp = x;
            sort(x.begin(), x.end());
            // umap.insert({x, temp}); // or
            umap[x].push_back(temp);
        }
        // this snippet returns the values of each keys of the map
        // the values are basically the anagrams of that key
        for(auto x: umap){
            // here x is the iterator of each element inside the map
            ans.push_back(x.second);
        }

        return ans;
    }
};


// TC: O(m*n) m is the length of the outer vector and n is the size of max length of a str in the given vector
// SC: O(m*n) as has to store a vector inside another vector to return the answer