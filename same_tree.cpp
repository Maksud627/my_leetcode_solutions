// 100. Same Tree: https://leetcode.com/problems/same-tree/description/
// easy, binary tree traversal, recursion

/*
Given two binary trees root,
we have to find if those are smae stucturally or not

both trees can be same if and only if
- present node values are same
- left child node values are same
- right child node values are same
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case ; if both null then true
        if(p == NULL || q == NULL) return p == q;

        /* criterias to be identical: 
            a. node values are equal
            b. node -> left values are equal
            c. node -> right values are equal
        */
        return (p->val == q->val) && isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};

// TC -> O(n) as traversing the whole trees
// SC -> O(1) as storing nothing