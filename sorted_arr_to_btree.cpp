// 108. Convert Sorted Array to Binary Search Tree:https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// binary tree, recursion, pre-order traversal

// approach
// watch this: https://youtu.be/12omz-VAyRk
// when it comes to sorted array, always think of binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        return constructTreefromArray(nums, 0, nums.size()-1);
    }

    TreeNode* constructTreefromArray(vector<int> nums, int left, int right){
        if(left > right) return nullptr;
        int midpoint = left + (right-left)/2;

        // as the pmidpoint will be the root for the BST
        TreeNode* node = new TreeNode(nums[midpoint]);

        node->left = constructTreefromArray(nums, left, midpoint-1);
        node->right = constructTreefromArray(nums, midpoint+1, right);
        return node;
    }
};