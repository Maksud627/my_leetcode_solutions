// 572. Subtree of Another Tree: https://leetcode.com/problems/subtree-of-another-tree/
// tree, dfs, traversal, recursion, easy

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

/*
    approach:
    three case:
    case 1: if root value and subroot values are null then return true
    case 2: if both values are same then go for both left and right subtree for both trees are same, if then return true
    case 3: if one subcase for left and right not equal for case 2 then return false, also for other case return false
*/

class Solution {
public:
    bool ans = false;

    bool match(TreeNode* root, TreeNode* subRoot){
        if(root != NULL && subRoot != NULL){
            bool a = match(root->left, subRoot->left);
            bool b = match(root->right, subRoot->right);

            if(root->val == subRoot->val && a && b) return true;
            else return false;
        }
        else if(root == NULL && subRoot == NULL) return true;
        else return false;
    }

    void inorder(TreeNode* root, TreeNode* subRoot){
        if(root!=NULL){
            inorder(root->left, subRoot);

            bool x = match(root, subRoot);
            if(x){ans = x;} 

            inorder(root->right, subRoot);
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inorder(root, subRoot);
        return ans;
    }
};

// TC: O(n) as for the recursion we are traversing the whole tree
// SC: O(1) we are not storing anything extra, so should be O(1)