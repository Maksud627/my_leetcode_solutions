/* three process
 pre-order, in-order, post-order
1. pre-order: process the root, traverse the left subtree, traverse the right subtree
2. in-order: traverse the left subtree, process the root, traverse the right subtree
3. post-order: traverse the left subtree, traverse the right subtree, process the root

to-do: study about polish notations
*/

#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class TreeDFS
{
    public:
        // pre-order traversal
        void preorder(TreeNode* root)
        {
            if (root == nullptr)
                return;

            cout << root->data << " "; // process the root
            preorder(root->left);      // traverse the left subtree
            preorder(root->right);     // traverse the right subtree
        }

        // in-order traversal
        void inorder(TreeNode* root)
        {
            if(root == nullptr)
                return;
            
            inorder(root->left);       // traverse the left subtree
            cout << root->data << " "; // process the root
            inorder(root->right);      // traverse the right subtree
        }

        // post-order traversal
        void postorder(TreeNode* root)
        {
            if(root == nullptr)
                return;
            
            postorder(root->left);     // traverse the left subtree
            postorder(root->right);    // traverse the right subtree
            cout << root->data << " "; // process the root
        }
};

int main()
{
    /* Constructed Tree:
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Pre-order Traversal: ";
    TreeDFS treeDFS;
    treeDFS.preorder(root);
    cout << endl;

    cout << "In-order Traversal: ";
    treeDFS.inorder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    treeDFS.postorder(root);
    cout << endl;
}