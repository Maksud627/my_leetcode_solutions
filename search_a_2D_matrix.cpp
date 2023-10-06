// LC: 74 Search a 2D Matrix: https://leetcode.com/problems/search-a-2d-matrix/
// Matrix, Binary Search, medium

// approach
// watch this: https://youtu.be/ZYpYur0znng

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();

        int low = 0;
        int high = (row * column) - 1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(matrix[mid/column][mid%column] == target) return true;
            else if(matrix[mid/column][mid%column] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};