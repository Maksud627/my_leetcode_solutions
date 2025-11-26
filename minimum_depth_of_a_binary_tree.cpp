// 111. Minimum Depth of Binary Tree: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
// easy, tree, traversal

/*
    level order traversal on a binary tree (basically a dfs will do)
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
    int leftsubTreeDepth;
    int rightsubTreeDepth;
    int minDepth(TreeNode* root) {
        // base cases
        if(root == NULL) return 0;

        // leaf node found
        if(root->left == NULL && root->right == NULL) return 1;

        // if left and right subtree exists
        if(root->left != NULL && root->right != NULL){
            leftsubTreeDepth = minDepth(root->left);
            rightsubTreeDepth = minDepth(root->right);
        }
        else if(root->left == NULL){
            leftsubTreeDepth = INT_MAX;
        }
        else if(root->right == NULL){
            rightsubTreeDepth = INT_MAX;
        }

        return min(leftsubTreeDepth, rightsubTreeDepth) + 1; // 1 is for the root level
    }
};