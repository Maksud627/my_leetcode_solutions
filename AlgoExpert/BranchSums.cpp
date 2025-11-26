// Tag: Easy
// dfs approach

/*
input: given a binary tree
output: return an array of sums from root to all the leaf nodes

run dfs through all the nodes,
and then return the sums for when each leaf nodes are hit
*/
#include <vector>
using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

vector<int> branchSums(BinaryTree *root)
{
    vector<int> sums;

    calculateRunningSums(root, 0, sums);
    return sums;
}

void calculateRunningSums(BinaryTree *node, int runningSum, vector<int> sums)
{
    // base case
    if (node == NULL) return;

    // update running sum for each node
    int newRunningSum = runningSum + node->value;

    // if found the leaf node then append and return
    if(node->left == NULL && node->right == NULL)
    {
        // append sum to the list for leaf nodes
        sums.push_back(newRunningSum);
        return;
    }

    // else call recursive dfs call on both side of the tree
    calculateRunningSums(node->left, newRunningSum, sums);
    calculateRunningSums(node->right, newRunningSum, sums);
}