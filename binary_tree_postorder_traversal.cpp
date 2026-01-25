// 145. Binary Tree Postorder Traversal: https://leetcode.com/problems/binary-tree-postorder-traversal/description/


// required knowledge: binary tree, tree traversal, stack, depth-first search
// Tag: easy

class TreeNode{
    int data;
public:
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
}