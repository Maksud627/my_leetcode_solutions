// 386. Lexicographical Numbers: https://leetcode.com/problems/lexicographical-numbers/description/
// medium, tree, dfs

/*
    given the range of n = 13,
    traverse from 1, explore all the values that comes after 1 lexicographically,
    10, 11, 12, 13 (hit the n)
    backtrack, move to 2, try to explore values that comes after 2 (not possible)
    backtrack move to 3, same scenario, backtrack, move to 4 ... 9

    dfs - preorder - backtracking solution 
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumberList;
        // root parents
        for(int start = 1; start <= 9; start++){
            generateLexicographicalNumbers(start, n, lexicographicalNumberList);
        }

        return lexicographicalNumberList;
    }

    void generateLexicographicalNumbers(int currentNumber, int limit, vector<int>& result){

        // base case check
        if(currentNumber > limit) return;

        // append current number
        result.push_back(currentNumber);

        // append all the values from 0-9 to the result
        for(int i = 0; i <= 9; i++){
            int nextNumber = currentNumber * 10 + i;

            if(nextNumber <= limit){
                // run dfs recursion
                generateLexicographicalNumbers(nextNumber, limit, result);
            }
            else break; 
        }
        
    }
};

// TC: O(n)
// SC: O(logn) 10 base; as we will be traversing dfs traversal so the depth will be actually the space complexity