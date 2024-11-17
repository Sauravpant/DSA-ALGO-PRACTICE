/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
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
    int calcMinDepth(TreeNode*node){
        if(!node)   return 0;
        int leftHeight=calcMinDepth(node->left);
        int rightHeight=calcMinDepth(node->right);
        if(node->left==nullptr)   return 1+rightHeight;
        if(node->right==nullptr)   return 1+leftHeight;
        return 1+min(leftHeight,rightHeight);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root)
        return 0;
        return calcMinDepth(root);
    }
};