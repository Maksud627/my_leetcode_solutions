// 226. Invert Binary Tree: https://leetcode.com/problems/invert-binary-tree/description/
// binary tree, easy, recursion, dfs, bfs

/*
approach:
    own previous solution
*/

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
    TreeNode* invertTree(TreeNode* root) {
        // base case
        if(root == NULL) return root;

        // traverse tree recursion
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        // swapping left to right using temp
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};