// 54. Spiral Matrix: https://leetcode.com/problems/spiral-matrix/description/
// medium, matrix manipulation

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size(), left = 0, right = matrix[0].size();

        // base case
        if(matrix.empty()) return ans;

        while(left < right && top < bottom)
        {
            for(int i = left; i < right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i < bottom; i++){
                ans.push_back(matrix[i][right - 1]);
            }
            right--;

            if(top < bottom){
                for(int i = right - 1; i >= left; i--){
                    ans.push_back(matrix[bottom - 1][i]);
                }
                bottom--;
            }

            if(left < right){
                for(int i = bottom - 1; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};

// TC : O(m * n)
// SC : ans O(n)