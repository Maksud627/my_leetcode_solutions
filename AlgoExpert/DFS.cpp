// Tag: Easy
// DFS algo

/*
input: given any tree
output: return a list of visiting all the nodes using dfs from root node

run dfs through all the nodes,
and then return the list of traversing nodes
*/

// dfs: explore a specific branch as deep as possible before exploring the next branch, likewise the rest

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

struct Level
{
    BinaryTree *root;
    int depth;
};

// vector<int> visitedNodes(BinaryTree *root)
// {
//     vector<int> visitedNodeList;
//     dfs(root, )

//     return visitedNodeList;
// }

void dfs()
{
    
}