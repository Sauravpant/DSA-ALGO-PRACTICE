
// 113.Path Sum II
// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
// Each path should be returned as a list of the node values, not node references.
// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

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
    void findPaths(TreeNode*node,vector<vector<int>>&paths,vector<int>&ds,int target){
    if(node==nullptr)  return;
    if(node->left==nullptr && node->right==nullptr){
        if(target-node->val==0){
        ds.push_back(node->val);
        paths.push_back(ds);
        ds.pop_back();
        }
        return;
    }
    ds.push_back(node->val);
    findPaths(node->left,paths,ds,target-(node->val));
    findPaths(node->right,paths,ds,target-(node->val));
    ds.pop_back();

}
    

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> ds;
        if(root==nullptr)   return paths;
        findPaths(root,paths,ds,targetSum);
        return paths;
       
    }
};