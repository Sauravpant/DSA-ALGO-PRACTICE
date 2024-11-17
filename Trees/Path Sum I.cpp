
// 112. Maximum Path Sum
// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the 
// path equals targetSum.
// A leaf is a node with no children.
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
    bool check=false;
    bool checkSum(TreeNode*node,int target){
        if(node==nullptr)
        return false;
        if(node->left==nullptr && node->right==nullptr){
            if(target-node->val==0) return true;
        }
        bool left=checkSum(node->left,target-node->val);
        bool right= checkSum(node->right,target-node->val);
        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        return false;
       return checkSum(root,targetSum);
        


        
    }
};